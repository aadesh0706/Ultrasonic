# Distance Display Project

This README provides instructions on how to set up and run a web-based distance display system using an ESP32 microcontroller and an ultrasonic sensor.

## Table of Contents

1. [Overview](#overview)
2. [Components Required](#components-required)
3. [Setup Instructions](#setup-instructions)
4. [Code Explanation](#code-explanation)
5. [How to Run the Project](#how-to-run-the-project)
6. [Troubleshooting](#troubleshooting)

---

## Overview

This project allows you to measure and display the distance measured by an ultrasonic sensor on a web page. The ESP32 microcontroller hosts a web server that responds to HTTP requests with the distance data.

---

## Components Required

- ESP32 Development Board
- HC-SR04 Ultrasonic Sensor
- USB cable for programming the ESP32
- Jumper wires
- Breadboard (optional)

---

## Setup Instructions

1. **Wiring the Ultrasonic Sensor:**
   - Connect the **VCC** pin of the HC-SR04 to the **5V** pin of the ESP32.
   - Connect the **GND** pin of the HC-SR04 to the **GND** pin of the ESP32.
   - Connect the **TRIG** pin of the HC-SR04 to GPIO **12** of the ESP32.
   - Connect the **ECHO** pin of the HC-SR04 to GPIO **14** of the ESP32.

2. **Install the Arduino IDE:**
   - Download and install the Arduino IDE from [Arduino's official website](https://www.arduino.cc/en/software).

3. **Install ESP32 Board Support:**
   - In Arduino IDE, go to **File** > **Preferences** and add the following URL to the "Additional Board Manager URLs" field:
     ```
     https://dl.espressif.com/dl/package_esp32_index.json
     ```
   - Then, go to **Tools** > **Board** > **Boards Manager**, search for "ESP32" and install it.

4. **Upload the Code:**
   - Open the Arduino IDE and create a new sketch.
   - Copy and paste the provided `.ino` code (see [Code Explanation](#code-explanation)).
   - Replace the `WiFi.begin("vivo", "Aadesh123");` line with your Wi-Fi SSID and password.
   - Connect the ESP32 to your computer and select the correct board and port in the Arduino IDE.
   - Click on the upload button to upload the code to the ESP32.

---

## Code Explanation

### HTML Code

The HTML code creates a simple web page that fetches and displays the distance from the ESP32 server.

- **Structure:**
  - A container to hold the title and distance display.
  - A button to refresh the distance.

- **JavaScript:**
  - Fetches the distance from the server at `http://192.168.189.217/distance`.
  - Automatically refreshes every 2 seconds.

### Arduino Code

The Arduino code does the following:

1. **Includes Libraries:**
   - Includes libraries for Wi-Fi connectivity and web server functionality.

2. **Defines Pins:**
   - `TRIG_PIN` is set to 12 and `ECHO_PIN` is set to 14.

3. **Setup Function:**
   - Initializes the serial communication.
   - Connects to the specified Wi-Fi network.
   - Sets up an HTTP route to handle distance requests.

4. **Loop Function:**
   - Continuously measures the distance and handles incoming client requests.
   - Sends the distance as a JSON response when a request is received.

---

## How to Run the Project

1. After uploading the code, open the Serial Monitor in the Arduino IDE.
2. Note the IP address assigned to your ESP32 (displayed in the Serial Monitor).
3. Open a web browser and enter the ESP32's IP address followed by `/distance`, e.g., `http://192.168.189.217/distance`.
4. The distance measured by the ultrasonic sensor will be displayed on the web page.

---

## Troubleshooting

- **ESP32 Not Connecting to Wi-Fi:**
  - Ensure that the SSID and password are correct.
  - Check the Wi-Fi signal strength and try to move the ESP32 closer to the router.

- **Distance Not Displaying:**
  - Verify that the ultrasonic sensor is correctly wired.
  - Ensure the ESP32 code is uploaded successfully.

- **Web Page Not Loading:**
  - Confirm the correct IP address is being used.
  - Make sure the ESP32 is connected to the same network as your computer.

---

Feel free to reach out if you have any questions or need further assistance!
