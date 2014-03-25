import processing.serial.*;

// By Paula Teixeira
// Physical Computing lab 5 - 03/24/14

Serial myPort; 
int val;      

float r = random(255);
float r2 = random(255);
float g = random(255);
float g2 = random(255);
float b = random(255);
float b2 = random(255);

void setup() 
{
  size(800, 600);
  smooth();
  noStroke();
  ellipseMode(CENTER);
  background(r,g,b);
  String portName = Serial.list()[5];
  myPort = new Serial(this, portName, 9600);
}

void draw()
{
  if ( myPort.available() > 0) {
    val = myPort.read();         
  }
  if (val == 0) {  
    fill(random(255),random(255),random(255));
  } 
  else {
    fill(r2,g2,b2);
  }
  ellipse(width/2,height/2,200,200);
}
