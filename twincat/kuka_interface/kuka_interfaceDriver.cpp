///////////////////////////////////////////////////////////////////////////////
// kuka_interfaceDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "kuka_interfaceDriver.h"
#include "kuka_interfaceClassFactory.h"

DECLARE_GENERIC_DEVICE(KUKA_INTERFACEDRV)

IOSTATUS Ckuka_interfaceDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new Ckuka_interfaceClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID Ckuka_interfaceDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl Ckuka_interfaceDriver::KUKA_INTERFACEDRV_GetVersion( )
{
	return( (KUKA_INTERFACEDRV_Major << 8) | KUKA_INTERFACEDRV_Minor );
}

