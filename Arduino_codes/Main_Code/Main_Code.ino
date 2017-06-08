#include <Wire.h> //I2C Arduino Library

/////////////////// UltraSonic //////////////////////

const byte Trig_Pin[] = {4, 5, 6, 7}; // Arduino pin tied to trigger pin on the ultrasonic sensor.
const byte Echo_Pin[] = {49 , 48 , 47 ,46 }; // Arduino pin tied to echo pin on the ultrasonic sensor.
//Ultra0 --> Front
//Ultra1 --> Back
//Ultra2 --> Right
//Ultra3 --> Left
int Duration = 0; //unsigned sonar
int Distance = 0; //distance in (CM)
int i = 0;


//////////////////// Magnometer //////////////////////

#define HMC5883L_ADDR 0x1E //0011110b, I2C 7bit address of HMC5883

bool haveHMC5883L = false;

bool detectHMC5883L ()
{
  // read identification registers
  Wire.beginTransmission(HMC5883L_ADDR); //open communication with HMC5883
  Wire.write(10); //select Identification register A
  Wire.endTransmission();
  Wire.requestFrom(HMC5883L_ADDR, 3);
  if (3 == Wire.available()) {
    char a = Wire.read();
    char b = Wire.read();
    char c = Wire.read();
    if (a == 'H' && b == '4' && c == '3')
      return true;
  }

  return false;
}



////////////////// H_bridge ////////////////////

int IN1 = 22;
int IN2 = 21;
int IN3 = 24;
int IN4 = 23;
int ENA = 3;
int ENB = 2;

int PWM_value = 150;





//proto types of all functions
float UltraSonic(int Sensor_Number);
float Magnometer();
void Forward();
void Backward();
void Right();
void Left();
void Break();





void setup() {

  Serial.begin(9600);
  //ultrasonics pins modes
  for (i = 0; i < 4; i++)
  {
    pinMode(Trig_Pin[i], OUTPUT);
    pinMode(Echo_Pin[i], INPUT);
  }

  //Magnometer
  Wire.begin();
  // lower I2C clock http://www.gammon.com.au/forum/?id=10896
  TWBR = 78;  // 25 kHz
  TWSR |= _BV (TWPS0);  // change prescaler

  //H_bridge
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

}






void loop() {
  // put your main code here, to run repeatedly:
  while (1)
  {

  }

}








/////////////////// Functions /////////////////////

float UltraSonic(int Sensor_Number)
{
  digitalWrite(Trig_Pin[Sensor_Number], LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_Pin[Sensor_Number], HIGH);
  delayMicroseconds(2);
  digitalWrite(Trig_Pin[Sensor_Number], LOW);
  Duration = pulseIn(Echo_Pin[Sensor_Number], HIGH);
  Distance = ((Duration / 2) * 0.03495);   //0.03495 cm/us speed of sound
  Serial.println(Distance);
  return Distance;
  delay (100);
}


float Magnometer()
{
  bool detect = detectHMC5883L();

  if (!haveHMC5883L)
  {
    if (detect)
    {
      haveHMC5883L = true;
      Serial.println("We have HMC5883L, moving on");
      // Put the HMC5883 IC into the correct operating mode
      Wire.beginTransmission(HMC5883L_ADDR); //open communication with HMC5883
      Wire.write(0x02); //select mode register
      Wire.write(0x00); //continuous measurement mode
      Wire.endTransmission();
    }
    else
    {
      Serial.println("No HMC5883L detected!");
      delay(2000);
      // return;
    }
  }
  else
  {
    if (!detect) {
      haveHMC5883L = false;
      Serial.println("Lost connection to HMC5883L!");
      delay(2000);
      // return;
    }
  }

  int x, y, z; //triple axis data

  //Tell the HMC5883 where to begin reading data
  Wire.beginTransmission(HMC5883L_ADDR);
  Wire.write(0x03); //select register 3, X MSB register
  Wire.endTransmission();

  //Read data from each axis, 2 registers per axis
  Wire.requestFrom(HMC5883L_ADDR, 6);
  if (6 <= Wire.available()) {
    x = Wire.read() << 8; //X msb
    x |= Wire.read(); //X lsb
    z = Wire.read() << 8; //Z msb
    z |= Wire.read(); //Z lsb
    y = Wire.read() << 8; //Y msb
    y |= Wire.read(); //Y lsb
  }

  //Print out values of each axis
  Serial.print("x: ");
  Serial.print(x);
  Serial.print("  y: ");
  Serial.print(y);
  Serial.print("  z: ");
  Serial.println(z);

  return y;
  delay(250);
}



void Forward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite (ENA, PWM_value);
  analogWrite (ENB, PWM_value);

}

void Backward()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite (ENA, PWM_value);
  analogWrite (ENB, PWM_value);

}
void Right()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite (ENA, PWM_value);
  analogWrite (ENB, PWM_value);

}

void Left()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite (ENA, PWM_value);
  analogWrite (ENB, PWM_value);
}

void Break()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite (ENA, 0);
  analogWrite (ENB, 0);
}

