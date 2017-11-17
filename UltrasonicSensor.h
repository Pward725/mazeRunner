class UltrasonicSensor
{
public:
    UltrasonicSensor(int, int);
    float getReading();
private:
    int trigPin;
    int echoPin;
};
