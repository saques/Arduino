const int PinA = 2;
const int PinB = 3;
const int LED = 9;
const int BOTTOM = 0;
const int TOP = 255;
const unsigned long DELTA = 5;
unsigned long time,curr;

int pinAVal, pinBVal;
int pos = 0;
int prev = pos;

void setup() {
  pinMode(PinA, INPUT_PULLUP);
  pinMode(PinB, INPUT_PULLUP);
  pinMode(LED, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(PinA),pinAInt,RISING);
  time = millis();
  Serial.begin(9600);
}

void loop() {
  if(pos != prev){
    analogWrite(LED,pos);
    prev = pos;
    Serial.println(pos);
  }
}

void readPinsAndVerifyDelta(){
  curr = millis();
  pinAVal = digitalRead(PinA);
  pinBVal = digitalRead(PinB);
  if(curr - time <= DELTA){
    pinAVal = LOW;
  }
  time = curr;
}

void pinAInt(){
  noInterrupts();
  readPinsAndVerifyDelta();
  if(pinAVal == LOW) {
    interrupts();
    return;
  }
  if(pinBVal == LOW){
    //counterclockwise
    if(pos>BOTTOM){
      pos--;
    }
  } else {
    //clockwise
    if(pos<TOP){
      pos++;
    }
  }
  interrupts();  
}
