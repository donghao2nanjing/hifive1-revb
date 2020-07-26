/*
 * File      : main.c
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2006 - 2012, RT-Thread Development Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-05-13     tyustli   first version
 */

#include <stdio.h>
#include <string.h>
#include <rtthread.h>

#include "drv_led.h"

int main(void)
{
    rt_uint32_t count = 0 ; 
    rt_kprintf("Running in main loop\n");
    led_init();

    led_set(LED_RED, LED_ON);
    rt_thread_mdelay(1000);

    led_set(LED_RED, LED_OFF);
    led_set(LED_GREEN, LED_ON);
    rt_thread_mdelay(1000);

    led_set(LED_GREEN, LED_OFF);
    led_set(LED_BLUE, LED_ON);
    rt_thread_mdelay(1000);

    led_set(LED_BLUE, LED_OFF);

    for(;;count ++){
        rt_thread_mdelay(1000);
        rt_kprintf("tick: %d\n", count);
        led_toggle(LED_BLUE);
    }
    return 0;
}