// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


#include "stdafx.h"
#include "webcalc.h"

// Dispatch interfaces referenced by this interface
#include "range.h"
#include "pane.h"
#include "Worksheet.h"
#include "TitleBar.h"

/////////////////////////////////////////////////////////////////////////////
// CWebCalc

IMPLEMENT_DYNCREATE(CWebCalc, CWnd)

/////////////////////////////////////////////////////////////////////////////
// CWebCalc properties

/////////////////////////////////////////////////////////////////////////////
// CWebCalc operations

void CWebCalc::AddIn(LPDISPATCH AddIn)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x60020001, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 AddIn);
}

CRange CWebCalc::Intersect(LPDISPATCH Range1, LPDISPATCH Range2)
{
	LPDISPATCH pDispatch;
	static BYTE parms[] =
		VTS_DISPATCH VTS_DISPATCH;
	InvokeHelper(0x60020002, DISPATCH_METHOD, VT_DISPATCH, (void*)&pDispatch, parms,
		Range1, Range2);
	return CRange(pDispatch);
}

CRange CWebCalc::Union(LPDISPATCH Range1, LPDISPATCH Range2)
{
	LPDISPATCH pDispatch;
	static BYTE parms[] =
		VTS_DISPATCH VTS_DISPATCH;
	InvokeHelper(0x60020003, DISPATCH_METHOD, VT_DISPATCH, (void*)&pDispatch, parms,
		Range1, Range2);
	return CRange(pDispatch);
}

void CWebCalc::BeginUndo()
{
	InvokeHelper(0x60020004, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CWebCalc::EndUndo()
{
	InvokeHelper(0x60020005, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CWebCalc::Undo()
{
	InvokeHelper(0x60020006, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CWebCalc::Refresh()
{
	InvokeHelper(0x60020007, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CWebCalc::LoadText(LPCTSTR File, LPCTSTR Delimiters, BOOL ConsecutiveDelimAsOne, LPCTSTR TextQualifier)
{
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_BOOL VTS_BSTR;
	InvokeHelper(0x60020008, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 File, Delimiters, ConsecutiveDelimAsOne, TextQualifier);
}

void CWebCalc::UpdatePropertyToolbox()
{
	InvokeHelper(0x60020009, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

CRange CWebCalc::GetActiveCell()
{
	LPDISPATCH pDispatch;
	InvokeHelper(0x6002000a, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
	return CRange(pDispatch);
}

CPane CWebCalc::GetActivePane()
{
	LPDISPATCH pDispatch;
	InvokeHelper(0x6002000b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
	return CPane(pDispatch);
}

CWorksheet CWebCalc::GetActiveSheet()
{
	LPDISPATCH pDispatch;
	InvokeHelper(0x6002000c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
	return CWorksheet(pDispatch);
}

BOOL CWebCalc::GetAllowPropertyToolbox()
{
	BOOL result;
	InvokeHelper(0x404, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWebCalc::SetAllowPropertyToolbox(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x404, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CRange CWebCalc::GetCells()
{
	LPDISPATCH pDispatch;
	InvokeHelper(0x6002000f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
	return CRange(pDispatch);
}

CRange CWebCalc::GetColumns()
{
	LPDISPATCH pDispatch;
	InvokeHelper(0x60020010, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
	return CRange(pDispatch);
}

BOOL CWebCalc::GetDirty()
{
	BOOL result;
	InvokeHelper(0x60020011, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWebCalc::SetDirty(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x60020011, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CWebCalc::GetDisplayColHeaders()
{
	BOOL result;
	InvokeHelper(0x3ec, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWebCalc::SetDisplayColHeaders(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3ec, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CWebCalc::GetDisplayGridlines()
{
	BOOL result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWebCalc::SetDisplayGridlines(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CWebCalc::GetDisplayHorizontalScrollBar()
{
	BOOL result;
	InvokeHelper(0x3ed, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWebCalc::SetDisplayHorizontalScrollBar(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3ed, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CWebCalc::GetDisplayPropertyToolbox()
{
	BOOL result;
	InvokeHelper(0x409, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWebCalc::SetDisplayPropertyToolbox(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x409, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CWebCalc::GetDisplayRowHeaders()
{
	BOOL result;
	InvokeHelper(0x3eb, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWebCalc::SetDisplayRowHeaders(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3eb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CWebCalc::GetDisplayTitleBar()
{
	BOOL result;
	InvokeHelper(0x3ef, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWebCalc::SetDisplayTitleBar(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3ef, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CWebCalc::GetDisplayToolbar()
{
	BOOL result;
	InvokeHelper(0x3f0, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWebCalc::SetDisplayToolbar(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3f0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CWebCalc::GetDisplayVerticalScrollBar()
{
	BOOL result;
	InvokeHelper(0x3ee, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWebCalc::SetDisplayVerticalScrollBar(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3ee, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CWebCalc::GetAutoFit()
{
	BOOL result;
	InvokeHelper(0x401, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWebCalc::SetAutoFit(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x401, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

VARIANT CWebCalc::GetMaxHeight()
{
	VARIANT result;
	InvokeHelper(0x407, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
	return result;
}

void CWebCalc::SetMaxHeight(const VARIANT& newValue)
{
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0x407, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 &newValue);
}

VARIANT CWebCalc::GetMaxWidth()
{
	VARIANT result;
	InvokeHelper(0x408, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
	return result;
}

void CWebCalc::SetMaxWidth(const VARIANT& newValue)
{
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0x408, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 &newValue);
}

BOOL CWebCalc::GetEnableAutoCalculate()
{
	BOOL result;
	InvokeHelper(0x3f1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWebCalc::SetEnableAutoCalculate(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3f1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CWebCalc::GetEnableEvents()
{
	BOOL result;
	InvokeHelper(0x3f2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWebCalc::SetEnableEvents(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3f2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString CWebCalc::GetHTMLData()
{
	CString result;
	InvokeHelper(0x3f5, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CWebCalc::SetHTMLData(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3f5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CWebCalc::GetHtmlurl()
{
	CString result;
	InvokeHelper(0x3f6, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CWebCalc::SetHtmlurl(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3f6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CWebCalc::GetCSVData()
{
	CString result;
	InvokeHelper(0x402, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CWebCalc::SetCSVData(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x402, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CWebCalc::GetCsvurl()
{
	CString result;
	InvokeHelper(0x403, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CWebCalc::SetCsvurl(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x403, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CWebCalc::GetDataType()
{
	CString result;
	InvokeHelper(0x3f7, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CWebCalc::SetDataType(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3f7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL CWebCalc::GetMoveAfterReturn()
{
	BOOL result;
	InvokeHelper(0x3f8, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWebCalc::SetMoveAfterReturn(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3f8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long CWebCalc::GetMoveAfterReturnDirection()
{
	long result;
	InvokeHelper(0x3f9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CWebCalc::SetMoveAfterReturnDirection(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x3f9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CRange CWebCalc::GetRange(const VARIANT& Cell1, const VARIANT& Cell2)
{
	LPDISPATCH pDispatch;
	static BYTE parms[] =
		VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x6002003b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, parms,
		&Cell1, &Cell2);
	return CRange(pDispatch);
}

BOOL CWebCalc::GetRightToLeft()
{
	BOOL result;
	InvokeHelper(0x405, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWebCalc::SetRightToLeft(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x405, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CRange CWebCalc::GetRows()
{
	LPDISPATCH pDispatch;
	InvokeHelper(0x6002003e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
	return CRange(pDispatch);
}

BOOL CWebCalc::GetScreenUpdating()
{
	BOOL result;
	InvokeHelper(0x3fd, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWebCalc::SetScreenUpdating(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3fd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CRange CWebCalc::GetSelection()
{
	LPDISPATCH pDispatch;
	InvokeHelper(0x60020041, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
	return CRange(pDispatch);
}

CTitleBar CWebCalc::GetTitleBar()
{
	LPDISPATCH pDispatch;
	InvokeHelper(0x60020042, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
	return CTitleBar(pDispatch);
}

CString CWebCalc::GetViewableRange()
{
	CString result;
	InvokeHelper(0x3fe, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CWebCalc::SetViewableRange(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3fe, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CWebCalc::GetVersion()
{
	CString result;
	InvokeHelper(0x60020045, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

BOOL CWebCalc::GetEnableUndo()
{
	BOOL result;
	InvokeHelper(0x406, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWebCalc::SetEnableUndo(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x406, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CWebCalc::GetCanUndo()
{
	BOOL result;
	InvokeHelper(0x60020048, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

LPDISPATCH CWebCalc::GetConstants()
{
	LPDISPATCH result;
	InvokeHelper(0x60020049, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long CWebCalc::GetMajorVersion()
{
	long result;
	InvokeHelper(0x6002004a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

CString CWebCalc::GetMinorVersion()
{
	CString result;
	InvokeHelper(0x6002004b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString CWebCalc::GetBuildNumber()
{
	CString result;
	InvokeHelper(0x6002004c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString CWebCalc::GetRevisionNumber()
{
	CString result;
	InvokeHelper(0x6002004d, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}
