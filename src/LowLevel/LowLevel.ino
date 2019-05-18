#include <TFT.h> // Hardware-specific library
#include <SPI.h>

#define CS   10
#define DC   9
#define RESET  8  

// pin definition for the Leonardo
// #define CS   7
// #define DC   0
// #define RESET  1 

TFT myScreen = TFT(CS, DC, RESET);

// variable to keep track of the elapsed time
int counter = 0;
// char array to print time
char printout[4];

double temp;

void setup() {
  // put your setup code here, to run once:
 myScreen.begin();  
  myScreen.setTextSize(1);
  myScreen.background(0,0,0);  // clear the screen with black
  myScreen.stroke(255,255,255);

 //  Drawing Left Tank
  
  myScreen.line(1, 15, 1, 80);
  myScreen.line(1, 80, 10, 115);
  myScreen.line(10, 115, 66, 115);
  myScreen.line(66, 115, 76, 80);
  myScreen.line(76, 80, 76, 15);
  myScreen.line(76, 15, 70, 3);
  myScreen.line(70, 3, 8, 3);
  myScreen.line(8, 3, 1, 15);

// Dreawing Right Tank

  myScreen.line(83, 15, 83, 80);
  myScreen.line(83, 80, 93, 115);
  myScreen.line(93, 115, 149, 115);
  myScreen.line(149, 115, 158, 80);
  myScreen.line(158, 80, 158, 15);
  myScreen.line(158, 15, 150, 3);
  myScreen.line(150, 3, 90, 3);
  myScreen.line(90, 3, 83, 15);

// Predefined text

  
  myScreen.stroke(0,191,255);
  myScreen.text("DS18b20 : ",10,120);


myScreen.text("o",20,60);
myScreen.setTextSize(3);
myScreen.text("C",30,60);

  delay(1000);  // pause for dramatic effect
}

void loop() {
  
  myScreen.setTextSize(2);
  temp = 20.4;
  myScreen.text("20,4",20,30);
  
  
  delay(1000);  // pause for dramatic effect
  
  // put your main code here, to run repeatedly:

}
