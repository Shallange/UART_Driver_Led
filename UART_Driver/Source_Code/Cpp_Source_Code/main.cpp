#include "Led.h"

//Enum i led.h (åtkomst namn är LedState_Type och har "ON" eller "OFF").
LedState_Type led1_state;
LedState_Type led2_state;
LedState_Type led3_state;

//Instans av klassen led vid namn led1 skapas och argumenten "RED" och "ON" skickas in. den här är skapad utanför main och det funkar men de är värt att- 
//Notera att objekt skapade utanför main i c++ är globala och "lever" längre än de objekt som är skapade innan för "main", de förstörs efter att main är klar.
Led led1(RED,ON);

int main(void){ //Huvudfunktion konstruerar och hanterar LED-lamporna.
  USART2_Init();//Ropar på funktionen som initierar seriell kommunikation.

  //Instans av klassen led vid namn led2 skapas och argumenten "BLUE" och "ON" skickas in. skapar objekter direkt på stacken.
  Led led2(BLUE,ON);

  //Här skapar man en pointer vid namn "led3" av typen Led. Denna skapas på Heap istället. använder även keyword "new".
  Led *led3 = new Led(YELLOW,ON);

  //Led1 är satt till RÖD och kommer då att kolla färgen och sedan retunera statusen på lampan. i det här fallet är status ON.
  led1_state = led1.getState();

  //led1 är satt till RÖD(ibörjan av koden) och kommer att kolla färgen (i en switch) och sedan sätta status efter vad man skickat in som argument,
  //här skickar man att statusen ska vara OFF. 
  led1.setState(OFF);

  //Led lampan som vi använde pekare och "new" för att skapa och allokera dynamisk minne till, behöver man också frigöra och det gör vi med "delete" operatorn.
  delete led3;

  //Infinte loop för att programmet ska köras utan att stängas ner.
  while(1){}

}
