
void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT_PULLUP);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);


}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println("sensor output is");
  Serial.println(sensorValue);
  if(sensorValue<600)
  {
    Serial.println("Light");
    digitalWrite(12,0);
    digitalWrite(13,1);

  }
  else{
    Serial.println("dark");
      digitalWrite(12,1);
      digitalWrite(13,0);
  }
  delay(300);
}
