#include "Arduino.h"
#include "ServoTask.h"

ServoTask::ServoTask(int pinServo){
    this->myservo = new Servo(pinServo);
}
  
void ServoTask::init(int period){
    Task::init(period);
    this->gate = DOWN;
}
  
void ServoTask::tick(){
    switch (gate){
    case DOWN:
        myservo->setRotationDeg(UP);// sets the servo position according to the scaled value
        Serial.println(UP);
        delay(15);
        gate = UP;
        break;

    case UP:
        myservo->setRotationDeg(DOWN);// sets the servo position according to the scaled value
        Serial.println(DOWN);
        delay(15);
        gate = DOWN;
        break;
    }
}