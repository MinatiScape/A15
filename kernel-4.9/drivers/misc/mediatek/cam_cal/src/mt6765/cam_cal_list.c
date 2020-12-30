/*
 * Copyright (C) 2018 MediaTek Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See http://www.gnu.org/licenses/gpl-2.0.html for more details.
 */
#include <linux/kernel.h>
#include "cam_cal_list.h"
#include "eeprom_i2c_common_driver.h"
#include "eeprom_i2c_custom_driver.h"
#include "kd_imgsensor.h"

struct stCAM_CAL_LIST_STRUCT g_camCalList[] = {
#ifdef ODM_WT_EDIT
	{YOGURT_TRULY_MAIN_S5K3L6_SENSOR_ID, 0xA0, Common_read_region},
	{YOGURT_QTECH_MAIN_OV13B10_SENSOR_ID, 0xA0, Common_read_region},
	{YOGURT_HLT_FRONT_GC5035_SENSOR_ID, 0xA8, Common_read_region},
	{YOGURT_SHENGTAI_FRONT_GC5035_SENSOR_ID, 0xA8, Common_read_region},
	{YOGURT_SUNNY_FRONT_GC5035_SENSOR_ID, 0xA8, Common_read_region},
	{YOGURT_HLT_DEPTH_GC02M1B_MIPI_SENSOR_ID, 0xA2, Common_read_region},
	{YOGURT_SHENGTAI_MICRO_GC02K0_SENSOR_ID, 0xA4, Common_read_region},
	{YOGURT_LHYX_MICRO_GC02K0_SENSOR_ID, 0xA4, Common_read_region},
	{YOGURT_CXT_MICRO_GC02K0_SENSOR_ID, 0xA4, Common_read_region},
#else

	{PASCALD_TRULY_MAIN_OV13B10_SENSOR_ID, 0xA0, Common_read_region},
	{PASCALD_QTECH_MAIN_OV13B10_SENSOR_ID, 0xA0, Common_read_region},

/* Shipei.Chen@Cam.Drv, 20200410, otp porting for gc5035*/
	{PASCALD_HLT_FRONT_GC5035_SENSOR_ID, 0xA8, Common_read_region},
/* wenhui.Chen@Cam.Drv, 20200430, sensor porting for shengtai GC5035*/
	{PASCALD_SHENGTAI_FRONT_GC5035_SENSOR_ID, 0xA8, Common_read_region},
/* wang.Gao@Cam.Drv, 20200529,sensor porting for shengtai2 GC5035*/
	{PASCALD_SHENGTAI2_FRONT_GC5035_SENSOR_ID, 0xA8, Common_read_region},
	/*Below is commom sensor */
	{IMX230_SENSOR_ID, 0xA0, Common_read_region},
	{S5K2T7SP_SENSOR_ID, 0xA4, Common_read_region},
	{IMX338_SENSOR_ID, 0xA0, Common_read_region},
	{S5K4E6_SENSOR_ID, 0xA8, Common_read_region},
	{IMX386_SENSOR_ID, 0xA0, Common_read_region},
	{S5K3M3_SENSOR_ID, 0xA0, Common_read_region},
	{S5K2L7_SENSOR_ID, 0xA0, Common_read_region},
	{IMX398_SENSOR_ID, 0xA0, Common_read_region},
	{IMX318_SENSOR_ID, 0xA0, Common_read_region},
	{OV8858_SENSOR_ID, 0xA8, Common_read_region},
	{IMX386_MONO_SENSOR_ID, 0xA0, Common_read_region},
	/*B+B*/
	{S5K2P7_SENSOR_ID, 0xA0, Common_read_region},
	{OV8856_SENSOR_ID, 0xA0, Common_read_region},
	/*61*/
	{IMX499_SENSOR_ID, 0xA0, Common_read_region},
	{S5K3L8_SENSOR_ID, 0xA0, Common_read_region},
	{S5K5E8YX_SENSOR_ID, 0xA2, Common_read_region},
	/*99*/
	{IMX258_SENSOR_ID, 0xA0, Common_read_region},
	{IMX258_MONO_SENSOR_ID, 0xA0, Common_read_region},
	/*97*/
	{OV23850_SENSOR_ID, 0xA0, Common_read_region},
	{OV23850_SENSOR_ID, 0xA8, Common_read_region},
	{S5K3M2_SENSOR_ID, 0xA0, Common_read_region},
	/*55*/
	{S5K2P8_SENSOR_ID, 0xA2, Common_read_region},
	{S5K2P8_SENSOR_ID, 0xA0, Common_read_region},
	{OV8858_SENSOR_ID, 0xA2, Common_read_region},
	/* Others */
	{S5K2X8_SENSOR_ID, 0xA0, Common_read_region},
	{IMX377_SENSOR_ID, 0xA0, Common_read_region},
	{IMX214_SENSOR_ID, 0xA0, Common_read_region},
	{IMX214_MONO_SENSOR_ID, 0xA0, Common_read_region},
	{IMX486_SENSOR_ID, 0xA8, Common_read_region},
	{OV12A10_SENSOR_ID, 0xA8, Common_read_region},
	{OV13855_SENSOR_ID, 0xA0, Common_read_region},
	{S5K3L8_SENSOR_ID, 0xA0, Common_read_region},
	{HI556_SENSOR_ID, 0x51, Common_read_region},
	{S5K5E8YX_SENSOR_ID, 0x5a, Common_read_region},
	{S5K5E8YXREAR2_SENSOR_ID, 0x5a, Common_read_region},
#endif
	/*  ADD before this line */
	{0, 0, 0}       /*end of list */
};

unsigned int cam_cal_get_sensor_list(
	struct stCAM_CAL_LIST_STRUCT **ppCamcalList)
{
	if (ppCamcalList == NULL)
		return 1;

	*ppCamcalList = &g_camCalList[0];
	return 0;
}


