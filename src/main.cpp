#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "WemoSwitch.h"
#include "WemoManager.h"
#include "CallbackFunction.h"

//ganti nama perangkat dengan nama yang anda ingingkan
#define NAMA_PERANGKAT "Table Lamp"
#define WIFI_SSID       "TerjebakRindu"
#define WIFI_PASSWORD   "11111111"
#define SERIAL_BAUDRATE 115200

//jika kamu pakai module seperti wemos / nodemcu gunakan D4,D5 
//atau jika menggunakan Generic ESP8266 cukup gunakan 4,5
#define relayPin 4 // Relay Pin pada GPIO 4
#define tmblPin  5 // Tombol Pin pada GPIO 5

int bacaBtn, relayState;
int lastTmblState = 1 ;
int wifiRetry = 0;

// Panggil object WemoManager
WemoManager myModule;
WemoSwitch *perangkat = NULL;

void nyala();
void padam();

void connectWifi(){
  WiFi.mode(WIFI_STA);
  Serial.printf("[WIFI] Menghubungkan Ke %s ", WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED){
    wifiRetry++;
    delay(1000);
    Serial.print(".");

    if(wifiRetry >= 10){
      ESP.restart();
    }
  }
  Serial.println(" ");
  Serial.printf("[WIFI] Terhubung ke SSID: %s, IP address: %s\n", WiFi.SSID().c_str(), WiFi.localIP().toString().c_str());

}

void setup() {
  Serial.begin(SERIAL_BAUDRATE);
  connectWifi();
  myModule.begin();
  perangkat = new WemoSwitch(NAMA_PERANGKAT, 80, nyala, padam);
  myModule.addDevice(*perangkat);
  pinMode(relayPin, OUTPUT);
  pinMode(tmblPin, INPUT_PULLUP);
}

void nyala(){
  relayState = HIGH;
}

void padam(){
  relayState = LOW;
}

void loop() {

 myModule.serverLoop();

 //toggle tombol on/off
 bacaBtn = digitalRead(tmblPin);
 if(bacaBtn != lastTmblState){
   if(bacaBtn == 1){
     if(relayState == 1)relayState = 0;
     else relayState = 1;
   }
   lastTmblState = bacaBtn;
 }

 digitalWrite(relayPin, relayState);
 delay(10);

//fungsi untuk "reconnect" ke wifi , jika terjadi "disconnect."
 if(WiFi.status() != WL_CONNECTED){
   Serial.printf("[WIFI] Terputus dari: %s\n", WiFi.SSID().c_str());
   connectWifi();
   delay(10);
 }

}