///////////////////////////////////////////////////////////////////////////////
// motive_interfaceDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "motive_interfaceDriver.h"
#include "motive_interfaceClassFactory.h"

DECLARE_GENERIC_DEVICE(MOTIVE_INTERFACEDRV)

IOSTATUS Cmotive_interfaceDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new Cmotive_interfaceClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID Cmotive_interfaceDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl Cmotive_interfaceDriver::MOTIVE_INTERFACEDRV_GetVersion( )
{
	return( (MOTIVE_INTERFACEDRV_Major << 8) | MOTIVE_INTERFACEDRV_Minor );
}

