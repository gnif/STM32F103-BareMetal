#include "stm32f103.h"

void gpio_setup(const uint32_t port, const uint8_t pin, const uint32_t cr_mode,
    const uint32_t cr_cnf)
{
  uint32_t shift = pin * 4;
  uint32_t * reg = (uint32_t * const)(GPIO_BASE + port);

  if (pin > 7)
  {
    ++reg;
    shift -= 32;
  }

  *reg = (*reg & ~(GPIO_CR_MODE | GPIO_CR_CNF) << shift) |
    (cr_mode | cr_cnf) << shift;
}

int main(void)
{
  RCC_APB2ENR |= RCC_APB2ENR_IOPCEN;
  gpio_setup(GPIOC, 13, GPIO_CR_MODE_OUT_2MHZ, GPIO_CR_CNF_OUT_PUSHPULL);

  for(int i = 0;; ++i)
  {
    if(i % 2)
      GPIOC_ODR |= (1 << 13);
    else
      GPIOC_ODR &= ~(1 << 13);

    for(int x = 0; x < 1000000; ++x) {}
  }
}
