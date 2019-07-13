# ESP8266-Amzon-Echo-Green-PCB-Relay

Module ESP8266 dengan Relay dan Digital input Terintegrasi dengan Amazon Echo (Alexa).

## Getting Started

Dibuat dengan Visual Studio Code dan PlatformIO
```
https://platformio.org/install
```
## Hardware

![alt text](https://raw.githubusercontent.com/AsyaSyarif/ESP8266-Amzon-Echo-Green-PCB-Relay-/master/img/image_layout.jpg)

## Programming
Hubungkan USB to Serial TTL ke Header P6
| First Header  | Second Header |
| ------------- | ------------- |
| Content Cell  | Content Cell  |
| Content Cell  | Content Cell  |

Pastikan anda mempunyai Usb to Serial TTL, dan patikan kondisi P3 ter-Jumper.
![alt text](https://raw.githubusercontent.com/AsyaSyarif/ESP8266-Amzon-Echo-Green-PCB-Relay-/master/img/programmer.jpg)
### Test Run
Cabut Jumper P3 dan restart ESP8266.
Buka Aplikasi Amazon Alexa lalu Add Devices dan search. 
