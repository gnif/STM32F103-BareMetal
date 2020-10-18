#ifndef _H_GPIO_
#define _H_GPIO_

#include <stdint.h>

#include "stm32f103.h"

void gpio_setup(const uint32_t port, const uint8_t pin, const uint32_t cr_mode,
    const uint32_t cr_cnf);

#define GPIO_PORT_WRITE(port, value) GPIOx_ODR(port) = ((value) & 0xFFFF)

#define GPIO_PIN_SET(port, pin) GPIOx_BSRR(port) |= (1 << (pin))
#define GPIO_PIN_CLR(port, pin) GPIOx_BSRR(port) |= (1 << ((pin) + 16))
#define GPIO_PIN_SET_GROUP(port, mask) \
  GPIOx_BSRR(port) |= (((mask) & 0xFFFF) <<  0)
#define GPIO_PIN_CLR_GROUP(port, mask) \
  GPIOx_BSRR(port) |= (((mask) & 0xFFFF) << 16)

#define GPIO_PIN_TOG(port, pin) \
  do \
  { \
    if (GPIOx_ODR(port) & (1 << (pin))) \
      GPIO_PIN_CLR(port, pin); \
    else \
      GPIO_PIN_SET(port, pin); \
  } \
  while(0)

#endif
