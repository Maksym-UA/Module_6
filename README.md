# ESP32-S3 Superloop and independent tasks

## Overview

Manage several independent processes in one loop() without blocks via ESP32.

Three leds on the board:

LED1 blinks every 200 ms
LED2 blinks every 500 ms
LED3 blinks every 1000 ms

## Hardware

| Component | Value / Details |
|---|---|
| MCU | ESP32-S3-DevKitC-1 |
| LED1 | Blue |
| LED2 | Yellow |
| LED3 | Red |


## Build, Upload, Monitor

Build:

```bash
pio run
```

Upload:

```bash
pio run -t upload
```

Serial monitor:

```bash
pio device monitor -b 115200
```

## Project Structure

```text
include/
  application.h

src/
  application.cpp
  CMakeLists.txt
  main.cpp

CMakeLists.txt
platformio.ini
sdkconfig.esp32-s3-devkitc-1
```

CONTACT
=======

Please send you feedback to
 max.savin3@gmail.com
