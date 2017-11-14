/* Written by Philip Ward and Alex Mathews. This is a maze solving robot that is able to 
calculate the fastest way through a maze after an intitial mapping run*/
#include "SR04.h"//Library for the ultrasonic sensors

// Define which ways the motors are going to turn
#define FORWARD  0
#define REVERSE 1

// Motor definitions to make life easier
#define MOTOR_A 0
#define MOTOR_B 1

//Pins to control the motors
#define DIRA 2 // Direction control for motor A
#define PWMA 3  // PWM control (speed) for motor A
#define DIRB 4 // Direction control for motor B
#define PWMB 11 // PWM control (speed) for motor B


void setup() {
  // All pins should be setup as outputs
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);

  // Initialize all pins as low:
  digitalWrite(PWMA, LOW);
  digitalWrite(PWMB, LOW);
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, LOW);
}

//minimum distance before action is needed (e.g. turn left)
int tolerance = 5;
int center = 5;// minimum difference between left and right sides

void loop() {

  //get the distances of each sensor
  //int front = getFrontSensor();
  //int right = getRightSensor();
  //int left = getLeftSensor();

  //if(front < tolerance)
   {
      //turnLeft();
      //return; //keep turning left until able to go straight
   }

   //driveForward();
  

  
}












