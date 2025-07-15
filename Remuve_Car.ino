  #include <Servo.h>
  #include "IRremote.h"

  #define SERVO_MOTOR 3
  Servo myservo;

  int RECV_PIN = 12; // задает номер пина, к которому подключен ИК-приемник.
  IRrecv irrecv(RECV_PIN); // irrecv — объект класса IRrecv, который управляет приемом сигналов на указанном пине (RECV_PIN)
  decode_results results;

  #define ENA 5
  #define ENB 6

  #define IN1 8
  #define IN2 9
  #define IN3 10
  #define IN4 11

  unsigned char Lpwm_val =150;
  unsigned char Rpwm_val = 150;
  
  void M_Control_IO_config(void)
  {
    pinMode(IN1,OUTPUT);
    pinMode(IN2,OUTPUT);
    pinMode(IN3,OUTPUT);
    pinMode(IN4,OUTPUT);
    pinMode(ENA,OUTPUT);
    pinMode(ENB,OUTPUT);   
  }

  void Set_Speed(unsigned char Left,unsigned char Right)
  {
    analogWrite(ENA,Left);
    analogWrite(ENB,Right);
  }

  void forward(){ 
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    
  }
  
  void back(){
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    
  }
  
  void left(){
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    
  }
  
  void right(){
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    
  }

  void stop()
  {
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,HIGH);
  }
  

  void setup() {

    Serial.begin(9600);
    myservo.attach(SERVO_MOTOR);
    M_Control_IO_config();
    Set_Speed(Lpwm_val,Rpwm_val);
    irrecv.enableIRIn(); // активирует прием сигналов инфракрасного приемника.
    pinMode (13, OUTPUT);
    digitalWrite (13, 1);
    
  }
  
  void returnServo()
  {
    myservo.write(0);
    delay(1500);
    myservo.write(180);
    delay(1500);
   

  }


    void IR_Control(void)
  {
    unsigned long Key;
    if(irrecv.decode(&results)) //judging if serial port receives data   
  {
      Key = results.value;
      switch(Key)
      {
        case 0xFF629D:forward();   //UP
        break;
        case 0xFFA857: back();   //back
        break;
        case 0xFF22DD:left();   //Left    
        break;
        case 0xFFC23D:right(); //Righ
        break;
        case 0xFF02FD:stop();   //stop
        break;
        default: 
        break;      
      } 
      irrecv.resume(); // Receive the next value
  }

      } 
    

        void loop() 
        {
          IR_Control();     
          //returnServo();  
        }
        
          
          
          //FF629D вперед
          //FFA857 назад
          //FF22DD влево
          //FFC23D вправо
          //FF02FD стоп
        
        