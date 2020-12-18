/*
 * wf.h
 *
 *  Created on: Dec 5, 2020
 *      Author: Jovan
 */

#ifndef WIFI_WF_H
#define WIFI_WF_H

#include "simplelink//include//simplelink.h"


_i32 establishConnectionWithAP();
_i32 disconnectFromAP();
_i32 configureSimpleLinkToDefaultState();
_i32 initializeAppVariables();



_i32 getWeather(void);
_i32 getHostIP();
_i32 createConnection();
_i32 getData(void);
_i32 CLI_DisplayData(void);
void  CLI_displayBanner(void);
void extractData(const char *city, const char *temperature, const char *weather, const char *icon);
int WIFI_Exec(void);

#endif /* WIFI_WF_H_ */
