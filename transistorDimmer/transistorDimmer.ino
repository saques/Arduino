const int Data = 9;
int value = 255;
int variation = 1;
void setup() {
  pinMode(Data, OUTPUT);
}

void loop() {
  analogWrite(Data, value);
  delay(5);
  if(value==0 || value==255){
    variation*=-1;
  }
  value+=variation;
}
