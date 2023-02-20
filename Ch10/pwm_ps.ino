// This code generate PWM on pin 3, 5 and 9
// as well as changing their pre-scalers.
void setup() {
  // set pin 3 as output
  pinMode(3, OUTPUT);
  // B010 equals 3 in decimal which maps to 32x
  // set frequency of pin 3 to 490Hz * 64 / 32 = 980Hz
  TCCR2B = TCCR2B & B11111000 | B011; 

  // set pin 9 as output
  pinMode(9, OUTPUT);
  // B010 equals 2 in decimal which maps to 8x
  // set frequency of pin 3 to 490Hz * 64 / 8 = 3920Hz
  TCCR1B = TCCR1B & B11111000 | B010; 

  // set pin 5 as output
  pinMode(5, OUTPUT);
  // B101 equals 5 in decimal which maps to 1024x
  // set frequency of pin 3 to 980Hz * 64 / 1024 = 61Hz
  TCCR0B = TCCR0B & B11111000 | B101;
}

void loop() {
  // set pin 3 to a 50% duty cycle
  analogWrite(3, 127);
  // set pin 9 to a 50% duty cycle
  analogWrite(9, 127);
  // set pin 5 to a 25% duty cycle
  analogWrite(5, 64);
}