//Laney Winkler
//Safe Cracking, Fall 2018
//Moving a servo with analog sensor
#include <Servo.h>
Servo servoMotor;
const int SafeCrackingServo = 3;
int serialInput;//variable to hold my serial inputs

void setup() {
  Serial.begin(9600);
  servoMotor.attach(SafeCrackingServo);//connects the servo to the input pin
}
void loop() {
  data = analogRead(A0);// reading serial input from the potentiameter
  Serial.println(serialInput);
//mapping the data, and translate it from the potentiometer to the servo
  int placement = map(data, 0, 1023, 0, 179); //Because the motor can move
  //180 degrees, I can map it 0-179.
  servoMotor.write(placement);
  //as I move the analog sensor, the servo will move as well.
}
