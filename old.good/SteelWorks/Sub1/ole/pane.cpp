// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


#include "stdafx.h"
#include "pane.h"

// Dispatch interfaces referenced by this interface
#include "Range.h"


/////////////////////////////////////////////////////////////////////////////
// CPane properties

/////////////////////////////////////////////////////////////////////////////
// CPane operations

LPDISPATCH CPane::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x60020000, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CRange CPane::GetVisibleRange()
{
	LPDISPATCH pDispatch;
	InvokeHelper(0x60020001, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
	return CRange(pDispatch);
}

long CPane::GetIndex()
{
	long result;
	InvokeHelper(0x60020002, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}