#include "UART.h" //Hämtar vår samlingsfil för headers och funktioner

void USART2_Init(void) { //Definierar en funktion för att initiera USART-protkokollet och dess beståndsdelar i Main.cpp senare

// 1. Enablea klocktillgång för UART2
//0010 0000 0000 0000 0000(bit 17)
RCC->APB1ENR |= 0x20000; //Atkiverar UART2 genom att sätta bit 17 i APB1ENR till 1(i dokumentet kan man se att bit 17 i registret är USART2(rw)).
//man aktiverar klockan för att annars går det inte att skicka eller hämta data via UART 
//när clock är aktiverad först då kan man konfiguera parametrarna som till exempel baud rate och dataformat.

// 2. Enablea klocktillgång för portA
RCC->AHB1ENR |= 0x01; //Aktiverar GPIOA genom att sätta bit 0 i AHB1ENR till 1. samma här så behöver man aktivera clock för att kunna använda och styra i detta fall port GPIOA.

// 3. Enablea pins relaterade till vald port, för alternativ funktion(10)
GPIOA->MODER &= ~0x00F0; //Rensar bitarna 4-7 för att förbereda pins PA2(PORT-A pin2) och PA3(PORT-A pin 3)
  //& samt ~forcerar en invertering som leder till att bitarna som via hex betecknas med 1, i realvärde ersätts med 0

GPIOA->MODER |= 0x00A0; //Sätter bitarna 5 och 7 till 1 för att aktivera alternativ funktionalitet på pins PA2 och PA3(alternativ funktionsläge gör det mökligt för UART kommunikation via pin)

// 4. Välja typen av specifik alternativ funktion för pins PA2 och PA3(GPIO alterante function low register)
GPIOA->AFR[0] &= ~0xFF00; //Rensar bitarna 8-15 för att förbereda pins PA2(PORT-A pin2) och PA3(PORT-A pin 3)
GPIOA->AFR[0] |= 0x7700; //Sätter vi bitarna 8-11 samt 12-15 till formatet 0111(AF7).
//Sätter PA2 till USART2_tx och PA3 till USART2_rx.

/* Konstruktion av enhetens kommunikation avslutas */

// Konfiguration utav UART
USART2->BRR = 0x0683; //Sätter vi standard baud-rate med hjälp av hexadecimalen 0x0683 (9600bps) eftrsom vi inte beöver högre baudrate med tanke på att vi skickar endast 8 bitar i taget
USART2->CR1 = 0x000C; //Sätter vi tx och rx till att arbeta i 8 bitars data. (8 bitars data, 1 stop bit, ingen paritet)-
//Bit 12(M) är oförändad och satt till 0 för 8 bitars läge, 0x000C sätter bit 2(RE) och bit 3(TE) till 1.
USART2->CR2 = 0x000; //Nollställer CR2, Detta är gjort för att säkerthetsälla att inget i CR2 är akiverat sedan tidigare som kan störa eller skapa konflikter.
USART2->CR3 = 0x000; //Nollställer CR3, Detta är gjort för att säkerthetsälla att inget i CR3 är akiverat sedan tidigare som kan störa eller skapa konflikter.
USART2->CR1 |= 0x2000; //Omställer bit 13 (UART-Aktiveringen) till 1, bit 13 är UE som står för UART ENABLE.
}
// UART Write
int USART2_write(int ch){ //Definierar skrivfunktionen (Överföringen av data till terminalen med UART)

  while(!(USART2->SR & 0x0080)){} //Så länge bit 7 inte är "1" i SR-registret så finns det kvar data som ska skickas
  USART2->DR = (ch & 0xFF); //Skriver least signifikant bits av värdet(ch) till dataregistret(DR). Detta gör så att endast 8bitar överförs och resten ignoreras, men med tanke på att
  //Vi har ställt in så att vi jobbar med 8 bitars data så kommer hela byten skickas till DR
  return ch; // Returnerar värdet (ch) som har skickats
}
// UART Read
int USART2_read(void){ //Definierar läsfunktionen (mottagning av information)
  while(!(USART2->SR & 0x0020)){}//Så länge bit 5(RXNE, Reciever not empty) inte är 0 så finns det mer data att läsa in.
  return USART2->DR; //Retunrerar hel byte(8 bitar) och på så sätt tömmer DR(vilket är värt att notera).
}
