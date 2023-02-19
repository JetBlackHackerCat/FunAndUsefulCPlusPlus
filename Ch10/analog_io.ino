// This code reads voltage from pin A0.
void setup() {
  // set A0 as input
  pinMode(A0, INPUT);
}
void loop() {
  // read from pin A0
  int value = analogRead(A0);
  // display value
  Serial.print("A0 = " + value);
  Serial.println(value);
}