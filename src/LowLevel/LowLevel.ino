#include <TFT.h> // Hardware-specific library
#include <SPI.h>
#include <Adafruit_MAX31865.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Use software SPI: CS, DI, DO, CLK
Adafruit_MAX31865 max = Adafruit_MAX31865(A0, A1, A2, A3 );

// The value of the Rref resistor. Use 430.0 for PT100 and 4300.0 for PT1000
#define RREF      430.0
// The 'nominal' 0-degrees-C resistance of the sensor
// 100.0 for PT100, 1000.0 for PT1000
#define RNOMINAL  100.0


#define ONE_WIRE_BUS 2

#define CS   10
#define DC   9
#define RESET  8  

#define RELAY1 6
#define RELAY2 7


double tankLRelayTemp = 99.0;

double tankRRelayTemp = 99.0;


TFT myScreen = TFT(CS, DC, RESET);

// variable to keep track of the elapsed time
int counter = 0;

double tempL;
float tempR;

String tempStringL;
String tempStringR;

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
  myScreen.circle(20, 100, 5);
}

void setRellayR(boolean pos){
    if (pos){
    myScreen.stroke(0,128,0);
    myScreen.fill(0,128,0);
    digitalWrite(RELAY2, 1);
  }
  else{
    myScreen.stroke(255,0,0);
    myScreen.fill(255,0,0);
    digitalWrite(RELAY2, 0);
  }
  myScreen.circle(100, 100, 5);

 

  
}

void updtaeRelayTempL(){
  char RrelayTempPrintout[5];
  String(tankLRelayTemp,5).toCharArray(RrelayTempPrintout,5);
  myScreen.stroke(0,0,0);
  myScreen.fill(0,0,0);
  myScreen.setTextSize(1);
  myScreen.rect(30,98,30,10);
  myScreen.stroke(0,191,255);
  myScreen.text(RrelayTempPrintout,30,98);
}

void updtaeRelayTempR(){
  char RrelayTempPrintout[5];
  String(tankRRelayTemp,5).toCharArray(RrelayTempPrintout,5);
  myScreen.stroke(0,0,0);
  myScreen.fill(0,0,0);
  myScreen.setTextSize(1);
  myScreen.rect(110,98,30,10);
  myScreen.stroke(0,191,255);
  myScreen.text(RrelayTempPrintout,110,98);
}




double getTemperature(){
  sensors.requestTemperatures(); // Send the command to get temperatures
  double out = sensors.getTempCByIndex(0);
  return out;
}

float getVoltage(uint8_t pin){
  int times = 10;
  double sumpoints = 0;
  for (int i =0; i<times; i++){
    sumpoints+=analogRead(pin);
    delay(10);
  }
  int v_points = sumpoints/times; 
  float voltage =  (v_points * 5);

voltage = voltage/1023;
  return voltage;
}


float getResistance2(float vout, float r, float vcc){
  int Vin=5;        // напряжение на выводе 5V arduino
float Vout=0;     // напряжение на выводе A0 arduino
float R1=109.2;    // значение известного сопротивления
float R2=0;       // значение неизвестного сопротивления

int a2d_data=0;    
float buffer=0;            

a2d_data=analogRead(A1);
if(a2d_data)
{
  buffer=a2d_data*Vin;
  Vout=(buffer)/1024.0;
  buffer=Vout/(Vin-Vout); 
  R2=R1*buffer;
}
return R2;
}

float getResistance(float vout, float r, float vcc){
  float Rx = r*vcc;
//  Serial.print("Rx");
//  Serial.print(Rx);

  Rx = Rx/vout;

  Rx = Rx - r;
  
  return Rx;
}

float getTermoT(float R_zero, float r_term){
float up = 0;
float down = 0;
float temp = -273.0;
//  double alfa = 3.9083 * pow(10,  -3);
  float alfa = 3.9083 * pow(10,  -3);
  float beta= -5.7750 * pow(10, -7);
//   double beta=  * pow(10, -7);
    
  up = (-R_zero * alfa) + sqrt(pow(R_zero, 2)* pow(alfa, 2) - 4* R_zero * beta * (R_zero - r_term));
//  up = (-R_zero * alfa) + sqrt(pow(R_zero, 2)* pow(alfa, 2) - 4* R_zero * beta * (R_zero - r_term));
  down = 2 * R_zero * beta;
  
  temp = up/down;
  
//  temp = -100 * a + sqrt(pow (100, 2) * pow(a, 2) - 4*100*b*(100 - r)) / 2 * 100 * b;
  return temp;
  
}

float getTemperatureResistance(){
  {
float voltage = getVoltage(A2);
//double voltage2 = getVoltage(A5);
//Serial.print("VoltageA5 ");
//Serial.println(voltage);
float resistance = getResistance2(voltage, 109.2, 5);
//Serial.println(resistance);
//resistance = resistance-1.69;

//resistance = getResistance2();

return getTermoT(100, resistance);
}
}


void getRelayTemp(){
  String data = Serial.readString();
  if ((data != "") && (data[0] == 'R'))
    if (data[1] = '+'){
      char arr[] = {data[2],data[3],data[4],data[5]};
//      Serial.println(arr);
      String temp(arr);
      if (temp.toDouble() != tankRRelayTemp){
        tankRRelayTemp = temp.toDouble();
        updtaeRelayTempR();
      }
//      Serial.println(tankRRelayTemp);
    
    }

   if ((data != "") && (data[0] == 'L'))
    if (data[1] = '+'){
      char arr[] = {data[2],data[3],data[4],data[5]};
//      Serial.println(arr);
      String temp(arr);
      if (temp.toDouble() != tankLRelayTemp){
        tankLRelayTemp = temp.toDouble();
        updtaeRelayTempL();
      }
//      Serial.println(tankLRelayTemp);
    
    }
      
//      tankRRelayTemp = double(data[2]+data[3]+data[4]);

  
}


void setup() {
  

pinMode(RELAY1, OUTPUT);
pinMode(RELAY2, OUTPUT);

sensors.begin();
tempL = -99;
tempR = -99;

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
  
  Serial.println("Adafruit MAX31865 PT100 Sensor Test!");

  max.begin(MAX31865_4WIRE);  // set to 2WIRE or 4WIRE as
  
  updtaeRelayTempR();
  updtaeRelayTempL();

  
}

float getTempMAX31865R(){
  
  uint16_t rtd = max.readRTD();

  //Serial.print("RTD value: "); Serial.println(rtd);
  float ratio = rtd;
  ratio /= 32768;
  //Serial.print("Ratio = "); Serial.println(ratio,8);
  //Serial.print("Resistance = "); Serial.println(RREF*ratio,8);
  //Serial.print("Temperature = "); Serial.println(max.temperature(RNOMINAL, RREF));

 

  // Check and print any faults
  uint8_t fault = max.readFault();
  if (fault) {
    Serial.print("Fault 0x"); Serial.println(fault, HEX);
    if (fault & MAX31865_FAULT_HIGHTHRESH) {
      Serial.println("RTD High Threshold"); 
    }
    if (fault & MAX31865_FAULT_LOWTHRESH) {
      Serial.println("RTD Low Threshold"); 
    }
    if (fault & MAX31865_FAULT_REFINLOW) {
      Serial.println("REFIN- > 0.85 x Bias"); 
    }
    if (fault & MAX31865_FAULT_REFINHIGH) {
      Serial.println("REFIN- < 0.85 x Bias - FORCE- open"); 
    }
    if (fault & MAX31865_FAULT_RTDINLOW) {
      Serial.println("RTDIN- < 0.85 x Bias - FORCE- open"); 
    }
    if (fault & MAX31865_FAULT_OVUV) {
      Serial.println("Under/Over voltage"); 
    }
    max.clearFault();
  }
  //Serial.println();
  return max.temperature(RNOMINAL, RREF);
}

void loop() { 

  getRelayTemp();
  
  
  tempL = getTemperature();
  tempR = getTempMAX31865R();
  
  if (tempL > tankLRelayTemp)
    setRellayL(true);
  else
    setRellayL(false);

  if (tempR > tankRRelayTemp)
    setRellayR(true); 
  else
    setRellayR(false); 
  
  if (!tempStringL.equals(String(tempL,5))){
      tempStringL = String(tempL,5);
      SetTemperatureL(tempStringL);
//      SetTemperatureR(tempStringR);
    }

    if (!tempStringR.equals(String(tempR,5))){
      tempStringR = String(tempR,5);
//      SetTemperatureL(tempStringL);
      SetTemperatureR(tempStringR);
    }
  
//  SetTemperature("right", "test");
//  TempToSerial();
  delay(1000);  // pause 
  
}
