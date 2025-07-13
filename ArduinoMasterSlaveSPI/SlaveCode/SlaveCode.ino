#include <SPI.h>

enum State { LISTEN, SCOPE };
State currentState = LISTEN;

volatile uint8_t command = 0;
volatile bool commandReady = false;
volatile uint8_t spiResponse = 0;
volatile uint8_t index = 0;
uint8_t registerData[6] = {11, 22, 33, 44, 55, 0};

void setup() {
  Serial.begin(9600);
  pinMode(MISO,OUTPUT);                   //Sets MISO as OUTPUT (Have to Send data to Master IN 
  SPCR = (1<<SPE) | (1<<SPIE);
  sei();
  SPI.attachInterrupt();
}

ISR(SPI_STC_vect) {
  uint8_t received = SPDR;
  command = received;
  commandReady = true;

  if (command >= 1 && command <= 5) {
    spiResponse = registerData[command - 1];
  } 
  else if (command == 6) {
    registerData[5] = 1;
    currentState = SCOPE;
    spiResponse = 0xAA;
  } 
  else if (command == 7) {
    registerData[5] = 0;
    currentState = LISTEN;
    spiResponse = 0x55;
  } 
  else if (command == 0xFF && currentState == SCOPE) {
    static uint8_t sendIndex = 0;
    spiResponse = registerData[sendIndex++];
    if (sendIndex >= 5) sendIndex = 0;
    index = sendIndex;
  } 
  else {
    spiResponse = 0x00;
  }
  SPDR = spiResponse;  // Load response for master
}

void loop() {
  if (commandReady) {
    commandReady = false;  // reset the flag
    Serial.print("SPI CMD: ");
    Serial.print(command);
    Serial.print(" → RESP: ");
    Serial.println(spiResponse);
  }

  // Optional: local Serial input debug for register view
  if (Serial.available()) {
    char input = Serial.read();
    if (input == '\r' || input == '\n') return;
    Serial.println(commandReady);
    int index = input - '1';
    if (index >= 0 && index < 6) {
      Serial.print("register[");
      Serial.print(index);
      Serial.print("] = ");
      Serial.println(registerData[index]);
    } else {
      Serial.println("Invalid input");
    }
  }
}
