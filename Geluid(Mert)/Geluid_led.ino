void setup() {
  // put your setup code here, to run once:
  pinMode (2, INPUT);
  pinMode (3, OUTPUT);
  Serial.begin(9600);
}

 

 

void loop() {
  // put your main code here, to run repeatedly:
  bool pulse = digitalRead(2);
    if(pulse == 0){
    digitalWrite(3, HIGH);
    Serial.println("ON");
  } else {
    digitalWrite(3, LOW);
    Serial.println("OFF");
  }
}
