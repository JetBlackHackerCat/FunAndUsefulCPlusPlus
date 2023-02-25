// This is an i2c master that forwards data
#include <Wire.h>
// endpoint addresses
#define EP_A 0x0c
#define EP_B 0x17

void setup() {
  // initialize an i2c
  Wire.begin();
}

void loop() {
  byte data = 0;
  // request data from A
  Wire.requestFrom(EP_A, 1);
  // wait for data
  while (Wire.available()) {
    data = Wire.read();
  }
  // send data to B
  Wire.beginTransmission(EP_B);
  Wire.write(data);
  Wire.endTransmission();
  // wait for response from B
  while (Wire.available()) { 
    data = Wire.read(); 
    Serial.println(data); 
  } 
  // wait for 1 seconds
  delay(1000);
}