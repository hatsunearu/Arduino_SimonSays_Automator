#include <Servo.h>

int INPUTPINS[] = {2, 3, 4, 5}; //digital inputs corresponding to light detector output
int TIMEOUTDELAY = 1000;

int pattern[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //0 = no instruction, 1 = first input pin
Servo s1, s2; //servos to actuate buttons
int currPattern = 0; //index of current pattern
long prevMillis = 0;
boolean pushMode = false;

void setup() {
  for(int i=0; i<4; i++) {
    pinMode(INPUTPINS[i], INPUT_PULLUP); //has internal pullup resistor 
  }
  
  
}

void loop() {
  for(int i=0; i<4 || !pushMode; i++) {
    if( !(digitalRead(INPUTPINS[i]) == LOW) ) { //if pulled low by phototransistor
       pattern[currPattern] = i+1;
       currPattern++;
       prevMillis = millis();
    }
    if (millis() - prevMillis > TIMEOUTDELAY) {
      pushMode = true;
    }
  }
  
  if (pushMode) {
    for(int i=0; i<10 && pattern[i] != 0; i++) {
      pushButton(pattern[i] - 1);
      pushMode = false;
      currPattern = 0;
    }
  }
  

  
}
void pushButton(int n) {
  
}
