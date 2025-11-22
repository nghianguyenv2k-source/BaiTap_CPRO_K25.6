#include "hal_button.h"
void HAL_Button_Init(void)
{
    // Initialize button hardware (stub implementation)
}
char HAL_Button_IsPressed(void)
{
    //read button state from keyboard
    char ch = getchar();
    int c;
    do
    {
        /* code */
        c = getchar();
    } while ((c != '\n') && (c != EOF ));
    
    return ch;
}