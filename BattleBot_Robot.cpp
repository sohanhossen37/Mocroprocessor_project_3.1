#include <Servo.h>
#define relay A0
int motorA_in1 = 2;
int motorA_in2 = 3;
int motorB_in3 = 4;
int motorB_in4 = 5;
int motorA_PWM = 9;
int motorB_PWM = 10;
int speed = 255;
char alpha;
Servo servoMotor;
Servo servoMotor1;

void setup() {
  Serial.begin(9600);

  servoMotor.attach(6); 
  servoMotor1.attach(12);// Attaching servo motor to pin 7
  pinMode(relay, OUTPUT);
  pinMode(motorA_in1, OUTPUT);
  pinMode(motorA_in2, OUTPUT);
  pinMode(motorB_in3, OUTPUT);
  pinMode(motorB_in4, OUTPUT);
  pinMode(motorA_PWM, OUTPUT);
  pinMode(motorB_PWM, OUTPUT);

  
}

void loop() {
  digitalWrite(motorA_PWM, HIGH);
  digitalWrite(motorB_PWM, HIGH);

  if (Serial.available()) {
    alpha = Serial.read();
  }

  if (alpha == 'F') {
    Forward();
  } else if (alpha == 'B') {
    Backward();
  } else if (alpha == 'R') {
    Right();
  } else if (alpha == 'L') {
    Left();
  }  else if (alpha == 'M') { // Example command to move servo motor
    MoveServo();
  }else if (alpha == 'O') {
    MoveServo1();
  }
  else if (alpha == 'S') {
    Stop();
  }
  else if (alpha == 'V') {
    Motor();
  }

  delay(100);
}

void Forward() {
  digitalWrite(motorA_in1, LOW);
  digitalWrite(motorA_in2, HIGH);
  digitalWrite(motorB_in3, HIGH);
  digitalWrite(motorB_in4, LOW);
  delay(100);
}

void Backward() {
  digitalWrite(motorA_in1, HIGH);
  digitalWrite(motorA_in2, LOW);
  digitalWrite(motorB_in3, LOW);
  digitalWrite(motorB_in4, HIGH);
  delay(100);
}

void Stop() {
  digitalWrite(motorA_in1, LOW);
  digitalWrite(motorA_in2, LOW);
  digitalWrite(motorB_in3, LOW);
  digitalWrite(motorB_in4, LOW);
  digitalWrite(relay, LOW);
}

void Right() {
  digitalWrite(motorA_in1, LOW);
  digitalWrite(motorA_in2, LOW);
  digitalWrite(motorB_in3, HIGH);
  digitalWrite(motorB_in4, LOW);
  delay(100);
}

void Left() {
  digitalWrite(motorA_in1, LOW);
  digitalWrite(motorA_in2, HIGH);
  digitalWrite(motorB_in3, LOW);
  digitalWrite(motorB_in4, LOW);
  delay(100);
}

void MoveServo() {
  servoMotor.write(150); 
  delay(700); 
  servoMotor.write(0); 
}
void MoveServo1() {
  servoMotor1.write(180);
  delay(600); 
  servoMotor1.write(0); 
}
void Motor()
{
   digitalWrite(relay, HIGH);

}