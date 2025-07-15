#define SensorLeft 4    // input pin of left sensor
//#define SensorMiddle A3   // input pin of middle sensor
#define SensorRight A5     // input pin of right sensor

unsigned char SL;         // state of left sensor
unsigned char SM;         // state of middle sensor
unsigned char SR;         // state of right sensor

#define Lpwm_pin 5        // pin controlling speed (ENA of motor driver board)
#define Rpwm_pin 6        // pin controlling speed (ENB of motor driver board)

int IN1 = 8;              // pin controlling direction (IN1 of motor driver board)
int IN2 = 9;              // pin controlling direction (IN2 of motor driver board)
int IN3 = 10;             // pin controlling direction (IN3 of motor driver board)
int IN4 = 11;             // pin controlling direction (IN4 of motor driver board)

unsigned char Lpwm_val = 120;  // speed of left wheel (adjusted for performance)
unsigned char Rpwm_val = 120;  // speed of right wheel (adjusted for performance)

void Sensor_IO_Config() {
  pinMode(SensorLeft, INPUT);
  //pinMode(SensorMiddle, INPUT);
  pinMode(SensorRight, INPUT);
}

void Sensor_Scan() {
  SL = digitalRead(SensorLeft);
  //SM = analogRead(SensorMiddle);
  SR = digitalRead(SensorRight);
}

void M_Control_IO_config() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(Lpwm_pin, OUTPUT);
  pinMode(Rpwm_pin, OUTPUT);
}

void Set_Speed(unsigned char Left, unsigned char Right) {
  analogWrite(Lpwm_pin, Left);
  analogWrite(Rpwm_pin, Right);
}

void forward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void back() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stop() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
}

void setup() {
  Sensor_IO_Config();
  M_Control_IO_config();
  Set_Speed(Lpwm_val, Rpwm_val); // setting initial speed
  stop();
}

void loop() {
  Sensor_Scan(); //там все глобальные переменные, поэтому они изменяются в глобальном пространстве
  
  if (SL == 0 && SR == 0)     
  {
    forward();
  } 

  else if (SL == 1 && SR == 0) 
  {
    left();
  } 

  else if (SL == 0 && SR == 1) 
  {
    right();
  } 

  else 
  {
    stop();
  }

}