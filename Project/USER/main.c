#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
 
 
/************************************************
************************************************/


 int main(void)
 {
    delay_init();       //延时函数初始化	  
    LED_Init();         //初始化与LED连接的硬件接口
    KEY_Init();         //按键初始化
    
    while(1)
    {
        u8 keypres = KEY_Scan(ENABLE_MORE_PRESS);
        if(keypres == NOKEY_PRES)
            continue;
        else if(keypres == KEY0_PRES)
        {
            LED0=0;
            LED1=0;
        }
        else if(keypres == KEY1_PRES)
        {
            LED0=1;
            LED1=0;
        }
        else
        {
            LED0=1;
            LED1=1;
        }
    }
 }


