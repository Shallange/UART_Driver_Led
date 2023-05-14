#include "Led.h" //Inkluderar header filen för att även denna fil skall känna till de olika LED-beteckningarna och funktioner.
/*
Färger som är _color kan vara (se led.h enums).
RED
GREEN
YELLOW
BLUE

Status som _state kan ha(se led.h enums)
OFF = 0
ON = 1  

*/
Led::Led(LedColor_Type _color, LedState_Type _state)
{
  // konstruktorn tar in färgen och statusen av en LED och initierar dom i objektet som skapas.
  
  this->color = _color; // sätter färgen till den färg som skickats in som argumet till konstruktorn.
  this->state = _state; // sätter statusen till den status som skickats in som argumet till konstruktorn.

  //Enablea klockan för LED-porten (GPIOB).
  RCC->AHB1ENR |= LED_PORT_CLOCK;//Är en register bit som används för att aktiverar klockan för GPIO-porten som LED är kopplade till,
  //man aktiverar GPIO porten och gör så att man kan manipulera pinsen som är kopplade till porten( de pinsen som LED-lamporna är anslutna till).

  //Konfigurera LED-pinsen baserad på deras färg och status.
  switch(_color){ // switch sats som kontrollerar vilken färg som LED har.


    //MODER är en registerbit i GPIO, MODER styr funktionaliteten för en specifik GPIO-pinne man kan genom att sätta ett värde ändra om pinnen ska vara output
    //input eller andra funktioner.
    case RED: //om led är RÖD.
      LED_PORT->MODER |= LED_RED_MODE_BIT;//Sätter pin-läget för RÖD LED till output(01), detta gör att man kan skicka ut signaler som antingen är high eller low för på eller av.
  
      if(this->state == ON){//Om argumentet som skickades in var "ON".
        //Sätter pinens output till aktiv, genom att sätta motsvarande bit i ODR regitret till 1(high).
        LED_PORT->ODR |= LED_RED_PIN;
      }
      else{//Om argumentet som skickades in för "state" var "OFF".
        //Sätter pinens output till inaktiv, genom att sätta motsvarande bit i ODR regitret till 0(low).
        LED_PORT->ODR &= ~LED_RED_PIN;
      }
      break;

      case YELLOW: //sätter pin-läget för GUL LED till output.
      LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
      if(this->state == ON){//Om argumentet som skickades in för "state" var "ON".
        //Sätter pinens output till aktiv, genom att sätta motsvarande bit i ODR regitret till 1(high).
        LED_PORT->ODR |= LED_YELLOW_PIN;
      }
      else{//Om argumentet som skickades in för "state" var "OFF".
        //Sätter pinens output till inaktiv, genom att sätta motsvarande bit i ODR regitret till 0(low).
        LED_PORT->ODR &= ~LED_YELLOW_PIN;
      }
      break;

      case BLUE: //Sätter pin-läget för BLÅ LED till output.
      LED_PORT->MODER |= LED_BLUE_MODE_BIT;
      if(this->state == ON){//Om argumentet som skickades in för "state" var "ON"
        //Sätter pinens output till aktiv, genom att sätta motsvarande bit i ODR regitret till 1(high).
        LED_PORT->ODR |= LED_BLUE_PIN;
      }
      else{//Om argumentet som skickades in för "state" var "OFF".
        //Sätter pinens output till inaktiv, genom att sätta motsvarande bit i ODR regitret till 0(low).
        LED_PORT->ODR &= ~LED_BLUE_PIN;
      }
      break;

      case GREEN: //Sätter pin-läget för GRÖN LED till output.
      LED_PORT->MODER |= LED_GREEN_MODE_BIT;
      if(this->state == ON){//Om argumentet som skickades in för "state" var "ON".
        //Sätter pinens output till aktiv, genom att sätta motsvarande bit i ODR regitret till 1(high).
        LED_PORT->ODR |= LED_GREEN_PIN;
      }
      else{//Om argumentet som skickades in för "state" var "OFF".
        //Sätter pinens output till inaktiv, genom att sätta motsvarande bit i ODR regitret till 0(low).
        LED_PORT->ODR &= ~LED_GREEN_PIN;
      }
      break;

  }

}
/*setState*/
void Led::setState(LedState_Type _state){
//Sätta statusen av LED:n till det som skickas in (ON eller OFF).
  this->state = _state;

  //Kolla färgen på LED för att veta att korrekt LED manipuleras.
  //led1.setState(OFF); switch casen kollar vilken färg "led1" är satt till så att rätt färg stängs av med setState.
  switch(this->color){
    //Om "this->color"(referens till namn på lamp objektets färg) matchar färg i swichcase, ändra statusen till antingen ON eller OFF.
    case RED:
      //Om color = RÖD sätt MODER pin för RÖD till outputläge (01).
      LED_PORT->MODER |= LED_RED_MODE_BIT;
      //Om argumentet som skickades in för "state" var "ON".
      if(this->state == ON){
        //Sätter pinens output till aktiv, genom att sätta motsvarande bit i ODR regitret till 1(high).
        LED_PORT->ODR |= LED_RED_PIN;
      }
      else{//Om argumentet som skickades in för "state" var "OFF".
        //Sätter pinens output till inaktiv, genom att sätta motsvarande bit i ODR regitret till 0(low).
        LED_PORT->ODR &= ~LED_RED_PIN;
      }
      break;

      case YELLOW:
     //Om color = GUL sätt MODER pin för GUL till outputläge (01).
      LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
      //Om argumentet som skickades in för "state" var "ON".
      if(this->state == ON){
        //Sätter pinens output till aktiv, genom att sätta motsvarande bit i ODR regitret till 1(high).
        LED_PORT->ODR |= LED_YELLOW_PIN;
      }
      else{//Om argumentet som skickades in för "state" var "OFF".
        //Sätter pinens output till inaktiv, genom att sätta motsvarande bit i ODR regitret till 0(low).
        LED_PORT->ODR &= ~LED_YELLOW_PIN;
      }
      break;

      case BLUE:
      //Om color = BLÅ sätt MODER pin för BLÅ till outputläge (01).
      LED_PORT->MODER |= LED_BLUE_MODE_BIT;
      //Om argumentet som skickades in för "state" var "ON".
      if(this->state == ON){
        //Sätter pinens output till aktiv, genom att sätta motsvarande bit i ODR regitret till 1(high).
        LED_PORT->ODR |= LED_BLUE_PIN;
      }
      else{//Om argumentet som skickades in för "state" var "OFF".
        //Sätter pinens output till inaktiv, genom att sätta motsvarande bit i ODR regitret till 0(low).
        LED_PORT->ODR &= ~LED_BLUE_PIN;
      }
      break;

      case GREEN:
     //Om color = GRÖN sätt MODER pin för GRÖN till outputläge (01).
      LED_PORT->MODER |= LED_GREEN_MODE_BIT;
      //Om argumentet som skickades in för "state" var "ON".
      if(this->state == ON){
        //Sätter pinens output till aktiv, genom att sätta motsvarande bit i ODR regitret till 1(high).
        LED_PORT->ODR |= LED_GREEN_PIN;
      }
      else{//Om argumentet som skickades in för "state" var "OFF".
        //Sätter pinens output till inaktiv, genom att sätta motsvarande bit i ODR regitret till 0(low).
        LED_PORT->ODR &= ~LED_GREEN_PIN;
      }
      break;
  }

}

LedState_Type Led::getState(void)const{
  //Denna metod kontrollerar nuvarande status på den färg som efterfrågas.
  //statusen kan antingen vara ON eller OFF.
  //led1.getState();    <-     this-color refererar till led1 color i det här fallet.
  //Retunerar slutligen statusen på lampan.

  switch(this->color){

    case RED:
      break;

    case YELLOW:
      break;

    case BLUE:
      break;

    case GREEN:
      break;
  }
             //Returnerar LED-lampans status av vald färg.
             return this->state;
}
