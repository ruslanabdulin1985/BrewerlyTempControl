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

void loop() {
  u = analogRead(A1);
  Serial.print("Points: ");
  Serial.println(u);
  u_in =  (u * 5.00 / 1023); //+ ((u * 5) % 1023); // Voltage
  u_lost = 5 - u_in;
  Serial.print("VOLTAGE: ");  
  Serial.println(u_lost);
  


  r = (Rr*5 / u_lost) - Rr;
  Serial.print("R: ");
  Serial.println(r);
//  r = 119.4;
r = r - 0.2*2;
  
  up = (-R0 *a) + sqrt(pow(R0, 2)* pow(a, 2) - 4* R0 * b * (R0 - r));
  down = 2 * R0 * b;
  
  temp = up/down;
  
//  temp = -100 * a + sqrt(pow (100, 2) * pow(a, 2) - 4*100*b*(100 - r)) / 2 * 100 * b;
  Serial.println(temp);
  delay(500);
  // put your main code here, to run repeatedly:

}
