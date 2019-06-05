int u =0;

void setup() {
  Serial.begin(9600);
  
  // put your setup code here, to run once:

}

void loop() {
  u = analogRead(A0);
  Serial.print(u);
  delay(1000)
  // put your main code here, to run repeatedly:

}
