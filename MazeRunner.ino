/* Written by Philip Ward and Alex Mathews. This is a maze solving robot that is able to 
calculate the fastest way through a maze after an intitial mapping run*/
#include "UltrasonicSensor.h"
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

const int leftTrig = 13;
const int leftEcho = 12;
const int frontTrig = 11;
const int frontEcho = 10;
const int rightTrig = 9;
const int rightEcho = 8;

UltrasonicSensor leftSensor(leftTrig, leftEcho);
float lastLeftDistance = leftSensor.getReading();
float newLeftDistance = leftSensor.getReading();
UltrasonicSensor rightSensor(rightTrig, rightEcho);
UltrasonicSensor frontSensor(frontTrig, frontEcho);

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

  
Serial.begin(9600);

}

//minimum distance before action is needed (e.g. turn left)
int tolerance = 20;
int center = 5;// minimum difference between left and right sides

void loop() {

//get new left distance
newLeftDistance = leftSensor.getReading();
Serial.println(newLeftDistance);
  //get the distances of each sensor
  if ((newLeftDistance - lastLeftDistance) > tolerance)
  {
   turnLeft();
   delay(500); 
  }

  //set this loops leftDistance to be the old left
   lastLeftDistance = newLeftDistance;
  driveForward();
  delay(1000);

  
}

void turnLeft()
{
  driveMotor(MOTOR_A, REVERSE, 255);
  driveMotor(MOTOR_B, FORWARD, 255);
  delay(450);
  stopMotor(MOTOR_A);  // STOP motor A
  stopMotor(MOTOR_B);  // STOP motor B
}

void driveForward()
{
  driveMotor(MOTOR_A, FORWARD, 255);
  driveMotor(MOTOR_B, FORWARD, 255);
  delay(100);//drive forward a bit before checking sensors again
}

// drives 'motor' in 'dir' direction at 'spd' speed
void driveMotor(byte motor, byte dir, byte spd)
{
  if (motor == MOTOR_A)
  {
    digitalWrite(DIRA, dir);
    analogWrite(PWMA, spd);
  }//PWMA is the pin for speed
  else if (motor == MOTOR_B)
  {
    digitalWrite(DIRB, dir);
    analogWrite(PWMB, spd);
  }//PWMB is the pin for speed
}

void stopMotor(byte motor)
{
  driveMotor(motor, 0, 0);
}













