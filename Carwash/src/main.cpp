/**
 * Lorenzo Dalmonte   0001021552
 * Marco Francolini   0001021056
 * Leonardo Marcaccio 0001021005
*/

#include <Arduino.h>
#include "State.h"
#include "PinConfig.h"
#include "Scheduler.h"
#include "TaskConfig.h"
#include "tasks/SleepTask.h"
#include "tasks/StartupTask.h"
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
#include "components/Motors/Servo/SimpleServo.h"
#include "components/Motors/Servo/Gate/Gate.h"
#include "components/DigitalSensor.h"
#include "components/DistanceSensor.h"

Scheduler sched;
State currentState;

unsigned long checkInTime = 5000;
unsigned long washStart = 1000;
unsigned long emergencyStart = 1000;
unsigned long emergencyInterval = 0;

void setup() {
	Serial.begin(9600);
	currentState = AWAKE;

	Led *l1 = new Led(PIN_L1);
	Led *l2 = new Led(PIN_L2);
	Led *l3 = new Led(PIN_L3);
	Button *startButton = new Button(PIN_BUTTON_START);
	DistanceSensor *sonar = new DistanceSensor(PIN_ECHO, PIN_TRIG);
	PIR *pir = new PIR(PIN_PIR, true);
	Gate *gate = new Gate(PIN_GATE_PWM, -90, 90);
	SimpleLCD *lcd = new SimpleLCD(I2C_LCD_ADDR, I2C_LCD_ROWS, I2C_LCD_COLS);
	Thermometer *therm = new Thermometer(PIN_TEMPERATURE, true);
	SerialPC *console = new SerialPC();

	Task *sleep = new SleepTask(SLEEP_PERIOD, &currentState, PIN_PIR, l1, l2, l3);
	Task *startUp = new StartupTask(STARTUP_PERIOD, &currentState, pir, gate, l1, lcd, &checkInTime);
	Task *openGate = new OpenGateTask(OPEN_PERIOD, &currentState, sonar, gate, l2, lcd, &checkInTime);
	Task *ready = new ReadyTask(READY_PERIOD, &currentState, lcd, startButton, &washStart);
	Task *washing = new WashingTask(WASH_PERIOD, &currentState, therm, l2, lcd, console, &washStart, &emergencyStart, &emergencyInterval);
	Task *emergency = new EmergencyTask(EMERGENCY_PERIOD, &currentState, console, lcd, &emergencyStart, &emergencyInterval);
	Task *checkOut = new CheckoutTask(CHECKOUT_PERIOD, &currentState, sonar, gate, l2, l3, lcd, console);

	sched.init(1000);

	sched.addTask(sleep);
	sched.addTask(startUp);
	sched.addTask(openGate);
	sched.addTask(ready);
	sched.addTask(washing);
	sched.addTask(emergency);
	sched.addTask(checkOut);
}

void loop() {
	sched.schedule();
}
