/* by created 2006
 by David A. Mellis
 modified 30 Aug 2011
 by Tom Igoe and Scott Fitzgerald
 Modified by Paula Teixeira - 03/01/14
for Physical Computing Lab 4
*/

#include <Servo.h> 
 
Servo myservo;
byte incomingByte;      // a variable to read incoming serial data into
int pos = 0;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  // see if there's incoming serial data:
  if (Serial.available()) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();

    if (incomingByte == 'R') {
       for(pos = 0; pos <= 180; pos += 1)  // goes from 0 degrees to 180 degrees 
        {                                  // in steps of 1 degree 
          myservo.write(pos);              // tell servo to go to position in variable 'pos' 
          delay(15);                       // waits 15ms for the servo to reach the position 
        } 
      } 

   
    if (incomingByte == 'L') {
       for(pos = 0; pos <= 180; pos += 1)  // goes from 0 degrees to 180 degrees 
        {                                  // in steps of 1 degree 
          myservo.write(pos);              // tell servo to go to position in variable 'pos' 
          delay(15);                       // waits 15ms for the servo to reach the position 
        } 
      } 
  }
}

