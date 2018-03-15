
#ifdef CONFIG_RTL8822B
#ifndef _FW_HEADER_8822B_H
#define _FW_HEADER_8822B_H

#ifdef LOAD_FW_HEADER_FROM_DRIVER
#if (DM_ODM_SUPPORT_TYPE & (ODM_WIN)) || (DM_ODM_SUPPORT_TYPE & (ODM_CE))
extern u1Byte Array_MP_8822B_FW_NIC[107896];
extern u4Byte ArrayLength_MP_8822B_FW_NIC;

#if (defined(CONFIG_AP_WOWLAN) || (DM_ODM_SUPPORT_TYPE & (ODM_AP)))
extern u1Byte Array_MP_8822B_FW_AP[75544];
extern u4Byte ArrayLength_MP_8822B_FW_AP;
#endif

extern u1Byte Array_MP_8822B_FW_WoWLAN[63168];
extern u4Byte ArrayLength_MP_8822B_FW_WoWLAN;
#endif
#endif /* end of LOAD_FW_HEADER_FROM_DRIVER*/

#endif
#endif /* end of HWIMG_SUPPORT*/


