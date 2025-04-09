#include <Arduino.h>
uint16_t Ent, And;
void setup() {
RCC->APB2ENR|=RCC_APB2ENR_IOPAEN_Msk;
RCC->APB2ENR|=RCC_APB2ENR_IOPBEN_Msk;
GPIOA->CRL=0X44444444;
GPIOA->CRH=0X44444444;
GPIOB->CRL=0X11111111;
GPIOB->CRH=0X11111111;
}
void loop() {
  Ent=GPIOB->IDR;
  And= Ent&0x23;
  GPIOA->BSRR=Ent;


}


