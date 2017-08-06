const int PinA = 2;
const int PinB = 3;

int pinAVal, pinBVal;

void setup() {
  pinMode(PinA, INPUT_PULLUP);
  pinMode(PinB, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(PinA),pinAInt,RISING);
  attachInterrupt(digitalPinToInterrupt(PinB),pinBInt,RISING);
  Serial.begin(9600);
}

void loop() {

}

void readPins(){
  pinAVal = digitalRead(PinA);
  pinBVal = digitalRead(PinB);
}

void pinAInt(){
  readPins();
  
  Serial.print("Pin A Rising ");
  Serial.print("PinA: ");
  Serial.print(pinAVal);
  Serial.print(" PinB: ");
  Serial.println(pinBVal);
}

void pinBInt(){
  readPins();

  Serial.print("Pin B Rising ");
  Serial.print("PinA: ");
  Serial.print(pinAVal);
  Serial.print(" PinB: ");
  Serial.println(pinBVal);
}
