// chessView.cpp : implementation of the CChessView class
//

#include "stdafx.h"
#include "chess.h"

#include "chessDoc.h"
#include "chessView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// CChessView

int a;
int chessArr[20][20];
IMPLEMENT_DYNCREATE(CChessView, CView)

BEGIN_MESSAGE_MAP(CChessView, CView)
	//{{AFX_MSG_MAP(CChessView)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_CANCELMODE()
	ON_WM_CAPTURECHANGED()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChessView construction/destruction

CChessView::CChessView()
{
	// TODO: add construction code here
      a=0;
	  for(int i=0;i<20;i++)
		  {
		  for(int j=0;j<20;j++)
			  {
			  chessArr[i][j]==0; 
		  }
	  }
}

CChessView::~CChessView()
{
}
bool CChessView::isLocation(CPoint cp) 
{
	bool isLoc = true;
	for(int i = 0;i < chessVec.size();i++)
	{
		if(cp.x== chessVec[i].x && cp.y == chessVec[i].y)
		{
			isLoc = false;
		}
	}
	return isLoc;
}
void CChessView::Location(CPoint cp) 
{
	chessVec.push_back(cp);
}

bool CChessView::isWin(CPoint cp)
{
	int cp_x=cp.x/50;
	 int cp_y=cp.y/50;
	 int i = cp_x;
	 int j = cp_y;
     int count = 1;
	 int nowChessColor = chessArr[cp_x][cp_y];
	 while(1)
	 {
		 if(i > 0 && i < 20)
		 {
			 i--;
			 if( nowChessColor == chessArr[i][j] )
			 {
				 count++;
				 if( count == 5 )
				 {
					 return true;
				 }
				 }
            else
			{
				break;
			}
		 }
		 else
		 {
			 break;
		 }
	 }
	 i = cp_x;
	 while(1) 
	 {
		 if(i > 0 && i < 20) 
		 {
			 i++;
			 if( nowChessColor == chessArr[i][j] ) 
			 {
				 count++;
				 if( count == 5 )
				 {
					 return true ;
				 }
			 }
			 else
			{
				break;
			}
		 }
        else
		 {
			 break;
		 }
	 }
	 i = cp_x;
	 count = 1;
     while(1)
	 {
		 if(j > 0 && j < 20)
		 {
			 j--;
			 if( nowChessColor == chessArr[i][j] )
			 {
				 count++;
				 if( count == 5 )
				 {
					 return true;
				 }
				 }
            else
			{
				break;
			}
		 }
		 else
		 {
			 break;
		 }
	 }
	 j = cp_y ;
while(1) 
	 {
		 if(j > 0 && j < 20) 
		 {
			 j++;
			 if( nowChessColor == chessArr[i][j] ) 
			 {
				 count++;
				 if( count == 5 )
				 {
					 return true ;
				 }
			 }
			 else
			
			 {
				break;
			}
		 }
		  else
		  {
			 break;
		 }
	 }
            j = cp_y;
            count = 1;
			while(1) 
			{
				if(j > 0 && j < 20 && i > 0 && i < 20) 
				{
					j++;
					i++;
					if( nowChessColor == chessArr[i][j] )
					{
						count++;
						if( count == 5 )
						{
							return true;
						}
					}
					else
			{
				break;
			}
		 }
        else
		 {
			 break;
		 }
	 }
			j = cp_y;
			i = cp_x;
			while(1) 

{
				if(j > 0 && j < 20 && i > 0 && i < 20) 
				{
					j--;
					i--;
					if( nowChessColor == chessArr[i][j] )
					{
						count++;
						if( count == 5 )
						{
							return true;
						}
					}
					else
			{
				break;
			}
		 }
        else
		 {
			 break;
		 }
	 }
			j = cp_y;
			i = cp_x;
			count = 1;
          while(1) 

		  {
				if(j > 0 && j < 20 && i > 0 && i < 20) 
				{
					j++;
					i--;
					if( nowChessColor == chessArr[i][j] )
					{
						count++;
						if( count == 5 )
						{
							return true;
						}
					}
					else
			{
				break;
			}
		 }
        else
		 {
			 break;
		 }
	 }
		  j = cp_y;
		  
		  i = cp_x;
          while(1) 

		  {
				if(j > 0 && j < 20 && i > 0 && i < 20) 
				{
					j--;
					i++;
					if( nowChessColor == chessArr[i][j] )
					{
						count++;
						if( count == 5 )
						{
							return true;
						}
					}
					else
			{
				break;
			}
		 }
        else
		 {
			 break;
		 }
	 }
            j = cp_y;
			i = cp_x;
			count = 1;
           return false;
}
BOOL CChessView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
			
			return CView::PreCreateWindow(cs);
}	

/////////////////////////////////////////////////////////////////////////////
// CChessView drawing

void CChessView::Checkerboard(CDC*pDC)
{
	for(int i=0;i<20;i++)
		{ 
		pDC->MoveTo(i*50,0);
		pDC->LineTo(i*50,1000);
	}
	for(i=0;i<20;i++) 
		{    
		pDC->MoveTo(0,i*50);    
		pDC->LineTo(1000,i*50);   
} 
}
void CChessView::OnDraw(CDC* pDC)
{

	CChessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	Checkerboard(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CChessView printing

BOOL CChessView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CChessView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CChessView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CChessView diagnostics

#ifdef _DEBUG
void CChessView::AssertValid() const
{
	CView::AssertValid();
}

void CChessView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CChessDoc* CChessView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CChessDoc)));
	return (CChessDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChessView message handlers

void CChessView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

			
	CView::OnLButtonDblClk(nFlags, point);
	
}

void CChessView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (a==1){
	CBrush* brush = new CBrush(RGB(255,255,255));
		CDC* pDC = this->GetDC();
	pDC->SelectObject(brush);
    for(int i = 0 ; i < 1000 ; i+=50)
		{for(int j = 0 ; j < 1000;  j+=50)
		{
		CRect rect(i,j,i+50,j+50);
		CPoint tempPoint;
		tempPoint = rect.CenterPoint();
		if(rect.PtInRect(point)&& isLocation(tempPoint)) 
		{
			pDC->Ellipse(tempPoint.x-20,tempPoint.y-20,tempPoint.x+20,tempPoint.y+20); 
			Location(tempPoint); 
			chessArr[tempPoint.x/50][tempPoint.y/50] = 2;
			if( isWin(point) )
			{
				MessageBox("白色棋子获胜！"); 
			}
			a--;
		}
	}
	}
	}
	CView::OnRButtonDown(nFlags, point);
}

void CChessView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
		if (a==0){
	CBrush* brush = new CBrush(RGB(0,0,0));
		CDC* pDC = this->GetDC();
	pDC->SelectObject(brush);
    for(int i = 0 ; i < 1000 ; i+=50)
		{
		for(int j = 0 ; j < 1000;  j+=50)
		{
			CRect rect(i,j,i+50,j+50); 
			CPoint tempPoint;
			tempPoint = rect.CenterPoint();
			if(rect.PtInRect(point)&&isLocation(tempPoint) )
			{
				pDC->Ellipse(tempPoint.x-20,tempPoint.y-20,tempPoint.x+20,tempPoint.y+20);
	            Location(tempPoint);
				chessArr[tempPoint.x/50][tempPoint.y/50] = 1;
                  if( isWin(point) )
				  {
					  MessageBox("黑色棋子获胜！"); 
				  }
				  a++;
			}
		}
	}
	}
	CView::OnLButtonDown(nFlags, point);
}

void CChessView::OnCancelMode() 
{
	CView::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}

void CChessView::OnCaptureChanged(CWnd *pWnd) 
{
	// TODO: Add your message handler code here
	
	CView::OnCaptureChanged(pWnd);
}
