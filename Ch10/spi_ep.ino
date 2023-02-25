
#include <SPI.h> 
#define CS 10 
volatile byte request = 0; 
void setup() {
  pinMode(CS, INPUT);
  // enable SPI peripheral mode with interruption
  SPCR |= _BV(SPE);
  SPCR |= _BV(SPIE);
}

ISR(SPI_STC_vect) {
  byte signal = SPDR;
  switch (request) {
    case 0:
      request = signal;
      SPDR = 0;
      break;
    case 0x42:
      SPDR = 0x69;
      break;
    case 0x69:
      SPDR = 0x42;
      break;
  }
}

void loop() {
  // reset request
  if (digitalRead (CS) == HIGH) {
    request = 0;
  }
}