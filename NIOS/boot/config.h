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
 *
 */
#define FPGA_VERSION 0xB0010101



#define RU_MODULE       1

/**
 * graphic module
 */
#define GFX_MODULE      1

#if defined(GFX_MODULE) && (GFX_MODULE == 1)

  #define GFX_FB_BASE (alt_u16*)((SDRAM_ARBITER_BASE + \
                              SDRAM_ARBITER_FB_OFFSET*sizeof(short)) | \
                             0x80000000)
  #define GFX_CAM_BASE    (alt_u16*)(SDRAM_ARBITER_BASE)

  #define GFX_FB_WIDTH    640
  #define GFX_FB_HEIGHT   480

  #define GFX_FONTS       0
  #define GFX_FONT_FILE   "Fonts/FreeMono12pt7b.h"
  #define GFX_FONT_NAME   FreeMono12pt7b

  #define GFX_CMDS        0
#endif /* defined(GFX_MODULE) && (GFX_MODULE == 1) */

#define GPIO_GPIO       0

#define SF_MODULE         1
#define SF_USE_QSPI       1
#define SF_SF_INVERT_BIT  0
#define SF_SECURITY_CMDS  1

#endif /* CONFIG_H_ */
