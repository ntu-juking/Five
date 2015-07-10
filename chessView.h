// chessView.h : interface of the CChessView class
//
/////////////////////////////////////////////////////////////////////////////
# include< vector >
#if !defined(AFX_CHESSVIEW_H__85781938_5989_4D3A_A8AC_DBCEB20A4EFC__INCLUDED_)
#define AFX_CHESSVIEW_H__85781938_5989_4D3A_A8AC_DBCEB20A4EFC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CChessView : public CView
{
	bool isWin(CPoint cp);
	std::vector<CPoint> chessVec;
	bool isLocation (CPoint cp);
	void Location(CPoint cp);
protected: // create from serialization only
	CChessView();
	DECLARE_DYNCREATE(CChessView)

// Attributes
public:
	CChessDoc* GetDocument();

// Operations
public:
void Checkerboard(CDC*pDC);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChessView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CChessView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CChessView)
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnCancelMode();
	afx_msg void OnCaptureChanged(CWnd *pWnd);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in chessView.cpp
inline CChessDoc* CChessView::GetDocument()
   { return (CChessDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHESSVIEW_H__85781938_5989_4D3A_A8AC_DBCEB20A4EFC__INCLUDED_)
