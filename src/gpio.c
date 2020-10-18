#include "gpio.h"

void gpio_setup(const uint32_t port, const uint8_t pin, const uint32_t cr_mode,
    const uint32_t cr_cnf)
{
  uint32_t shift = pin * 4;
  uint32_t * reg = &GPIOx_CRL(port);

  if (pin > 7)
  {
    ++reg;
    shift -= 32;
  }

  *reg = (*reg & ~((GPIO_CR_MODE | GPIO_CR_CNF) << shift)) |
    (cr_mode | cr_cnf) << shift;
}
