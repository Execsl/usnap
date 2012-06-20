#if !defined(AFX_BORDERS_H__B9713D7E_F0CB_4E5B_BD97_FE9895AE7043__INCLUDED_)
#define AFX_BORDERS_H__B9713D7E_F0CB_4E5B_BD97_FE9895AE7043__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CBorder;

/////////////////////////////////////////////////////////////////////////////
// CBorders wrapper class

class CBorders : public COleDispatchDriver
{
public:
	CBorders() {}		// Calls COleDispatchDriver default constructor
	CBorders(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CBorders(const CBorders& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	VARIANT GetColor();
	void SetColor(VARIANT* newValue);
	VARIANT GetLineStyle();
	void SetLineStyle(long nNewValue);
	LPDISPATCH GetParent();
	VARIANT GetWeight();
	void SetWeight(long nNewValue);
	long GetCount();
	CBorder GetItem(const VARIANT& Index);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BORDERS_H__B9713D7E_F0CB_4E5B_BD97_FE9895AE7043__INCLUDED_)