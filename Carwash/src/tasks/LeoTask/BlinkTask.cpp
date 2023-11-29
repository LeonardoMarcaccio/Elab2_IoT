#include "Arduino.h"
#include "BlinkTask.h"

BlinkTask::BlinkTask(int pin){
  this->pin = pin;    
}
  
void BlinkTask::init(int period){
  Task::init(period); 
  state = OFF;    
}
  
void BlinkTask::tick(){
  switch (state){
    case OFF:
      digitalWrite(this->pin, HIGH);
      state = ON; 
      break;
    case ON:
      digitalWrite(this->pin, LOW);
      state = OFF;
      break;
  }
}