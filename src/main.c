#include <stdlib.h>

#include "FreeRTOS.h"
#include "task.h"

volatile unsigned long  ulIdleCycleCounter = 0UL;

static void vDummyTask(void* pvParameters)
{
    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

void vApplicationIdleHook()
{
	/* Background task */
    ++ulIdleCycleCounter;
}

void vApplicationMallocFailedHook()
{
    /* Function called when pvPortMalloc failed to allocate memory. */
}

int main()
{
    xTaskCreate(vDummyTask, "DUMMY", configMINIMAL_STACK_SIZE, NULL,
            tskIDLE_PRIORITY + 2, NULL);

    vTaskStartScheduler();

    /* Should NEVER go here. */
    while (1);

    return 0;
}

