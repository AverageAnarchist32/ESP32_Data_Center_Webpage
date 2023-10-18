# Data Center ESP32

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
This was a project born from a school assignment. This project is all about controlling a light remotely using a website. Here's how it works: We have a small computer called an ESP32 that can connect to the internet. It showcases different sensor values through a front-end html js served webpage. It takes data from several different sensors and displays them on a webpage. It also output a rick-roll (-_-) from a piezo buzzer and turns an LED on when the light sensor vlaue drops below a certain threshold. Showing the status of the LED as well.

thanks you for choosing this project


## Features:
- Web-server, WiFi based client manager and server HTML webpage
- Autotmatic dynamic webpage which updates values simultaneously 
- Automatic LED Change (on or off) and light sensor value readings displayed on webpage
- Integration with DHT sensor to provide real-time temperature and humidity readings.



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

Follow these steps to install and set up your project:

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

Now that you've installed the necessary software and uploaded the code to your ESP32, you can start using your project. Follow the instructions provided in the project documentation to interact with the LED and monitor the light sensor data.
- Multi-sensor programme which can display light sensor values from a room and turn the light on or off accordingly
- Also displays the temeprature and humidity within the same environment.


### References
Chat/s Title: Automated_LEDcontroller Project Setup
                "IOT LED Controller using ESP32 with Arduino and Node.js, including HTML frontend, serving files from a 'data' folder, and reading photoresistor values."
                Wire Photoresistor
Date: September 8, 2023
Description: This chat session covers the setup and documentation of the "Automated_LEDcontroller" project, including the project structure, installation guide, and README.md file generation.

ChatGPT. "ESP32 DHT-11 Sensor Wiring Diagram." OpenAI, 19 Sep. 2023, https://chat.openai.com/chatgpt/...

"Random Nerd Tutorials. (2023, September 2). ESP32 DHT11/DHT22 Temperature and Humidity Sensor with Arduino IDE. Retrieved from https://randomnerdtutorials.com/esp32-dht11-dht22-temperature-humidity-sensor-arduino-ide/"

"ESP32 IO. (2023, September 2). ESP32 Temperature and Humidity Sensor Tutorial. Retrieved from https://esp32io.com/tutorials/esp32-temperature-humidity-sensor/"

"ESP32 IO. (2023, September 3). ESP32 LED Blink Tutorial. Retrieved from https://esp32io.com/tutorials/esp32-led-blink#google_vignette"

"ESP32 IO. (2023, September 5). ESP32 Piezo Buzzer Tutorial. Retrieved from https://esp32io.com/tutorials/esp32-piezo-buzzer"

"Hibit.dev. (2023, September 14). Playing Popular Songs with Arduino and a Buzzer. Retrieved from https://www.hibit.dev/posts/62/playing-popular-songs-with-arduino-and-a-buzzer"
