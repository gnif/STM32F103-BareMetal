#ifndef _H_STM32F103_
#define _H_STM32F103_

#include <stdint.h>

#define PERIPH_BASE 0x40000000

#define REGISTER(name, addr) \
  uint32_t * const name = (uint32_t * const)(addr);

#define SET_REG(reg, mask, value) \
  (reg) = ((reg) & (mask)) | value

#define RCC_BASE   (PERIPH_BASE + 0x21000)
#define FLASH_BASE (PERIPH_BASE + 0x22000)
#define GPIO_BASE  (PERIPH_BASE + 0x10800)

#define RCC_CR       (*(uint32_t * const)(RCC_BASE   + 0x00))
#define RCC_CFGR     (*(uint32_t * const)(RCC_BASE   + 0x04))
#define RCC_CIR      (*(uint32_t * const)(RCC_BASE   + 0x08))
#define RCC_APB2RSTR (*(uint32_t * const)(RCC_BASE   + 0x0C))
#define RCC_APB1RSTR (*(uint32_t * const)(RCC_BASE   + 0x10))
#define RCC_AHBENR   (*(uint32_t * const)(RCC_BASE   + 0x14))
#define RCC_APB2ENR  (*(uint32_t * const)(RCC_BASE   + 0x18))
#define RCC_APB1ENR  (*(uint32_t * const)(RCC_BASE   + 0x1C))
#define RCC_BDCR     (*(uint32_t * const)(RCC_BASE   + 0x20))
#define RCC_CSR      (*(uint32_t * const)(RCC_BASE   + 0x24))

#define RCC_CR_HSION   0x00000001
#define RCC_CR_HSIRDY  0x00000002
#define RCC_CR_HSITRIM 0x00000078
#define RCC_CR_HSICAL  0x0000FF00
#define RCC_CR_HSEON   0x00010000
#define RCC_CR_HSERDY  0x00020000
#define RCC_CR_HSEBYP  0x00040000
#define RCC_CR_CSSON   0x00080000
#define RCC_CR_PLLON   0x01000000
#define RCC_CR_PLLRDY  0x02000000

#define RCC_CFGR_SW       0x0000003
#define RCC_CFGR_SWS      0x000000C
#define RCC_CFGR_HPRE     0x00000F0
#define RCC_CFGR_PPRE1    0x0000700
#define RCC_CFGR_PPRE2    0x0003800
#define RCC_CFGR_ADCPRE   0x000C000
#define RCC_CFGR_PLLSRC   0x0010000
#define RCC_CFGR_PLLXTPRE 0x0020000
#define RCC_CFGR_PLLMUL   0x03C0000
#define RCC_CFGR_USBPRE   0x0400000
#define RCC_CFGR_MCO      0x7000000

#define RCC_CFGR_SW_HSI         (0x0 << 0)
#define RCC_CFGR_SW_HSE         (0x1 << 0)
#define RCC_CFGR_SW_PLL         (0x2 << 0)

#define RCC_CFGR_SWS_HSI        (0x0 << 2)
#define RCC_CFGR_SWS_HSE        (0x1 << 2)
#define RCC_CFGR_SWS_PLL        (0x2 << 2)

#define RCC_CFGR_HPRE_DIV_1     (0x0 << 4)
#define RCC_CFGR_HPRE_DIV_2     (0x8 << 4)
#define RCC_CFGR_HPRE_DIV_4     (0x9 << 4)
#define RCC_CFGR_HPRE_DIV_8     (0xA << 4)
#define RCC_CFGR_HPRE_DIV_16    (0xB << 4)
#define RCC_CFGR_HPRE_DIV_64    (0xC << 4)
#define RCC_CFGR_HPRE_DIV_128   (0xD << 4)
#define RCC_CFGR_HPRE_DIV_256   (0xE << 4)
#define RCC_CFGR_HPRE_DIV_512   (0xF << 4)

#define RCC_CFGR_PPRE1_DIV_1    (0x0 << 8)
#define RCC_CFGR_PPRE1_DIV_2    (0x4 << 8)
#define RCC_CFGR_PPRE1_DIV_4    (0x5 << 8)
#define RCC_CFGR_PPRE1_DIV_8    (0x6 << 8)
#define RCC_CFGR_PPRE1_DIV_16   (0x7 << 8)

#define RCC_CFGR_PPRE2_DIV_1    (0x0 << 11)
#define RCC_CFGR_PPRE2_DIV_2    (0x4 << 11)
#define RCC_CFGR_PPRE2_DIV_4    (0x5 << 11)
#define RCC_CFGR_PPRE2_DIV_8    (0x6 << 11)
#define RCC_CFGR_PPRE2_DIV_16   (0x7 << 11)

#define RCC_CFGR_ADCPRE_DIV_2   (0x0 << 14)
#define RCC_CFGR_ADCPRE_DIV_4   (0x1 << 14)
#define RCC_CFGR_ADCPRE_DIV_6   (0x2 << 14)
#define RCC_CFGR_ADCPRE_DIV_8   (0x3 << 14)

#define RCC_CFGR_PLLSRC_HSI     (0x0 << 16)
#define RCC_CFGR_PLLSRC_HSE     (0x1 << 16)

#define RCC_CFGR_PLLXTPRE_DIV_1 (0x0 << 17)
#define RCC_CFGR_PLLXTPRE_DIV_2 (0x1 << 17)

#define RCC_CFGR_PLLMUL_MUL_2   (0x0 << 18)
#define RCC_CFGR_PLLMUL_MUL_3   (0x1 << 18)
#define RCC_CFGR_PLLMUL_MUL_4   (0x2 << 18)
#define RCC_CFGR_PLLMUL_MUL_5   (0x3 << 18)
#define RCC_CFGR_PLLMUL_MUL_6   (0x4 << 18)
#define RCC_CFGR_PLLMUL_MUL_7   (0x5 << 18)
#define RCC_CFGR_PLLMUL_MUL_8   (0x6 << 18)
#define RCC_CFGR_PLLMUL_MUL_9   (0x7 << 18)
#define RCC_CFGR_PLLMUL_MUL_10  (0x8 << 18)
#define RCC_CFGR_PLLMUL_MUL_11  (0x9 << 18)
#define RCC_CFGR_PLLMUL_MUL_12  (0xA << 18)
#define RCC_CFGR_PLLMUL_MUL_13  (0xB << 18)
#define RCC_CFGR_PLLMUL_MUL_14  (0xC << 18)
#define RCC_CFGR_PLLMUL_MUL_15  (0xD << 18)
#define RCC_CFGR_PLLMUL_MUL_16  (0xE << 18)
#define RCC_CFGR_PLLMUL_MUL_16_ (0xF << 18)

#define RCC_CFGR_USBPRE_DIV_1_5 (0x0 << 22)
#define RCC_CFGR_USBPRE_DIV_1   (0x1 << 22)

#define RCC_CFGR_MCO_OFF        (0x0 << 24)
#define RCC_CFGR_MCO_SYSCLK     (0x4 << 24)
#define RCC_CFGR_MCO_HSI        (0x5 << 24)
#define RCC_CFGR_MCO_HSE        (0x6 << 24)
#define RCC_CFGR_MCO_PLL_DIV_2  (0x7 << 24)

#define RCC_CIR_LSIRDYF         (0x1 <<  0)
#define RCC_CIR_LSERDYF         (0x1 <<  1)
#define RCC_CIR_HSIRDYF         (0x1 <<  2)
#define RCC_CIR_HSERDYF         (0x1 <<  3)
#define RCC_CIR_PLLRDYF         (0x1 <<  4)
#define RCC_CIR_CSSF            (0x1 <<  7)
#define RCC_CIR_LSIRDYIE        (0x1 <<  8)
#define RCC_CIR_LSERDYIE        (0x1 <<  9)
#define RCC_CIR_HSIRDYIE        (0x1 << 10)
#define RCC_CIR_HSERDYIE        (0x1 << 11)
#define RCC_CIR_PLLRDYIE        (0x1 << 12)
#define RCC_CIR_LSIRDYC         (0x1 << 16)
#define RCC_CIR_LSERDYC         (0x1 << 17)
#define RCC_CIR_HSIRDYC         (0x1 << 18)
#define RCC_CIR_HSERDYC         (0x1 << 19)
#define RCC_CIR_PLLRDYC         (0x1 << 20)
#define RCC_CIR_CSSC            (0x1 << 23)

#define RCC_APB2RSTR_AFIORST    (0x1 <<  0)
#define RCC_APB2RSTR_IOPARST    (0x1 <<  2)
#define RCC_APB2RSTR_IOPBRST    (0x1 <<  3)
#define RCC_APB2RSTR_IOPCRST    (0x1 <<  4)
#define RCC_APB2RSTR_IOPDRST    (0x1 <<  5)
#define RCC_APB2RSTR_IOPERST    (0x1 <<  6)
#define RCC_APB2RSTR_IOPFRST    (0x1 <<  7)
#define RCC_APB2RSTR_IOPGRST    (0x1 <<  8)
#define RCC_APB2RSTR_ADC1RST    (0x1 <<  9)
#define RCC_APB2RSTR_ADC2RST    (0x1 << 10)
#define RCC_APB2RSTR_TIM1RST    (0x1 << 11)
#define RCC_APB2RSTR_SPI1RST    (0x1 << 12)
#define RCC_APB2RSTR_TIM8RST    (0x1 << 13)
#define RCC_APB2RSTR_USART1RST  (0x1 << 14)
#define RCC_APB2RSTR_ADC3RST    (0x1 << 15)
#define RCC_APB2RSTR_TIM9RST    (0x1 << 19)
#define RCC_APB2RSTR_TIM10RST   (0x1 << 20)
#define RCC_APB2RSTR_TIM11RST   (0x1 << 21)

#define RCC_APB1RSTR_TIM2RST    (0x1 <<  0)
#define RCC_APB1RSTR_TIM3RST    (0x1 <<  1)
#define RCC_APB1RSTR_TIM4RST    (0x1 <<  2)
#define RCC_APB1RSTR_TIM5RST    (0x1 <<  3)
#define RCC_APB1RSTR_TIM6RST    (0x1 <<  4)
#define RCC_APB1RSTR_TIM7RST    (0x1 <<  5)
#define RCC_APB1RSTR_TIM12RST   (0x1 <<  6)
#define RCC_APB1RSTR_TIM13RST   (0x1 <<  7)
#define RCC_APB1RSTR_TIM14RST   (0x1 <<  8)
#define RCC_APB1RSTR_WWDGRST    (0x1 << 11)
#define RCC_APB1RSTR_SPI2RST    (0x1 << 14)
#define RCC_APB1RSTR_SPI3RST    (0x1 << 15)
#define RCC_APB1RSTR_USART2RST  (0x1 << 17)
#define RCC_APB1RSTR_USART3RST  (0x1 << 18)
#define RCC_APB1RSTR_UART4RST   (0x1 << 19)
#define RCC_APB1RSTR_UART5RST   (0x1 << 20)
#define RCC_APB1RSTR_I2C1RST    (0x1 << 21)
#define RCC_APB1RSTR_I2C2RST    (0x1 << 22)
#define RCC_APB1RSTR_USBRST     (0x1 << 23)
#define RCC_APB1RSTR_CANRST     (0x1 << 25)
#define RCC_APB1RSTR_BKPRST     (0x1 << 27)
#define RCC_APB1RSTR_PWRRST     (0x1 << 28)
#define RCC_APB1RSTR_DACRST     (0x1 << 29)

#define RCC_AHBENR_SDIOEN       (0x1 <<  0)
#define RCC_AHBENR_FSMCEN       (0x1 <<  1)
#define RCC_AHBENR_CRCEN        (0x1 <<  2)
#define RCC_AHBENR_FLITFEN      (0x1 <<  4)
#define RCC_AHBENR_SRAMEN       (0x1 <<  6)
#define RCC_AHBENR_DMA2EN       (0x1 <<  8)
#define RCC_AHBENR_DMA1EN       (0x1 << 10)

#define RCC_APB2ENR_AFIOEN      (0x1 <<  0)
#define RCC_APB2ENR_IOPAEN      (0x1 <<  2)
#define RCC_APB2ENR_IOPBEN      (0x1 <<  3)
#define RCC_APB2ENR_IOPCEN      (0x1 <<  4)
#define RCC_APB2ENR_IOPDEN      (0x1 <<  5)
#define RCC_APB2ENR_IOPEEN      (0x1 <<  6)
#define RCC_APB2ENR_IOPFEN      (0x1 <<  7)
#define RCC_APB2ENR_IOPGEN      (0x1 <<  8)
#define RCC_APB2ENR_ADC1EN      (0x1 <<  9)
#define RCC_APB2ENR_ADC2EN      (0x1 <<  10)
#define RCC_APB2ENR_TIM1EN      (0x1 <<  11)
#define RCC_APB2ENR_SPI1EN      (0x1 <<  12)
#define RCC_APB2ENR_TIM8EN      (0x1 <<  13)
#define RCC_APB2ENR_USART1EN    (0x1 <<  14)
#define RCC_APB2ENR_ADC3EN      (0x1 <<  15)
#define RCC_APB2ENR_TIM9EN      (0x1 <<  19)
#define RCC_APB2ENR_TIM10EN     (0x1 <<  20)
#define RCC_APB2ENR_TIM11EN     (0x1 <<  21)

#define RCC_APB1ENR_TIM2EN      (0x1 <<  0)
#define RCC_APB1ENR_TIM3EN      (0x1 <<  1)
#define RCC_APB1ENR_TIM4EN      (0x1 <<  2)
#define RCC_APB1ENR_TIM5EN      (0x1 <<  3)
#define RCC_APB1ENR_TIM6EN      (0x1 <<  4)
#define RCC_APB1ENR_TIM7EN      (0x1 <<  5)
#define RCC_APB1ENR_TIM12EN     (0x1 <<  6)
#define RCC_APB1ENR_TIM13EN     (0x1 <<  7)
#define RCC_APB1ENR_TIM14EN     (0x1 <<  8)
#define RCC_APB1ENR_WWDGEN      (0x1 << 11)
#define RCC_APB1ENR_SPI2EN      (0x1 << 14)
#define RCC_APB1ENR_SPI3EN      (0x1 << 15)
#define RCC_APB1ENR_USART2EN    (0x1 << 17)
#define RCC_APB1ENR_USART3EN    (0x1 << 18)
#define RCC_APB1ENR_UART4EN     (0x1 << 19)
#define RCC_APB1ENR_UART5EN     (0x1 << 20)
#define RCC_APB1ENR_I2C1EN      (0x1 << 21)
#define RCC_APB1ENR_I2C2EN      (0x1 << 22)
#define RCC_APB1ENR_USBEN       (0x1 << 23)
#define RCC_APB1ENR_CANEN       (0x1 << 25)
#define RCC_APB1ENR_BKPEN       (0x1 << 27)
#define RCC_APB1ENR_PWREN       (0x1 << 28)
#define RCC_APB1ENR_DACEN       (0x1 << 29)

#define RCC_BDCR_LSEON          (0x1 <<  0)
#define RCC_BDCR_LSERDY         (0x1 <<  1)
#define RCC_BDCR_LSEBYP         (0x1 <<  2)
#define RCC_BDCR_RTCSEL         (0x3 <<  8)
#define RCC_BDCR_RTCEN          (0x1 << 15)
#define RCC_BDCR_BDRST          (0x1 << 16)

#define RCC_CSR_LSION           (0x1 <<  0)
#define RCC_CSR_LSIRDY          (0x1 <<  1)
#define RCC_CSR_RMVF            (0x1 << 24)
#define RCC_CSR_PINRSTF         (0x1 << 26)
#define RCC_CSR_PORRSTF         (0x1 << 27)
#define RCC_CSR_SFTRSTF         (0x1 << 28)
#define RCC_CSR_IWDGRSTF        (0x1 << 29)
#define RCC_CSR_WWDGRSTF        (0x1 << 30)
#define RCC_CSR_LPWRRSTF        (0x1 << 31)

#define FLASH_ACR (*(uint32_t * const)(FLASH_BASE + 0x00))

#define FLASH_ACR_LATENCY       (0x7 << 0)
#define FLASH_HLFCYA            (0x1 << 3)
#define FLASH_PRFTBE            (0x1 << 4)
#define FLASH_PRFTBS            (0x1 << 5)

#define FLASH_ACR_LATENCY_0     (0x0 << 0)
#define FLASH_ACR_LATENCY_1     (0x1 << 0)
#define FLASH_ACR_LATENCY_2     (0x2 << 0)

#define GPIOA 0x0000
#define GPIOB 0x0400
#define GPIOC 0x0800
#define GPIOD 0x0C00
#define GPIOE 0x1000
#define GPIOF 0x1400
#define GPIOG 0x1800

#define GPIOx_OFFSET_CRL  0x00
#define GPIOx_OFFSET_CRH  0x04
#define GPIOx_OFFSET_IDR  0x08
#define GPIOx_OFFSET_ODR  0x0C
#define GPIOx_OFFSET_BSRR 0x10
#define GPIOx_OFFSET_BRR  0x14
#define GPIOx_OFFSET_LCKR 0x18

#define GPIOx_CRL(p)  (*(uint32_t * const)(GPIO_BASE + p + GPIOx_OFFSET_CRL))
#define GPIOx_CRH(p)  (*(uint32_t * const)(GPIO_BASE + p + GPIOx_OFFSET_CRH))
#define GPIOx_IDR(p)  (*(uint32_t * const)(GPIO_BASE + p + GPIOx_OFFSET_IDR))
#define GPIOx_ODR(p)  (*(uint32_t * const)(GPIO_BASE + p + GPIOx_OFFSET_ODR))
#define GPIOx_BSRR(p) (*(uint32_t * const)(GPIO_BASE + p + GPIOx_OFFSET_BSRR))
#define GPIOx_BRR(p)  (*(uint32_t * const)(GPIO_BASE + p + GPIOx_OFFSET_BRR))
#define GPIOx_LCKR(p) (*(uint32_t * const)(GPIO_BASE + p + GPIOx_OFFSET_LCKR))

#define GPIO_CR_MODE 0x3
#define GPIO_CR_CNF  0xC

#define GPIO_CR_MODE_IN           (0x0 << 0)
#define GPIO_CR_MODE_OUT_10MHZ    (0x1 << 0)
#define GPIO_CR_MODE_OUT_2MHZ     (0x2 << 0)
#define GPIO_CR_MODE_OUT_50MHZ    (0x3 << 0)

#define GPIO_CR_CNF_IN_ANALOG     (0x0 << 2)
#define GPIO_CR_CNF_IN_FLOAT      (0x1 << 2)
#define GPIO_CR_CNF_IN_PULL       (0x2 << 2)
#define GPIO_CR_CNF_OUT_PUSHPULL  (0x0 << 2)
#define GPIO_CR_CNF_OUT_OPENDRAIN (0x1 << 2)
#define GPIO_CR_CNF_ALT_PUSHPULL  (0x2 << 2)
#define GPIO_CR_CNF_ALT_OPENDRAIN (0x3 << 2)

#endif
