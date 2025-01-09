#include "CytronMotorDriver.h"
#include <Servo.h>
Servo myservo;
CytronMD motor1(PWM_PWM, 2, 3); // bottom right
CytronMD motor2(PWM_PWM, 4, 5); // bottom left
CytronMD motor3(PWM_PWM, 8, 12); // front left
CytronMD motor4(PWM_PWM, 10, 11); // front right

#define BT_TX 6
#define BT_RX 7
#include "SoftwareSerial.h"
SoftwareSerial BTSerial(BT_TX, BT_RX); // Maker UNO RX, TX

#define BUTTON  2
#define DELAY 400
#define NOTE_G4  392
#define NOTE_C5  523
#define NOTE_G5  784
#define NOTE_C6  1047

int btConnect[] = {NOTE_G5, NOTE_C6};
int btConnectNoteDurations[] = {12, 8};
int pos = 0;

#define playBtConnectMelody() playMelody(btConnect, btConnectNoteDurations, 2)

boolean BTConnect = false;
char inChar;

void setup()
{
  pinMode(BUTTON,INPUT_PULLUP);
  Serial.begin(9600);
  BTSerial.begin(9600);
  myservo.attach(9); 
  myservo.write(2);
  delay(DELAY);
}
void loop()
{
  inChar = 'S';

  if (BTSerial.available()) {
    inChar = BTSerial.read();
    Serial.println(inChar);
  }

  if (inChar == 'F') {
    motor1.setSpeed(255);
    motor2.setSpeed(255);
    motor3.setSpeed(-255);
    motor4.setSpeed(-255);
    delay(DELAY);
    
  }
  else if (inChar == 'B') {
    motor1.setSpeed(-255);
    motor2.setSpeed(-255);
    motor3.setSpeed(255);
    motor4.setSpeed(255);
    delay(DELAY);
    
  }
  else if (inChar == 'R') {
    motor1.setSpeed(-200);
    motor2.setSpeed(200);
    motor3.setSpeed(-200);
    motor4.setSpeed(200);
    delay(DELAY);
  }
  else if (inChar == 'L') {
    motor1.setSpeed(200);
    motor2.setSpeed(-200);
    motor3.setSpeed(200);
    motor4.setSpeed(-200);
    delay(DELAY);
  } else if (inChar == 'T') {
    myservo.write(2);
  } else if (inChar == 'X'){
    myservo.write(92);
  } else if (inChar == 'C'){
    motor1.setSpeed(255);
    motor2.setSpeed(-255);
    motor3.setSpeed(255);
    motor4.setSpeed(-255);
    delay(1150);
  } else if (inChar == 'S') {
    motor1.setSpeed(0);
    motor2.setSpeed(0);
    motor3.setSpeed(0);
    motor4.setSpeed(0);
    delay(300);
  }
}