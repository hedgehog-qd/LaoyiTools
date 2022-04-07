﻿
// LaoyiToolsDlg.h: 头文件
//

#pragma once


// CLaoyiToolsDlg 对话框
class CLaoyiToolsDlg : public CDialogEx
{
// 构造
public:
	CLaoyiToolsDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAOYITOOLS_DIALOG };
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
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnNMCustomdrawProgress1(NMHDR* pNMHDR, LRESULT* pResult);
	CString NUMBER;
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedButton1();
};
