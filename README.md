# Data Center ESP32

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Arduino Setup](#arduino-setup)
  - [Node.js Setup](#nodejs-setup)
- [Usage](#usage)
- [References](#references)

## Introduction
The Data Center ESP32 project allows you to remotely control a light using a web interface. It utilizes an ESP32 microcontroller that connects to the internet and provides sensor data via a dynamic web page. In addition to displaying sensor values, the project includes a playful touch—a rick-roll from a piezo buzzer and automatic control of an LED based on the light sensor value.

Thank you for choosing this project!

## Features:
- Web-server with a WiFi-based client manager and an HTML webpage.
- Dynamic webpage that updates values in real-time.
- Automatic control of an LED (on or off) based on light sensor readings.
- Integration with a DHT sensor to provide real-time temperature and humidity data.

## Project Structure
- **Automated_LEDcontroller/**
  - **esp32/**
    - `esp32_code.ino` - Arduino code for the ESP32.
  - **nodejs/**
    - `server.js` - Node.js server code.
  - **public/**
    - `index.html` - HTML file for the web interface.
  - `README.md` - Documentation for the project (the file you're currently reading).

## Getting Started

### Prerequisites
Before you begin, make sure you have the following prerequisites:

1. **ESP32 Board**: You should have an ESP32 development board.

2. **Arduino IDE**: Install the Arduino Integrated Development Environment (IDE) on your computer if you haven't already. You can download it from the [Arduino website](https://www.arduino.cc/en/software).

3. **Node.js**: Install Node.js on your computer. You can download it from the [Node.js website](https://nodejs.org/).

### Arduino Setup

1. Open the Arduino IDE.

2. Connect your ESP32 board to your computer via USB.

3. In the Arduino IDE, select the appropriate board and port for your ESP32 under the "Tools" menu.

4. Open the `esp32_code.ino` file located in the `esp32/` directory of your project.

5. Click the "Upload" button in the Arduino IDE to upload the code to your ESP32 board.

### Node.js Setup

1. Open a terminal or command prompt.

2. Navigate to the `nodejs/` directory of your project using the `cd` command.

3. Install the required Node.js packages by running the following commands:

```shell
npm install express axios.

### Usage
Now that you've installed the necessary software and uploaded the code to your ESP32, you can start using your project. Follow the instructions provided in the project documentation to interact with the LED and monitor the light sensor data.

- Multi-sensor program that can display light sensor values from a room and turn the light on or off accordingly.
- Also displays the temperature and humidity within the same environment.

### References
- **Chat/s Title:** Automated_LEDcontroller Project Setup
  - "IOT LED Controller using ESP32 with Arduino and Node.js, including HTML frontend, serving files from a 'data' folder, and reading photoresistor values."
  - Date: September 8, 2023
  - Description: This chat session covers the setup and documentation of the "Automated_LEDcontroller" project, including the project structure, installation guide, and README.md file generation.

- [Random Nerd Tutorials](https://randomnerdtutorials.com/): ESP32 DHT11/DHT22 Temperature and Humidity Sensor with Arduino IDE.

- [ESP32 IO](https://esp32io.com/): ESP32 Temperature and Humidity Sensor Tutorial, ESP32 LED Blink Tutorial, and ESP32 Piezo Buzzer Tutorial.

- [Hibit.dev](https://www.hibit.dev/): Playing Popular Songs with Arduino and a Buzzer.

