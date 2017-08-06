/*
 * Usage of a rotary encoder,
 * using insight from http://www.instructables.com/id/Improved-Arduino-Rotary-Encoder-Reading/
 */

const int PinA = 2;
const int PinB = 3;
const int LED = 9;
const int BOTTOM = 0;
const int TOP = 255;

int pinAVal, pinBVal;

//expecting A or B flags
int expA, expB;

int pos = 0;
int prev = pos;

void setup() {
  pinMode(PinA, INPUT_PULLUP);
  pinMode(PinB, INPUT_PULLUP);
  pinMode(LED, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(PinA),pinAInt,RISING);
  attachInterrupt(digitalPinToInterrupt(PinB),pinBInt,RISING);
  expA = expB = 0;
  
  Serial.begin(9600);
}

void loop() {
  if(pos != prev){
    analogWrite(LED,pos);
    Serial.println(pos);
    prev = pos;
  }
}

void readPins(){
  pinAVal = digitalRead(PinA);
  pinBVal = digitalRead(PinB);
}

void pinAInt(){
  noInterrupts();
  readPins();
  if(pinAVal == HIGH && pinBVal == HIGH && expA){
    if(pos<TOP){
      pos++;
    }
    expA = 0;
    expB = 0;
  } else if( pinBVal == LOW && pinAVal == HIGH ) {
    expB = 1;
  }
  interrupts();
}

void pinBInt(){
  noInterrupts();
  readPins();
  if(pinBVal == HIGH && pinAVal == HIGH && expB){
    if(pos>BOTTOM){
      pos--;
    }
    expA = 0;
    expB = 0;
  } else if( pinAVal == LOW && pinBVal == HIGH ) {
    expA = 1;
  }
  interrupts();
}


