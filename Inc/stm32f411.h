#ifndef STM32F411_H
#define STM32F411_H

#include <stdint.h>

/* ============================================================
   BASE ADDRESSES — from RM0383 chapter 2 memory map
   ============================================================ */

/* RCC */
#define RCC_BASE        0x40023800


/* GPIO */
#define GPIOA_BASE      0x40020000
#define GPIOB_BASE      0x40020400
#define GPIOC_BASE      0x40020800
#define GPIOD_BASE      0x40020C00
#define GPIOE_BASE      0x40021000

/* ============================================================
   GPIO STRUCT — same layout for every port
   ============================================================ */

typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFR[2];
} GPIO_TypeDef;

/* GPIO port instances */
#define GPIOA   ((GPIO_TypeDef*)GPIOA_BASE)
#define GPIOB   ((GPIO_TypeDef*)GPIOB_BASE)
#define GPIOC   ((GPIO_TypeDef*)GPIOC_BASE)
#define GPIOD   ((GPIO_TypeDef*)GPIOD_BASE)
#define GPIOE   ((GPIO_TypeDef*)GPIOE_BASE)

/* ============================================================
   RCC AHB1ENR BIT DEFINITIONS
   ============================================================ */

#define RCC_AHB1ENR_GPIOAEN    0
#define RCC_AHB1ENR_GPIOBEN    1
#define RCC_AHB1ENR_GPIOCEN    2
#define RCC_AHB1ENR_GPIODEN    3
#define RCC_AHB1ENR_GPIOEEN    4
#define RCC_AHB1ENR_DMA1EN     21
#define RCC_AHB1ENR_DMA2EN     22

/* ============================================================
   RCC STRUCT — Reset and Clock Control
   ============================================================ */

typedef struct {
    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;
    volatile uint32_t AHB3RSTR;
    uint32_t          RESERVED0;
    volatile uint32_t APB1RSTR;
    volatile uint32_t APB2RSTR;
    uint32_t          RESERVED1[2];
    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;
    volatile uint32_t AHB3ENR;
    uint32_t          RESERVED2;
    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;
} RCC_TypeDef;

#define RCC   ((RCC_TypeDef*)RCC_BASE)

/* ============================================================
   BIT MANIPULATION MACROS
   ============================================================ */

#define SET_BIT(reg, bit)     ((reg) |= (1U << (bit)))
#define CLEAR_BIT(reg, bit)   ((reg) &= ~(1U << (bit)))
#define TOGGLE_BIT(reg, bit)  ((reg) ^= (1U << (bit)))
#define READ_BIT(reg, bit)    (((reg) >> (bit)) & 1U)

#endif /* STM32F411_H */