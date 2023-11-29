#include <Arduino.h>
#include "State.h"
#include "PinConfig.h"
#include "Scheduler.h"
#include "TaskConfig.h"
#include "tasks/StartupTask.h"
#include "tasks/CheckInTask.h"
#include "tasks/OpenGateTask.h"
#include "tasks/WashingTask.h"
#include "tasks/EmergencyTask.h"
#include "tasks/CheckoutTask.h"
#include "components/PIR.h"
#include "components/SimpleLCD.h"
#include "components/SerialPC/SerialPC.h"
#include "components/Motors/Servo/Servo.h"
#include "components/Motors/Servo/Gate/Gate.h"

Scheduler sched;
State currentState;

// put function declarations here:
void awake();

void setup() {
  // put your setup code here, to run once:
  currentState = SLEEPING;
  attachInterrupt(INT_PIN, awake, RISING);

  Sonar *sonar = new Sonar(PIN_TRIG, PIN_ECHO, true);
  PIR *pir = new PIR(PIN_PIR, true);
  Gate *gate = new Gate(PIN_GATE_P, PIN_GATE_N, PIN_GATE_PWM, true, 0, 90);
  SimpleLCD *lcd = new SimpleLCD("sooos");

  Task *startUp = new StartupTask(STARTUP_PERIOD, &currentState, pir, NULL);
  Task *checkIn = new CheckinTask(CHECKIN_PERIOD, &currentState, pir, NULL);
  Task *openGate = new OpenGateTask(OPEN_PERIOD, &currentState, sonar, pir, gate, NULL);
  Task *washing = new WashingTask(WASH_PERIOD, &currentState, NULL, NULL, NULL);
  Task *emergency = new EmergencyTask(EMERGENCY_PERIOD, &currentState, lcd, NULL, NULL);
  Task *checkOut = new CheckoutTask(CHECKOUT_PERIOD, &currentState, sonar, pir, gate);

  sched.addTask(startUp);
  sched.addTask(checkIn);
  sched.addTask(openGate);
  sched.addTask(washing);
  sched.addTask(emergency);
  sched.addTask(checkOut);
}

void loop() {
	sched.schedule();
}

// put function definitions here:
void awake() {
  currentState = AWAKE;
}
