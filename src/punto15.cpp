#include <Arduino.h>
#include "stm32f103xb.h"

uint32_t Ent, B;
void setup() {
RCC->APB2ENR|=RCC_APB2ENR_IOPAEN_Msk;
RCC->APB2ENR|=RCC_APB2ENR_IOPBEN_Msk;
GPIOA->CRL=0X44444444;
GPIOA->CRH=0X44444444;
GPIOB->CRL=0X11111111;
GPIOB->CRH=0X11111111;
}
void loop() {
  uint32_t B = GPIOB->IDR;
  uint32_t Ent = B << 1;
  GPIOA->BSRR=Ent;


}


