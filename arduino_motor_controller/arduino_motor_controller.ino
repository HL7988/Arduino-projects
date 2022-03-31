int speedpin1=5;
int speedpin2=10;
int dir1=4;
int dir2=3;
int dir3=7;
int dir4=8;
int xpin=A0;
int ypin=A1;
int spin=2;
int xval;
int yval;
int sval;
float m1speed;
float m2speed;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(speedpin1,OUTPUT);
  pinMode(speedpin2,OUTPUT);
  
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(dir3,OUTPUT);
  pinMode(dir4,OUTPUT);
  pinMode(spin,INPUT);
  pinMode(ypin,INPUT);
  pinMode(spin,INPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  xval=analogRead(xpin);
  yval=analogRead(ypin);
  sval=digitalRead(spin);
  Serial.println(xval,yval);
  
  if(xval<=523)
  {
    m1speed=255-(255.0/523.0)*xval;
    analogWrite(speedpin1,m2speed);
    digitalWrite(dir3,HIGH);
    digitalWrite(dir4,LOW);
    
  }
  if(xval>523)
  {
    m2speed=(255.0/500.0)*(xval-523);
    analogWrite(speedpin2,m1speed);
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,LOW);
    
  }
  if(yval>488)
  {
    m1speed=m2speed=(255.0/535.0)*(yval-488);
    analogWrite(speedpin1,m1speed);
    analogWrite(speedpin2,m2speed);
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,LOW);
    digitalWrite(dir3,LOW);
    digitalWrite(dir4,HIGH);
  }
  if(yval<488)
  {m1speed=m2speed=255-(255.0/488)*yval;
    
  
  analogWrite(speedpin1,m1speed);
  analogWrite(speedpin2,m2speed);
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,LOW);
  digitalWrite(dir3,LOW);
  digitalWrite(dir4,HIGH);
  }
 }
