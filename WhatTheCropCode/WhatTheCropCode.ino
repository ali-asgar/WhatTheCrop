/*
 * Project Name: What The Crop! (HACKNJIT)
 *
 * Program Name: WhatTheCropCode.ino
 * Author: Ali Asgar Tashrifwala
 * Created Date: 11/04/2018
 * 
 * Last Edited: 08/07/2019    By Ali Asgar Tashrifwala
 *               
 * Purpose of this file: To provide IoT solution to automate the farm and track sensor data
 * 
 */

#include <SoftwareSerial.h>     //Step 1: Setup Serial library for communication
#include "dht.h"                // dht library
SoftwareSerial esp8266(10,11);  // RX is digital pin 10 (connect to TX of other device)
                                // TX is digital pin 11 (connect to RX of other device)
dht DHT;                        // Object of class dht

int ldrValueOne, ldrValueTwo, moistureValue, countTrueCommand, countTimeCommand; 

void dhtFunction() {
    DHT.read11(A0); // Analog Pin A0 is connected to DHT11 sensor
    delay(50);
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);   // Humidity Value
    Serial.print("% \n");
    Serial.print("Current temperature = ");
    Serial.print(DHT.temperature);// Temperature Value
    Serial.println("C \n");
}

void ldrFunction() {
    ldrValueOne = analogRead(A1); // Analog Pin A1 is connected to LDR1
    delay(50);
    ldrValueTwo = analogRead(A2); // Analog Pin A2 is connected to LDR2
    delay(50);
    Serial.print("Current lightOne = ");
    Serial.print(ldrValueOne);
    Serial.print("Lux \n");
    Serial.print("Current lightTwo = ");
    Serial.print(ldrValueTwo);
    Serial.print("Lux \n");
}

void moistureFunction() {
    moistureValue = analogRead(A3); // Analog Pin A3 is connected to moisture
    delay(50);
    Serial.print("Current soil moisture = ");
    Serial.print(moistureValue);
    Serial.print(" m3 water/m3 soil \n");
}

String AP = "Ali";                  // Mobile Hotspot ID name
String PASS = "12345678";           // Mobile Hotspot Password
String API = "AR37FUEYFMWSVUYM";    // Thingspeak IoT dashboard API key
String HOST = "api.thingspeak.com"; 
String PORT = "80";

void wifiFunction() {
    String getData = "GET /update?api_key="+ API +"&field1="+String(DHT.temperature)+"&field2="+String(DHT.humidity)+"&field3="+String(ldrValueOne)+"&field4="+String(ldrValueTwo)+"&field5="+String(moistureValue); 
    sendCommand("AT+CIPMUX=1",5,"OK");
    sendCommand("AT+CIPSTART=0,\"TCP\",\""+ HOST +"\","+ PORT,15,"OK");
    sendCommand("AT+CIPSEND=0," +String(getData.length()+4),4,">");
    esp8266.println(getData);delay(1500);countTrueCommand++;
    sendCommand("AT+CIPCLOSE=0",5,"OK");
}

void sendCommand(String command, int maxTime, char readReplay[]) {
    bool found = false;
    Serial.print(countTrueCommand);
    Serial.print(". at command => ");
    Serial.print(command);
    Serial.print(" ");
    while(countTimeCommand < (maxTime*1)) {
        esp8266.println(command);//at+cipsend
        if(esp8266.find(readReplay)) { //ok
            found = true;
            break;
        } 
        countTimeCommand++;
    }
    if(found == true) {
        Serial.println("Pass");   // Command is PASS
        countTrueCommand++; 
    }
    if(found == false) {
        Serial.println("Fail");   // Command is FAIL
        countTrueCommand = 0;
    }
    countTimeCommand = 0;
    found = false;
 }
  
void setup() {
  Serial.begin(9600);
  esp8266.begin(115200);
  sendCommand("AT",5,"OK");
  sendCommand("AT+CWMODE=3",5,"OK");
  sendCommand("AT+CWJAP=\""+ AP +"\",\""+ PASS +"\"",20,"OK");
}
void loop() {
    dhtFunction();            // Receives and displays Temperature and Humidity values
    delay(1000);
    void ldrFunction();       // Receives and displays LDR 1 and LDR 2 values
    delay(1000);
    void moistureFunction();  // Receives and displays Moisture Sensor values
    delay(1000);
    wifiFunction();           // Sends the sensor values to Thingspeak IoT dashboard
    delay(1000);
}

// End of the program
