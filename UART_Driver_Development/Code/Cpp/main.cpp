#include "led.h"

LedState_Type led1_state;
LedState_Type led2_state;
LedState_Type led3_state;

Led led1(RED,ON);

int main(void){ //huvudfunktion konstruerar och hanterar LED-lamporna
  USART2_Init();

  Led led2(BLUE,ON);

  Led *led3 = new Led(YELLOW,ON);

  led1_state = led1.getState();

  led1.setState(OFF);

  delete led3;

  while(1){}

}
