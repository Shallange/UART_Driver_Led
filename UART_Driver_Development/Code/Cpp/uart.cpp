#include "UART.h" //Hämtar vår samlingsfil för headers och funktioner

void USART2_Init(void) { //Deklarerar en funktion för att initiera USART-protkokollet och dess beståndsdelar

// 1. Enablea klocktillgång för uart2

RCC->APB1ENR |= 0x20000; //Atkiverar UART2 genom att sätta bit 17 i APB1ENR till 1.

// 2. Enablea klocktillgång för portA

RCC->AHB1ENR |= 0x01; //Atkiverar GPIOA genom att sätta bit 0 i AHB1ENR till 1.

// 3. Enablea pins relaterade till vald port, för alternativ funktion
GPIOA->MODER &= ~0x00F0; //Rensar bitarna 4-7 för att förbereda pins PA2 och PA3
  //& samt ~forcerar en invertering som leder till att bitarna som via hex betecknas med 1, i realvärde ersätts med 0

GPIOA->MODER |= 0x00A0; //Sätter bitarna 5 och 7 till 1 för att aktivera alternativ funktionalitet på pins PA2 och PA3

// 4. Välja typen av alternativ funktion för de valde pinsen
GPIOA->AFR[0] &= ~0xFF00; //Rensar bitarna 8-15 för att förbereda pins PA2 och PA3
GPIOA->AFR[0] |= 0x7700; //Sätter vi bitarna 8-11 samt 12-15 till formatet 0111

/* Konstruktion av enhetens kommunikation avslutas */

// Konfiguration utav UART

USART2->BRR = 0x0683; //Sätter vi standard baud-rate med hjälp av hexadecimalen 0x0683 (9600bps)
USART2->CR1 = 0x000C; //Sätter vi tx och rx till att arbeta i 8 bitars data. (8 bitars data, 1 stop bit, ingen paritet)
USART2->CR2 = 0x000; //Nollställer CR2
USART2->CR3 = 0x000; //Nollställer CR3
USART2->CR1 |= 0x2000; //Omställer bit 13 (UART-Aktiveringen) till 1

}
// UART Write
int USART2_write(int ch){ //Deklarerar skrivfunktionen (Överföringen av data till terminalen)

  while(!(USART2->SR & 0x0080)){} //Sätter vi ett krav som kontrollerar att statusen på överföringen är tom och kan ta emot nästa karaktär (byte)
  USART2->DR = (ch & 0xFF); //Sätter överföringen av byten till dataregistret

  return ch;

}
// UART Read
int USART2_read(void){ //Deklarerar läsfunktionen (mottagning av information)

  while(!(USART2->SR & 0x0020)){} //Sätter vi ett krav som kontrollerar om det finns mer data att hämta
  return USART2->DR; //Läser ut datan
}
