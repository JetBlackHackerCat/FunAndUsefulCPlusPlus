//This code output the amount of interruptions

// interrupt on PIN 2
#define PIN_INT 2 

// count of interruption amount 
volatile int count = 0;

void setup() { 
  // initialize the serial port for output 
  Serial.begin(9600); 
  //define interruption PIN as input 
  pinMode(PIN_INT, INPUT); 
  //insert an interruption 
  attachInterrupt(digitalPinToInterrupt(PIN_INT), eventHandler, RISING); 
} 

// handle interruption 
void eventHandler() { 
  count = count + 1; 
  Serial.println(count);
  // detach interruption when count reaches 10
  if (count >= 10) {
    detachInterrupt(digitalPinToInterrupt(PIN_INT));
  }
} 

void loop() {
  // empty
} 