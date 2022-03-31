#include<Servo.h>
int pos=90;
int servopin=9;
int servodelay=25;
int trigpin=13;
int echopin=11;
float t1;
float sos=343.5;
float distance;
float dis;
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
  // put your setup code here, to run once:
  Serial.begin(9600);
  mypointer.attach(servopin);
  mypointer.write(pos);
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
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  t1=pulseIn(echopin,HIGH);
  t1=t1/10000;
  distance=t1*sos/2;
  Serial.println(distance);
  delay(100);
  if(distance<20)
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
  else
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
    
    
    
}
