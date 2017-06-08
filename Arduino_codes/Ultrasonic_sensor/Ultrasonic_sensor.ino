
const byte Trig_Pin=9;  // Arduino pin tied to trigger pin on the ultrasonic sensor.
const byte Echo_Pin=22;  // Arduino pin tied to echo pin on the ultrasonic sensor.
int Duration=0;//unsigned sonar
int Distance=0;//distance in (CM)
void setup() 
{
  Serial.begin(9600);
  pinMode(Trig_Pin,OUTPUT);
  pinMode(Echo_Pin,INPUT);

}

void loop() 
{
  digitalWrite(Trig_Pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_Pin, HIGH);
  delayMicroseconds(2);
  digitalWrite(Trig_Pin, LOW);
  Duration = pulseIn(Echo_Pin,HIGH);
  Distance = ((Duration/2) * 0.03495);     //0.03495 cm/us speed of sound 
  Serial.println(Distance);
  delay (100);
}

