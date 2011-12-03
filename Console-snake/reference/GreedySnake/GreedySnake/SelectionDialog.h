/*
////////////////////////////////////////////////////////

Team member:
	聂森 莫小琪 彭云波 陈飞宇 尹伦琴 陈沁茜 李朝朝 

Date:
	3.2008 ~ 5.2008

所有权限归 cqu. mstc. Team Satan 所有.

////////////////////////////////////////////////////////
*/

#pragma once
#include "afxwin.h"

#define WM_GOODBYE WM_USER+5

// CSelectionDialog 对话框

class CSelectionDialog : public CDialog
{
	DECLARE_DYNAMIC(CSelectionDialog)

public:
	CSelectionDialog(CWnd* pParent = NULL);   // 标准构造函数
	CSelectionDialog(CView* pView);
	BOOL Create();
	virtual ~CSelectionDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CView* m_pView;
public:
	int m_nSelection;
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
