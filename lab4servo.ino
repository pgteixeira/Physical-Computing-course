// by BARRAGAN <http://barraganstudio.com> 
// Modified by Paula Teixeira - 03/01/14
// for Physical Computing Lab 4


#include <Servo.h> 
 
Servo helloservo;  
               
int pos = 0;    
 
void setup() 
{ 
  helloservo.attach(8);  
} 
 
 
void loop() 
{ 
  for(pos = 0; pos < 180; pos += 1)  
  {                                  
    helloservo.write(pos);            
    delay(30);                       
  } 
  for(pos = 180; pos>=1; pos-=1)    
  {                                
    helloservo.write(pos);           
    delay(30);                       
  } 
} 
