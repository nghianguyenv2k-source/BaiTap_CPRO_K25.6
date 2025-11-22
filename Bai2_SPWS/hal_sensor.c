#include "hal_sensor.h"

static float soil_moisture = 0.0f;
static float air_temperature = 0.0f;
static float air_humidity = 0.0f;
// Sensor HAL (Hardware Abstraction Layer) implementation
void HAL_Sensor_Init(void)
{
    // Initialize sensor hardware (stub implementation)
    printf("Input the sensor inittal values from the keyboard:\n");
    printf("Input soil moisture percentage:\n");
    scanf("%f", &soil_moisture);
    printf("Input air temperature in Celsius:\n");
    scanf("%f", &air_temperature);
    printf("Input air humidity percentage:\n");
    scanf("%f", &air_humidity);
    printf("Sensor initialized.\n");
}
float HAL_Sensor_ReadSoilMoisture(void)
{
    return soil_moisture;
}
float HAL_Sensor_ReadAirTemperature(void) 
{
    return air_temperature;
}
float HAL_Sensor_ReadAirHumidity(void)
{
    return air_humidity;
}