/***********************************************************
** Copyright (C), 2009-2019, OPPO Mobile Comm Corp., Ltd.
** VENDOR_EDIT
** File: - oppo_nwpower.h
** Description: BugID:2120730, Add for classify glink wakeup services and count IPA wakeup.
**
** Version: 1.0
** Date : 2019/07/31
** Author: Asiga@PSW.NW.DATA
**
** ------------------ Revision History:------------------------
** <author> <data> <version > <desc>
** Asiga 2019/07/31 1.0 build this module
****************************************************************/
#ifndef __OPPO_NWPOWER_H_
#define __OPPO_NWPOWER_H_

//Add for IPA wakeup
struct oppo_ipv4_hook_struct {
	u32 addr;
	kuid_t uid;
	u64 ipa_wakeup[100];
};

//Add for QMI wakeup
extern void oppo_match_qmi_wakeup(int passageway, int channel);

extern void oppo_nwpower_hook_on(bool normal);
extern void oppo_nwpower_hook_off(bool normal, bool unsl);

#endif /* __OPPO_NWPOWER_H_ */