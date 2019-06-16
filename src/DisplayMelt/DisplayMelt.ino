// подключаем стандартную библиотеку LiquidCrystal
#include <LiquidCrystal.h>
 
// инициализируем объект-экран, передаём использованные 
// для подключения контакты на Arduino в порядке:
// RS, E, DB4, DB5, DB6, DB7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//
//double a = 3.9083 * pow(10,  -3);
//double b= -5.7750 * pow(10, -7);
float voltage = 0;
float resistance = 100;
float temperature = 0;

int points = 0;
void setup()

{
    // устанавливаем размер (количество столбцов и строк) экрана
    lcd.begin(16, 2);
    
  Serial.begin(9600);
   
    
}


float getVoltage(uint8_t pin){
  int v_points = analogRead(pin); 
  float voltage =  (v_points * 5);

voltage = voltage/1023;
  Serial.print("Vout ");
  Serial.println(voltage);
  return voltage;
}



float getResistance(float v_x, float r_known, float v_total){

  float r_x = (r_known * v_total / v_x) - r_known;  //books suggestion
  
  return r_x;
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
  Serial.println(temp);
  return temp;
  
}

void print(){
   // печатаем первую строку
   lcd.setCursor(0, 0);
    lcd.print("R: ");
    lcd.print(resistance);
    lcd.print(" Om");

    // устанавливаем курсор в колонку 0, строку 1
    // на самом деле это вторая строка, т.к. нумерация начинается с нуля
    lcd.setCursor(0, 1);
    lcd.print("T: ");
    lcd.print(temperature);
    lcd.print(" C ");
    lcd.print(voltage);
    
    delay(1000);
    // печатаем вторую строку
}

float getResistance2(){
  float reading;
 
  reading = analogRead(A4);
  // convert the value to resistance
  reading = (1023 / reading)  - 1;     // (1023/ADC - 1) 
  reading = 112 / reading;  // 10K / (1023/ADC - 1)
 
  return reading;
}

float getResistance3(float vout, float r, float vcc){
  float Rx = r*vcc;
  Serial.print("1: ");
  Serial.println(Rx);
  Rx = Rx/vout;
  Serial.print("2: ");
  Serial.println(Rx);
  Rx = Rx - r;
  Serial.print("3: ");
  Serial.println(Rx);
  
  return Rx;
}


 
void loop()
{
voltage = getVoltage(A3);
resistance = getResistance3(voltage, 110, 3.3);
resistance = resistance;
//resistance = getResistance2();

temperature = getTermoT(100, resistance);
print();
  
}
