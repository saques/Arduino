
//rotary encoder pins
const int PinA = 3;
const int PinB = 2;

//motor controller pins
const int pin1 = 5;
const int pin2 = 6;

//limits
const int BOTTOM = 0;
const int TOP = 255;

const int TARGET = 16;
const int SPEED = 50;

int pinAVal, pinBVal;

//expecting A or B flags
int expA, expB;

int pos = 16;
int prev = pos;

void setup() {
  pinMode(PinA, INPUT_PULLUP);
  pinMode(PinB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PinA),pinAInt,RISING);
  attachInterrupt(digitalPinToInterrupt(PinB),pinBInt,RISING);
  expA = expB = 0;
  
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  
  Serial.begin(9600);
}

void loop() {
  motorToTargetPos(TARGET);
}

/*
 * A function used to send a motor
 * to a given position, using the steps
 * of the en11 rotary encoder (20 steps/rev).
 */
void motorToTargetPos(int t){
  /*
   * Depending on how the rotary
   * encoder is attached to the
   * axis of the motor, the order
   * of the following comparisons
   * may need to be inverted.
   */
  if(pos < t){
    analogWrite(pin1,LOW);
    analogWrite(pin2,SPEED);    
  } else if (pos > t){
    analogWrite(pin2,LOW);
    analogWrite(pin1,SPEED);
  } else {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
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
