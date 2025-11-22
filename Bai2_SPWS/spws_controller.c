#include "spws_controller.h"
// SPWS (Smart Plant Watering System) controller implementation
SystemState_t spws_RunAutonomousMode(SystemConfig_t *config, SensorData_t *sensorData)
{
    SystemState_t systemState;
    // Initialize system state
    systemState.CurrentMode = MODE_AUTO;
    systemState.Config = *config;
    systemState.CurrentSensorData = *sensorData;
    // Determine pump and LED states based on sensor data and configuration
    if (sensorData->soil_moisturePercent < config->MinMoistureThresholdPercent)
    {
        systemState.PumpState = PUMP_ON;
        systemState.LEDState = LED_WATERING;
        printf("Autonomous Mode: Soil moisture low (%.2f%%). Pump ON.\n", sensorData->soil_moisturePercent);    
    }
    else
    {
        systemState.PumpState = PUMP_OFF;
        systemState.LEDState = LED_NORMAL;
        printf("Autonomous Mode: Soil moisture adequate (%.2f%%). Pump OFF.\n", sensorData->soil_moisturePercent);  
    }
    return systemState;
}

SystemState_t spws_HandleManualWatering(SystemConfig_t *config)
{
    SystemState_t systemState;
    // Initialize system state
    systemState.CurrentMode = MODE_MANUAL;
    systemState.Config = *config;
    // Set pump and LED states for manual watering
    systemState.PumpState = PUMP_ON;
    systemState.LEDState = LED_WATERING;
    printf("Manual Mode: Pump ON for %u seconds.\n", config->ManualWateringDurationSec);
    return systemState;
}