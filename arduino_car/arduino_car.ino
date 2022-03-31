#include<Servo.h>
int pos=90;
int servopin=9;
int servodelay=25;
int trigpin=13;
int echopin=11;
float t1;
float sos=343;
float distance;
float dis1;
float dis2;
Servo mypointer;


int speedpin1=5;
int speedpin2=10;
int dir1=4;
int dir2=3;
int dir3=7;
int dir4=8;
float m1speed;
float m2speed;

void setup() {
  
  Serial.begin(9600);
  mypointer.attach(servopin);
  pinMode(6,OUTPUT);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(speedpin1,OUTPUT);
  pinMode(speedpin2,OUTPUT);
  
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(dir3,OUTPUT);
  pinMode(dir4,OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  dis1=reqsignal();
  Serial.println(dis1);
  if(dis1>15)
  {
   forward();
   Serial.println("moving forward");
  }
  else
  { stopm();
    pos=pos+90;
    mypointer.write(pos);
    delay(100);
    dis1=reqsignal();
    delay(200);
    Serial.print("LEFT SIDE DISTANCE");
    Serial.println(dis1);
    pos=pos-90;
    mypointer.write(pos);
    delay(250);
    pos=pos-90;
    mypointer.write(pos);
    delay(100);
    dis2=reqsignal();
    delay(200);
    Serial.print("RIGHT SIDE DISTANCE");
    Serial.println(dis2);
    pos=pos+90;
    mypointer.write(pos);
    delay(200);
      if ((dis1>dis2)&&(dis1>15))
      { 
        turn90L();
        Serial.println("left turn");
        delay(500);
      }
      else if((dis2>dis1)&&(dis2>15))
      {
          turn90R();
          Serial.println("right turn");
          delay(500);
       }
       else
         {
          turn();
          Serial.println("turn");
          delay(1000);
         }
    
       
   }   
    
    
    
  }
  void forward()
  {
    m2speed=255;
    m1speed=255;
    analogWrite(speedpin2,m2speed);
    analogWrite(speedpin1,m1speed);
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,LOW);
    digitalWrite(dir3,LOW);
    digitalWrite(dir4,HIGH);
  }
  
  void turn()
  {
    m2speed=255;
    m1speed=255;
    analogWrite(speedpin2,m2speed);
    analogWrite(speedpin1,m1speed);
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,HIGH);
    digitalWrite(dir3,LOW);
    digitalWrite(dir4,HIGH);
   
  }
  void turn90L()
  {
     m2speed=255;
    m1speed=255;
    analogWrite(speedpin2,m2speed);
    analogWrite(speedpin1,m1speed);
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,HIGH);
    digitalWrite(dir3,LOW);
    digitalWrite(dir4,HIGH);
    
  }

  void turn90R()
  {
     m2speed=255;
    m1speed=255;
    analogWrite(speedpin2,m2speed);
    analogWrite(speedpin1,m1speed);
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,LOW);
    digitalWrite(dir3,HIGH);
    digitalWrite(dir4,LOW);
    
  }
 
    
  float reqsignal()
  {
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  t1=pulseIn(echopin,HIGH);
  t1=t1/10000;
  distance=t1*sos/2;
  return distance;
  }
  void stopm()
  {
    analogWrite(speedpin2,m2speed);
    analogWrite(speedpin1,m1speed);
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,LOW);
    digitalWrite(dir3,LOW);
    digitalWrite(dir4,LOW);
    delay(500);
  }
