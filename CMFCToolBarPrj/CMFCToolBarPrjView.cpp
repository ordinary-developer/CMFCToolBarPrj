
// CMFCToolBarPrjView.cpp : implementation of the CCMFCToolBarPrjView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CMFCToolBarPrj.h"
#endif

#include "CMFCToolBarPrjDoc.h"
#include "CMFCToolBarPrjView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCMFCToolBarPrjView

IMPLEMENT_DYNCREATE(CCMFCToolBarPrjView, CView)

BEGIN_MESSAGE_MAP(CCMFCToolBarPrjView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CCMFCToolBarPrjView construction/destruction

CCMFCToolBarPrjView::CCMFCToolBarPrjView() noexcept
{
	// TODO: add construction code here

}

CCMFCToolBarPrjView::~CCMFCToolBarPrjView()
{
}

BOOL CCMFCToolBarPrjView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCMFCToolBarPrjView drawing

void CCMFCToolBarPrjView::OnDraw(CDC* /*pDC*/)
{
	CCMFCToolBarPrjDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CCMFCToolBarPrjView printing

BOOL CCMFCToolBarPrjView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCMFCToolBarPrjView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCMFCToolBarPrjView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CCMFCToolBarPrjView diagnostics

#ifdef _DEBUG
void CCMFCToolBarPrjView::AssertValid() const
{
	CView::AssertValid();
}

void CCMFCToolBarPrjView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCMFCToolBarPrjDoc* CCMFCToolBarPrjView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCMFCToolBarPrjDoc)));
	return (CCMFCToolBarPrjDoc*)m_pDocument;
}
#endif //_DEBUG


// CCMFCToolBarPrjView message handlers
