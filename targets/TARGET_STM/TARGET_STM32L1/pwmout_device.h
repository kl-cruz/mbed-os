/* mbed Microcontroller Library
 *******************************************************************************
 * Copyright (c) 2017, STMicroelectronics
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of STMicroelectronics nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************
 */
#ifndef MBED_PWMOUT_DEVICE_H
#define MBED_PWMOUT_DEVICE_H

#include "cmsis.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef DEVICE_PWMOUT

/*  L1 HAL do not offer Output Compare idle nor inverted mode*/
#define PWMOUT_INVERTED_NOT_SUPPORTED

typedef enum {
    PWMOUT_ON_APB1 = 0,
    PWMOUT_ON_APB2 = 1,
    PWMOUT_UNKNOWN = 2
} PwmoutApb;

/*  Structure to describe Timers to APB */
typedef struct pwm_apb_map {
    PWMName pwm;   // an index entry for each EXIT line
    PwmoutApb pwmoutApb;
} pwm_apb_map_t;

static const pwm_apb_map_t pwm_apb_map_table[] =
{
#if defined(TIM2_BASE)
    {PWM_2, PWMOUT_ON_APB1},
#endif
#if defined(TIM3_BASE)
    {PWM_3, PWMOUT_ON_APB1},
#endif
#if defined(TIM4_BASE)
    {PWM_4, PWMOUT_ON_APB1},
#endif
#if defined(TIM5_BASE)
    {PWM_5, PWMOUT_ON_APB1},
#endif
#if defined(TIM9_BASE)
    {PWM_9, PWMOUT_ON_APB2},
#endif
#if defined(TIM10_BASE)
    {PWM_10, PWMOUT_ON_APB2},
#endif
#if defined(TIM11_BASE)
    {PWM_11, PWMOUT_ON_APB2},
#endif
    {(PWMName) 0, PWMOUT_UNKNOWN}
};

#endif // DEVICE_PWMOUT

#endif