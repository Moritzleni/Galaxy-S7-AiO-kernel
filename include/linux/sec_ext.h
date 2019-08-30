/* sec_ext.h
 *
 * Copyright (C) 2014 Samsung Electronics
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 *
 */

#ifndef SEC_EXT_H
#define SEC_EXT_H

/* 
 * PMU register offset : MUST MODIFY ACCORDING TO SoC
 */
#define EXYNOS_PMU_INFORM2 0x0808
#define EXYNOS_PMU_INFORM3 0x080C
#define EXYNOS_PMU_PS_HOLD_CONTROL 0x330C

/*
 * Bootstat @ /proc/boot_stat
 */
#ifdef CONFIG_SEC_BOOTSTAT
extern void sec_bootstat_mct_start(u64 t);
extern void sec_bootstat_add(const char * c);
extern void sec_bootstat_add_initcall(const char *);

extern void sec_bootstat_get_cpuinfo(int *freq, int *online);
extern void sec_bootstat_get_thermal(int *temp);
#else
#define sec_bootstat_mct_start(a)		do { } while(0)
#define sec_bootstat_add(a)			do { } while(0)
#define sec_bootstat_add_initcall(a)		do { } while(0)

#define sec_bootstat_get_cpuinfo(a,b)		do { } while(0)	
#define sec_bootstat_get_thermal(a)		do { } while(0)	
#endif /* CONFIG_SEC_BOOT_STAT */

/*
 * Initcall log @ /proc/initcall_debug
 * show a sorted execution time list of initcalls.
 */
#ifdef CONFIG_SEC_INITCALL_DEBUG
#define SEC_INITCALL_DEBUG_MIN_TIME		10000
extern void sec_initcall_debug_add(initcall_t fn, unsigned long long t);
#else
#define sec_initcall_debug_add(a,b)		do { } while(0)	
#endif /* CONFIG_SEC_INITCALL_DEBUG */

/*
 * Param op.
 */
#ifdef CONFIG_SEC_PARAM
#define CM_OFFSET				CONFIG_CM_OFFSET
#define CM_OFFSET_LIMIT 8
enum
{
	PARAM_OFF = '0',
	PARAM_ON = '1',
};
enum
{
	PARAM_TEST0 = 0,
	PARAM_TEST1,
	PARAM_TEST2,
	PARAM_TEST3,
	PARAM_MAX,
};
extern int sec_set_param(unsigned long offset, char val);
extern int sec_set_param_str(unsigned long offset, const char *val, int size);
#else
#define sec_set_param(a,b)			{-1)
#endif /* CONFIG_SEC_PARAM */

#endif /* CONFIG_SEC_EXT */
