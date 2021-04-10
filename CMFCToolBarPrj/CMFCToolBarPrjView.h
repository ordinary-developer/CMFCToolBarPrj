
// CMFCToolBarPrjView.h : interface of the CCMFCToolBarPrjView class
//

#pragma once


class CCMFCToolBarPrjView : public CView
{
protected: // create from serialization only
	CCMFCToolBarPrjView() noexcept;
	DECLARE_DYNCREATE(CCMFCToolBarPrjView)

// Attributes
public:
	CCMFCToolBarPrjDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CCMFCToolBarPrjView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CMFCToolBarPrjView.cpp
inline CCMFCToolBarPrjDoc* CCMFCToolBarPrjView::GetDocument() const
   { return reinterpret_cast<CCMFCToolBarPrjDoc*>(m_pDocument); }
#endif

