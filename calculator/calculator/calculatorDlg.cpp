
// calculatorDlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CcalculatorDlg �Ի���



CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDITSHOW, mEdit); //������ϵ
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


// CcalculatorDlg ��Ϣ�������

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CFont* m_font = new CFont;
	m_font->CreateFont(36, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_SWISS, _T("����"));
	mEdit.SetFont(m_font, FALSE);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CcalculatorDlg::OnEnChangeEditshow()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorDlg::OnBnClickedEsc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	mEdit.SetWindowText(_T(""));
}


void CcalculatorDlg::OnBnClickedDelete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CString str;
	//�Ƴ����ұ�һ���ַ�  
	CString str;
	UpdateData(TRUE);
	mEdit.GetWindowText(str);
	str = str.Left(str.GetLength() - 1);
	mEdit.SetWindowText(str);
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	mEdit.GetWindowText(str);
	if (str != "")
	{
		str = str + _T("=");
		Mark = true;
		CT2CA pszConvertedAnsiString(str);  // �� TCHAR ת��Ϊ LPCSTR
		string exp_str(pszConvertedAnsiString); // �� LPCSTR ���� string
	
		Scan *p1 = new Scan();  /*�����ڴ� */
		Calculation *cal = new Calculation();
		string strGetInputRet;

		p1->setinput(exp_str);
		strGetInputRet = p1->getinput();
		double results;
		string tmp; 
		results = cal->CaculateExpression(p1->ToStringQueue(strGetInputRet)); //������н��м��� 
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// TODO: Add your control notification handler code here   
	// ���ù�����   
	TCHAR szFilter[] = _T("�ı��ļ�(*.txt)|*.txt|�����ļ�(*.*)|*.*||");
	// ������ļ��Ի���   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	CString strFilePath;

	// ��ʾ���ļ��Ի���   
	if (IDOK == fileDlg.DoModal())
	{
		// ���������ļ��Ի����ϵġ��򿪡���ť����ѡ����ļ�·����ʾ���༭����   
		strFilePath = fileDlg.GetPathName();
		SetDlgItemText(IDC_OPEN_EDIT, strFilePath);
	}
}


void CcalculatorDlg::OnBnClickedSaveButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// TODO: Add your control notification handler code here   
	// ���ù�����   
	TCHAR szFilter[] = _T("�ı��ļ�(*.txt)|*.txt|Word�ļ�(*.doc)|*.doc|�����ļ�(*.*)|*.*||");
	// ���챣���ļ��Ի���   
	CFileDialog fileDlg(FALSE, _T("doc"), _T("my"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);
	CString strFilePath;

	// ��ʾ�����ļ��Ի���   
	if (IDOK == fileDlg.DoModal())
	{
		// ���������ļ��Ի����ϵġ����桱��ť����ѡ����ļ�·����ʾ���༭����   
		strFilePath = fileDlg.GetPathName();
		SetDlgItemText(IDC_SAVE_EDIT, strFilePath);
	}
}


void CcalculatorDlg::OnEnChangeOpenEdit()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
	CString strOpenFile;
	UpdateData(TRUE);
	writeEdit.GetWindowText(strOpenFile);
	CT2CA pszConvertedAnsiString(strOpenFile);  // �� TCHAR ת��Ϊ LPCSTR
	string test_str(pszConvertedAnsiString); // �� LPCSTR ���� string
	test_str_ = test_str;
	//Choose_Mark1 = true;
	UpdateData(FALSE);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������*/
}


void CcalculatorDlg::OnEnChangeSaveEdit()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
	CString strSaveFile;
	UpdateData(TRUE);
	readEdit.GetWindowText(strSaveFile);
	CT2CA pszConvertedAnsiString(strSaveFile);  // �� TCHAR ת��Ϊ LPCSTR
	string results_str(pszConvertedAnsiString); // �� LPCSTR ���� string
	results_str_ = results_str;
	//Choose_Mark2 = true;
	UpdateData(FALSE);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������*/
}


void CcalculatorDlg::OnBnClickedButtoncount()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	PPrint *t = new PPrint();
	t->FileOutput(test_str_, results_str_);  //����pprint��������
	delete t;
	t = NULL;
}


void CcalculatorDlg::OnBnClickedButtonexitover()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}
