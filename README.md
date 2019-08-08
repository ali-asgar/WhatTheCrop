# WhatTheCrop

WhatTheCrop repository contains source code for connecting your Arduino Uno with the DHT11 temperature and humidity sensor, 2 LDR and Capacitive Soil Moisture Sensor for Automatic monitoring system for TCS Farm. The repository makes use of customized dht library developed for this project.

In this IoT project we took temperature, humidity, soil moisture, and light sensors to capture real time data on gardens/farms and help users make data driven agriculture decisions. Data is loaded dynamically with AJAX calls to the server and displayed in a GUI that is simple and effective. Users are notified when moisture levels and temperature readings reach specified levels. There are separate small-scale garden and large-scale farm interfaces. The large-scale farm interface utilizes the HERE.com API for the map and markers for the sensor nodes. The small-scale garden is a responsive CSS grid that renders dynamically based off sensor readings.

## Setting up prerequisites
Clone this repository to your **/Documents/Arduino/libraries** folder.

### Hardware Requirements 
- [Arduino Uno](https://store.arduino.cc/usa/arduino-uno-rev3)
- [DHT11 Temperature and Humidity sensor](https://www.amazon.com/FTCBlock-Temperature-Humidity-Arduino-Raspberry/dp/B07HF7CQHQ)
- [LDR](https://www.amazon.com/Honbay-Photoresistor-Dependent-Resistor-Sensitive/dp/B07DHDQ8LN)
- [Capacitive Soil Moisture Sensor](https://www.amazon.com/Anmbest-Sensitivity-Corrosion-Resistant-Capacitive/dp/B07S8K2HLX)
- [Wifi Module ESP8266](https://www.amazon.com/Diymore-ESP8266-Wireless-Transceiver-Controller/dp/B078Y5VP28)
- A to B Cable
- Jumper Cables

### Software Requirements
- [Arduino IDE](https://www.arduino.cc/en/main/software)

The next goal is to create incoporate a database to save sensor data across a long period of time with the goal of visualizing data to better inform decisions. We also want to add further customization in crop selections, sensor parameter alerts, farm/garden size, and sensor node placement. It could also be a possibility to incorporate picture and video to visually track crop growth.

[Devpost](https://devpost.com/software/what-the-crop)

[Web Development](https://github.com/stonecyan/WhatTheCrop)

![picture1](https://user-images.githubusercontent.com/15716059/48079219-ebbc0500-e1b8-11e8-887e-e7a4984c14aa.png)

![picture1](https://user-images.githubusercontent.com/15716059/48079357-30e03700-e1b9-11e8-81d9-0383d53c86b2.png)
