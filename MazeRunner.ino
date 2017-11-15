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

  //set up the variable for distance calculation
  
unsigned long t1;
unsigned long t2;
unsigned long pulse_width;
unsigned long lastLeft = checkLeft();

}

//minimum distance before action is needed (e.g. turn left)
int tolerance = 5;
int center = 5;// minimum difference between left and right sides

void loop() {

//get new left distance
newLeft = checkLeft();
  //get the distances of each sensor
  if ((thisLeft - lastLeft) > tolerance)
  {
   turnLeft(); 
  }
  //int front = getFrontSensor();
  //int right = getRightSensor();
  //int left = getLeftSensor();

  //if(front < tolerance)
   {
      //turnLeft();
      //return; //keep turning left until able to go straight
   }

  //set this loops leftDistance to be the old left
   lastLeft = newLeft();
   //driveForward();
  

  
}

int checkLeft()
{
  unsigned long t1;
  unsigned long t2;
  unsigned long pulse_width; 
  
  //trigger the sensor by setting it to one for 10 us
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Wait for pulse on echo pin
  while ( digitalRead(ECHO_PIN) == 0 );

  // Measure how long the echo pin was held high (pulse width)
  // Note: the micros() counter will overflow after ~70 min
  t1 = micros();
  while ( digitalRead(ECHO_PIN) == 1);
  t2 = micros();
  pulse_width = t2 - t1;
  

  // Calculate distance in centimeters and inches. The constants
  // are found in the datasheet, and calculated from the assumed speed 
  //of sound in air at sea level (~340 m/s).
  return pulse_width / 58.0;
}












