// Basic sketch for trying out the Adafruit DRV8871 Breakout

#define MOTOR_IN1 9
#define MOTOR_IN2 10

String inData;
int motor1Val = 0;
int motor2Val = 0;
int solenoidVal = 0;

void setup() {
  Serial.begin(19200);

  Serial.println("Serial Motor Control");
  
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);

} 


  

void loop() {

if (Serial.available() > 0) {
    char recieved = Serial.read(); 
    //delay(3); //give time for serial to read data (necessary for Xbees)
    inData += recieved; //Build a string from the incoming serial data
        // Process message when new line character is recieved
     if (recieved == '\n') //If we get a newline char ASCII-10
     {
//            Serial.print("Arduino Received: ");
//            Serial.println(inData);

            // You can put some if and else here to process the message juste like that:

//            if(inData == "+++\n"){ // DON'T forget to add "\n" at the end of the string.
//              Serial.println("OK. Press h for help.");
//            }
//            
         //Ignore the 'C's being sent from Max to trigger Serial.available
         if (inData.charAt(0) == 'C') { 
                 inData = inData.substring(1);
//                 Serial.print("New inData without C: ");
//                 Serial.println(inData);
         }
         
          // f for DC motor forward
           if(inData.charAt(0) == 'f') {
               // Serial.println("we got a f");
                if (inData.length() > 1) {
                  String mySubstring;
                  mySubstring = inData.substring(1);
                  motor1Val = mySubstring.toInt();
                  analogWrite(MOTOR_IN1, motor1Val);
//                  if(motor1Val >255)
//                  motor1Val = 255;
//                  if(motor1Val <0)
//                  motor1Val = 0;

                }
             }  
             // r for DC motor reverse
           if(inData.charAt(0) == 'r') {
               // Serial.println("we got a r");
                if (inData.length() > 1) {
                  String mySubstring;
                  mySubstring = inData.substring(1);
                  motor2Val = mySubstring.toInt();
                  analogWrite(MOTOR_IN2, motor2Val);
//                  if(motor1Val >255)
//                  motor1Val = 255;
//                  if(motor1Val <0)
//                  motor1Val = 0;

                }
             }  
             // s for solenoid
           if(inData.charAt(0) == 's') {
               // Serial.println("we got a s");
                if (inData.length() > 1) {
                  String mySubstring;
                  mySubstring = inData.substring(1);
                  solenoidVal = mySubstring.toInt();
                  analogWrite(MOTOR_IN1, solenoidVal);

                }
             }  
           
         
            inData = ""; // Clear recieved buffer
        
  }  
}

   
    

}


