#include <TFT.h> // Hardware-specific library
#include <SPI.h>

#include <OneWire.h>
#include <DallasTemperature.h>


#define ONE_WIRE_BUS 2

#define CS   10
#define DC   9
#define RESET  8  

#define RELAY1 6
#define RELAY2 7





TFT myScreen = TFT(CS, DC, RESET);

// variable to keep track of the elapsed time
int counter = 0;

double temp;
String tempString;

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Создаем объект DallasTemperature для работы с сенсорами, передавая ему ссылку на объект для работы с 1-Wire.
DallasTemperature sensors(&oneWire);

void clearScreen(){
  myScreen.setTextSize(1);
  myScreen.background(0,0,0);  // clear the screen with black  
  myScreen.stroke(255,255,255);
}

void drawLeftTank(){
  
 //  Drawing Left Tank
  
  myScreen.line(1, 15, 1, 80);
  myScreen.line(1, 80, 10, 115);
  myScreen.line(10, 115, 66, 115);
  myScreen.line(66, 115, 76, 80);
  myScreen.line(76, 80, 76, 15);
  myScreen.line(76, 15, 70, 3);
  myScreen.line(70, 3, 8, 3);
  myScreen.line(8, 3, 1, 15);

  myScreen.setTextSize(1);
  myScreen.text("o",25,60);
  myScreen.setTextSize(3);
  myScreen.text("C",35,60);
}

void drawRightTank(){
  // Dreawing Right Tank
  myScreen.line(83, 15, 83, 80);
  myScreen.line(83, 80, 93, 115);
  myScreen.line(93, 115, 149, 115);
  myScreen.line(149, 115, 158, 80);
  myScreen.line(158, 80, 158, 15);
  myScreen.line(158, 15, 150, 3);
  myScreen.line(150, 3, 90, 3);
  myScreen.line(90, 3, 83, 15);

  myScreen.setTextSize(1);
  myScreen.text("o",105,60);
  myScreen.setTextSize(3);
  myScreen.text("C",115,60);
}


void SetTemperatureL(String text){

  char printout[4];

  text.toCharArray(printout,5);
  
  myScreen.setTextSize(2);

  text.toCharArray(printout,5);
  myScreen.stroke(0,0,0);
  myScreen.fill(0,0,0);
  myScreen.rect(20,30,50,20);
  myScreen.stroke(0,191,255);
  myScreen.text(printout,20,30);
  

}

void SetTemperatureR(String text){

  char printout[4];

  text.toCharArray(printout,5);
  
  myScreen.setTextSize(2);
 
  myScreen.stroke(0,0,0);
  myScreen.fill(0,0,0);
  myScreen.rect(100,30,50,20);
  myScreen.stroke(0,191,255);
  myScreen.text(printout,100,30);

}

void setRellayL(boolean pos){
  if (pos){
    myScreen.stroke(0,128,0);
    myScreen.fill(0,128,0);
    digitalWrite(RELAY1, 1);
  }
  else{
    myScreen.stroke(255,0,0);
    myScreen.fill(255,0,0);
    digitalWrite(RELAY1, 0);
  }
  myScreen.circle(40, 100, 5);
}

void setRellayR(boolean pos){
    if (pos){
    myScreen.stroke(0,128,0);
    myScreen.fill(0,128,0);
  }
  else{
    myScreen.stroke(255,0,0);
    myScreen.fill(255,0,0);
  }
  myScreen.circle(122, 100, 5);
}


double getTemperature(){
  sensors.requestTemperatures(); // Send the command to get temperatures
  double out = sensors.getTempCByIndex(0);
  return out;
}

void setup() {

pinMode(RELAY1, OUTPUT);
pinMode(RELAY2, OUTPUT);

sensors.begin();
temp = -99;

  // put your setup code here, to run once:
myScreen.begin();  

clearScreen();

drawLeftTank();
//
drawRightTank();
 
// Predefined text

  
//  myScreen.stroke(0,191,255);
//  myScreen.text("DS18b20 : ",10,120);


//  delay(1000);  // pause for dramatic effect
  // start serial port
 
  Serial.begin(9600);
}

void loop() { 
  double temp = getTemperature();
  
  if (temp > 20)
    setRellayL(true);

  if (temp > 20)
    setRellayR(false); 
  
  if (!tempString.equals(String(temp,5))){
      tempString = String(temp,5);
      SetTemperatureL(tempString);
      SetTemperatureR(tempString);
    }
  
//  SetTemperature("right", "test");
  delay(1000);  // pause 
  
}
