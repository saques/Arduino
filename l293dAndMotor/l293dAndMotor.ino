const int pin1 = 5;
const int pin2 = 6;

void setup() {
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
}

void loop() {
  digitalWrite(pin2,LOW);
  digitalWrite(pin1,HIGH);

  delay(1000);
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,HIGH);

  delay(1000);

  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  
}
