#include <Arduino.h>
#include <ESP8266WiFi.h>
/*************************************************
 *  Основные функции 
 ************************************************/

// Параметры подключения к WiFi
const char* wifiSSID = "TP-LINK_7C62CE";
const char* wifiPASS = "54601666";


void setup() {
 // Настройка COM - порта
 Serial.begin(9600);
 Serial.println();
 Serial.println("Demo project FOR ESP8266");

 //Настраиваем подключение к WiFi
 WiFi.mode(WIFI_STA);
 WiFi.begin(wifiSSID, wifiPASS);

 // Ждем пока подключение не будет установлено
 Serial.print("Connecting to WiFi AP");
 Serial.print(wifiSSID);
 Serial.print("");
 while (WiFi.status() != WL_CONNECTED)
 {
  Serial.print(".");
  delay(500);
 }
 
 // Подключение успешноустановлено
 Serial.println(" ок");
 Serial.print("WiFi connected, obtained IP address: ");
 Serial.println(WiFi.localIP());
}

void loop() {
  if (WiFi.isConnected()) {
    Serial.println("WiFi connection available");
  } else {
    Serial.println("WiFi connection not available");
  };
  delay(10000);
}