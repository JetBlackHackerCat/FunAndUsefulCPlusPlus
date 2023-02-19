//This code controls the LED depends on the input at pin 1  
#define PIN_LED 13 
#define PIN_IN 1 
void setup() {
  pinMode(PIN_IN, INPUT);   //set input
  pinMode(PIN_LED, OUTPUT); //set output
}

void loop() {
  boolean sig = digitalRead(PIN_IN); //read input
  digitalWrite(PIN_LED, sig);  //assign LED
}