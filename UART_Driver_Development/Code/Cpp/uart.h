#ifndef __UART_H
#define __UART_H

#include "stm32f4xx.h" //Hämtar källkoden och hänvisningar för arbete på STM-Hårdvara
#include <stdio.h> //Inkluderar standard I/O för C

void USART2_Init(void); // Kallar på och refererar till deklarationen av vår UART-funktion
void test_setup(void); //Kallar på och refererar till vår testfunktion ur UART.c
#endif //Förtydligar avslutningen av vår headerfil
