/*
 * main.c - get weather details sample application
 *
 * Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/
 *
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*
 * Application Name     -   Get weather
 * Application Overview -   This is a sample application demonstrating how
 *                          to connect to openweathermap.org server and request
 *                          for weather details of a city. The application\
 *                          opens a TCP socket w/ the server and sends a HTTP
 *                          Get request to get the weather details. The received
 *                          data is processed and displayed on the console
 * Application Details  -   http://processors.wiki.ti.com/index.php/CC31xx_Get_Weather_Application
 *                          doc\examples\get_weather.pdf
 */



#include "wifi/wifi_weather_demo.h"
#include "common//sl_common.h"

#define APPLICATION_VERSION (_u8 *)"1.2.0"

#define SL_STOP_TIMEOUT        0xFF

#define CITY_NAME       "Novi Sad"

#define WEATHER_SERVER  "api.openweathermap.org"

#define PREFIX_BUFFER   "GET /data/2.5/weather?q="
#define POST_BUFFER     "&mode=xml&units=metric&APPID=49eb634cacaa5b37f81996c6ca30505f HTTP/1.1\r\nHost:api.openweathermap.org\r\nAccept: */"
#define POST_BUFFER2    "*\r\n\r\n"

extern _u32  g_Status;
extern int en_cli_debug;

#define SMALL_BUF           32
#define MAX_SEND_BUF_SIZE   512
#define MAX_SEND_RCV_SIZE   2048
/*
 * GLOBAL VARIABLES -- Start
 */
struct{
    _u8 Recvbuff[MAX_SEND_RCV_SIZE];
    _u8 SendBuff[MAX_SEND_BUF_SIZE];

    _u8 HostName[SMALL_BUF];
    _u8 CityName[SMALL_BUF];

    _u32 DestinationIP;
    _i16 SockID;
}g_AppData;


#define SUCCESS	0
/* Application specific status/error codes */
typedef enum{
    DEVICE_NOT_IN_STATION_MODE = -0x7D0,        /* Choosing this number to avoid overlap with host-driver's error codes */
    HTTP_SEND_ERROR = DEVICE_NOT_IN_STATION_MODE - 1,
    HTTP_RECV_ERROR = HTTP_SEND_ERROR - 1,
    HTTP_INVALID_RESPONSE = HTTP_RECV_ERROR -1,

    STATUS_CODE_MAX = -0xBB8
}e_AppStatusCodes;


//Application's entry point
int WIFI_Exec(void)
{
    _i32 retVal = -1;

    retVal = initializeAppVariables();
    ASSERT_ON_ERROR(retVal);

    /* Stop WDT and initialize the system-clock of the MCU */
    // Cube and main handles this

    /* Configure command line interface */
    CLI_Configure();

    en_cli_debug=1;  // enable handlers feedback via CLI

    CLI_displayBanner();

    /*
     * Following function configures the device to default state by cleaning
     * the persistent settings stored in NVMEM (viz. connection profiles &
     * policies, power policy etc)
     *
     * Applications may choose to skip this step if the developer is sure
     * that the device is in its default state at start of application
     *
     * Note that all profiles and persistent settings that were done on the
     * device will be lost
     */
    retVal = configureSimpleLinkToDefaultState();
    if(retVal < 0)
    {
        if (DEVICE_NOT_IN_STATION_MODE == retVal)
            CLI_Write((_u8 *)" Failed to configure the device in its default state \n\r");

        LOOP_FOREVER();
    }

    CLI_Write((_u8 *)" Device is configured in default state \n\r");

    /*
     * Assumption is that the device is configured in station mode already
     * and it is in its default state
     */
    retVal = sl_Start(0, 0, 0);
    if ((retVal < 0) ||
        (ROLE_STA != retVal) )
    {
        CLI_Write((_u8 *)" Failed to start the device \n\r");
        LOOP_FOREVER();
    }

    CLI_Write((_u8 *)" Device started as STATION \n\r");

    /* Connecting to WLAN AP */
    retVal = establishConnectionWithAP();
    if(retVal < 0)
    {
        CLI_Write((_u8 *)" Failed to establish connection w/ an AP \n\r");
        LOOP_FOREVER();
    }

    CLI_Write((_u8 *)" Connection established w/ AP and IP is acquired \n\r");


    retVal = getWeather();
    if(retVal < 0)
    {
        CLI_Write((_u8 *)" Failed to get weather information \n\r");
        LOOP_FOREVER();
    }

    retVal = CLI_DisplayData();
    if(retVal < 0)
    {
        CLI_Write((_u8 *)" Failed to parse data \n\r");
        LOOP_FOREVER();
    }

    retVal = disconnectFromAP();
    if(retVal < 0)
    {
        CLI_Write((_u8 *)" Failed to disconnect from AP \n\r");
        LOOP_FOREVER();
    }

    en_cli_debug=0;  // enable handlers feedback via CLI

    return 0;
}

//This function Obtains the required data from the server
_i32  getData(void)
{
    _u8* p_bufLocation = NULL;
    _i32 retVal = -1;

    pal_Memset(g_AppData.Recvbuff, 0, sizeof(g_AppData.Recvbuff));

    // Puts together the HTTP GET string.
    p_bufLocation = g_AppData.SendBuff;
    pal_Strcpy(p_bufLocation, PREFIX_BUFFER);

    p_bufLocation += pal_Strlen(PREFIX_BUFFER);
    pal_Strcpy(p_bufLocation, g_AppData.CityName);

    p_bufLocation += pal_Strlen(g_AppData.CityName);
    pal_Strcpy(p_bufLocation, POST_BUFFER);

    p_bufLocation += pal_Strlen(POST_BUFFER);
    pal_Strcpy(p_bufLocation, POST_BUFFER2);

    // Send the HTTP GET string to the open TCP/IP socket.
    retVal = sl_Send(g_AppData.SockID, g_AppData.SendBuff, pal_Strlen(g_AppData.SendBuff), 0);
    if(retVal != pal_Strlen(g_AppData.SendBuff))
        ASSERT_ON_ERROR(HTTP_SEND_ERROR);

    // Receive response
    retVal = sl_Recv(g_AppData.SockID, &g_AppData.Recvbuff[0], MAX_SEND_RCV_SIZE, 0);
    if(retVal <= 0)
        ASSERT_ON_ERROR(HTTP_RECV_ERROR);

    g_AppData.Recvbuff[pal_Strlen(g_AppData.Recvbuff)] = '\0';

    return SUCCESS;
}

_i32 CLI_DisplayData(void)
{
    _u8 *p_startPtr = NULL;
    _u8 *p_endPtr = NULL;

    //Get ticker name
    p_startPtr = (_u8 *)pal_Strstr(g_AppData.Recvbuff, "name=");
    if( NULL != p_startPtr )
    {
        p_startPtr = p_startPtr + pal_Strlen("name=") + 1;
        p_endPtr = (_u8 *)pal_Strstr(p_startPtr, "\">");
        if( NULL != p_endPtr )
        {
            *p_endPtr = 0;
        }
    }

    CLI_Write((_u8 *)"\n ************************ \n\r\n\r");
    CLI_Write((_u8 *)" City: ");
    if(p_startPtr == NULL)
    {
        CLI_Write((_u8 *)"N/A\n\r\n\r");
    }
    else
    {
        CLI_Write((_u8 *)p_startPtr);
        CLI_Write((_u8 *)"\n\r\n\r");
    }

    if(p_endPtr == NULL)
    {
        CLI_Write((_u8 *)" Error during parsing the data.\r\n");
        ASSERT_ON_ERROR(HTTP_INVALID_RESPONSE);
    }

    // Get Temperature Value
    p_startPtr = (_u8 *)pal_Strstr(p_endPtr+1, "temperature value");
    if( NULL != p_startPtr )
    {
        p_startPtr = p_startPtr + pal_Strlen("temperature value") + 2;
        p_endPtr = (_u8 *)pal_Strstr(p_startPtr, "\" ");
        if( NULL != p_endPtr )
        {
            *p_endPtr = 0;
        }
    }

    CLI_Write((_u8 *)" Temperature: ");
    if(p_startPtr == NULL)
    {
        CLI_Write((_u8 *)"N/A\n\r\n\r");
    }
    else
    {
        CLI_Write((_u8 *)p_startPtr);
        CLI_Write((_u8 *)" C\n\r\n\r");
    }

    //Get weather
    p_startPtr = (_u8 *)pal_Strstr(p_endPtr+1, "weather number");
    if( NULL != p_startPtr )
    {
        p_startPtr = p_startPtr + pal_Strlen("weather number") + 14;
        p_endPtr = (_u8 *)pal_Strstr((char *)p_startPtr, "\" ");
        if( NULL != p_endPtr )
        {
            *p_endPtr = 0;
        }
    }

    CLI_Write((_u8 *)" Weather Condition: ");
    if(p_startPtr == NULL)
    {
        CLI_Write((_u8 *)"N/A\n\r\n\r");
    }
    else
    {
        CLI_Write((_u8 *)p_startPtr);
        CLI_Write((_u8 *)"\n\r\n\r");
    }

    //Get icon
    p_startPtr = (_u8 *)pal_Strstr(p_endPtr+1, "icon");
    if( NULL != p_startPtr )
    {
        p_startPtr = p_startPtr + pal_Strlen("icon") + 2;
        p_endPtr = (_u8 *)pal_Strstr((char *)p_startPtr, "\"");
        if( NULL != p_endPtr )
        {
            *p_endPtr = 0;
        }
    }

    CLI_Write((_u8 *)" Weather Icon: ");
    if(p_startPtr == NULL)
    {
        CLI_Write((_u8 *)"N/A\n\r\n\r");
    }
    else
    {
        CLI_Write((_u8 *)p_startPtr);
        CLI_Write((_u8 *)"\n\r\n\r");
    }
    CLI_Write((_u8 *)"\n ************************ \n\r\n\r");

    return SUCCESS;
}

void extractData(const char *city, const char *temperature, const char *weather, const char *icon)
{
    _u8 *p_startPtr = NULL;
    _u8 *p_endPtr = NULL;

    //Get city name
    p_startPtr = (_u8 *)pal_Strstr(g_AppData.Recvbuff, "name=");
    if( NULL != p_startPtr )
    {
        p_startPtr = p_startPtr + pal_Strlen("name=") + 1;
        p_endPtr = (_u8 *)pal_Strstr(p_startPtr, "\">");
        if( NULL != p_endPtr ) *p_endPtr = 0;
    }
    if(p_startPtr == NULL) pal_Strcpy(city, "N/A");
    else pal_Strcpy(city, p_startPtr);


    // Get Temperature Value
    p_startPtr = (_u8 *)pal_Strstr(p_endPtr+1, "temperature value");
    if( NULL != p_startPtr )
    {
        p_startPtr = p_startPtr + pal_Strlen("temperature value") + 2;
        p_endPtr = (_u8 *)pal_Strstr(p_startPtr, "\" ");
        if( NULL != p_endPtr ) *p_endPtr = 0;
    }
    if(p_startPtr == NULL) pal_Strcpy(temperature, "N/A");
    else pal_Strcpy(temperature, p_startPtr);


    //Get weather
    p_startPtr = (_u8 *)pal_Strstr(p_endPtr+1, "weather number");
    if( NULL != p_startPtr )
    {
        p_startPtr = p_startPtr + pal_Strlen("weather number") + 14;
        p_endPtr = (_u8 *)pal_Strstr((char *)p_startPtr, "\" ");
        if( NULL != p_endPtr ) *p_endPtr = 0;
    }
    if(p_startPtr == NULL) pal_Strcpy(weather, "N/A");
    else pal_Strcpy(weather, p_startPtr);


    //Get icon
    p_startPtr = (_u8 *)pal_Strstr(p_endPtr+1, "icon");
    if( NULL != p_startPtr )
    {
        p_startPtr = p_startPtr + pal_Strlen("icon") + 2;
        p_endPtr = (_u8 *)pal_Strstr((char *)p_startPtr, "\"");
        if( NULL != p_endPtr ) *p_endPtr = 0;
    }
    if(p_startPtr == NULL) pal_Strcpy(icon, "N/A");
    else pal_Strcpy(icon, p_startPtr);
}

//
_i32 createConnection()
{
    SlSockAddrIn_t  Addr;

    _i16 sd = 0;
    _i16 AddrSize = 0;
    _i32 ret_val = 0;

    Addr.sin_family = SL_AF_INET;
    Addr.sin_port = sl_Htons(80);

    /* Change the DestinationIP endianity, to big endian */
    Addr.sin_addr.s_addr = sl_Htonl(g_AppData.DestinationIP);

    AddrSize = sizeof(SlSockAddrIn_t);

    sd = sl_Socket(SL_AF_INET,SL_SOCK_STREAM, 0);
    if( sd < 0 )
    {
        //CLI_Write((_u8 *)" Error creating socket\n\r\n\r");
        ASSERT_ON_ERROR(sd);
    }

    ret_val = sl_Connect(sd, ( SlSockAddr_t *)&Addr, AddrSize);
    if( ret_val < 0 )
    {
        /* error */
        //CLI_Write((_u8 *)" Error connecting to server\n\r\n\r");
        ASSERT_ON_ERROR(ret_val);
    }

    return sd;
}

// This function obtains the server IP address

_i32 getHostIP()
{
    _i32 status = -1;

    status = sl_NetAppDnsGetHostByName((_i8 *)g_AppData.HostName,
                                       pal_Strlen(g_AppData.HostName),
                                       &g_AppData.DestinationIP, SL_AF_INET);
    ASSERT_ON_ERROR(status);

    return SUCCESS;
}

// Get the Weather from server

_i32 getWeather(void)
{
    _i32 retVal = -1;

    pal_Strcpy((char *)g_AppData.HostName, WEATHER_SERVER);

    retVal = getHostIP();
    if(retVal < 0)
    {
        CLI_Write((_u8 *)" Unable to reach Host\n\r\n\r");
        ASSERT_ON_ERROR(retVal);
    }

    g_AppData.SockID = createConnection();
    ASSERT_ON_ERROR(g_AppData.SockID);

    pal_Memset(g_AppData.CityName, 0x00, sizeof(g_AppData.CityName));
    pal_Memcpy(g_AppData.CityName, CITY_NAME, pal_Strlen(CITY_NAME));
    g_AppData.CityName[pal_Strlen(CITY_NAME)] = '\0';

    retVal = getData();
    ASSERT_ON_ERROR(retVal);


    retVal = sl_Close(g_AppData.SockID);
    ASSERT_ON_ERROR(retVal);

    return 0;
}

// This function configure the SimpleLink device in its default state
/*
	   - Sets the mode to STATION
	   - Configures connection policy to Auto and AutoSmartConfig
	   - Deletes all the stored profiles
	   - Enables DHCP
	   - Disables Scan policy
	   - Sets Tx power to maximum
	   - Sets power policy to normal
	   - Unregisters mDNS services
	   - Remove all filters
*/

_i32 configureSimpleLinkToDefaultState()
{
    SlVersionFull   ver = {0};
    _WlanRxFilterOperationCommandBuff_t  RxFilterIdMask = {0};

    _u8           val = 1;
    _u8           configOpt = 0;
    _u8           configLen = 0;
    _u8           power = 0;

    _i32          retVal = -1;
    _i32          mode = -1;

    mode = sl_Start(0, 0, 0);
    ASSERT_ON_ERROR(mode);

    /* If the device is not in station-mode, try configuring it in station-mode */
    if (ROLE_STA != mode)
    {
        if (ROLE_AP == mode)
        {
            /* If the device is in AP mode, we need to wait for this event before doing anything */
            while(!IS_IP_ACQUIRED(g_Status)) { _SlNonOsMainLoopTask(); }
        }

        /* Switch to STA role and restart */
        retVal = sl_WlanSetMode(ROLE_STA);
        ASSERT_ON_ERROR(retVal);

        retVal = sl_Stop(SL_STOP_TIMEOUT);
        ASSERT_ON_ERROR(retVal);

        retVal = sl_Start(0, 0, 0);
        ASSERT_ON_ERROR(retVal);

        /* Check if the device is in station again */
        if (ROLE_STA != retVal)
        {
            /* We don't want to proceed if the device is not coming up in station-mode */
            ASSERT_ON_ERROR(DEVICE_NOT_IN_STATION_MODE);
        }
    }

    /* Get the device's version-information */
    configOpt = SL_DEVICE_GENERAL_VERSION;
    configLen = sizeof(ver);
    retVal = sl_DevGet(SL_DEVICE_GENERAL_CONFIGURATION, &configOpt, &configLen, (_u8 *)(&ver));
    ASSERT_ON_ERROR(retVal);

    /* Set connection policy to Auto + SmartConfig (Device's default connection policy) */
    retVal = sl_WlanPolicySet(SL_POLICY_CONNECTION, SL_CONNECTION_POLICY(1, 0, 0, 0, 1), NULL, 0);
    ASSERT_ON_ERROR(retVal);

    /* Remove all profiles */
    retVal = sl_WlanProfileDel(0xFF);
    ASSERT_ON_ERROR(retVal);

    /*
     * Device in station-mode. Disconnect previous connection if any
     * The function returns 0 if 'Disconnected done', negative number if already disconnected
     * Wait for 'disconnection' event if 0 is returned, Ignore other return-codes
     */
    retVal = sl_WlanDisconnect();
    if(0 == retVal)
    {
        /* Wait */
        while(IS_CONNECTED(g_Status)) { _SlNonOsMainLoopTask(); }
    }

    /* Enable DHCP client*/
    retVal = sl_NetCfgSet(SL_IPV4_STA_P2P_CL_DHCP_ENABLE,1,1,&val);
    ASSERT_ON_ERROR(retVal);

    /* Disable scan */
    configOpt = SL_SCAN_POLICY(0);
    retVal = sl_WlanPolicySet(SL_POLICY_SCAN , configOpt, NULL, 0);
    ASSERT_ON_ERROR(retVal);

    /* Set Tx power level for station mode
       Number between 0-15, as dB offset from max power - 0 will set maximum power */
    power = 0;
    retVal = sl_WlanSet(SL_WLAN_CFG_GENERAL_PARAM_ID, WLAN_GENERAL_PARAM_OPT_STA_TX_POWER, 1, (_u8 *)&power);
    ASSERT_ON_ERROR(retVal);

    /* Set PM policy to normal */
    retVal = sl_WlanPolicySet(SL_POLICY_PM , SL_NORMAL_POLICY, NULL, 0);
    ASSERT_ON_ERROR(retVal);

    /* Unregister mDNS services */
    retVal = sl_NetAppMDNSUnRegisterService(0, 0);
    ASSERT_ON_ERROR(retVal);

    /* Remove  all 64 filters (8*8) */
    pal_Memset(RxFilterIdMask.FilterIdMask, 0xFF, 8);
    retVal = sl_WlanRxFilterSet(SL_REMOVE_RX_FILTER, (_u8 *)&RxFilterIdMask,
                       sizeof(_WlanRxFilterOperationCommandBuff_t));
    ASSERT_ON_ERROR(retVal);

    retVal = sl_Stop(SL_STOP_TIMEOUT);
    ASSERT_ON_ERROR(retVal);

    retVal = initializeAppVariables();
    ASSERT_ON_ERROR(retVal);

    return retVal; /* Success */
}


// This function connects to the required AP (SSID_NAME).
_i32 establishConnectionWithAP()
{
    SlSecParams_t secParams = {0};
    _i32 retVal = 0;

    secParams.Key = PASSKEY;
    secParams.KeyLen = PASSKEY_LEN;
    secParams.Type = SEC_TYPE;

    retVal = sl_WlanConnect(SSID_NAME, pal_Strlen(SSID_NAME), 0, &secParams, 0);
    ASSERT_ON_ERROR(retVal);

    /* Wait */
    while((!IS_CONNECTED(g_Status)) || (!IS_IP_ACQUIRED(g_Status))) { _SlNonOsMainLoopTask(); }

    return SUCCESS;
}

//This function disconnects from the connected AP
_i32 disconnectFromAP()
{
    _i32 retVal = -1;

    /*
     * The function returns 0 if 'Disconnected done', negative number if already disconnected
     * Wait for 'disconnection' event if 0 is returned, Ignore other return-codes
     */
    retVal = sl_WlanDisconnect();
    if(0 == retVal)
    {
        /* Wait */
        while(IS_CONNECTED(g_Status)) { _SlNonOsMainLoopTask(); }
    }

    return SUCCESS;
}

// This function initializes the application variables
_i32 initializeAppVariables()
{
    g_Status = 0;
    pal_Memset(&g_AppData, 0, sizeof(g_AppData));

    return SUCCESS;
}

// This function displays the application's banner
void CLI_displayBanner(void)
{
    CLI_Write((_u8 *)"\n\r\n\r");
    CLI_Write((_u8 *)" Get weather application - Version ");
    CLI_Write(APPLICATION_VERSION);
    CLI_Write((_u8 *)"\n\r*******************************************************************************\n\r");
}

