/*
 * main.h
 *
 *  Created on: 10 jul 2012
 *      Author: BenjaminVe
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "stm32f4xx.h"
#include <stdio.h>
#include "stm32f4xx_it.h"
#include "usb_hcd_int.h"
#include "usbh_usr.h"
#include "usbh_core.h"
#include "usbh_msc_core.h"

// Function prototypes
void TimingDelay_Decrement(void);
void Delay(volatile uint32_t nTime);

#endif /* MAIN_H_ */
