#include <Arduino.h>
#include "Scheduler.h"

void Scheduler::init(int basePeriod){
  this->basePeriod = basePeriod;
  timer.setupPeriod(basePeriod);  
  nTasks = 0;
}

bool Scheduler::addTask(Task* task){
  if (nTasks < MAX_TASKS-1){
    taskList[nTasks] = task;
    nTasks++;
    return true;
  } else {
    return false; 
  }
}
  
void Scheduler::schedule(){
  timer.waitForNextTick();
  for (int i = 0; i < nTasks; i++){
    if (taskList[i]->updateAndCheckTime(basePeriod)){
      this->startTime = millis();
      taskList[i]->tick();
      /*while (this->startTime == millis()) {
        Serial.print("Odio il C");
        Serial.flush();
      }*/
      Serial.println(millis() - this->startTime);
      Serial.flush();
    }
  }
}
