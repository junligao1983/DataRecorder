// MyFormView2.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "MyFormView2.h"
#include "MyFormView.h"

// MyFormView2

IMPLEMENT_DYNCREATE(MyFormView2, CFormView)

MyFormView2::MyFormView2()
	: CFormView(IDD_FORMVIEW1)
{

}

MyFormView2::~MyFormView2()
{
}

void MyFormView2::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(MyFormView2, CFormView)
END_MESSAGE_MAP()


// MyFormView2 诊断

#ifdef _DEBUG
void MyFormView2::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void MyFormView2::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


CSplitterWnd m_wndSplitter2;
BOOL MyFormView2::OnCreateClient(LPCREATESTRUCT /*lpcs*/, CCreateContext *pContext)
{
	if (!m_wndSplitter2.CreateStatic(this, 1, 2))
		return FALSE;

	if (!m_wndSplitter2.CreateView(0, 0, RUNTIME_CLASS(MyFormView), CSize(160, 200), pContext) ||
		!m_wndSplitter2.CreateView(0, 1, RUNTIME_CLASS(MyFormView), CSize(100, 200), pContext))
	{
		m_wndSplitter2.DestroyWindow();
		return FALSE;
	}
	return TRUE;
}

// MyFormView2 消息处理程序
