///////////////////////////////////////////////////////////////////////////////
// motive_interfaceCtrl.h

#ifndef __MOTIVE_INTERFACECTRL_H__
#define __MOTIVE_INTERFACECTRL_H__

#include <atlbase.h>
#include <atlcom.h>

#define MOTIVE_INTERFACEDRV_NAME "MOTIVE_INTERFACE"

#include "resource.h"       // main symbols
#include "motive_interfaceW32.h"
#include "TcBase.h"
#include "motive_interfaceClassFactory.h"
#include "TcOCFCtrlImpl.h"

class Cmotive_interfaceCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<Cmotive_interfaceCtrl, &CLSID_motive_interfaceCtrl>
	, public Imotive_interfaceCtrl
	, public ITcOCFCtrlImpl<Cmotive_interfaceCtrl, Cmotive_interfaceClassFactory>
{
public:
	Cmotive_interfaceCtrl();
	virtual ~Cmotive_interfaceCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_MOTIVE_INTERFACECTRL)
DECLARE_NOT_AGGREGATABLE(Cmotive_interfaceCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(Cmotive_interfaceCtrl)
	COM_INTERFACE_ENTRY(Imotive_interfaceCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __MOTIVE_INTERFACECTRL_H__
