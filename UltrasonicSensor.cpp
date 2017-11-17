#include "UltrasonicSensor.h"
#include "Arduino.h"

UltrasonicSensor::UltrasonicSensor(int trigPin, int echoPin)
{
    trigPin = trigPin;
    echoPin = echoPin;
}

float UltrasonicSensor::getReading()
{

      unsigned long t1;
      unsigned long t2;
      float pulse_width; 
      
      //trigger the sensor by setting it to one for 10 us
      digitalWrite (trigPin, 1);
      delayMicroseconds(10);
      digitalWrite(trigPin, 0);
    
      // Wait for pulse on echo pin
      while ( digitalRead(echoPin) == 0 );
    
      // Measure how long the echo pin was held high (pulse width)
      // Note: the micros() counter will overflow after ~70 min
      t1 = micros();
      while ( digitalRead(echoPin) == 1);
      t2 = micros();
      pulse_width = t2 - t1;
      
    
      // Calculate distance in centimeters and inches. The constants
      // are found in the datasheet, and calculated from the assumed speed 
      //of sound in air at sea level (~340 m/s).
      return pulse_width / 58.0;

}

