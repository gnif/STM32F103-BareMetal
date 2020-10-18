#include "stm32f103.h"
#include "gpio.h"

int main(void)
{
  RCC_APB2ENR |= RCC_APB2ENR_IOPCEN;
  gpio_setup(GPIOC, 13, GPIO_CR_MODE_OUT_2MHZ, GPIO_CR_CNF_OUT_PUSHPULL);

  for(int i = 0;; ++i)
  {
    GPIO_PIN_TOG(GPIOC, 13);
    for(int x = 0; x < 1000000; ++x) {}
  }
}
