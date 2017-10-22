// Oberlin DC Motor Control Workshop 10/27/2017
// Steven Kemper, stevenTkemper@gmail.com
// Basic sketch for trying out the Adafruit DRV8871 Breakout
// taken from https://learn.adafruit.com/adafruit-drv8871-brushed-dc-motor-driver-breakout/usage

#define MOTOR_IN1 9 // Define pin 9 as "MOTOR_IN1"
#define MOTOR_IN2 10 // Define pin 10 as "MOTOR_IN2"

// In this code, MOTOR_IN2 controls "fowrward" rotation
// and MOTOR_IN1 controls "backward" rotation

void setup() {
  Serial.begin(9600); // Turn on serial communication
                      // (only used to print message below)
  Serial.println("DRV8871 test"); //Print message on startup
  
  pinMode(MOTOR_IN1, OUTPUT); // Set MOTOR_IN1 (pin 9) as output pin
  pinMode(MOTOR_IN2, OUTPUT); // Set MOTOR_IN2 (pin 10) as output pin
}

void loop() {

  // ramp up forward
  // speed up MOTOR_IN2 (pin 10) in "forward" direction
  digitalWrite(MOTOR_IN1, LOW); // Turn MOTOR_IN1 (pin 9) off
  for (int i=0; i<255; i++) {
    analogWrite(MOTOR_IN2, i); // Sets duty cycle of PWM output 
                               // for MOTOR_IN2 (pin 10)
                               // values between 0=0% (off), 255=100% (max on)
    delay(10); // pause for 10ms before repeating the loop
  }

  // forward full speed for one second
  delay(1000); // pause for 1000ms (1 sec) while MOTOR_IN2 (pin 10) is at max 
              // PWM value
  
  // ramp down forward
  // reverses the previous loop, slowing motor down
  for (int i=255; i>=0; i--) {
    analogWrite(MOTOR_IN2, i);
    delay(10);
  }

  // ramp up backward
  // reverses previous code
  digitalWrite(MOTOR_IN2, LOW);
  for (int i=0; i<255; i++) {
    analogWrite(MOTOR_IN1, i);
    delay(10);
  }

  // backward full speed for one second
  delay(1000);

  // ramp down backward
  for (int i=255; i>=0; i--) {
    analogWrite(MOTOR_IN1, i);
    delay(10);
  }
}
