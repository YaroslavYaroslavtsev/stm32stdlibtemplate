#include "stm32f4xx.h"
#include "stdio.h"

int __io_putchar(int ch) {
    ITM_SendChar(ch);
    return ch;
}

int main(void) {
    SystemInit();
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    while (1) {
        GPIO_SetBits(GPIOC, GPIO_Pin_13);
        for(int i=0;i<10000000; i++){
            __asm("nop");
        }

        GPIO_ResetBits(GPIOC, GPIO_Pin_13);
        for(int i=0;i<10000000; i++){
            __asm("nop");
        }
        printf("Hello\n");
    }
}
