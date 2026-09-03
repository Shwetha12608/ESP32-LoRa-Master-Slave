#include "LoRa_E32.h"

// AUX=15, M0=21, M1=19
LoRa_E32 e32ttl(&Serial2, 15, 21, 19);

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, 27, 26); // RX=27, TX=26
  e32ttl.begin();
  delay(500);

  ResponseStructContainer c = e32ttl.getConfiguration();
  Serial.println("getConfiguration code: " + c.status.getResponseDescription());
  if (c.status.code != E32_SUCCESS) {
    Serial.println("Config read FAILED — stopping here.");
    while (true) { delay(1000); }
  }

  Configuration config = *(Configuration*) c.data;
  config.ADDL = 0x02;
  config.ADDH = 0x00;
  config.CHAN = 0x17;
  config.OPTION.transmissionPower = POWER_20; // = 30dBm on 900T30D
  config.SPED.uartBaudRate = UART_BPS_9600;
  config.SPED.airDataRate = AIR_DATA_RATE_010_24;
  ResponseStatus rs = e32ttl.setConfiguration(config, WRITE_CFG_PWR_DWN_SAVE);
  Serial.println("setConfiguration code: " + rs.getResponseDescription());
  c.close();

  Serial.println("Master ready");
}

void loop() {
  ResponseStatus rs = e32ttl.sendFixedMessage(0x00, 0x01, 0x17, "Hello");
  Serial.println("Sent: Hello | " + rs.getResponseDescription());
  delay(2000);
}
