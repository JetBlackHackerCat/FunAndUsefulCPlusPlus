// This is an i2c endpoint responses data
#include <Wire.h>
#define EP 0x17
void setup() {
  // initialize an i2c as given address
  Wire.begin(EP);
  // define handler
  Wire.onReceive(requestHandler);
}
void requestHandler(int amount) {
  byte request = 0;
  // capture request
  while (Wire.available())
  {
    request = Wire.read();
  }
  // response accordingly
  switch (request) {
  case 0x42:
    Wire.write(0x69);
    break;
  case 0x69:
    Wire.write(0x42);
    break;
  default:
    Wire.write(0);
    break;
  }
}
void loop() {
  // empty
}