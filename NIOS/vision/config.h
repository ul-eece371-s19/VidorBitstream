/*
 * config.h
 *
 *  Created on: Jun 20, 2018
 *      Author: max
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include <system.h>

/**
 * FPGA Version returned by command 0x00000001
 */
#define FPGA_VERSION 0x01010108


/**
 * GPIO module
 */
#define GPIO_MODULE       1
#if defined(GPIO_MODULE) && (GPIO_MODULE == 1)
  #define GPIO_DID  0x00000100
  #define GPIO_VER  0x0003
  #define GPIO_SUB  0x03
  #define GPIO_CHN  0x20
#endif /* defined(GPIO_MODULE) && (GPIO_MODULE == 1) */

/**
 * PWM module
 */
#define PWM_MODULE 1
#if defined(PWM_MODULE) && (PWM_MODULE == 1)
  #define PWM_DID  0x00000110
  #define PWM_VER  0x0003
  #define PWM_SUB  0x03
  #define PWM_CHN  0x20

  #define PWM_BASE SAM_PWM_BASE
#endif /* defined(PWM_MODULE) && (PWM_MODULE == 1) */

/**
 * graphic module
 */
#define GFX_MODULE      1

#if defined(GFX_MODULE) && (GFX_MODULE == 1)
  #define GFX_DID  0x00000200
  #define GFX_VER  0x0001
  #define GFX_SUB  0x01
  #define GFX_CHN  0x00

  #define GFX_FB_BASE (alt_u16*)((SDRAM_ARBITER_BASE + \
                              SDRAM_ARBITER_FB_OFFSET*sizeof(short)) | \
                             0x80000000)
  #define GFX_CAM_BASE    (alt_u16*)(SDRAM_ARBITER_BASE)

  #define GFX_FB_WIDTH    640
  #define GFX_FB_HEIGHT   480

  #define GFX_CLEAR       1
  #define GFX_LOGO        1

  #define GFX_FONTS       1
  #define GFX_FONT_FILE   "fonts.h"
  #define GFX_FONT_NAME   FreeMono12pt7b
  #define FONT_MONO
  #define FONT_SANS
  #define FONT_SERIF
  #define FONT_9PT
  #define FONT_12PT
  #define FONT_18PT
  #define FONT_24PT
  //#define FONT_BOLD
  //#define FONT_ITALIC

  #define GFX_CMDS        1

  /* define graphic context */
  #include "gfx.h"

  #define GFX_GC_NUM    (1 + NEOPIXEL_0_CHANNELS)
  extern GFXgc *gfxGc[];

/* TODO define graphic context */

#endif /* defined(GFX_MODULE) && (GFX_MODULE == 1) */

/**
 * serial flash module
 */
#define SF_MODULE         0
#if defined(SF_MODULE) && (SF_MODULE == 1)
  #define SF_DID  0x00000300
  #define SF_VER  0x0001
  #define SF_SUB  0x01
  #define SF_CHN  0x00

  #define SF_USE_QSPI       0
  #define SF_SPI_IDX        6
  #define SF_INVERT_BIT     0
  #define SF_SECURITY_CMDS  1
#endif /* defined(SF_MODULE) && (SF_MODULE == 1) */

/**
 */
#define I2C_MODULE    1
#if defined(I2C_MODULE) && (I2C_MODULE == 1)
  #define I2C_DID  0x00000400
  #define I2C_VER  0x0004
  #define I2C_SUB  0x04
  #define I2C_CHN  0x00

  #define I2C_DEV_NUM 2
  #define I2C_DEV_BASE   CSI_I2C_BASE, HDMI_I2C_BASE,
#endif /* defined(I2C_MODULE) && (I2C_MODULE == 1) */

/**
 * spi module
 */
#define SPI_MODULE  1
#if defined(SPI_MODULE) && (SPI_MODULE == 1)
  #define SPI_DID  0x00000500
  #define SPI_VER  0x0006
  #define SPI_SUB  0x06
  #define SPI_CHN  0x00

  #define SPI_DEV_NUM 1
  #define SPI_INTERRUPT_CONTROLLER_ID NINA_IRQ_INTERRUPT_CONTROLLER_ID
  #define SPI_DEV_CFG \
    /*    BASE        MOSI   MISO    CLK     SS  A */ \
    {NINA_SPI_BASE ,    -1,    -1,    -1,    -1, 0}, \
    {FLASH_SPI_BASE,    -1,    -1,    -1,    -1, 1},
  #define SPI_SS_AUTO  0
#endif /* defined(SPI_MODULE) && (SPI_MODULE == 1) */

/**
 * uart module
 */
#define UART_MODULE  1
#if defined(UART_MODULE) && (UART_MODULE == 1)
  #define UART_DID  0x00000600
  #define UART_VER  0x0009
  #define UART_SUB  0x01
  #define UART_CHN  0x00

  #define UART_DEV_NUM 1
  #define UART_PIN_MUX 4
  #define UART_DEV_CFG \
    /*      name  cap     tx  rx rts cts dtr dsr*/\
    {NINA_UART_NAME, 0x0, 64+15, 64+16, -1, -1, -1, -1},

#endif /* defined(UART_MODULE) && (UART_MODULE == 1) */

/**
 * qrcode module
 */
#define QR_MODULE 1
#if defined(QR_MODULE) && (QR_MODULE == 1)
  #define QR_DID  0x00000700
  #define QR_VER  0x0001
  #define QR_SUB  0x01
  #define QR_CHN  0x00

  #define QR_CNT_MAX      1000
  #define QR_GET_TIMEOUT 10000
  #define QR_PT_NUM        100
#endif /* defined(QR_MODULE) && (QR_MODULE == 1) */

/**
 * SDRAM module
 */
#define SDRAM_MODULE         1
#if defined(SDRAM_MODULE) && (SDRAM_MODULE == 1)
  #define SDRAM_DID  0x00000800
  #define SDRAM_VER  0x0001
  #define SDRAM_SUB  0x01
  #define SDRAM_CHN  0x00

  #define SDRAM_BASE  (void*)(SDRAM_ARBITER_BASE | 0x80000000)
  #define SDRAM_SIZE  SDRAM_ARBITER_SPAN
  //#define SDRAM_BASE  (0 | 0x80000000)
  //#define SDRAM_SIZE  0x00800000
  //#define SDRAM_SIZE  SDRAM_SPAN
#endif /* defined(SDRAM_MODULE) && (SDRAM_MODULE == 1) */

/**
 * Neo Pixels module
 */
#define NP_MODULE         1
#if defined(NP_MODULE) && (NP_MODULE == 1)
  #define NP_DID  0x00000900
  #define NP_VER  0x0010
  #define NP_SUB  0x01
  #define NP_CHN  NEOPIXEL_0_CHANNELS

  #define NP_DEV_NUM      NEOPIXEL_0_CHANNELS
  #define NP_CSR_BASE     NEOPIXEL_0_BASE
  #define NP_MEM_BASE     ((SDRAM_ARBITER_BASE + 0x00200000)  | 0x80000000)
  #define NP_MEM_SIZE      (SDRAM_ARBITER_SPAN - 0x00200000)
  #define NP_PIN_MUX      4
  #define NP_PIN          32+1, 32+2, 32+3, 32+4, 32+5, 32+6, 32+7, 32+8, \
                          32+9, 32+10, 32+11,
#endif /* defined(NP_MODULE) && (NP_MODULE == 1) */

/**
 * Qudrature encoder module
 */
#define ENC_MODULE  1
#if defined(ENC_MODULE) && (ENC_MODULE == 1)
  #define ENC_DID  0x00000A00
  #define ENC_VER  0x0001
  #define ENC_SUB  0x01
  #define ENC_CHN  11

  #define ENC_DEV_NUM     11
  #define ENC_BASE        QUAD_ENCODER_0_BASE
#endif /* defined(ENC_MODULE) && (ENC_MODULE == 1) */

/**
 * register module
 */
#define REG_MODULE  1
#if defined(REG_MODULE) && (REG_MODULE == 1)
  #define REG_DID  0x00000B00
  #define REG_VER  0x0001
  #define REG_SUB  0x01
  #define REG_CHN  0x00
#endif /* defined(ENC_MODULE) && (ENC_MODULE == 1) */

/**
 * timer module
 */
#define TMR_MODULE  1
#if defined(TMR_MODULE) && (TMR_MODULE == 1)
  #define TMR_BASE        TIMER_0_BASE
  #define TMR_FREQ        TIMER_0_FREQ
  #define TMR_IRQ_CTR_ID  0
  #define TMR_IRQ         TIMER_0_IRQ
#endif /* defined(TMR_MODULE) && (TMR_MODULE == 1) */

void configInit(void);

#endif /* CONFIG_H_ */
