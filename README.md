# ESP8266-Amzon-Echo-Green-PCB-Relay

Module ESP8266 dengan Relay dan Digital input Terintegrasi dengan Amazon Echo (Alexa).

## Getting Started

Dibuat dengan Visual Studio Code dan PlatformIO
```
https://platformio.org/install
```
lalu clone repo ini

```
git clone https://github.com/AsyaSyarif/ESP8266-Amzon-Echo-Green-PCB-Relay-.git
```

## Hardware

![alt text](https://raw.githubusercontent.com/AsyaSyarif/ESP8266-Amzon-Echo-Green-PCB-Relay-/master/img/image_layout.jpg)

## Programming
### Port and Baudrate

Untuk setting port dan baudrate, buka file [platformio.ini](https://github.com/AsyaSyarif/ESP8266-Amzon-Echo-Green-PCB-Relay-/blob/master/platformio.ini), lalu sesuaikan dengan serialport anda.

Hubungkan USB to Serial TTL ke Header P6


| USB TO Serial TTL  | P6 Header |
| ------------- | ------------- |
| GND  | GND  |
| RX  | TX  |
| TX  | RX  |

dan jangan lupa kondisi Header P3 ter-Jumper.
Dan Upload.

![alt text](https://raw.githubusercontent.com/AsyaSyarif/ESP8266-Amzon-Echo-Green-PCB-Relay-/master/img/programmer.jpg)
### Test Run
Cabut Jumper P3 dan restart ESP8266.
Buka Aplikasi Amazon Alexa lalu Add Devices dan search. 

### Enclosure
https://www.thingiverse.com/thing:3760139
