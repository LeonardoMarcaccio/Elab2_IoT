#include "Arduino.h"
#include "PingTask.h"

const float temperature = 20;
const float vs = 331.45 + 0.62*temperature;


PingTask::PingTask(int pinTrig, int pinEcho){
  this->pinTrig = pinTrig;
  this->pinEcho = pinEcho;
}
  
void PingTask::init(int period){
  Task::init(period);
}
  
void PingTask::tick(){

  digitalWrite(this->pinTrig,LOW);
  delayMicroseconds(3);
  digitalWrite(this->pinTrig,HIGH);
  delayMicroseconds(5);
  digitalWrite(this->pinTrig,LOW);
  
  /* Receiving the echo */

  float tUS = pulseIn(pinEcho, HIGH);
  float t = tUS / 1000.0 / 1000.0 / 2;
  float d = t*vs;
  
  Serial.println("Distanza: " + String(d));
}