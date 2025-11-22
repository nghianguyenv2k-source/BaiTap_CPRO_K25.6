#ifndef _HAL_SENSOR_H
#define _HAL_SENSOR_H

#include <stdio.h>

// Sensor HAL (Hardware Abstraction Layer) interface
// Sensor handling functions would be declared here
//Sensor initialization function
void HAL_Sensor_Init(void);
//Function to read soil moisture percentage
float HAL_Sensor_ReadSoilMoisture(void);
//Function to read air temperature in Celsius
float HAL_Sensor_ReadAirTemperature(void);
//Function to read air humidity percentage
float HAL_Sensor_ReadAirHumidity(void);
#endif // _HAL_SENSOR_H


