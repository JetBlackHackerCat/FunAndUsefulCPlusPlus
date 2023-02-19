//This code controls the LED depends on the input at pin 1  
void setup() {
  pinMode(1, INPUT);   //set pin 1 as input
  pinMode(13, OUTPUT); //set pin 13 (LED) as output
}

void loop() {
  boolean sig = digitalRead(1); //read input from pin 1
  digitalWrite(13, sig);  //assign LED with value of pin 1
}