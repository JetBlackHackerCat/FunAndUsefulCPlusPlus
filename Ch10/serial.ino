// This code echos the serial input 
void setup() {
  // initialize Serial port at 9600 bits per second 
  Serial.begin(9600);
}

void loop()  {
  Serial.println("Hello World, please tell me anything:");
  // wait for input
  while ( Serial.available() == 0 ) {}
  String message = Serial.readString();
  message.trim();
  Serial.print("Echo: ");
  Serial.println(message);
} 