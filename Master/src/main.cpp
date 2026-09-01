#include <Arduino.h>

#define LORA_RX 16
#define LORA_TX 17
#define LORA_AUX 18
#define LORA_M0  21
#define LORA_M1  19

HardwareSerial LoRaSerial(2);

void setup() {
    // PC Serial Monitor
    Serial.begin(9600);
    delay(2000);

    // LoRa control pins
    pinMode(LORA_AUX, INPUT);
    pinMode(LORA_M0, OUTPUT);
    pinMode(LORA_M1, OUTPUT);

    // LoRa Normal Mode: M0 = LOW, M1 = LOW
    digitalWrite(LORA_M0, LOW);
    digitalWrite(LORA_M1, LOW);

    // LoRa UART
    LoRaSerial.begin(9600, SERIAL_8N1, LORA_RX, LORA_TX);

    Serial.println("LORA MASTER STARTED");
}

void loop() {
    Serial.println("Sending: HELLO FROM MASTER");

    LoRaSerial.println("HELLO FROM MASTER");

    delay(3000);
}