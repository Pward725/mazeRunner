#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(int trigPin, int echoPin)
{
    trigPin = trigPin;
    echoPin = echoPin;
}

float UltrasonicSensor::getReading()
{

      unsigned long t1;
      unsigned long t2;
      unsigned long pulse_width; 
      
      //trigger the sensor by setting it to one for 10 us
      digitalWrite leftTrig, HIGH);
      delayMicroseconds(10);
      digitalWrite leftTrig, LOW);
    
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

