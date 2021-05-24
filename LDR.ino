//This Program is used to Detect the LDR 
int Status = 12;
int sensor = 13;
void setup() {
 Serial.begin(9600);
  pinMode(sensor, INPUT); 
  pinMode(Status, OUTPUT);
}
void loop() {
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.0);
  Serial.println(voltage);

    long state = digitalRead(sensor);
  delay(1000);
    if(state == HIGH){
      digitalWrite (Status, HIGH);
      Serial.println("Motion detected!");
    }
    else {
      digitalWrite (Status, LOW);
      Serial.println("Motion absent!");
      }
}
