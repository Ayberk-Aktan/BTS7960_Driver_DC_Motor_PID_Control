#define ENCA 2
#define ENCB 3
#define LEN 12
#define REN 9
#define LPWM 11 
#define RPWM 10 

volatile long posi = 0;
float ePrev = 0;
unsigned long prevT = 0;
float eIntegral = 0; 
float lastDTerm = 0;

void setup() {
  pinMode(LEN, OUTPUT); 
  pinMode(REN, OUTPUT);
  pinMode(LPWM, OUTPUT); 
  pinMode(RPWM, OUTPUT);
  pinMode(ENCA, INPUT_PULLUP);
  pinMode(ENCB, INPUT_PULLUP);
  digitalWrite(LEN, HIGH);
  digitalWrite(REN, HIGH);
  attachInterrupt(digitalPinToInterrupt(ENCA), countMotor, RISING);
}

void loop() {
  //PID Factors from Simulink Models
  const double Kp = 2.9735;
  const double Ki = 0.3001;
  const double Kd = 6.5378;
  const double N = 181.6;
  
  int target = 24;

  unsigned long currT = micros();
  float deltaT = ((currT - prevT) / 1e6);
  if(deltaT < 0.01){
    return;
  }
  prevT = currT;

  int pos = 0;
  noInterrupts();
  pos = posi;
  interrupts();

  int error = target - pos;

  eIntegral += error * deltaT; 
  
  //Integral Windup
  if(eIntegral > 1){
    eIntegral = 1;
  }else if(eIntegral < -1){
    eIntegral = -1;
  }

  float eD = ((error - ePrev)/deltaT);
  float dTerm = lastDTerm + (N * deltaT * (eD - lastDTerm));
  lastDTerm = dTerm;

  float u = (Kp * error) + (Ki * eIntegral) + (Kd * dTerm);

  int pwr = abs(u); 
  
  if(pwr > 255){
    pwr = 255;
  }

  int dir = 1;

  if(u < 0){
    dir = -1;
  }

  if(abs(error) < 2){
    eIntegral = 0;
    setMotor(0,0);
  }else{
    setMotor(dir,pwr);
  }

  ePrev = error;
}

void setMotor(int dir, int ppwr) {
  if (dir == 1) {
    digitalWrite(LPWM, LOW);
    analogWrite(RPWM, ppwr);
  } else if (dir == -1) {
    digitalWrite(RPWM, LOW);
    analogWrite(LPWM, ppwr);
  } else {
    digitalWrite(LPWM, HIGH);
    digitalWrite(RPWM, HIGH);
  }
}

void countMotor() {
  if (digitalRead(ENCB) > 0){
    posi++;
  }
  else{ 
    posi--;
  }
}