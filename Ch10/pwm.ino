// This code generate PWM on pin 3
void setup() {
  // set pin 3 as output
  pinMode(3, OUTPUT);
}
void loop() {
  // set pin 3 to a 50% duty cycle
  analogWrite(3, 127);
}