#include "stm32f103.h"

__attribute__((naked)) int __main(void)
{
  while(1) {}
}

int main(void) __attribute__ ((weak, alias ("__main")));

__attribute__((naked)) void Reset_Handler()
{
  extern unsigned int __bss_start__;
  extern unsigned int __bss_end__;
  extern unsigned int _sidata;
  extern unsigned int _sdata;
  extern unsigned int _edata;

  unsigned int * dst = &__bss_start__;
  unsigned int * end = &__bss_end__;

  /* zero BSS */
  while(dst < end)
  {
    *dst = 0x0;
    ++dst;
  }

  unsigned int * src = &_sidata;
  dst = &_sdata;
  end = &_edata;

  /* copy data */
  while(dst < end)
  {
    *dst = *src;
    ++dst; ++src;
  }

  /* turn on the high speed external oscillator and wait for it */
  RCC_CR |= RCC_CR_HSEON;
  while((RCC_CR & RCC_CR_HSERDY) == 0) {}

  /* switch to the HSE clock and wait for it */
  SET_REG(RCC_CFGR, RCC_CFGR_SW, RCC_CFGR_SW_HSE);
  while((RCC_CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSE) {}

  /* disable the HSI to save power */
  SET_REG(RCC_CR, RCC_CR_HSION, 0);

  /* at 72MHz we need to set the read latency to two cycles, we also do not need
   * to worry about prefetch as we are not dividing the AHB */
  SET_REG(
      FLASH_ACR,
      FLASH_ACR_LATENCY   | FLASH_HLFCYA | FLASH_PRFTBE,
      FLASH_ACR_LATENCY_2 | 0            | 0
  );

  /*
   * configure the PLL with:
   * PLL    = HSE
   * SYSCLK = 72MHz
   * APB1   = 36MHz
   * APB2   = 72MHz
   * ADC    = 12MHz
   * USB    = 48MHz
   */
  SET_REG
  (
    RCC_CFGR,

    RCC_CFGR_PLLXTPRE |
    RCC_CFGR_PLLSRC   |
    RCC_CFGR_PLLMUL   |
    RCC_CFGR_PPRE1    |
    RCC_CFGR_PPRE2    |
    RCC_CFGR_HPRE     |
    RCC_CFGR_ADCPRE   |
    RCC_CFGR_USBPRE,

    0                       |
    RCC_CFGR_PLLSRC_HSE     |
    RCC_CFGR_PLLMUL_MUL_9   |
    RCC_CFGR_PPRE1_DIV_2    |
    RCC_CFGR_PPRE2_DIV_1    |
    RCC_CFGR_HPRE_DIV_1     |
    RCC_CFGR_ADCPRE_DIV_6   |
    RCC_CFGR_USBPRE_DIV_1_5
  );

  /* turn on the PLL oscillator and wait for it */
  RCC_CR |= RCC_CR_PLLON;
  while((RCC_CR & RCC_CR_PLLRDY) == 0) {}

  /* switch to the PLL clock and wait for it */
  SET_REG(RCC_CFGR, RCC_CFGR_SW, RCC_CFGR_SW_PLL);
  while((RCC_CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL) {}

  /* jump to `main` to avoid adding our return address to the stack as `main`
   * should never return anyway */
  __asm("b %0" : : "i"(&main));
}
