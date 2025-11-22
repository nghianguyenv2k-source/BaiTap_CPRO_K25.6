#ifndef _CONFIG_H
#define _CONFIG_H

#include <stdio.h>

//Modes of system operation
typedef enum {
    MODE_MANUAL,
    MODE_AUTO
} SystemMode_t;

// Status of actuators
typedef enum 
{
    PUMP_OFF,
    PUMP_ON
}
PumpStatus_t;

// Status of LEDs
typedef enum
{
    LED_NORMAL,                 //Green: Normal operation
    LED_WATERING,               //yellow: Watering in progress
    LED_LOW_MOISTURE_ALERT,     //Red blinking: Low moisture alert
    LED_ERROR                   //Red solid: Error state    
} LEDStatus_t;

//Sensor data structure
typedef struct
{
    float soil_moisturePercent;   //Soil moisture percentage
    float air_temperatureCelsius;  //Air temperature in Celsius
    float air_humidityPercent;     //Air humidity percentage
    
}SensorData_t;

//Data structure for storing system configuration
typedef struct
{
    float MinMoistureThresholdPercent; //Minimum soil moisture threshold percentage
    float MaxMoistureThresholdPercent; //Maximum soil moisture threshold percentage
    unsigned int MaxWateringDurationSec; //Maximum watering duration in seconds
    unsigned int ManualWateringDurationSec; //Manual watering duration in seconds
    unsigned int SensorReadIntervalSec; //Sensor read interval in seconds

}SystemConfig_t;

//Data structure for managing the state of the entire system
typedef struct
{
    SystemMode_t CurrentMode;            //Current system modePumpStatus_t
    PumpStatus_t PumpState;              //Current pump state
    LEDStatus_t LEDState;                //Current LED state
    SensorData_t CurrentSensorData;      //Latest sensor data
    SystemConfig_t Config;               //System configuration parameters
}SystemState_t;

#endif // _CONFIG_H
