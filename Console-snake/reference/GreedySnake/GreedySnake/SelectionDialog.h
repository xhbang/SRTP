/*
////////////////////////////////////////////////////////

Team member:
	��ɭ ĪС�� ���Ʋ� �·��� ������ ������ ��� 

Date:
	3.2008 ~ 5.2008

����Ȩ�޹� cqu. mstc. Team Satan ����.

////////////////////////////////////////////////////////
*/

#pragma once
#include "afxwin.h"

#define WM_GOODBYE WM_USER+5

// CSelectionDialog �Ի���

class CSelectionDialog : public CDialog
{
	DECLARE_DYNAMIC(CSelectionDialog)

public:
	CSelectionDialog(CWnd* pParent = NULL);   // ��׼���캯��
	CSelectionDialog(CView* pView);
	BOOL Create();
	virtual ~CSelectionDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CView* m_pView;
public:
	int m_nSelection;
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
