// kuka_interfaceCtrl.cpp : Implementation of CTckuka_interfaceCtrl
#include "TcPch.h"
#pragma hdrstop

#include "kuka_interfaceW32.h"
#include "kuka_interfaceCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// Ckuka_interfaceCtrl

Ckuka_interfaceCtrl::Ckuka_interfaceCtrl() 
	: ITcOCFCtrlImpl<Ckuka_interfaceCtrl, Ckuka_interfaceClassFactory>() 
{
}

Ckuka_interfaceCtrl::~Ckuka_interfaceCtrl()
{
}

