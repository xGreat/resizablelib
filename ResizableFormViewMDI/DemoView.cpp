// DemoView.cpp : implementation of the CDemoView class
//

#include "stdafx.h"
#include "Demo.h"

#include "DemoDoc.h"
#include "DemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoView

IMPLEMENT_DYNCREATE(CDemoView, CResizableFormView)

BEGIN_MESSAGE_MAP(CDemoView, CResizableFormView)
	//{{AFX_MSG_MAP(CDemoView)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoView construction/destruction

CDemoView::CDemoView()
	: CResizableFormView(CDemoView::IDD)
{
	//{{AFX_DATA_INIT(CDemoView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CDemoView::~CDemoView()
{
}

void CDemoView::DoDataExchange(CDataExchange* pDX)
{
	CResizableFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDemoView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CResizableFormView::PreCreateWindow(cs);
}

void CDemoView::OnInitialUpdate()
{
	AddAnchor(IDC_EDIT1, TOP_LEFT, CSize(40,100));
	AddAnchor(IDC_BUTTON1, BOTTOM_LEFT, CSize(40,100));
	AddAnchor(IDC_BUTTON2, BOTTOM_LEFT, CSize(40,100));
	AddAnchor(IDC_GROUP1, CSize(40,0), BOTTOM_RIGHT);
	AddAnchor(IDC_COMBO1, CSize(40,0), TOP_RIGHT);
	AddAnchor(IDC_RADIO1, CSize(70,0), CSize(70,0));
	AddAnchor(IDC_RADIO2, CSize(70,0), CSize(70,0));
	AddAnchor(IDC_STATIC1, CSize(40,0), BOTTOM_RIGHT);
	AddAnchor(IDC_ICON1, CSize(40,0), CSize(70,0));

	CResizableFormView::OnInitialUpdate();
	ResizeParentToFit();
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView diagnostics

#ifdef _DEBUG
void CDemoView::AssertValid() const
{
	CResizableFormView::AssertValid();
}

void CDemoView::Dump(CDumpContext& dc) const
{
	CResizableFormView::Dump(dc);
}

CDemoDoc* CDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemoDoc)));
	return (CDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemoView message handlers

void CDemoView::OnButton2() 
{
	// ever wanted a real dialog?
	ModifyStyleEx(WS_EX_CLIENTEDGE, 0, SWP_FRAMECHANGED);
	GetParent()->ModifyStyle(WS_THICKFRAME, WS_DLGFRAME, SWP_FRAMECHANGED);
}

void CDemoView::OnButton1() 
{
	// go back to formview
	ModifyStyleEx(0, WS_EX_CLIENTEDGE, SWP_FRAMECHANGED);
	GetParent()->ModifyStyle(WS_DLGFRAME, WS_THICKFRAME|WS_CAPTION, SWP_FRAMECHANGED);
}
