  unsigned char Bluetooth_val;       //defining variable val
    #define ENA 5
    #define ENB 6

    #define IN1 8
    #define IN2 9
    #define IN3 10
    #define IN4 11

  unsigned char Lpwm_val = 180;
  unsigned char Rpwm_val = 180;

 void M_Control_IO_config()
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
      
  void setup() 
  { 
    M_Control_IO_config();
    Set_Speed(Lpwm_val,Rpwm_val);
    Serial.begin(9600);   //initialized serial port , using Bluetooth as serial port, setting baud at 9600 
    //stop(); 
  }
  void loop() 
  {  
    if(Serial.available()) //to judge whether the serial port receives the data.
      {
      Bluetooth_val=Serial.read();  //reading (Bluetooth) data of serial port,giving the value of val;
      switch(Bluetooth_val)
      {
        case 'F':forward(); 
        break;
        case 'B': back();   
        break;
        case 'L':left();   
        break;
        case 'R':right();  
        break;
        case 'S':stop();    
        break;   
      }
      } 
  }
