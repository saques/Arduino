const int Trig = 8;
const int Echo = 7;

long duration;
double dist;

void setup() {
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(distance());
}

double distance(){
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);

  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);

  //Full travel time (microseconds 1E-6)
  duration = pulseIn(Echo, HIGH) ;
  //340.29 m/s -> .00034029 m/ms -> .034029 cm/ms
  dist = duration*.034029 / 2;

  return dist;
}

