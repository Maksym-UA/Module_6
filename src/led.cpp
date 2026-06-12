#include "led.h"

namespace {

void ledTask(void* parameter) {
    // Cast the parameter to our TaskConfig structure
    const led::TaskConfig* cfg = static_cast<const led::TaskConfig*>(parameter);
    bool state = false;

    for (;;) {
        state = !state;
        digitalWrite(cfg->pin, state ? HIGH : LOW);
        vTaskDelay(pdMS_TO_TICKS(cfg->intervalMs));
    }
}

}  // namespace

namespace led {

    void startTasks(const TaskConfig* configs, size_t count) {
        for (size_t i = 0; i < count; ++i) {
            const TaskConfig& cfg = configs[i];

            pinMode(cfg.pin, OUTPUT);

            // Create the FreeRTOS task for this LED
            BaseType_t ok = xTaskCreatePinnedToCore(
            ledTask, // Task function
            cfg.taskName, // Task name
            cfg.stackWords, // Stack size in words
            (void*)&cfg, // Parameter to pass to the task
            cfg.priority, // Task priority
            nullptr, // Task handle (not used)
            cfg.core // Core to run the task on
            );

            if (ok != pdPASS) {
                Serial.print("Failed to create task: ");
                Serial.println(cfg.taskName);
            }
        }
    }
}  // namespace led
