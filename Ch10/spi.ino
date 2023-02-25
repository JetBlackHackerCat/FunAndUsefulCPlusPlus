#include <SPI.h>

#define CS 6
 
SPISettings settings(2000000, MSBFIRST, SPI_MODE0); 

void setup() {
  // initialize SPI
  SPI.begin();
  // set Chip Select as output
  pinMode(CS, OUTPUT); 
  // default Chip Select to high 
  digitalWrite(CS, HIGH); 
}

void loop() { 
  // send and receive data over SPI 
  SPI.beginTransaction(settings); 
  digitalWrite(CS, LOW);
  byte data = SPI.transfer(0x42);
  digitalWrite(CS, HIGH); 
  SPI.endTransaction(); 
  // display data 
  Serial.print("Received: ");
  Serial.println(data);
}