// Oberlin DC Motor Control Workshop 10/27/2017
// Steven Kemper, stevenTkemper@gmail.com
// Basic sketch for trying out the Adafruit DRV8871 Breakout
// taken from https://learn.adafruit.com/adafruit-drv8871-brushed-dc-motor-driver-breakout/usage

#define SOLENOID_IN1 9 // Define pin 9 as "SOLENOID_IN1"

void setup() {
  Serial.begin(9600); // Turn on serial communication
                      // (only used to print message below)
  Serial.println("DRV8871 solenoid test"); //Print message on startup

  pinMode(SOLENOID_IN1, OUTPUT); //Set SOLENOID_IN1 (pin 9) as output pin
}

void loop() {

  digitalWrite(SOLENOID_IN1, HIGH); // Turn on solenoid

  delay(1000); // wait for 1000ms (1 sec)
  
  digitalWrite(SOLENOID_IN1, LOW); // Turn off solenoid

  delay(1000); // wait for 1000ms (1 sec)
  
 
}
