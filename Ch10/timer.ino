void setup() {
}

void loop() {
   //read microseconds 
   long utime = micros(); 
   Serial.println(utime);
   //read milliseconds 
   long mtime = millis(); 
   Serial.println(mtime);
}