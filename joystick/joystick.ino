int VRx = A0;
int VRy = A1;
int SW = 2;

int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

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
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 
  pinMode(speedpin1,OUTPUT);
  pinMode(speedpin2,OUTPUT);
  
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(dir3,OUTPUT);
  pinMode(dir4,OUTPUT);
  
}

void loop() {
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  mapX = map(xPosition, 0, 1023, 0, 1023);
  mapY = map(yPosition, 0, 1023, 0, 1023);
  
  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.print(mapY);
  Serial.print(" | Button: ");
  Serial.println(SW_state);
  
  if(mapX<=523)
  {
    m1speed=255-0.487*mapX;
    analogWrite(speedpin1,m2speed);
    digitalWrite(dir3,HIGH);
    digitalWrite(dir4,LOW);
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,LOW);
    
    
  }
  if(mapX>523)
  {
    m2speed=(255.0/500.0)*(mapX-523);
    analogWrite(speedpin2,m1speed);
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,LOW);
    digitalWrite(dir3,LOW);
    digitalWrite(dir4,LOW);
    
  }
  if(mapY>488)
  {
    m1speed=m2speed=(255.0/535.0)*(mapY-488);
    analogWrite(speedpin1,m1speed);
    analogWrite(speedpin2,m2speed);
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,HIGH);
    digitalWrite(dir3,LOW);
    digitalWrite(dir4,HIGH);
  }
  if(mapY<488)
  {m1speed=m2speed=255-(255.0/488)*mapY;
    
  
  analogWrite(speedpin1,m1speed);
  analogWrite(speedpin2,m2speed);
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,LOW);
  digitalWrite(dir3,LOW);
  digitalWrite(dir4,HIGH);
  }

  delay(100);
  
}
