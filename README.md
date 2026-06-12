# ESP32-S3 Multitasking with FreeRTOS

## Overview

This project runs three independent LED blink tasks on ESP32-S3 using FreeRTOS.
Each LED has its own task and its own interval.

Three leds on the board:

LED1 blinks every 250 ms
LED2 blinks every 700 ms
LED3 blinks every 1300 ms

## Hardware

| Component | Value / Details |
|---|---|
| MCU | ESP32-S3-DevKitC-1 |
| LED1 | Red |
| LED2 | Blue |
| LED3 | Yellow |


## Build and run

Build firmware:

```bash
pio run
```

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
  led.h

src/
  application.cpp
  led.cpp
  main.cpp
  CMakeLists.txt

CMakeLists.txt
platformio.ini
sdkconfig.esp32-s3-devkitc-1
```

## Contact

Feedback: max.savin3@gmail.com
