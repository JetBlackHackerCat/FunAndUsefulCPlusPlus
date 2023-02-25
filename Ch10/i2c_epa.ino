// This is an i2c endpoint returns data
#include <Wire.h>
#define EP 0x0c
void setup() {
  // initialize an i2c as given address
  Wire.begin(EP);
  // define handler
  Wire.onRequest(requestHandler);
}
void requestHandler() {
  // send a byte of data
  Wire.send(0x42);
}
void loop() {
  // empty
}