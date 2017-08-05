const int Data = 9;

void setup() {
 pinMode(Data, OUTPUT);
 digitalWrite(Data, LOW);
}

void loop() {
 delay(1000);
 digitalWrite(Data,LOW);
 delay(1000);
 digitalWrite(Data,HIGH);
}
