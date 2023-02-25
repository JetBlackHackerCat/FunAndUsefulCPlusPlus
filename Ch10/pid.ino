// This code is a PID control system for DC motor
#define MOTOR_SPEED_INPUT A0 
#define MOTOR_ENCODER A1 
#define MOTOR_CONTROL 3 

// A sampling period of 2 milliseconds
#define CONTORL_PERIOD_MICROS 2048

#define MAX_ERROR 1000000000


void setup() {
  pinMode(MOTOR_SPEED_INPUT, INPUT); 
  pinMode(MOTOR_ENCODER, INPUT); 
  pinMode(MOTOR_CONTROL, OUTPUT); 
} 

long output = 0;
long previous_error = 0;
long cumulative_error = 0;

// PID control settings (to be scale down by 1024x)
long contorl_p = 256, contorl_i = 128, contorl_d = 64;

void loop() { 
    long start = micros();

    // error measures the difference between the actual speed and the desired speed
    long error = analogRead(MOTOR_ENCODER) - analogRead(MOTOR_SPEED_INPUT); 
    // calcuate the change of error
    long diff_error = error - previous_error;
    // accumulate the error
    cumulative_error += error;
    // limit the range of the cumulative error to prevent overflow
    if (cumulative_error > MAX_ERROR) {
      cumulative_error = MAX_ERROR;
    } else if (cumulative_error < -MAX_ERROR) {
      cumulative_error = -MAX_ERROR;
    }
    // record error for next iteration
    previous_error = error;

    // correction = [P, I, D] * [error, cumulative_error * dt, diff_error / dt]
    // assume base time unit is also 2 milliseconds, thus dt = 1 
    long correction = contorl_p * error + contorl_i * cumulative_error + contorl_d * diff_error;

    // adjust output with correction (scale down control by 1024x)
    output -= correction >> 10;

    // limit output within its valid range (PWM)
    if (output > 4095) {
      output = 4095;
    } else if(output < 0) {
      output = 0;
    } 
    analogWrite(MOTOR_CONTROL, output); 

    long elapsed = micros() - start;
    delayMicroseconds(CONTORL_PERIOD_MICROS - elapsed);
} 
