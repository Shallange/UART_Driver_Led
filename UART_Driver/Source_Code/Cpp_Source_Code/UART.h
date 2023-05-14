#ifndef __UART_H// Om __UART_H inte är definerad( inte inkluderad i koden tidigare).
#define __UART_H // Definera __UART_H.

#include "stm32f4xx.h" //Hämtar källkoden och hänvisningar för arbete på STM-Hårdvara.
#include <stdio.h> //Inkluderar standard I/O för C.

void USART2_Init(void); // Kallar på och refererar till deklarationen av vår UART-funktion(defineras i uart.cpp).

//void test_setup(void); //Denna function kallar på och refererar till vår testfunktion i UART.Cpp(är inaktiv då detta är bara för test ). 

#endif //Förtydligar avslutningen av vår headerfil.
