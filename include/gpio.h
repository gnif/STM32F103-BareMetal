#ifndef _H_GPIO_
#define _H_GPIO_

#include <stdint.h>

#include "stm32f103.h"

void gpio_setup(const uint32_t port, const uint8_t pin, const uint32_t cr_mode,
    const uint32_t cr_cnf);

#define GPIO_PIN_SET(port, pin) GPIOx_BSRR(port) |= (1 << pin)
#define GPIO_PIN_CLR(port, pin) GPIOx_BSRR(port) |= (1 << (pin + 16))
#define GPIO_PIN_TOG(port, pin) \
  do \
  { \
    if (GPIOx_ODR(port) & (1 << pin)) \
      GPIOx_BSRR(port) |= (1 << (pin + 16)); \
    else \
      GPIOx_BSRR(port) |= (1 << pin); \
  } \
  while(0)

#endif
