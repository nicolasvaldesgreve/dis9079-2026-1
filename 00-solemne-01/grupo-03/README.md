# grupo-03

## integrantes

* Antonella Aguilar
* Tomás Catrileo
* Angel Sabogal

## descripción del proyecto

## materiales usados en solemne-01

- 1x Arduino UNO R4 WiFi
- 1x LED RGB
- 1x Protoboard
- 3x Resistencias 220Ω
- 4x Cables dupont (m-m)

## código usado con Adafruit IO

### código para enviar

### código base de biblioteca de Adafruit IO 

example: adafruitio_13_rgb

```cpp
// Adafruit IO RGB LED Output Example
// Tutorial Link: https://learn.adafruit.com/adafruit-io-basics-color
//
// Adafruit invests time and resources providing this open source code.
// Please support Adafruit and open source hardware by purchasing
// products from Adafruit!
//
// Written by Todd Treece for Adafruit Industries
// Copyright (c) 2016-2017 Adafruit Industries
// Licensed under the MIT license.
//
// All text above must be included in any redistribution.

/************************** Configuration ***********************************/

// edit the config.h tab and enter your Adafruit IO credentials
// and any additional configuration needed for WiFi, cellular,
// or ethernet clients.
#include "config.h"

/************************ Example Starts Here *******************************/

// default PWM pins for ESP8266.
// you should change these to match PWM pins on other platforms.
#define RED_PIN 4
#define GREEN_PIN 5
#define BLUE_PIN 2

// set up the 'color' feed
AdafruitIO_Feed *color = io.feed("color");

void setup() {

  // start the serial connection
  Serial.begin(115200);



  // wait for serial monitor to open
  while (!Serial)
    ;

#if defined(ARDUINO_ARCH_ESP32) // ESP32 pinMode
#if ESP_IDF_VERSION >= ESP_IDF_VERSION_VAL(5, 1, 1)
  // New ESP32 LEDC API
  ledcAttach(RED_PIN, 12000, 8); // 12 kHz PWM, 8-bit resolution
  ledcAttach(GREEN_PIN, 12000, 8);
  ledcAttach(BLUE_PIN, 12000, 8);
#else
  // Legacy ESP32 LEDC API
  ledcAttachPin(RED_PIN, 1);
  ledcAttachPin(GREEN_PIN, 2);
  ledcAttachPin(BLUE_PIN, 3);
  ledcSetup(1, 12000, 8);
  ledcSetup(2, 12000, 8);
  ledcSetup(3, 12000, 8);
#endif
#else
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
#endif

  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // set up a message handler for the 'color' feed.
  // the handleMessage function (defined below)
  // will be called whenever a message is
  // received from adafruit io.
  color->onMessage(handleMessage);

  // wait for a connection
  while (io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());
  color->get();

// set analogWrite range for ESP8266
#ifdef ESP8266
  analogWriteRange(255);
#endif
}

void loop() {

  // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  io.run();
}

// this function is called whenever a 'color' message
// is received from Adafruit IO. it was attached to
// the color feed in the setup() function above.
void handleMessage(AdafruitIO_Data *data) {

  // print RGB values and hex value
  Serial.println("Received:");
  Serial.print("  - R: ");
  Serial.println(data->toRed());
  Serial.print("  - G: ");
  Serial.println(data->toGreen());
  Serial.print("  - B: ");
  Serial.println(data->toBlue());
  Serial.print("  - HEX: ");
  Serial.println(data->value());

  // invert RGB values for common anode LEDs
  analogWrite(RED_PIN, 255 - data->toRed());
  analogWrite(GREEN_PIN, 255 - data->toGreen());
  analogWrite(BLUE_PIN, 255 - data->toBlue());
}

```
config.h

```cpp
/************************ Adafruit IO Config *******************************/

// visit io.adafruit.com if you need to create an account,
// or if you need your Adafruit IO key.
#define IO_USERNAME "udpmontoyamoraga"
#define IO_KEY "blabla"

#define WIFI_SSID "iPhone-Antonella"
#define WIFI_PASS "blabla"

// uncomment the following line if you are using airlift
// #define USE_AIRLIFT

// uncomment the following line if you are using winc1500
// #define USE_WINC1500

// uncomment the following line if you are using mrk1010 or nano 33 iot
// #define ARDUINO_SAMD_MKR1010

// comment out the following lines if you are using fona or ethernet
#include "AdafruitIO_WiFi.h"

#if defined(USE_AIRLIFT) || defined(ADAFRUIT_METRO_M4_AIRLIFT_LITE) ||         \
    defined(ADAFRUIT_PYPORTAL)
// Configure the pins used for the ESP32 connection
#if !defined(SPIWIFI_SS) // if the wifi definition isnt in the board variant
// Don't change the names of these #define's! they match the variant ones
#define SPIWIFI SPI
#define SPIWIFI_SS 10 // Chip select pin
#define NINA_ACK 9    // a.k.a BUSY or READY pin
#define NINA_RESETN 6 // Reset pin
#define NINA_GPIO0 -1 // Not connected
#endif
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS, SPIWIFI_SS,
                   NINA_ACK, NINA_RESETN, NINA_GPIO0, &SPIWIFI);
#else
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);
#endif

/**************************** ETHERNET ************************************/

// the AdafruitIO_Ethernet client will work with the following boards:
//   - Ethernet FeatherWing -> https://www.adafruit.com/products/3201

// uncomment the following two lines for ethernet,
// and comment out the AdafruitIO_WiFi client in the WIFI section
// #include "AdafruitIO_Ethernet.h"
// AdafruitIO_Ethernet io(IO_USERNAME, IO_KEY);
```

### código para recibir

```cpp
// rellenar
```

## imágenes

![led a tiempo real](./imagenes/ledenclase.gif)

## investigaciones individuales

rellenar en el mismo orden que los integrantes del grupo

[persona-01.md](./persona-01.md)
[persona-02.md](./persona-02.md)
[persona-03.md](./persona-03.md)

## bibliografía

Adafruit. (s. f.). Adafruit IO. https://io.adafruit.com/

Surbyte. (2017). Arduino Forum. https://forum.arduino.cc/t/solucionado-ayuda-monitor-serial-con-caracteres-ilegibles/473044/5

MK Electrónica. (s. f.). Aprende a utilizar la plataforma Adafruit IO para tus dispositivos IoT. https://mkelectronica.com/aprende-a-utilizar-la-plataforma-adafruit-io-para-tus-dispositivos-iot-parte-1/

Adafruit. (s. f.). Adafruit IO Basics: Color. Adafruit Learning System. https://learn.adafruit.com/adafruit-io-basics-color
