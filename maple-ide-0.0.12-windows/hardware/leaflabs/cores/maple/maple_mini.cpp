/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2011 LeafLabs, LLC.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *****************************************************************************/

/**
 * @file   maple_mini.cpp
 * @author Marti Bolivar <mbolivar@leaflabs.com>
 * @brief  Maple Mini board file.
 */

#ifdef BOARD_maple_mini

#include "maple_mini.h"

#include "gpio.h"
#include "timer.h"
#include "wirish_debug.h"
#include "wirish_types.h"

/* Since we want the Serial Wire/JTAG pins as GPIOs, disable both SW
 * and JTAG debug support */
void boardInit(void) {
    disableDebugPorts();
}

extern const stm32_pin_info PIN_MAP[BOARD_NR_GPIO_PINS] = {

    /* Top header */

    {GPIOA, TIMER1, NULL, 10, 3, ADCx}, /* D0/PA10 */
    {GPIOA, TIMER1, NULL,  9, 2, ADCx}, /* D1/PA9 */
    {GPIOB,   NULL, NULL, 11, 0, ADCx}, /* D2/PB11 */
    {GPIOB,   NULL, NULL, 10, 0, ADCx}, /* D3/PB10 */


    {GPIOA, TIMER1, NULL,  8, 1, ADCx}, /* D4/PA8 */
    {GPIOA,   NULL, NULL, 13, 0, ADCx}, /* D5/PA13 */
    {GPIOA,   NULL, NULL, 14, 0, ADCx}, /* D6/PA14 */
 
    {GPIOA,   NULL, NULL, 15, 0, ADCx}, /* D7/PA15 */
    {GPIOB,   NULL, NULL,  3, 0, ADCx}, /* D8/PB3 */
    {GPIOB,   NULL, NULL,  4, 0, ADCx}, /* D9/PB4 */
    
    {GPIOA,   NULL, ADC1,  4, 0,    4}, /* D10/PA4 */
    {GPIOA, TIMER3, ADC1,  7, 2,    7}, /* D11/PA7 */
    {GPIOA, TIMER3, ADC1,  6, 1,    6}, /* D12/PA6 */
    {GPIOA,   NULL, ADC1,  5, 0,    5}, /* D13/PA5 */

    {GPIOA, TIMER2, ADC1,  0, 1,    0}, /* D14/PA0 */
    {GPIOA, TIMER2, ADC1,  1, 2,    1}, /* D15/PA1 */
    {GPIOA, TIMER2, ADC1,  2, 3,    2}, /* D16/PA2 */
    {GPIOA, TIMER2, ADC1,  3, 4,    3}, /* D17/PA3 */

    {GPIOB, TIMER4, NULL,  7, 2, ADCx}, /* D18/PB7 */
    {GPIOB, TIMER4, NULL,  6, 1, ADCx}, /* D19/PB6 */

    {GPIOB, TIMER3, ADC1,  0, 3,    8}, /* D20/PB0 */
    {GPIOB, TIMER3, ADC1,  1, 4,    9}, /* D21/PB1 */


    /* Bottom header */

    {GPIOB, TIMER4, NULL,  8, 3, ADCx}, /* D22/PB8 */

    {GPIOA,   NULL, NULL, 12, 0, ADCx}, /* D23/PA12 */
    {GPIOA, TIMER1, NULL, 11, 4, ADCx}, /* D24/PA11 */
};

extern const uint8 boardPWMPins[BOARD_NR_PWM_PINS] __FLASH__ = {
    0,1,4,11,12,14,15,16,17,18,19,20,21,22,24
};

extern const uint8 boardADCPins[BOARD_NR_ADC_PINS] __FLASH__ = {
    10,11,12,13,14,15,16,17,20,21
};

#define USB_DP 23
#define USB_DM 24

extern const uint8 boardUsedPins[BOARD_NR_USED_PINS] __FLASH__ = {
    BOARD_LED_PIN, BOARD_BUTTON_PIN, USB_DP, USB_DM
};

#endif
