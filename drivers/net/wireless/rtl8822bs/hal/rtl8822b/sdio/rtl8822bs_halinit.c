/******************************************************************************
 *
 * Copyright(c) 2015 - 2016 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/
#define _RTL8822BS_HALINIT_C_

#include <drv_types.h>		/* PADAPTER, basic_types.h and etc. */
#include <hal_data.h>		/* HAL_DATA_TYPE */
#include "../../hal_halmac.h"	/* rtw_halmac_query_tx_page_num() */
#include "../rtl8822b.h"	/* rtl8822b_hal_init(), rtl8822b_phy_init_haldm() and etc. */
#include "rtl8822bs.h"		/* rtl8822bs_init_interrupt() */


u32 rtl8822bs_init(PADAPTER adapter)
{
	u8 ok;


	ok = rtl8822b_hal_init(adapter);
	if (_FALSE == ok)
		return _FAIL;

	rtw_halmac_query_tx_page_num(adapter_to_dvobj(adapter));

	rtl8822bs_init_interrupt(adapter);
	rtl8822b_mac_verify(adapter);

	rtl8822b_phy_init_haldm(adapter);
#ifdef CONFIG_BEAMFORMING
	rtl8822b_phy_init_beamforming(adapter);
#endif /* CONFIG_BEAMFORMING */

#ifdef CONFIG_BT_COEXIST
	/* Init BT-Coex hardware config */
	if (_TRUE == GET_HAL_DATA(adapter)->EEPROMBluetoothCoexist)
		rtw_btcoex_HAL_Initialize(adapter, _FALSE);
#endif /* CONFIG_BT_COEXIST */

	rtl8822b_init_misc(adapter);

	return _SUCCESS;
}

void rtl8822bs_init_default_value(PADAPTER adapter)
{
	PHAL_DATA_TYPE hal;


	hal = GET_HAL_DATA(adapter);

	rtl8822b_init_default_value(adapter);

	/* interface related variable */
	hal->SdioRxFIFOCnt = 0;
}
