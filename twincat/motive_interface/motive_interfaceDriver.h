///////////////////////////////////////////////////////////////////////////////
// motive_interfaceDriver.h

#ifndef __MOTIVE_INTERFACEDRIVER_H__
#define __MOTIVE_INTERFACEDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define MOTIVE_INTERFACEDRV_NAME        "MOTIVE_INTERFACE"
#define MOTIVE_INTERFACEDRV_Major       1
#define MOTIVE_INTERFACEDRV_Minor       0

#define DEVICE_CLASS Cmotive_interfaceDriver

#include "ObjDriver.h"

class Cmotive_interfaceDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl MOTIVE_INTERFACEDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(MOTIVE_INTERFACEDRV)
	VxD_Service( MOTIVE_INTERFACEDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __MOTIVE_INTERFACEDRIVER_H__