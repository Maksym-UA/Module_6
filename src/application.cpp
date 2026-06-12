#include "application.h"
#include "led.h"

#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#if CONFIG_FREERTOS_UNICORE
#error "This code is designed to run on a dual-core ESP32. Disable unicore in sdkconfig."
#endif

namespace {

    struct Config {
        static constexpr uint8_t Led1 = 16;
        static constexpr uint8_t Led2 = 17;
        static constexpr uint8_t Led3 = 18;
        static constexpr uint32_t BaudRate = 115200;
        static constexpr BaseType_t TaskCore = 0;
    };

  
    static const led::TaskConfig kLedTasks[] = {
        {Config::Led1, 250, "Led1Task", Config::TaskCore, tskIDLE_PRIORITY + 1, 2048},
        {Config::Led2, 700, "Led2Task", Config::TaskCore, tskIDLE_PRIORITY + 1, 2048},
        {Config::Led3, 1300, "Led3Task", Config::TaskCore, tskIDLE_PRIORITY + 1, 2048}
    };

}

namespace app {

    void setup() {
        Serial.begin(Config::BaudRate);
        while (!Serial) {
        }

        Serial.println("Starting LED application...");
        led::startTasks(kLedTasks, sizeof(kLedTasks) / sizeof(kLedTasks[0]));
    }

    void loop() {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }

}