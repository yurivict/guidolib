/*
	GUIDO Library
	Copyright (C) 2002  Holger Hoos, Juergen Kilian, Kai Renz

	This library is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 2.1 of the License, or (at your option) any later version.

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public
	License along with this library; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/
#if !defined(AFX_M2GCONVDIALOG_H__F3C94AD1_DED9_45C6_A2C5_26B1FAD863EC__INCLUDED_)
#define AFX_M2GCONVDIALOG_H__F3C94AD1_DED9_45C6_A2C5_26B1FAD863EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"

/////////////////////////////////////////////////////////////////////////////
// Dialogbox CM2GConvDialog 

class CM2GConvDialog : public CDialog
{
// construction
public:
	CM2GConvDialog(CWnd* pParent = NULL);   // Standardconstructor

	int m_isfulllog;
// Dialogboxdata
	//{{AFX_DATA(CM2GConvDialog)
	enum { IDD = IDD_M2G_CONVERSION_LOG };
	CButton	m_fulllog;
	CString	m_logtext;
	//}}AFX_DATA


// overrides
	// virtual overrides generated by the class wizzar
	//{{AFX_VIRTUAL(CM2GConvDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-support
	//}}AFX_VIRTUAL

// implementation
protected:

	// generated message maps 	//{{AFX_MSG(CM2GConvDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnFulllog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// MS Visual C++ inserts directly before the previous line additional deklarations

#endif // AFX_M2GCONVDIALOG_H__F3C94AD1_DED9_45C6_A2C5_26B1FAD863EC__INCLUDED_