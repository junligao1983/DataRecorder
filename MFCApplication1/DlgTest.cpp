// DlgTest.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "DlgTest.h"
#include "afxdialogex.h"
#include <iostream>
#include "MyFormView.h"
using std::cout;
using std::endl;

// DlgTest 对话框

IMPLEMENT_DYNAMIC(DlgTest, CDialogEx)

DlgTest::DlgTest(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, editIntBind(0)
{

}


DlgTest::~DlgTest()
{

}

CSplitterWnd m_wndSplitter3;
int DlgTest::OnCreate(LPCREATESTRUCT)
{
	if (!m_wndSplitter3.CreateStatic(this, 1, 2))
		return FALSE;

	if (!m_wndSplitter3.CreateView(0, 0, RUNTIME_CLASS(MyFormView), CSize(160, 200), NULL) ||
		!m_wndSplitter3.CreateView(0, 1, RUNTIME_CLASS(MyFormView), CSize(100, 200), NULL))
	{
		m_wndSplitter3.DestroyWindow();
		return FALSE;
	}
	return 0;
}

int DlgTest::FunPointerTest(int a, int b)
{
	return a + b;
}

void DlgTest::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LISTBOX, listBox);

	listBox.AddString(_T("123"));
	listBox.AddString(_T("456"));
	DDX_Control(pDX, IDGetCurrentText, btnGetCurrentText);
	DDX_Control(pDX, IDC_EDIT1, txtFilePath);
	DDX_Control(pDX, IDGetCurrentText2, btnSelectFile);
	DDX_Control(pDX, IDC_LIST2, listControl);
	DDX_Control(pDX, IDC_ListControl2, btnMemcpy);
	DDX_Control(pDX, IDC_TREE1, treeView);
	DDX_Control(pDX, IDC_ListControl3, btnLoadTreeview);
	DDX_Control(pDX, IDC_COMBO1, comBox);
	DDX_Control(pDX, IDC_COMBOBOXEX2, comBoxEX);
	DDX_Control(pDX, IDC_BUTTON1, btnReadTime);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, dtPicker);
	DDX_Control(pDX, IDC_BUTTON2, btnStartThread);
	DDX_Control(pDX, IDC_EDIT2, txtThreadText);
	DDX_Text(pDX, IDC_EDIT1, editIntBind);
	DDV_MinMaxInt(pDX, editIntBind, 2, 10);
}

BEGIN_MESSAGE_MAP(DlgTest, CDialogEx)
	ON_BN_CLICKED(IDOK, &DlgTest::OnBnClickedOk)
	ON_BN_CLICKED(IDGetCurrentText, &DlgTest::OnBnClickedGetcurrenttext)
	ON_BN_CLICKED(IDGetCurrentText2, &DlgTest::OnBnClickedGetcurrenttext2)
	ON_BN_CLICKED(IDC_ListControl, &DlgTest::OnBnClickedListcontrol)
	ON_BN_CLICKED(IDC_ListControl2, &DlgTest::OnBnClickedListcontrol2)
	ON_BN_CLICKED(IDC_ListControl3, &DlgTest::OnBnClickedListcontrol3)
	ON_BN_CLICKED(IDC_BUTTON1, &DlgTest::OnBnClickedButton1)
	ON_COMMAND(ID_APP_ABOUT, &DlgTest::ContextMenuTest)
	ON_WM_TIMER()
	ON_WM_CONTEXTMENU()
	ON_BN_CLICKED(IDC_BUTTON2, &DlgTest::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &DlgTest::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &DlgTest::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &DlgTest::OnBnClickedButton5)
	ON_MESSAGE(WM_MY_MESSAGE, OnMyMessage)
	ON_BN_CLICKED(IDC_BUTTON6, &DlgTest::OnBnClickedButton6)
	ON_BN_CLICKED(IDOK2, &DlgTest::OnBnClickedOk2)
	ON_BN_CLICKED(IDC_BUTTON7, &DlgTest::OnBnClickedButton7)
END_MESSAGE_MAP()


// DlgTest 消息处理程序

void DlgTest::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
}


void DlgTest::OnBnClickedGetcurrenttext()
{
	CString str;
	int index = listBox.GetCurSel();
	listBox.GetText(index, str);
	listBox.SetCurSel(1);
	AfxMessageBox(str);
	// TODO: 在此添加控件通知处理程序代码
}


void DlgTest::OnBnClickedGetcurrenttext2()
{
	CFileDialog dlg(true);
	dlg.DoModal();
	CString name = dlg.GetFileName();
	CString path = dlg.GetFolderPath();
	txtFilePath.SetWindowText(name);
	AfxMessageBox(name);
	// TODO: 在此添加控件通知处理程序代码
}


void DlgTest::ContextMenuTest()
{
	AfxMessageBox(_T("右键菜单响应！"));
}

void DlgTest::OnBnClickedListcontrol()
{
	listControl.InsertItem(0, _T("王小五儿"), 1);
	listControl.SetItemText(0, 1, _T("20"));

	listControl.InsertItem(1, _T("张三"), 0);
	listControl.SetItemText(1, 1, _T("40"));
	// TODO: 在此添加控件通知处理程序代码
}

BOOL DlgTest::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetTimer(1, 1000, NULL);
	listControl.InsertColumn(0, _T("姓名"), LVCFMT_LEFT, 60, -1);
	listControl.InsertColumn(1, _T("年龄"), LVCFMT_LEFT, 60, -1);
	m_ImgList.Create(16, 16, ILC_COLOR24, 11, 0);//创建CImageList对象	
	m_ImgList.SetBkColor(RGB(255, 255, 255));//设置背景色	
	UINT nIconID[] = { IDR_MAINFRAME,IDR_MFCApplication1TYPE };
	//依次将图标ID加入链表
	for (int index = 0; index < 2; index++)
	{
		m_ImgList.Add(AfxGetApp()->LoadIcon(nIconID[index]));
	}
	comBox.AddString(_T("1"));
	comBox.AddString(_T("1"));
	comBox.AddString(_T("1"));
	comBox.AddString(_T("1"));
	comBox.AddString(_T("1"));
	comBox.AddString(_T("1"));
	treeView.SetImageList(&m_ImgList, LVSIL_SMALL);
	listControl.SetImageList(&m_ImgList, LVSIL_SMALL);
	comBoxEX.SetImageList(&m_ImgList);
	COMBOBOXEXITEM     cbi;
	CString            str;
	int                nItem;

	cbi.mask = CBEIF_IMAGE | CBEIF_INDENT | CBEIF_OVERLAY |
		CBEIF_SELECTEDIMAGE | CBEIF_TEXT;

	cbi.iItem = 0;
	cbi.pszText = _T("TEST");
	cbi.cchTextMax = str.GetLength();
	cbi.iImage = 0;
	cbi.iSelectedImage = 1;
	cbi.iOverlay = 2;
	nItem = comBoxEX.InsertItem(&cbi);
	//comBoxEX.AddString(_T("2"));
	//comBoxEX.AddString(_T("2"));
	//comBoxEX.AddString(_T("2"));
	// TODO:  在此添加额外的初始化
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void DlgTest::OnBnClickedListcontrol2()
{
	const char src[50] = "http://www.runoob.com";
	char dest[50];
	memcpy(dest, src, strlen(src) + 1);
	CString str = CString(dest);
	AfxMessageBox(str);
	// TODO: 在此添加控件通知处理程序代码
}

void DlgTest::OnBnClickedListcontrol3()
{
	HTREEITEM hRoot, hCur;//树控制项目句柄
	TVINSERTSTRUCT TCItem;//插入数据项数据
	TCItem.hParent = TVI_ROOT;//增加根项
	TCItem.hInsertAfter = TVI_LAST;//在最后项之后
	TCItem.item.mask = TVIF_TEXT | TVIF_PARAM | TVIF_IMAGE | TVIF_SELECTEDIMAGE;//设屏蔽
	TCItem.item.pszText = _T("数据选择");
	TCItem.item.lParam = 0;//序号
	TCItem.item.iImage = 0;//正常图标
	TCItem.item.iSelectedImage = 1;//选中时图标
	hRoot = treeView.InsertItem(&TCItem);//返回根项句柄
	treeView.EditLabel(hRoot);
	// TODO: 在此添加控件通知处理程序代码
}

void DlgTest::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CTime time;
	dtPicker.GetTime(time);
	AfxMessageBox(time.Format("%Y-%m-%d %H:%M:%S %W-%A"));
}

void DlgTest::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDialogEx::OnTimer(nIDEvent);
	txtFilePath.SetWindowTextW(_T("ON Timer"));
	//AfxMessageBox(_T("123"));
}


void DlgTest::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	// TODO: 在此处添加消息处理程序代码
	CMenu menu;
	menu.LoadMenu(IDR_MENU1);
	CMenu * pMenu;
	pMenu = menu.GetSubMenu(0);
	pMenu->EnableMenuItem(ID_APP_ABOUT, MF_BYCOMMAND | MF_ENABLED);
	pMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
	pMenu->Detach();
	menu.DestroyMenu();
}


void DlgTest::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	hThread1 = CreateThread(NULL, 0, Fun1Procx, this, 0, NULL);
	CloseHandle(hThread1);
}

DWORD WINAPI Fun1Procx(LPVOID lpParameter)
{
	while (true)
	{
		DlgTest* dlg = (DlgTest*)lpParameter;
		CTime ctime;
		ctime = ctime.GetCurrentTime();
		Sleep(100);
		dlg->txtThreadText.SetWindowTextW(ctime.Format("%Y-%m-%d %H:%M:%S %W-%A"));
		//这里的线程不是UI线程，调用UI线程需要使用SendMessage发送消息即可。
	}
	return 0;
}

void DlgTest::OnBnClickedButton3()
{
	funPointer  fp = FunPointerTestx;//该函数为全局函数
	int x = fp(5, 7);
	// TODO: 在此添加控件通知处理程序代码
}

int FunPointerTestx(int a, int b)
{
	return a + b;
}

int DlgTest::add(int x, int y)
{	
	AfxMessageBox(_T("指向类成员函数的指针被调用了！"));
	return 1;
}
int DlgTest::testClassMemberFunc(addFunc x)
{ 
	int k = ((*this).*x)(1, 2);
	AfxMessageBox(_T("成员函数指针回调成功！"));
	return 0;
}
void DlgTest::OnBnClickedButton4()
{
	addFunc af = &DlgTest::add;
	DlgTest dg;
	int k = (dg.*af)(1, 2);
	testClassMemberFunc(af);
	//函数返回指针
}

void DlgTest::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	CString* str = new CString("123456");
	::SendMessage(m_hWnd, WM_USER + 100, 1, (LPARAM)str);
}

LRESULT  DlgTest::OnMyMessage(WPARAM wParam, LPARAM lParam)
{
	CString* str = (CString*)lParam;
	AfxMessageBox(*str);
	return true;
}

void DlgTest::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
}

void DlgTest::OnBnClickedOk2()
{
	// TODO: 在此添加控件通知处理程序代码
}

void DlgTest::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
}