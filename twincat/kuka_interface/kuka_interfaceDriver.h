///////////////////////////////////////////////////////////////////////////////
// kuka_interfaceDriver.h

#ifndef __KUKA_INTERFACEDRIVER_H__
#define __KUKA_INTERFACEDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define KUKA_INTERFACEDRV_NAME        "KUKA_INTERFACE"
#define KUKA_INTERFACEDRV_Major       1
#define KUKA_INTERFACEDRV_Minor       0

#define DEVICE_CLASS Ckuka_interfaceDriver

#include "ObjDriver.h"

class Ckuka_interfaceDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl KUKA_INTERFACEDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(KUKA_INTERFACEDRV)
	VxD_Service( KUKA_INTERFACEDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __KUKA_INTERFACEDRIVER_H__