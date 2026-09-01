# ESP32 LoRa Master-Slave Communication

A point-to-point wireless communication project using two ESP32 boards and LoRa UART modules. The project implements a Master-Slave architecture where one ESP32 transmits data wirelessly and another ESP32 receives and displays the data.

---

## 📌 Overview

This project demonstrates long-range wireless communication between two ESP32 nodes using LoRa UART modules.

The system consists of two nodes:

- **Master Node:** Sends messages through the LoRa module.
- **Slave Node:** Receives the transmitted messages and displays them on the Serial Monitor.

The ESP32 communicates with the LoRa module through UART. The project was developed to gain practical experience with wireless communication, UART interfacing, ESP32 programming, and debugging embedded hardware communication issues.

---

## 🛠️ Tech Stack

### Hardware

- ESP32 Development Boards
- LoRa UART Modules
- Jumper Wires
- USB Cables

### Software

- PlatformIO
- VS Code
- Arduino Framework
- C++

### Tools

- Git
- GitHub

### Communication Technologies

- UART
- LoRa Wireless Communication

---

---

## ⚙️ Working Principle

The project uses two ESP32 nodes communicating wirelessly through LoRa modules.

### Master Node

1. Initializes the Serial Monitor for debugging.
2. Initializes UART communication with the LoRa module.
3. Configures the LoRa module in normal operating mode.
4. Sends a message to the LoRa module through UART.
5. The LoRa module transmits the message wirelessly.

### Slave Node

1. Initializes the Serial Monitor for debugging.
2. Initializes UART communication with the LoRa module.
3. Configures the LoRa module in normal operating mode.
4. Continuously checks for incoming data.
5. The LoRa module receives the wireless message.
6. The received data is transferred to the Slave ESP32 through UART.
7. The Slave ESP32 displays the received message on the Serial Monitor.

### Communication Flow

```text
Master ESP32
     │
     ▼
UART Communication
     │
     ▼
LoRa Module
     │
     ▼
Wireless Transmission
     │
     ▼
LoRa Module
     │
     ▼
UART Communication
     │
     ▼
Slave ESP32
```

---

## 🧪 Challenges Faced

### 1. Incorrect LoRa Communication Approach

Initially, an SPI-based LoRa library was used to initialize the LoRa module.

This resulted in initialization and module detection errors because the LoRa module used in this project communicates with the ESP32 through UART rather than SPI.

As a result, the system displayed errors such as:

```text
LoRa initialization FAILED!
LoRa module NOT detected!
```

### 2. Receiving Invalid `0x00` Data

After switching to UART communication, the Slave initially received repeated invalid data.

Example:

```text
DEC: 0   HEX: 0x00   CHAR: [NON-PRINTABLE]
```

Instead of receiving the expected message, repeated `0x00` values and non-printable characters were displayed.

### 3. UART Communication Configuration

Correct communication required proper UART configuration between the ESP32 and the LoRa module.

Incorrect communication settings resulted in invalid or corrupted data being received.

---

## 🔍 Debugging Approach

The issues were debugged systematically using the following approach:

- Checked the available pins on the LoRa module to identify its communication interface.
- Identified that the module uses UART communication instead of SPI.
- Removed the incorrect SPI-based communication approach.
- Used ESP32 UART2 with `HardwareSerial`.
- Verified the UART communication path between the ESP32 and LoRa module.
- Checked the Master and Slave UART configurations.
- Matched the communication settings on both nodes.
- Tested different baud rate configurations.
- Used the Serial Monitor to observe transmitted and received data.
- Printed received data in decimal and hexadecimal format to identify invalid `0x00` values.
- Monitored the AUX pin status to verify the LoRa module's operating state.
- Repeatedly tested communication after each configuration change.

This systematic debugging process helped identify and resolve the communication issues.

---

## 💻 UART Implementation

The ESP32 uses a hardware UART interface to communicate with the LoRa module.

The `HardwareSerial` class was used to create and configure UART2 for LoRa communication.

Example:

```cpp
HardwareSerial LoRaSerial(2);
```

The UART interface is initialized with matching communication settings:

```cpp
LoRaSerial.begin(115200, SERIAL_8N1, LORA_RX, LORA_TX);
```

This enables the ESP32 to send data to and receive data from the LoRa module.

---

## 📡 LoRa Operating Mode

The LoRa module is configured in normal operating mode for wireless data transmission and reception.

The mode control pins are configured before starting communication.

The Master and Slave operate with compatible communication settings to enable successful wireless data transfer.

---

## ✅ Outcome

Successful wireless communication was established between the Master and Slave ESP32 nodes.

The Master successfully transmitted messages through the LoRa module, and the Slave successfully received and displayed the messages.

### Example Output

```text
LORA SLAVE STARTED
Waiting for messages...

Received: HELLO FROM MASTER
Received: HELLO FROM MASTER
Received: HELLO FROM MASTER
```

The successful output confirmed that the complete communication path was working:

```text
ESP32 Master
     ↓
LoRa Module
     ↓
Wireless Communication
     ↓
LoRa Module
     ↓
ESP32 Slave
```

---

## 🎯 Key Learnings

Through this project, I gained practical experience in:

- ESP32 programming
- LoRa wireless communication
- UART communication
- HardwareSerial on ESP32
- Master-Slave architecture
- Wireless data transmission and reception
- Serial debugging
- GPIO and mode control
- Embedded hardware troubleshooting
- Debugging invalid UART data
- Identifying communication interfaces from hardware pins
- PlatformIO development
- Git and GitHub

---

## 🚀 Future Applications

This project can be extended into several real-world IoT and embedded applications.

### Agriculture

- Remote soil monitoring
- Smart irrigation systems
- Temperature and humidity monitoring
- Agricultural field sensor networks

### Industrial IoT

- Remote equipment monitoring
- Machine status monitoring
- Industrial sensor data transmission
- Predictive maintenance systems

### Smart Cities

- Environmental monitoring
- Air quality monitoring
- Water level monitoring
- Smart street infrastructure

### Automotive and Telemetry

- Vehicle telemetry
- Remote sensor monitoring
- Long-range data communication
- Vehicle status transmission

### Future Improvements

The project can be enhanced by adding:

- Real-time sensor data transmission
- Temperature and humidity sensors
- Air quality monitoring
- Bidirectional communication
- Acknowledgement messages
- Packet IDs
- Data validation
- Timestamps
- JSON formatted data
- Error detection
- Cloud connectivity
- IoT dashboard integration

---

This project is created for learning and educational purposes.
