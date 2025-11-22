#ifndef _HAL_BUTTON_H
#define _HAL_BUTTON_H

#include <stdio.h>

// Button HAL (Hardware Abstraction Layer) interface
//button handling functions
void HAL_Button_Init(void);
char HAL_Button_IsPressed(void);
#endif // _HAL_BUTTON_H
