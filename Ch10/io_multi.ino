// This code output alternate Port D between 01010101 and 10101010 and read input from PORTB
void setup() {
  // set all pin on port D as output
  DDRD = B11111111;
  // set all pin on port C as input
  DDRB = B00000000;
  // set every other pin on port D to high
  PORTD = B01010101;
}

void loop() {
  // output the invert the signal
  PORTD = PORTD ^ B11111111;
  // read value from port B
  int portB = PINB;
}