#ifndef LED_H // Om LED_h inte är definerad(inte inkluderad i koden tidigare).
#define LED_H // Definera LED_H.

#include <stdint.h> // Inkluderar C-biblioteket stdin.h för int-typer.
#include "UART.h" // Inkluderar "UART.h"för att andvända UART-funktionaliteten.
#include "stm32f4xx.h" //Device Header för enhetsspecifika angivelser om hårdvaran.

//Definera vilken GPIO som skall vara ansvarig för LED-funktionen, vi väljer GPIOB för att vi har GPIOA till UART 
//vi väljer bara nästkommande port som är GPIOB i detta fall.
#define LED_PORT GPIOB

//Definerar klocksignalen för porten, vi aktiverar porten för att aktivera porten.
#define LED_PORT_CLOCK (1U<<1)


//Man Definierar både pins och respekive MODE_BIT nedan för att enklare kunna göra bitwise operations.

//Definiera de olika pinsen för de olika LED-färgerna, pin 12-13-14-15 är pinsen som lamporna är kopplade till.
#define LED_RED_PIN (1U<<14)
#define LED_GREEN_PIN (1U<<12)
#define LED_YELLOW_PIN (1U<<13)
#define LED_BLUE_PIN (1U<<15)

//Definiera mode bits för varje LED-färg. varje port har 4 olika 32-bit register för konfiguering, vi använder MODER
//32 bits och varje pin har 2 bit, exempelvis så pin 12 har by default (00) och vi sätter den til(01)
//genom att sätta bit 24 till 1(se mer i word dokumentet).
#define LED_RED_MODE_BIT (1U<<28)
#define LED_GREEN_MODE_BIT (1U<<24)
#define LED_YELLOW_MODE_BIT (1U<<26)
#define LED_BLUE_MODE_BIT (1U<<30)

//Definierar de olika LED-färgerna som finns, dessa skickas int som argument till Led klassens metoder och man kan på sätt 
//välja vilken lampa man vill styra.
typedef enum {
  RED = 0,
  GREEN,
  YELLOW,
  BLUE
}LedColor_Type;

//Definierar de olika lägena led kan ha, ON eller OFF och andvänds för att skicka in som argument till Led klassens metoder 
typedef enum {
  OFF = 0,
  ON = 1
}LedState_Type;

//Definierar de attribut och metoder som LED består utav.
class Led{

  private:
      LedColor_Type color;//Definierar vilken färg LED har.
      LedState_Type state;//Definierar vilket läge (ON/OFF) LED befinner sig i. 

  public:

      Led(LedColor_Type _color,LedState_Type _state);//Definiera konstruktor för LED, för att skapa lamp objekt (Led led1(BLUE,ON)).
      void setState(LedState_Type _state);//Definiera metoden för att sätta LED till ett visst läge(ON/OFF)(man kan välja vald lampa ska vara på eller av).
      LedState_Type getState() const;//Definiera metoden för att hämta LED aktuella läge(för att vet om en specifk lampa är på eller av).

};

#endif//Avslutar ifndef-satsen.
