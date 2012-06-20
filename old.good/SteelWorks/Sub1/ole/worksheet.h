#if !defined(AFX_WORKSHEET_H__6BBEE42D_550F_409B_BDDC_E20BF2D3F64F__INCLUDED_)
#define AFX_WORKSHEET_H__6BBEE42D_550F_409B_BDDC_E20BF2D3F64F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CRange;
class CPanes;
class CProtection;
class CAutoFilter;

/////////////////////////////////////////////////////////////////////////////
// CWorksheet wrapper class

class CWorksheet : public COleDispatchDriver
{
public:
	CWorksheet() {}		// Calls COleDispatchDriver default constructor
	CWorksheet(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWorksheet(const CWorksheet& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	void Calculate();
	void Export(LPCTSTR FileName, long ExportAction);
	void Scroll(LPDISPATCH Range);
	VARIANT Eval(LPCTSTR Formula);
	void ShowAllData();
	CRange GetCells();
	CRange GetColumns();
	BOOL GetEnableAutoCalculate();
	void SetEnableAutoCalculate(BOOL bNewValue);
	BOOL GetEnableAutoFilter();
	void SetEnableAutoFilter(BOOL bNewValue);
	BOOL GetFreezePanes();
	CPanes GetPanes();
	LPDISPATCH GetParent();
	CProtection GetProtection();
	CRange GetRange(const VARIANT& Cell1, const VARIANT& Cell2);
	CRange GetRows();
	CRange GetUsedRange();
	CString GetViewableRange();
	void SetViewableRange(LPCTSTR lpszNewValue);
	CRange GetVisibleRange();
	CAutoFilter GetAutoFilter();
	BOOL GetAutoFilterMode();
	void SetAutoFilterMode(BOOL bNewValue);
	BOOL GetFilterMode();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORKSHEET_H__6BBEE42D_550F_409B_BDDC_E20BF2D3F64F__INCLUDED_)