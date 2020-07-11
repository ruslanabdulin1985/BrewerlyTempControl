/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/
  byte buf[1];

int led = 13;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
//  buf = new byte[1];
  pinMode(led, OUTPUT); 
    buf[0] = 0;
}

void blinkOnce(){
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
}

// the loop routine runs over and over again forever:
void loop() {

buf[0] = 0;  
if (Serial.available()){
  Serial.readBytes(buf, 1);
  Serial.print(buf[0]);
}
//  digitalWrite(led, HIGH);
//  int num = random(5, 10);
 
  if (buf[0] == 49)
    blinkOnce();
  if (buf[0] == 48){
    
  }
//    digitalWrite(led, LOW);
    
  delay(1000);        // delay in between reads for stability
}
