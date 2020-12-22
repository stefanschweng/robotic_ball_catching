﻿// ****************** Ccontroller_ballcatcherDrv.h *******************************
// Generated by TwinCAT Target for MATLAB/Simulink (TE1400)
// MATLAB R2018b (win64)
// TwinCAT 3.1.4024
// TwinCAT Target 1.2.1237
// Beckhoff Automation GmbH & Co. KG     (www.beckhoff.com)
// *************************************************************
#ifndef CCONTROLLER_BALLCATCHERDRV_H_INCLUDED
#define CCONTROLLER_BALLCATCHERDRV_H_INCLUDED

#include "TcPch.h"

#define controller_ballcatcherDRV_NAME			"controller_ballcatcher"
#define controller_ballcatcherDRV_Major			1
#define controller_ballcatcherDRV_Minor			0

#if defined DEVICE_MAIN		// is supposed to be __cplusplus

#define DEVICE_CLASS			Ccontroller_ballcatcherDrv

#include "ObjDriver.h"

class Ccontroller_ballcatcherDrv : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad( );
	virtual VOID		OnUnLoad( );
	
  //////////////////////////////////////////////////////
  // VxD-Services exported by this driver
  static unsigned long _cdecl controller_ballcatcher_GetVersion( );
};

#endif	// #if defined DEVICE_MAIN

Begin_VxD_Service_Table( controller_ballcatcherDRV)
	VxD_Service( controller_ballcatcher_GetVersion		)
End_VxD_Service_Table


#endif