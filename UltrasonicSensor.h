class UltrasonicSensor
{
public:
    UltrasonicSensor(int, int);
    float getReading();
private:
    int trigPin;
    ing echoPin;
};