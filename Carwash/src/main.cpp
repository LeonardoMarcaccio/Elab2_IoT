#include <Arduino.h>
#include "State.h"
#include "PinConfig.h"
#include "Scheduler.h"
#include "TaskConfig.h"
#include "tasks/StartupTask.h"
#include "tasks/CheckInTask.h"
#include "tasks/OpenGateTask.h"
#include "tasks/ReadyTask.h"
#include "tasks/WashingTask.h"
#include "tasks/EmergencyTask.h"
#include "tasks/CheckoutTask.h"
#include "components/Led.h"
#include "components/Button.h"
#include "components/PIR.h"
#include "components/SimpleLCD.h"
#include "components/Thermometer.h"
#include "components/SerialPC/SerialPC.h"
#include "components/Motors/Servo/Servo.h"
#include "components/Motors/Servo/Gate/Gate.h"
#define DEBUG
#ifndef DEBUG
Scheduler sched;
State currentState;

// put function declarations here:
void awake();

void setup() {
	// put your setup code here, to run once:
	currentState = SLEEPING;
	attachInterrupt(INT_PIN, awake, RISING);

	Led *l1 = new Led(PIN_L1);
	Led *l2 = new Led(PIN_L2);
	Led *l3 = new Led(PIN_L3);
	Button *startButton = new Button(PIN_BUTTON_START);
	Button *emergButton = new Button(PIN_BUTTON_EMERGENCY);
	Sonar *sonar = new Sonar(PIN_TRIG, PIN_ECHO, true);
	PIR *pir = new PIR(PIN_PIR, true);
	Gate *gate = new Gate(PIN_GATE_P, PIN_GATE_N, PIN_GATE_PWM, true, 0, 90);
	SimpleLCD *lcd = new SimpleLCD(0x27, 4, 20);
	Thermometer *therm = new Thermometer(PIN_TEMPERATURE, true);

	Task *startUp = new StartupTask(STARTUP_PERIOD, &currentState, pir, l1, lcd, NULL);
	Task *checkIn = new CheckinTask(CHECKIN_PERIOD, &currentState, pir, NULL);
	Task *openGate = new OpenGateTask(OPEN_PERIOD, &currentState, sonar, pir, gate, l2, lcd);
	Task *ready = new ReadyTask(READY_PERIOD, &currentState, lcd, startButton, NULL);
	Task *washing = new WashingTask(WASH_PERIOD, &currentState, therm, NULL, NULL, NULL);
	Task *emergency = new EmergencyTask(EMERGENCY_PERIOD, &currentState, lcd, emergButton, NULL, NULL);
	Task *checkOut = new CheckoutTask(CHECKOUT_PERIOD, &currentState, sonar, pir, gate, l2, l3, lcd);

	sched.addTask(startUp);
	sched.addTask(checkIn);
	sched.addTask(openGate);
	sched.addTask(ready);
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
#endif

#ifdef DEBUG
/**
* Source code:
* https://www.italiantechproject.it/tutorial-arduino/interfaccia-i2c-per-display-lcd
*/
#include <LiquidCrystal_I2C.h>
SimpleLCD *lcd;
 
void setup(){
	lcd = new SimpleLCD(0x27, 20, 4);
}

void loop(){
	lcd->setDisplayText("Si nil mondo ci fosse un po di bene e ognun si considerasse suo frahello, ci sarebbe meno male e meno pene");
}

#endif
