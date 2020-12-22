///////////////////////////////////////////////////////////////////////////////
// kuka_interfaceCtrl.h

#ifndef __KUKA_INTERFACECTRL_H__
#define __KUKA_INTERFACECTRL_H__

#include <atlbase.h>
#include <atlcom.h>

#define KUKA_INTERFACEDRV_NAME "KUKA_INTERFACE"

#include "resource.h"       // main symbols
#include "kuka_interfaceW32.h"
#include "TcBase.h"
#include "kuka_interfaceClassFactory.h"
#include "TcOCFCtrlImpl.h"

class Ckuka_interfaceCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<Ckuka_interfaceCtrl, &CLSID_kuka_interfaceCtrl>
	, public Ikuka_interfaceCtrl
	, public ITcOCFCtrlImpl<Ckuka_interfaceCtrl, Ckuka_interfaceClassFactory>
{
public:
	Ckuka_interfaceCtrl();
	virtual ~Ckuka_interfaceCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_KUKA_INTERFACECTRL)
DECLARE_NOT_AGGREGATABLE(Ckuka_interfaceCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(Ckuka_interfaceCtrl)
	COM_INTERFACE_ENTRY(Ikuka_interfaceCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __KUKA_INTERFACECTRL_H__
