#define ENCA 2
#define ENCB 3
#define LEN 12
#define REN 9
#define LPWM 11 
#define RPWM 10 

volatile int posi = 0;
float ePrev = 0;
float eIntegral = 0; 
long prevT = 0;

void setup() {
  pinMode(LEN,OUTPUT);
  pinMode(REN,OUTPUT);
  pinMode(LPWM,OUTPUT);
  pinMode(RPWM,OUTPUT);

  pinMode(ENCA,INPUT_PULLUP);
  pinMode(ENCB,INPUT_PULLUP);

  digitalWrite(LEN, HIGH);
  digitalWrite(REN, HIGH);

  attachInterrupt(digitalPinToInterrupt(ENCA),countMotor,RISING);
}

void loop() {
  float Kp = 5;
  float Ki = 0.05;
  float Kd = 0.05;

  float target = 48;

  long currT = micros();
  float deltaT = ((float)(currT - prevT)/1e6);
  prevT = currT;

  int pos = 0;
  noInterrupts();
  pos = posi;
  interrupts();

  float error = target - pos;

  eIntegral += error * deltaT;

  float ed = ((error - ePrev)/deltaT);

  float u = (Kp * error) + (Ki * eIntegral) + (Kd * ed);

  float pwr = fabs(u);

  if(pwr > 255){
    pwr = 255;
  }

  int dir = 1;

  if(u < 0){
    dir = -1;
  }

  if(fabs(error) < 5){
    eIntegral = 0;
    setMotor(0,0);
  }else{
    setMotor(dir,(int)pwr);
  }

  ePrev = error;
}

void setMotor(int dir , int ppwr){
  if(dir == 1){
    digitalWrite(LPWM,LOW);
    analogWrite(RPWM,ppwr);
  }else if(dir == -1){
    digitalWrite(RPWM,LOW);
    analogWrite(LPWM,ppwr);
  }else{
    digitalWrite(RPWM,LOW);
    digitalWrite(LPWM,LOW);
  }
}

void countMotor(){
  int b = digitalRead(ENCB);

  if(b > 0){
    posi++;
  }else{
    posi--;
  }
}