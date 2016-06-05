
// calculatorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"
#include "PPrint.h"
#include<sstream>
#include <string>

string test_str_, results_str_;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CcalculatorDlg 对话框



CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDITSHOW, mEdit); //建立联系
	DDX_Control(pDX, IDC_OPEN_EDIT, writeEdit);
	DDX_Control(pDX, IDC_SAVE_EDIT, readEdit);

}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ESC, &CcalculatorDlg::OnBnClickedEsc)
	ON_EN_CHANGE(IDC_EDITSHOW, &CcalculatorDlg::OnEnChangeEditshow)
	ON_BN_CLICKED(IDC_DELETE, &CcalculatorDlg::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_BUTTON1, &CcalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CcalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CcalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CcalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CcalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CcalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CcalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CcalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CcalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON0, &CcalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_LeftBracket, &CcalculatorDlg::OnBnClickedLeftbracket)
	ON_BN_CLICKED(IDC_RightBracket, &CcalculatorDlg::OnBnClickedRightbracket)
	ON_BN_CLICKED(IDC_ADD, &CcalculatorDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_MINUS, &CcalculatorDlg::OnBnClickedMinus)
	ON_BN_CLICKED(IDC_MULTIPLY, &CcalculatorDlg::OnBnClickedMultiply)
	ON_BN_CLICKED(IDC_DIVIDE, &CcalculatorDlg::OnBnClickedDivide)
	ON_BN_CLICKED(IDC_POINT, &CcalculatorDlg::OnBnClickedPoint)
	ON_BN_CLICKED(IDC_EQUAL, &CcalculatorDlg::OnBnClickedEqual)
	ON_BN_CLICKED(IDC_OPEN_BUTTON, &CcalculatorDlg::OnBnClickedOpenButton)
	ON_BN_CLICKED(IDC_SAVE_BUTTON, &CcalculatorDlg::OnBnClickedSaveButton)
	ON_EN_CHANGE(IDC_OPEN_EDIT, &CcalculatorDlg::OnEnChangeOpenEdit)
	ON_EN_CHANGE(IDC_SAVE_EDIT, &CcalculatorDlg::OnEnChangeSaveEdit)
	ON_BN_CLICKED(IDC_BUTTONCOUNT, &CcalculatorDlg::OnBnClickedButtoncount)
	ON_BN_CLICKED(IDC_BUTTONEXITOVER, &CcalculatorDlg::OnBnClickedButtonexitover)
END_MESSAGE_MAP()


// CcalculatorDlg 消息处理程序

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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
	CFont* m_font = new CFont;
	m_font->CreateFont(36, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_SWISS, _T("宋体"));
	mEdit.SetFont(m_font, FALSE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CcalculatorDlg::OnPaint()
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
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CcalculatorDlg::OnEnChangeEditshow()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CcalculatorDlg::OnBnClickedEsc()
{
	// TODO: 在此添加控件通知处理程序代码
	mEdit.SetWindowText(_T(""));
}


void CcalculatorDlg::OnBnClickedDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	//CString str;
	//移除最右边一个字符  
	CString str;
	UpdateData(TRUE);
	mEdit.GetWindowText(str);
	str = str.Left(str.GetLength() - 1);
	mEdit.SetWindowText(str);
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (Mark == true)
	{
		mEdit.SetWindowText(_T(""));
	}
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("1");
	mEdit.SetWindowText(str);
	Mark = false;
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (Mark == true)
	{
		mEdit.SetWindowText(_T(""));
	}
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("2");	
	mEdit.SetWindowText(str);
	Mark = false;
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (Mark == true)
	{
		mEdit.SetWindowText(_T(""));
	}
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("3");
	mEdit.SetWindowText(str);
	Mark = false;
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (Mark == true)
	{
		mEdit.SetWindowText(_T(""));
	}
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("4");
	mEdit.SetWindowText(str);
	Mark = false;
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (Mark == true)
	{
		mEdit.SetWindowText(_T(""));
	}
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("5");	Mark = false;
	mEdit.SetWindowText(str);

	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (Mark == true)
	{
		mEdit.SetWindowText(_T(""));
	}
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("6");	
	mEdit.SetWindowText(str);
	Mark = false;
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (Mark == true)
	{
		mEdit.SetWindowText(_T(""));
	}
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("7");	
	mEdit.SetWindowText(str);
	Mark = false;
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (Mark == true)
	{
		mEdit.SetWindowText(_T(""));
	}
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("8");	
	mEdit.SetWindowText(str);
	Mark = false;
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (Mark == true)
	{
		mEdit.SetWindowText(_T(""));
	}
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("9");	
	mEdit.SetWindowText(str);
	Mark = false;
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton0()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (Mark == true)
	{
		mEdit.SetWindowText(_T(""));
	}
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("0");
	mEdit.SetWindowText(str);
	Mark = false;
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedLeftbracket()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (Mark == true)
	{
		mEdit.SetWindowText(_T(""));
	}
	CString str;
	mEdit.GetWindowText(str);
	if (str == "")
	{
		str = str + _T("(");
	}
	else
	{
		if (str.GetAt(str.GetLength() - 1)<'0' || str.GetAt(str.GetLength() - 1)>'9')
		{
			str = str + _T("(");
		}
	}
	mEdit.SetWindowText(str);
	Mark = false;
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedRightbracket()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (Mark == true)
	{
		mEdit.SetWindowText(_T(""));
	}
	CString str;
	mEdit.GetWindowText(str);
	if (str != "")
	{
		str = str + _T(")");
	}
	mEdit.SetWindowText(str);
	Mark = false;
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (Mark == true)
	{
		mEdit.SetWindowText(_T(""));
	}
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("+");	
	mEdit.SetWindowText(str);
	Mark = false;
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedMinus()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (Mark == true)
	{
		mEdit.SetWindowText(_T(""));
	}
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("-");
	mEdit.SetWindowText(str);
	Mark = false;
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedMultiply()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	mEdit.GetWindowText(str);
	if (str != ""&&Mark==false)
	{
		if (str.GetAt(str.GetLength() - 1) != '+' && str.GetAt(str.GetLength() - 1) != '-'
			&& str.GetAt(str.GetLength() - 1) != '*' && str.GetAt(str.GetLength() - 1) != '/')
		{
			str = str + _T("*");
		}
	}
	mEdit.SetWindowText(str);
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedDivide()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString str;
	mEdit.GetWindowText(str);
	if (str != ""&&Mark==false)
	{
		if (str.GetAt(str.GetLength() - 1) != '+' && str.GetAt(str.GetLength() - 1) != '-'
			&& str.GetAt(str.GetLength() - 1) != '*' && str.GetAt(str.GetLength() - 1) != '/')
		{
			str = str + _T("/");
		}
	}
	mEdit.SetWindowText(str);
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedPoint()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString str;
	mEdit.GetWindowText(str);
	if (str != ""&&Mark==false)
	{
		if (str.GetAt(str.GetLength() - 1) >= '0' && str.GetAt(str.GetLength() - 1) <= '9')
		{
			str = str + _T(".");
		}
	}
	mEdit.SetWindowText(str);
	UpdateData(FALSE);
}



void CcalculatorDlg::OnBnClickedEqual()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	mEdit.GetWindowText(str);
	if (str != "")
	{
		str = str + _T("=");
		Mark = true;
		CT2CA pszConvertedAnsiString(str);  // 将 TCHAR 转换为 LPCSTR
		string exp_str(pszConvertedAnsiString); // 从 LPCSTR 构造 string
	
		Scan *p1 = new Scan();  /*申请内存 */
		Calculation *cal = new Calculation();
		string strGetInputRet;

		p1->setinput(exp_str);
		strGetInputRet = p1->getinput();
		double results;
		string tmp; 
		results = cal->CaculateExpression(p1->ToStringQueue(strGetInputRet)); //传入队列进行计算 
		stringstream ss;
		ss << results;
		ss >> tmp;
		str= tmp.c_str();
		delete p1;
		p1 = NULL;
		delete cal;
		cal = NULL;
	}
	mEdit.SetWindowText(str);
	UpdateData(FALSE);
}


BOOL CcalculatorDlg::PreTranslateMessage(MSG* pMsg)
{
	bool flag = true;
	CWnd *pFocusWnd = GetFocus(); 
	if (pFocusWnd && (pFocusWnd == GetDlgItem(IDC_OPEN_EDIT) || pFocusWnd == GetDlgItem(IDC_SAVE_EDIT)))
	{
		flag = false;
	}
	else
	{
		flag = true;
	}
	if (pMsg->message == WM_KEYDOWN&&flag )
	{
		switch (pMsg->wParam)
		{
		case VK_NUMPAD0:
			OnBnClickedButton0(); break;
		case VK_NUMPAD1:
		case '1':
			OnBnClickedButton1(); break;
		case '2':
		case VK_NUMPAD2:
			OnBnClickedButton2(); break;
		case '3':
		case VK_NUMPAD3:
			OnBnClickedButton3(); break;
		case '4':
		case VK_NUMPAD4:
			OnBnClickedButton4(); break;
		case '5':
		case VK_NUMPAD5:
			OnBnClickedButton5(); break;
		case '6':
		case VK_NUMPAD6:
			OnBnClickedButton6(); break;
		case '7':
		case VK_NUMPAD7:
			OnBnClickedButton7(); break;
		case VK_NUMPAD8:
			OnBnClickedButton8(); break;
		case VK_NUMPAD9:
			OnBnClickedButton9();
			break;
		case '8':
			if (GetKeyState(VK_SHIFT) < 0)
			{
				OnBnClickedMultiply();
			}
			else
			{
				OnBnClickedButton8();
			}
			break;
		case '9':
			if (GetKeyState(VK_SHIFT) < 0)
			{
				OnBnClickedLeftbracket();
			}
			else
			{
				OnBnClickedButton9();
			}
			break;
		case '0':
			if (GetKeyState(VK_SHIFT) < 0)
			{
				OnBnClickedRightbracket();
			}
			else
			{
				OnBnClickedButton0();
			}
			break;
		case VK_OEM_PLUS:
			if (GetKeyState(VK_SHIFT) < 0)
			{
				OnBnClickedAdd();
			}
			else
			{
				OnBnClickedEqual();
			}
			break;
		case VK_OEM_PERIOD:
		case VK_DECIMAL:
			OnBnClickedPoint(); break;
		case VK_SUBTRACT:
		case VK_OEM_MINUS:
			OnBnClickedMinus(); break;
		case VK_DIVIDE:
		case VK_OEM_2:
			OnBnClickedDivide(); break;
		case VK_ADD:
			OnBnClickedAdd(); break;
		case VK_MULTIPLY:
			OnBnClickedMultiply(); break;
		case VK_BACK:
			OnBnClickedDelete(); break;
		case VK_RETURN:
			OnBnClickedEqual(); return TRUE;
		case VK_ESCAPE:
			OnBnClickedEsc(); return TRUE;
		default:
			break;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}



void CcalculatorDlg::OnBnClickedOpenButton()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: Add your control notification handler code here   
	// 设置过滤器   
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	// 构造打开文件对话框   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	CString strFilePath;

	// 显示打开文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
		strFilePath = fileDlg.GetPathName();
		SetDlgItemText(IDC_OPEN_EDIT, strFilePath);
	}
}


void CcalculatorDlg::OnBnClickedSaveButton()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: Add your control notification handler code here   
	// 设置过滤器   
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|Word文件(*.doc)|*.doc|所有文件(*.*)|*.*||");
	// 构造保存文件对话框   
	CFileDialog fileDlg(FALSE, _T("doc"), _T("my"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);
	CString strFilePath;

	// 显示保存文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“保存”按钮，则将选择的文件路径显示到编辑框里   
		strFilePath = fileDlg.GetPathName();
		SetDlgItemText(IDC_SAVE_EDIT, strFilePath);
	}
}


void CcalculatorDlg::OnEnChangeOpenEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	CString strOpenFile;
	UpdateData(TRUE);
	writeEdit.GetWindowText(strOpenFile);
	CT2CA pszConvertedAnsiString(strOpenFile);  // 将 TCHAR 转换为 LPCSTR
	string test_str(pszConvertedAnsiString); // 从 LPCSTR 构造 string
	test_str_ = test_str;
	//Choose_Mark1 = true;
	UpdateData(FALSE);
	// TODO:  在此添加控件通知处理程序代码*/
}


void CcalculatorDlg::OnEnChangeSaveEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	CString strSaveFile;
	UpdateData(TRUE);
	readEdit.GetWindowText(strSaveFile);
	CT2CA pszConvertedAnsiString(strSaveFile);  // 将 TCHAR 转换为 LPCSTR
	string results_str(pszConvertedAnsiString); // 从 LPCSTR 构造 string
	results_str_ = results_str;
	//Choose_Mark2 = true;
	UpdateData(FALSE);
	// TODO:  在此添加控件通知处理程序代码*/
}


void CcalculatorDlg::OnBnClickedButtoncount()
{
	// TODO: 在此添加控件通知处理程序代码
	PPrint *t = new PPrint();
	t->FileOutput(test_str_, results_str_);  //传入pprint批量计算
	delete t;
	t = NULL;
}


void CcalculatorDlg::OnBnClickedButtonexitover()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}
