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
//#define DEBUG
#ifndef DEBUG

Scheduler sched;
State currentState;
unsigned long startTime = 0;

// put function declarations here:
void awake();

void setup() {
	Serial.begin(9600);
	Serial.println("Cacca");
	Serial.flush();
	//delay(5000);
	// put your setup code here, to run once:
	currentState = OPEN_GATE;
	attachInterrupt(INT_PIN, awake, RISING);

	//Led *l1 = new Led(PIN_L1);
	Led *l2 = new Led(PIN_L2);
	//Led *l3 = new Led(PIN_L3);
	//Button *startButton = new Button(PIN_BUTTON_START);
	//Button *emergButton = new Button(PIN_BUTTON_EMERGENCY);
	Sonar *sonar = new Sonar(PIN_TRIG, PIN_ECHO, true);
	PIR *pir = new PIR(PIN_PIR, true);
	Gate *gate = new Gate(PIN_GATE_P, PIN_GATE_N, PIN_GATE_PWM, true, 0, 90);
	SimpleLCD *lcd = new SimpleLCD(I2C_LCD_ADDR, I2C_LCD_ROWS, I2C_LCD_COLS);
	//Thermometer *therm = new Thermometer(PIN_TEMPERATURE, true);

	unsigned long checkInTime = 5000;

	//Task *startUp = new StartupTask(STARTUP_PERIOD, &currentState, pir, l1, lcd, NULL);
	//Task *checkIn = new CheckinTask(CHECKIN_PERIOD, &currentState, pir, &checkInTime);
	Task *openGate = new OpenGateTask(OPEN_PERIOD, &currentState, sonar, pir, gate, l2, lcd);
	//Task *ready = new ReadyTask(READY_PERIOD, &currentState, lcd, startButton, NULL);
	//Task *washing = new WashingTask(WASH_PERIOD, &currentState, therm, NULL, NULL, NULL);
	//Task *emergency = new EmergencyTask(EMERGENCY_PERIOD, &currentState, lcd, emergButton, NULL, NULL);
	//Task *checkOut = new CheckoutTask(CHECKOUT_PERIOD, &currentState, sonar, pir, gate, l2, l3, lcd);
	
	sched.init(1000);

	/*
	sched.addTask(startUp);
	sched.addTask(checkIn);
	*/
	sched.addTask(openGate);
	/*
	sched.addTask(ready);
	sched.addTask(washing);
	sched.addTask(emergency);
	sched.addTask(checkOut);
	*/
}

void loop() {
	Serial.println("Gay+");
	Serial.flush();
	sched.schedule();
}

// put function definitions here:
void awake() {
	if (currentState == SLEEPING) {
		currentState = AWAKE;
	}
}
#endif

#ifdef DEBUG
/**
* Source code:
* https://www.italiantechproject.it/tutorial-arduino/interfaccia-i2c-per-display-lcd
*/
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "LoadingBar.h"
#include "StringUtil.h"

#define PIR_PIN 4
#define CALIBRATION_TIME_SEC 30

SimpleLCD *lcd;
LoadingBar* bar;

void setup(){
	
	/*lcd = new SimpleLCD(0x27, 4, 20);
	bar = new LoadingBar(0, 0, 100, 20);
	Serial.begin(9600);
	lcd->setDisplayText("Washing complete,   you can leave the area");
	delay(1500);
	lcd->clear();
	lcd->setDisplayText(bar->getLoadingBar());
	Serial.println(bar->getLoadingBar());
	Serial.println(bar->getPercentage());
	delay(1500);
	bar->setCurrentValue(25);
	Serial.println(bar->getPercentage());
	Serial.println(bar->getLoadingBar());
	lcd->setDisplayText(bar->getLoadingBar());
	delay(1500);
	Serial.println(StringUtil::centerString("Stringona", 20, "-"));
	lcd->setDisplayText(StringUtil::centerString("Stringona", 20, "-")+bar->getLoadingBar());
	delay(1500);
	lcd->setDisplayText("StringonaadadoanoidnStringonab");


	pinMode(PIR_PIN,INPUT);
	Serial.begin(9600);
	
	//give the sensor some time to calibrate
	Serial.print("Calibrating sensor... ");
	for(int i = 0; i < CALIBRATION_TIME_SEC; i++){
		Serial.print(".");
		delay(1000);
	}
	Serial.println(" done");
	Serial.println("PIR SENSOR READY.");
	delay(50);*/
}

void loop(){
	/*lcd->setDisplayText(bar->getLoadingBar());
	Serial.println(bar->getLoadingBar());
	delay(1500);
	bar->setCurrentValue(25);
	Serial.println(bar->getLoadingBar());
	lcd->setDisplayText(bar->getLoadingBar());*/

	/*int detected = digitalRead(PIR_PIN);
	if (detected == HIGH){
		Serial.println("detected!");  
	} else {
		Serial.println("la sbuma");
	}
	Serial.flush();
	delay(100);*/
}

#endif

