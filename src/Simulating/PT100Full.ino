void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

float voltmeter(float range, int points){
  	float bufer = points*range;
  	Serial.println(bufer);
   	return bufer/1024.0;
}

float readData(){
	analogReference(INTERNAL);
	int points = analogRead(A0);
  	float Vout = voltmeter(1.1, points);
  	float Vreal = Vout/10;
  	Serial.print("Vout: ");
  	Serial.println(Vout);
  	Serial.print("Vreal: ");
  	Serial.println(Vreal);
  	return Vreal;
}
float calculateResistance(float Vout){
  	float Vin = 5;
	float R1=6000;    // значение известного сопротивления
	float R2=0;       // значение неизвестного сопротивления
  	float Vfin = Vin - Vout;
  	float buffer= (Vin/Vfin) -1;
  	R2= R1 * buffer;
  	Serial.print("R (ohm) = ");
  	Serial.println(R2);
}

void loop()
{
  
  //readData();
  calculateResistance(readData());
  
}