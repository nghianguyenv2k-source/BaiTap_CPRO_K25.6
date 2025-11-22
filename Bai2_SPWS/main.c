#include <stdio.h>
#include "config.h"
#include "hal_button.h"
#include "hal_sensor.h"
#include "hal_actuator.h"
#include "spws_controller.h"

SystemState_t systemInit()
{
    SystemState_t initialState;

    // Set default system mode to AUTO
    initialState.CurrentMode = MODE_AUTO;

    // Set pump and LED states to OFF/NORMAL
    initialState.PumpState = PUMP_OFF;
    initialState.LEDState = LED_NORMAL;

    // Initialize sensor data to zero
    initialState.CurrentSensorData.soil_moisturePercent = 0.0f;
    initialState.CurrentSensorData.air_temperatureCelsius = 0.0f;
    initialState.CurrentSensorData.air_humidityPercent = 0.0f;

    // Set default configuration parameters
    initialState.Config.MinMoistureThresholdPercent = 30.0f; // 30%
    initialState.Config.MaxMoistureThresholdPercent = 70.0f; // 70%
    initialState.Config.MaxWateringDurationSec = 600;        // 10 minutes
    initialState.Config.ManualWateringDurationSec = 300;     // 5 minutes
    initialState.Config.SensorReadIntervalSec = 60;          // 1 minute

    return initialState;
}

int main() 
{
    printf("Hello every body!\n");
    printf("This is the Smart Plant Watering System (SPWS) project.\n");
    // Initialize system components here
        HAL_Sensor_Init();
        //Display initialized sensor values
        printf("Initialized Sensor Values:\n");
        printf("Soil Moisture: %.2f%%\n", HAL_Sensor_ReadSoilMoisture());
        printf("Air Temperature: %.2f oC\n", HAL_Sensor_ReadAirTemperature());
        printf("Air Humidity: %.2f%%\n", HAL_Sensor_ReadAirHumidity());
    return 0;
}