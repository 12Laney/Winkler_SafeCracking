//Laney Winkler
//Safe Cracking, Fall 2018
//Moving a servo with button

#include <Servo.h>
//For this homework assignment, I went back to my Object project journal 
//(Thank goodness for good documentation!) because I forgot a lot about motors.
//It would have been much easier to control the motor with two buttons, but in
//order for me to do it with one, I first tried to use a series of if statements,
//but it got confusing, so I simplified it to use a bool statement instead.

int button = 3; //I connected my button to pin 3 on the redboard
Servo safecrackingServo; // for the servo libary, initiallizing my servo.
int State = 0; //I needed a type of counter variable for my boolean
boolean turn = true; //initializing my boolean variable to true.

void setup(){
  //reading the inputs of my button and servo ("attach" from the servo library)
  pinMode(button, INPUT);
  safecrackingServo.attach(9); 
  digitalWrite(3, HIGH); 
}

void loop(){
  State = digitalRead(button);//having the Redboard read the current state
  //of the button, whether it is pushed or not. The first loop is saying if
  //my boolean variable is true, turn the servo 100 degrees, and then switch my
  //variable to false. When the button is pressed again, the code will go into
  //the else statement, which turns it back to 20 degrees, which is where I 
  //started. This was, I can toggle between the two states. 
  if (State == LOW){
    if(turn){
      safecrackingServo.write(100);
      turn = !turn;
    }
    else{
      safecrackingServo.write(20);
      turn = !turn;
    }
  }
  delay(1000);//initially I didn't have a delay, and I wasn't sure why I 
  //couldn't get the code to work, but I think it has to do with the type
  //of button I am using, and I had to give time to release the button?
  //That's the best guess for why I needed a delay for the code to work.
}
