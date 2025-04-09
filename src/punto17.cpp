#include <Arduino.h>
#include "stm32f103xb.h"


void setup() {
    RCC->APB2ENR |= (RCC_APB2ENR_IOPAEN_Msk);
    RCC->APB2ENR |= (RCC_APB2ENR_IOPBEN_Msk);  
    GPIOA->CRL = 0x44444444;
    GPIOA->CRH = 0x11111111;
}


void loop() {
   int a = GPIOB ->IDR & (1<<0);
    if(a=0)  {
      GPIOA -> BSRR |= GPIO_BSRR_BS0|GPIO_BSRR_BR1|
                       GPIO_BSRR_BS2|GPIO_BSRR_BR3|
                       GPIO_BSRR_BS4|GPIO_BSRR_BR5|
                       GPIO_BSRR_BS6|GPIO_BSRR_BR7;
               
    }else{
      GPIOA -> BSRR |= GPIO_BSRR_BS0|GPIO_BSRR_BS1|
                       GPIO_BSRR_BS2|GPIO_BSRR_BS3|
                       GPIO_BSRR_BS4|GPIO_BSRR_BS5|
                       GPIO_BSRR_BS6|GPIO_BSRR_BS7;
    }
}
