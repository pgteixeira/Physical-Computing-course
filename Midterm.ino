// Reaction Game - Midterm Project
//by Paula Teixeira
//DIGF 2B03 Physical Computing 
//February 10th 2014
//Code of reference: 
//Arduino example "Button State Change Detection" (http://arduino.cc/en/Tutorial/Tone)
//"Play a Melody using the tone() function" (http://arduino.cc/en/Tutorial/ButtonStateChange)

#include "pitches.h" // Include of pitches for buzzer
const int buttonOrange = 2;  // Defining the pins for all the leds and button.
const int ledOne  = 13; 
const int ledTwo  = 12;
const int ledRed  = 11;
const int ledFour = 10;
const int ledFive = 9;
const int buzzer = 7;    
// Array of Pins
int ledPins[] =   // an array of variables refering pin numbers to which LEDs are attached
{   
  ledOne,
  ledTwo,
  ledRed,
  ledFour,
  ledFive
};   
         
int delayTime = 400;  // Defining an initial delay time
int clickCounter = 0; // Defining a Counter for the click event 
int buttonState = 0;  // Defining an initial button state
int ledState = 0;     // Defining an initial led state
int lastButtonState = 0;   // Defining a last button state
void setup()
{
  for (int currentPin = 0; currentPin < 5; currentPin++)   // A loop that creates a pinMode for each 
  {
    pinMode(ledPins[currentPin], OUTPUT);                  // led specified in the begginning.
  }
  pinMode(buzzer,OUTPUT);
  pinMode(buttonOrange, INPUT);   // Configured the button pin to behave as an input  
  Serial.begin(9600);   // Start the communication using serial
}
void loop()
{
  for(int i = 0; i <= 5; i++)   // Block of code that will make the led light in sequence
  { 
    
    buttonState = digitalRead(buttonOrange); // Reads the value from the buttonOrange pin
    ledState = digitalRead(ledRed);  // Reads the value from the ledRed pin
    
    int offLED = i - 1;  // OffLED is the led that should turn off, after the next one is ON
    
    if(i == 0) {    // If the first is ON, it will turn off the last one.       
      offLED = 5;        
    }     
    digitalWrite(ledPins[i], HIGH); // Make the led specified turn ON
    if (buttonState != lastButtonState) // Check if the button has been clicked
    {
      if(buttonState == HIGH && ledState == LOW) // Check if the button in ON but the led is OFF
      {
        Serial.println("Wrong!");
        clickCounter++;    // Add a value to the counter of button clicks at the wrong time
        tone(buzzer, NOTE_C4, 400);
        delay(400);
        noTone(buzzer);        
       
        if (clickCounter == 5)     // Check if the user has clicked 5 times to reset the game
        {
          for(int a = 0; a < 5; a++)   // Loop to turn ON all the leds
          {     
            digitalWrite(ledPins[a], HIGH);   // Turn ON all the leds in sequence
          }  
          delay(3000);                      // Make them stay ON for 3 seconds
          for(int b = 0; b < 5; b++)   // Loop to turn ON all the leds
          {     
            digitalWrite(ledPins[b], LOW);    // Turn them all OFF in sequence
          }  
          delayTime = 400; // Restore the default configuration for the delay
          clickCounter = 0; // Restore the default configuration of clicks
        }
      }
      else if (buttonState == HIGH && ledState == HIGH) // If both button and led are ON
      {   
        Serial.println("Right!");
        delayTime = delayTime - 25;                   // Reduce the time of the ledSequence
        clickCounter = 0;                             // Restore the default configuration of clicks
        
        for (int thisNote = 0; thisNote < 8; thisNote++)
        {
          tone(buzzer, NOTE_C5, 20);
          delay(20);
          noTone(buzzer);  
        }
      } 
    }
    lastButtonState = buttonState; //Transform the last state of the button into the actual state
    digitalWrite(ledPins[offLED], LOW); // Turn OFF the led
    delay(delayTime); // The interval between a led turning OFF and the next one turning ON
  }
}
