#define VECTORS() \
  VECTOR(Reset) \
  VECTOR(NMI) \
  VECTOR(HardFault) \
  VECTOR(MMUFault) \
  VECTOR(BusFault) \
  VECTOR(UsageFault) \
  RESERVED() \
  RESERVED() \
  RESERVED() \
  RESERVED() \
  VECTOR(SVCall) \
  VECTOR(DebugMonitor) \
  RESERVED() \
  VECTOR(PendSV) \
  VECTOR(SysTick) \
  VECTOR(WWDG) \
  VECTOR(PVD) \
  VECTOR(TAMPER) \
  VECTOR(RTC) \
  VECTOR(FLASH) \
  VECTOR(RCC) \
  VECTOR(EXTI0) \
  VECTOR(EXTI1) \
  VECTOR(EXTI2) \
  VECTOR(EXTI3) \
  VECTOR(EXTI4) \
  VECTOR(DMA1_Channel1) \
  VECTOR(DMA1_Channel2) \
  VECTOR(DMA1_Channel3) \
  VECTOR(DMA1_Channel4) \
  VECTOR(DMA1_Channel5) \
  VECTOR(DMA1_Channel6) \
  VECTOR(DMA1_Channel7) \
  VECTOR(ADC1_2) \
  VECTOR(USB_HP_CAN_TX) \
  VECTOR(USB_LP_CAN_RX0) \
  VECTOR(CAN_RX1) \
  VECTOR(CAN_SCE) \
  VECTOR(EXTI9_5) \
  VECTOR(TIM1_BRK) \
  VECTOR(TIM1_UP) \
  VECTOR(TIM1_TRG_COM) \
  VECTOR(TIM1_CC) \
  VECTOR(TIM2) \
  VECTOR(TIM3) \
  VECTOR(TIM4) \
  VECTOR(I2C1_EV) \
  VECTOR(I2C1_ER) \
  VECTOR(I2C2_EV) \
  VECTOR(I2C2_ER) \
  VECTOR(SPI1) \
  VECTOR(SPI2) \
  VECTOR(USART1) \
  VECTOR(USART2) \
  VECTOR(USART3) \
  VECTOR(EXTI15_10) \
  VECTOR(RTCAlarm) \
  VECTOR(USBWakeup) \
  VECTOR(TIM8_BRK) \
  VECTOR(TIM8_UP) \
  VECTOR(TIM8_TRG_COM) \
  VECTOR(TIM8_CC) \
  VECTOR(ADC3) \
  VECTOR(FSMC) \
  VECTOR(SDIO) \
  VECTOR(TIM5) \
  VECTOR(SPI3) \
  VECTOR(UART4) \
  VECTOR(UART5) \
  VECTOR(TIM6) \
  VECTOR(TIM7) \
  VECTOR(DMA2_Channel1) \
  VECTOR(DMA2_Channel2) \
  VECTOR(DMA2_Channel3) \
  VECTOR(DMA2_Channel4_5)

__attribute__((naked)) void Default_Handler(void)
{
  while(1) {}
}

#define RESERVED()
#define VECTOR(x) \
    void x ## _Handler(void) __attribute__ ((weak, alias ("Default_Handler")));
VECTORS()

#undef  RESERVED
#undef  VECTOR
#define RESERVED() 0,
#define VECTOR(x) x ## _Handler,

extern void * _estack;

void * vectors[] __attribute__((section(".isr_vector"))) =
{
  (void*)&_estack,
  VECTORS()
};

#undef VECTOR
