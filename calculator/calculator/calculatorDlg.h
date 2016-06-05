
// calculatorDlg.h : 头文件
//

#pragma once
#include"Scan.h"
#include"Calculation.h"
#include "Operate.h"
#include "PPrint.h"
// CcalculatorDlg 对话框
class CcalculatorDlg : public CDialogEx
{
// 构造
public:
	CcalculatorDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit mEdit;
	bool Mark=false;
	CEdit writeEdit;
	CEdit readEdit;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedEsc();
	afx_msg void OnEnChangeEditshow();
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedLeftbracket();
	afx_msg void OnBnClickedRightbracket();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedMinus();
	afx_msg void OnBnClickedMultiply();
	afx_msg void OnBnClickedDivide();
	afx_msg void OnBnClickedPoint();
	afx_msg void OnBnClickedEqual();
	afx_msg void OnBnClickedOpenButton();
	afx_msg void OnBnClickedSaveButton();
	afx_msg void OnEnChangeOpenEdit();
	afx_msg void OnEnChangeSaveEdit();
	afx_msg void OnBnClickedButtoncount();
	afx_msg void OnBnClickedButtonexitover();
};
