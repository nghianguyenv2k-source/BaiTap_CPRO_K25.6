#ifndef _SPWS_CONTROLLER_H
#define _SPWS_CONTROLLER_H

#include "config.h"
// SPWS (Smart Plant Watering System) controller interface
// Controller functions would be declared here
SystemState_t spws_RunAutonomousMode(SystemConfig_t *config, SensorData_t *sensorData);
SystemState_t spws_HandleManualWatering(SystemConfig_t *config);

#endif // _SPWS_CONTROLLER_H
