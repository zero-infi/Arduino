#include<AFMotor.h>
int a1,a2,a3,a4,a5;

AF_DCMotor motor1(1, MOTOR12_64KHZ); // create motor #2, 64KHz pwm
AF_DCMotor motor2(2, MOTOR12_64KHZ);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
motor1.setSpeed(255);
  motor2.setSpeed(255);

}
  int mode=5;

void loop() {
  a1=analogRead(A1);
  a2=analogRead(A2);
  a3=analogRead(A3);
  a4=analogRead(A4);
  a5=analogRead(A5);
  Serial.println(a1);
  Serial.println(a2);
  Serial.println(a3);
  Serial.println(a4);
  Serial.println(a5);
  Serial.println(" ");
  delay(500);
  if(a1 > 900 && a2 > 900 && a3 < 900 && a4 > 900 && a5 > 900)
  {
    if(mode!=1)
    {
     motor2.run(FORWARD);
     motor1.run(FORWARD);
     mode=1;
  }
  }
  else if(a1 < 900 && a2 < 900 && a3 > 900 && a4 < 900 && a5 < 900)
  {
    if(mode!=2)
    {
     motor2.run(FORWARD);
     motor1.run(FORWARD);
     mode=2;
  }
  }
  else if(a2 < 900)
  {
    if( a4 > 900 && a5 > 900)
    {
    if(mode!=3)
    {
    
     motor2.run(FORWARD);
     motor1.run(RELEASE);
     mode=3;
  }}
  }
  else if(a4 > 900)
   {if(a4 < 900 && a5 < 900)
    {if(mode!=4)
    {
    
     motor2.run(RELEASE);
     motor1.run(FORWARD);
     mode=4;
  }}
  }
  else if(a1 < 900 && a2 < 900 && a4 < 900 && a5 < 900)
  {
   if(mode!=5)
   {
     motor2.run(RELEASE);
     motor1.run(RELEASE);
     mode=5;
  }
  }
  
 
  }
