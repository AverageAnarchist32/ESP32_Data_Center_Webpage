# Automated_LEDcontroller

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Customization](#customization)
- [Contributing](#contributing)

## Introduction

Briefly introduce your project. Explain what the project does, its purpose, and any key features.

## Features:
- Web-server, WiFi based client manager and server HTML webpage
- Autotmatic dynamic webpage which updates values simultaneously 
- Automatic LED Change (on or off) and light sensor value readings displayed on webpage


## Project Structure
- Automated_LEDcontroller/
  - esp32/
    - esp32_code.ino         # Your Arduino code for the ESP32
  - nodejs/
    - server.js              # Your Node.js server code
  - public/
    - index.html             # Your HTML file
  - README.md                # Documentation or README for your project

## Installation Guide

Follow these steps to install and set up your "Automated_LEDcontroller" project:

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

2. Navigate to the `nodejs/` directory of your project using the `cd` command:

3. Install the required Node.js packages by running the following commands:

### Usage

Now that you've installed the necessary software and uploaded the code to your ESP32, you can start using your "Automated_LEDcontroller" project. Follow the instructions provided in the project documentation to interact with the LED and monitor the light sensor data.


### References
Chat/s Title: Automated_LEDcontroller Project Setup
                "IOT LED Controller using ESP32 with Arduino and Node.js, including HTML frontend, serving files from a 'data' folder, and reading photoresistor values."
                Wire Photoresistor
Date: September 8, 2023
Description: This chat session covers the setup and documentation of the "Automated_LEDcontroller" project, including the project structure, installation guide, and README.md file generation.

