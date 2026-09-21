// ACLAB_RTOS_Day1&2_Challenge

#define Onboard_led 2
#define Led 4
#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>

// Arduino SDK
//  void setup(){
//      pinMode(Onboard_led, OUTPUT);
//      pinMode(Led, OUTPUT);
//  }

// void loop() {
//     digitalWrite(Onboard_led, HIGH);
//     digitalWrite(Led, HIGH);
//     delay(500);

//     digitalWrite(Onboard_led, LOW);
//     digitalWrite(Led, LOW);
//     delay(500);
// }

// RTOS Arduino
//  void TaskBlinkonled(void *pvParameters){
//      while (1){
//          digitalWrite(Onboard_led, HIGH);
//          vTaskDelay(pdMS_TO_TICKS(500));
//          digitalWrite(Onboard_led, LOW);
//          vTaskDelay(pdMS_TO_TICKS(500));
//      }
//  }

// void TaskBlinkled(void *pvParameters){
//     while (1){
//         digitalWrite(Led, HIGH);
//         vTaskDelay(pdMS_TO_TICKS(500));
//         digitalWrite(Led, LOW);
//         vTaskDelay(pdMS_TO_TICKS(500));
//     }
// }

// void setup(){
//     pinMode(Onboard_led, OUTPUT);
//     pinMode(Led, OUTPUT);
//     xTaskCreate(
//         TaskBlinkonled,
//         "Blink Onboard Led",
//         2048,
//         NULL,
//         1,
//         NULL
//     );
//     xTaskCreate(
//         TaskBlinkled,
//         "Blink Led",
//         2048,
//         NULL,
//         1,
//         NULL
//     );
// }

// void loop(){}

// RTOS ESP IDF
void TaskBlinkonled(void *pvParameters)
{
    while (1)
    {
        gpio_set_level(GPIO_NUM_2, 1);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_set_level(GPIO_NUM_2, 0);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void TaskBlinkled(void *pvParameters)
{
    while (1)
    {
        gpio_set_level(GPIO_NUM_4, 1);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_set_level(GPIO_NUM_4, 0);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void app_main()
{
    gpio_reset_pin(GPIO_NUM_2);
    gpio_reset_pin(GPIO_NUM_4);

    gpio_set_direction(GPIO_NUM_2, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_NUM_4, GPIO_MODE_OUTPUT);

    xTaskCreate(
        TaskBlinkonled,
        "Blink Onboard Led",
        2048,
        NULL,
        1,
        NULL);

    xTaskCreate(
        TaskBlinkled,
        "Blink Led",
        2048,
        NULL,
        1,
        NULL);
}