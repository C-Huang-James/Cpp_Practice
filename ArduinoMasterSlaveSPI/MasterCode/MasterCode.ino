#include <SPI.h>

enum State { STATE_IDLE, STATE_DECODE, STATE_SCOPE };
enum Scope_State {SCOPE_RUN, SCOPE_STOP};
State currentState = STATE_IDLE;
Scope_State scopeState = SCOPE_STOP;

const int SLAVE_SELECT = 10;
unsigned long lastTransmitTime = 0;
const unsigned long transmitInterval = 500;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  pinMode(SLAVE_SELECT, OUTPUT);
  digitalWrite(SLAVE_SELECT, HIGH);
}

void loop() {
  char input = '0';
  if (Serial.available()) {
    input = Serial.read();}
  if (input == '\r' || input == '\n') return;

  if (input-'0' > 0){
     currentState = STATE_DECODE;
    }
  else if (scopeState != SCOPE_RUN){
    currentState = STATE_IDLE;
  }
  else{
    currentState = STATE_SCOPE;
  }

  switch (currentState){
    case STATE_IDLE:
    {
      break;
    }
    case STATE_DECODE:
    {
      if (input >= '1' && input <= '5') 
      {
        handleSTATE_DECODE(input - '0');
      } 
      else if (input == '6') 
      {
        Serial.println("STATE_SCOPE Start!");
        currentState = STATE_SCOPE;
        scopeState = SCOPE_RUN;
        sendCommand(6);
      } 
      else if (input == '7') 
      {
        Serial.println("STATE_SCOPE Stop!");
        currentState = STATE_IDLE;
        scopeState = SCOPE_STOP;
        sendCommand(7);
      }
      break;
    }
    case STATE_SCOPE:
    {
      if (millis() - lastTransmitTime >= transmitInterval) 
      {
        Serial.println(millis() - lastTransmitTime);
        lastTransmitTime = millis();
        readSTATE_SCOPEData();
      }
      break;
    }
  }
  delay(50);
}

void handleSTATE_DECODE(uint8_t command) {
  sendCommand(command);
  delay(10);  // Give slave time to respond
  uint8_t value = receiveData();
  Serial.print("Register ");
  Serial.print(command);
  Serial.print(": ");
  Serial.println(value);
}

uint8_t sendCommand(uint8_t command) {
  digitalWrite(SLAVE_SELECT, LOW);
  delayMicroseconds(10); // small delay
  uint8_t val = SPI.transfer(command);
  delayMicroseconds(10);
  digitalWrite(SLAVE_SELECT, HIGH);
  return val;
}


uint8_t receiveData() {
  digitalWrite(SLAVE_SELECT, LOW);
  delayMicroseconds(10);
  uint8_t val = SPI.transfer(0x00);
  delayMicroseconds(10);
  digitalWrite(SLAVE_SELECT, HIGH);
  return val;
}

void readSTATE_SCOPEData() {
  digitalWrite(SLAVE_SELECT, LOW);
  for (int i = 0; i < 5; i++) {
    SPI.transfer(0xFF);  // Dummy command to prompt data send
    delayMicroseconds(10);
    uint8_t val = SPI.transfer(0x00);
    Serial.print(val);
    Serial.print(" ");
  }
  Serial.println();
  digitalWrite(SLAVE_SELECT, HIGH);
}
