double u =0;
double u_in=0;
double u_lost=0;


double r=0;
double temp = -273;
//double a = 0.0039803;
double a = 3.9083 * pow(10,  -3);
double b= -5.7750 * pow(10, -7);

double R0 = 100;
double Rr = 978;

double up = 0;
double down = 0;

double c = pow(2, 3);

void setup() {
  Serial.begin(9600);
  
  // put your setup code here, to run once:

}

double getVoltage(uint8_t pin){
  int v_points = analogRead(pin); 
//  Serial.print("Points: ");
//  Serial.println(v_points);
  double voltage =  (v_points * 5.00 / 1024);

//  Serial.print("VOLTAGE ");
//  Serial.print(pin);
//  Serial.print(" : ");
//  Serial.println(voltage); 
  return voltage;
}

double getResistanceA(double v_messured, double r_known, double v_total){
  
  double v_lost = v_total - v_messured;
 

  double r_x = (r_known * v_total / v_messured) - r_known;  //books suggestion
  
  return r_x;
}

double getResistanceB(double v_messured, double r_known, double v_total){
  
  double v_lost = v_total - v_messured;
 

  double r_x = (r_known * v_total / v_lost) - r_known;  //books suggestion
  
  return r_x;
}
//измеряемый ближе к плюсу, v_x - напряжение на измеряемом
double getResistanceC(double v_x, double r_known, double v_total){

  double r_x = (r_known * v_total / v_x) - r_known;  //books suggestion
  
  return r_x;
}


double getTermoT(double R_zero, double r_term){

//  double alfa = 3.9083 * pow(10,  -3);
  double alfa = 3.7869 * pow(10,  -3);
  double beta= -5.7750 * pow(10, -7);
//   double beta=  * pow(10, -7);
    
  up = (-R_zero * alfa) + sqrt(pow(R_zero, 2)* pow(alfa, 2) - 4* R_zero * beta * (R_zero - r_term));
//  up = (-R_zero * alfa) + sqrt(pow(R_zero, 2)* pow(alfa, 2) - 4* R_zero * beta * (R_zero - r_term));
  down = 2 * R_zero * beta;
  
  temp = up/down;
  
//  temp = -100 * a + sqrt(pow (100, 2) * pow(a, 2) - 4*100*b*(100 - r)) / 2 * 100 * b;
  Serial.println(temp);
  return temp;
  
}



void loop() {

  //Test делителя
  double del_test = getResistanceC(getVoltage(A1), 220, 5)- 1.3;
  del_test = 113.2;
  Serial.print("ТЕст делителя ");
  Serial.println(del_test);
  

  // Узнаем напряжение в контуре
  double v_kontur = 5 - getVoltage(A2);
  Serial.print("V_KONTUR: ");
  Serial.println(v_kontur);


  
  // Узнаем сопротивление проводника
  double r_provod = getResistanceC(v_kontur - getVoltage(A1), 220.0, v_kontur);
  Serial.print(getVoltage(A1));
  Serial.print("R_provod: ");
  Serial.println(r_provod);
  Serial.print(5 - getVoltage(A1));

  //Узнаем сопротивление градусника
  double r_term = getResistanceB(5-v_kontur, 220 + r_provod, 5);
  Serial.print("r_term: ");
  Serial.println(r_term);
//  
//  Serial.print("TotalVoltage: ");
//  Serial.println(totalvoltage);
 
  
    

    temp = getTermoT(101.95, del_test);
//  temp = -100 * a + sqrt(pow (100, 2) * pow(a, 2) - 4*100*b*(100 - r)) / 2 * 100 * b;
  Serial.print("TEMPERATURE ");
  Serial.println(temp);
  delay(3000);
  // put your main code here, to run repeatedly:

}
