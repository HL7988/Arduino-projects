#include<Servo.h>
int pos=0;
int servopin=9;
int servodelay=25;
Servo mypointer;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mypointer.attach(servopin);
   mypointer.write(pos);
   

}

void loop() {
  // put your main code here, to run repeatedly:
 
 
  

}




pos=pos-60;
    mypointer.write(pos);
    dis=reqsignal();
    pos=pos+60;
    mypointer.write(pos);
    if(dis<10)
    {
      sturnL();
      forward();
    }
    pos=pos+60;
    dis=reqsignal();
    pos=pos-60;
    mypointer.write(pos);
    dis=reqsignal();
    if(dis<10)
    {
      sturnR();
      forward();
    }
