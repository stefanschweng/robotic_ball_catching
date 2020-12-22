///////////////////////////////////////////////////////////////////////////////
// kuka_interfaceClassFactory.cpp
#include "TcPch.h"
#pragma hdrstop

#include "kuka_interfaceClassFactory.h"
#include "kuka_interfaceServices.h"
#include "kuka_interfaceVersion.h"
#include "kuka_module.h"

BEGIN_CLASS_MAP(Ckuka_interfaceClassFactory)
///<AutoGeneratedContent id="ClassMap">
	CLASS_ENTRY(CID_kuka_interfaceCkuka_module, SRVNAME_KUKA_INTERFACE "!Ckuka_module", Ckuka_module)
///</AutoGeneratedContent>
END_CLASS_MAP()

Ckuka_interfaceClassFactory::Ckuka_interfaceClassFactory() : CObjClassFactory()
{
	TcDbgUnitSetImageName(TCDBG_UNIT_IMAGE_NAME(SRVNAME_KUKA_INTERFACE)); 
#if defined(TCDBG_UNIT_VERSION)
	TcDbgUnitSetVersion(TCDBG_UNIT_VERSION(kuka_interface));
#endif //defined(TCDBG_UNIT_VERSION)
}
