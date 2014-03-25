// By Paula Teixeira
// Physical Computing lab 5 - 03/24/14

 import processing.serial.*; 
  Serial port;
int ballX;
int ballY;
int radius;
int ballSpeed;

 
void setup()
{
  size(400, 600);
  
  smooth();
  frameRate(60);
   
  ballX = width/2;
  ballY = height/2;
  radius = 25;
  ballSpeed = 5;
  noStroke();
   
   println(Serial.list()); 
   port = new Serial(this, Serial.list()[5], 9600); 
}
 
void draw()
{ 
  background(255, 255, 255,150);  
  fill(255, 0, 0);
  ellipse(ballX, ballY, radius*2, radius*2);
}
 
  
void keyPressed() {
  if (key == CODED) {
    if (keyCode == LEFT) {
       ballX = ballX - ballSpeed;
       port.write('L');

    }
    
    if (keyCode == RIGHT) {
      ballX = ballX + ballSpeed;
      port.write('R');
    } 
  }
}

