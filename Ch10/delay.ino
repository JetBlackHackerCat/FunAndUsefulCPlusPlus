void setup() {
}

void loop() { 
   // wait 100 microseconds 
   long start = micros(); 
   delayMicroseconds(100); 
   // elapsed about 100 microseconds
   Serial.println(micros() - start); 

   // wait 10 milliseconds 
   start = micros(); 
   delay(10); 
   // elapsed about 10,000 microseconds
   Serial.println(micros() - start); 

} 