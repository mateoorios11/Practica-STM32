#include <Arduino.h>
#include "stm32f103xb.h"

void setup() {
  RCC->APB2ENR|=RCC_APB2ENR_IOPAEN_Msk;
  RCC->APB2ENR|=RCC_APB2ENR_IOPBEN_Msk;
  
  GPIOA -> CRL = 0x11111111;
  GPIOB -> CRL|= 0x44444444;

}

void loop() {
  int aa = GPIOB->IDR & (1<<0);
  if(aa==0){
    GPIOA -> BSRR |=GPIO_BSRR_BS0|GPIO_BSRR_BS1|
                   GPIO_BSRR_BS2|GPIO_BSRR_BS3|
                   GPIO_BSRR_BR4|GPIO_BSRR_BR5|
                   GPIO_BSRR_BR6|GPIO_BSRR_BR7;
  }else{
    GPIOA -> BSRR |=GPIO_BSRR_BR0|GPIO_BSRR_BR1|
                   GPIO_BSRR_BR2|GPIO_BSRR_BR3|
                   GPIO_BSRR_BS4|GPIO_BSRR_BS5|
                   GPIO_BSRR_BS6|GPIO_BSRR_BS7;
  }
}