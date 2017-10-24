// Oberlin DC Motor Control Workshop 10/27/2017
// Steven Kemper, stevenTkemper@gmail.com
// Control the Adafruit DRV8871 Breakout via Max MSP
// Adapted from Arduino Serial Call/Response example code

#define MOTOR_IN1 9 // Define pin 9 as "MOTOR_IN1"
#define MOTOR_IN2 10 // Define pin 10 as "MOTOR_IN2"
//
// In this code, MOTOR_IN2 controls "fowrward" rotation
// and MOTOR_IN1 controls "backward" rotation (DC mode)
// MOTOR_IN1 controls solenoid (solenoid mode)

String inData; // variable to store incoming serial data
int motor1Val = 0; //initalize value for global variable motor1Val
int motor2Val = 0;//initalize value for global variable motor2Val
int solenoidVal = 0;//initalize value for global variable solenoidVal

void setup() {
  Serial.begin(19200); //Set serial communication speed

  Serial.println("Serial Motor Control");
  
  pinMode(MOTOR_IN1, OUTPUT); // Set MOTOR_IN1 (pin 9) as output pin
  pinMode(MOTOR_IN2, OUTPUT); // Set MOTOR_IN2 (pin 10) as output pin

} 


void loop() {

if (Serial.available() > 0) { //If there is serial data
    char recieved = Serial.read(); //read data from serial port
    inData += recieved; //Build a string from the incoming serial data
        // Process message when new line character is recieved
     if (recieved == '\n') //If we get a newline char ASCII-10--parse data when we get "\n"
     {
//            Serial.print("Arduino Received: ");
//            Serial.println(inData);

            // You can put some if and else here to process the message just like that:

         
          // f for DC motor forward
           if(inData.charAt(0) == 'f') { //If the incoming message begins with an "f"
               // Serial.println("we got a f");
                if (inData.length() > 1) {
                  String mySubstring;
                  mySubstring = inData.substring(1); //read the next byte of data
                  motor1Val = mySubstring.toInt(); //store that data as an integer
                  analogWrite(MOTOR_IN1, motor1Val); //write PWM output to pin 9
                }
             }  
             // r for DC motor reverse
           if(inData.charAt(0) == 'r') { //If the incoming message begins with an "r"
               // Serial.println("we got a r");
                if (inData.length() > 1) {
                  String mySubstring;
                  mySubstring = inData.substring(1);
                  motor2Val = mySubstring.toInt();
                  analogWrite(MOTOR_IN2, motor2Val); //write PWM output to pin 10

                }
             }  
             // s for solenoid
           if(inData.charAt(0) == 's') { //If the incoming message begins with an "s"
               // Serial.println("we got a s");
                if (inData.length() > 1) {
                  String mySubstring;
                  mySubstring = inData.substring(1);
                  solenoidVal = mySubstring.toInt();
                  analogWrite(MOTOR_IN1, solenoidVal); //write PWM output to pin 9
                    //Note, the solenoid control code is exactly the same as motor1Val code above
                    //but allows separate controls from Max that are geared towards Solenoid control

                }
             }  
           
         
            inData = ""; // Clear recieved buffer
        
  }  
}

   
    

}


