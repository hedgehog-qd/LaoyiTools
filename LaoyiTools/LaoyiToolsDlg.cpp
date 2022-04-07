
// LaoyiToolsDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "LaoyiTools.h"
#include "LaoyiToolsDlg.h"
#include "afxdialogex.h"
#include "windows.h"
#include "cstring"
#include "afxinet.h"
#include  <direct.h>  
#include "string"
#pragma comment(lib,"URlmon")
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
int selfnumber = 0;
bool autopic;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLaoyiToolsDlg 对话框



CLaoyiToolsDlg::CLaoyiToolsDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LAOYITOOLS_DIALOG, pParent)
	, NUMBER(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CLaoyiToolsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, NUMBER);
}

BEGIN_MESSAGE_MAP(CLaoyiToolsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CLaoyiToolsDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_RADIO2, &CLaoyiToolsDlg::OnBnClickedRadio2)
	//ON_BN_CLICKED(IDC_CHECK2, &CLaoyiToolsDlg::OnBnClickedCheck2)
	//ON_NOTIFY(NM_CUSTOMDRAW, IDC_PROGRESS1, &CLaoyiToolsDlg::OnNMCustomdrawProgress1)
	ON_BN_CLICKED(IDC_RADIO3, &CLaoyiToolsDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_BUTTON1, &CLaoyiToolsDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CLaoyiToolsDlg 消息处理程序

BOOL CLaoyiToolsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CLaoyiToolsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CLaoyiToolsDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CLaoyiToolsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLaoyiToolsDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	UpdateData(true);
	selfnumber = _ttoi(NUMBER);
	//selfnumber = NUMBER;
	// TODO:  在此添加控件通知处理程序代码
}


void CLaoyiToolsDlg::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	autopic = false;
}


void CLaoyiToolsDlg::OnBnClickedCheck2()
{
	// TODO: 在此添加控件通知处理程序代码
}





void CLaoyiToolsDlg::OnBnClickedRadio3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	autopic = true;
}

int GetFileAuto() {

	char buffer[MAX_PATH];
	_getcwd(buffer, MAX_PATH);
	strcat_s(buffer, "//picture.jpg");
	HRESULT Result = URLDownloadToFileA(NULL, "https://api.hedgehog-qd.xyz/PixPics/pixpics.php", buffer, 0, NULL);
	switch (Result)
	{
	case S_OK:printf("The download started successfully.\n"); break;
	case E_OUTOFMEMORY: printf("The buffer length is invalid, or there is insufficient memory to complete the operation.\n"); break;
	}
	return 0;

}
int GetAutoSet(int a) {

	char buffer[MAX_PATH];
	_getcwd(buffer, MAX_PATH);
	strcat_s(buffer, "//pictureself.jpg");
	//CString part1 = (CString)'https://api.hedgehog-qd.xyz/PixPics/PictureBase/';
	//CString part2 = a;
	//CString part3 = (CString)".jpg";
	//CString pp = part1 + part2 + part3;
	//LPCSTR p = (LPCSTR)pp.GetBuffer(pp.GetLength());
	//MessageBoxA(0, p, "消息", 3);
	//LPCSTR p = (LPCSTR)pp;
	string ppp = "https://api.hedgehog-qd.xyz/PixPics/PictureBase/" + to_string(a) + (string)".jpg";
	LPCSTR p = ppp.c_str();
	MessageBoxA(0, p, "将会从以下URL下载", 1);
	HRESULT Result = URLDownloadToFileA(NULL, p, buffer, 0, NULL);
	switch (Result)
	{
	case S_OK: printf("The download started successfully.\n"); break;
	case E_OUTOFMEMORY: printf("The buffer length is invalid, or there is insufficient memory to complete the operation.\n"); break;
	}
	return 0;
}
void CLaoyiToolsDlg::OnBnClickedButton1()
{
	UpdateData(true);
	// TODO: 在此添加控件通知处理程序代码
	if (autopic == true) {
		int p = GetFileAuto();
		if (p == 0) {
			MessageBoxA(0, "成功下载保存！", "状态", 1);
		}
		
	}
	else {
		int p = GetAutoSet(selfnumber);
		if (p == 0) {
			MessageBoxA(0, "成功下载自定义图片并保存！", "状态", 1);
		}
	}
}

