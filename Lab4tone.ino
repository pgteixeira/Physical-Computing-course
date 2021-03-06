
 
 //created 21 Jan 2010
// modified 30 Aug 2011
// by Tom Igoe 
// modified by Paula Teixeira for the Physical Computing course


 #include "pitches.h"
 
 int sensorValue = 0;

int inputPin = A0;

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4,4,4,4,4 };

void setup() {
  
   Serial.begin(9600);
     pinMode(inputPin, INPUT); 
     // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(8, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
  }
}
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability



 if(sensorValue<20){

  // iterate over the notes of the melody:
  tone(8, 440, 200);
  delay(200);

 }

 else{

    noTone(8); 


 }
}
