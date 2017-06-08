int IN1 = 22;
int IN2 = 21;
int IN3 = 24;
int IN4 = 23;
int ENA = 3;
int ENB = 2;

int PWM_1_value =0;
int PWM_2_value =0;

void setup() {
 
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  while(1)
  {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3,LOW );
  digitalWrite(IN4, HIGH);
  analogWrite (ENA, 155);
  analogWrite (ENB, 155);
  }
  
delay(2000);

}
