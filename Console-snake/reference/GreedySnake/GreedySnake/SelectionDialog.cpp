// SelectionDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "GreedySnake.h"
#include "SelectionDialog.h"


// CSelectionDialog 对话框

IMPLEMENT_DYNAMIC(CSelectionDialog, CDialog)

CSelectionDialog::CSelectionDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CSelectionDialog::IDD, pParent)
	, m_nSelection(IDC_RADIO_SINGLE)
{
	m_pView = NULL;
}

CSelectionDialog::CSelectionDialog(CView* pView) : m_pView(pView)
{
}

BOOL CSelectionDialog::Create()
{
	return CDialog::Create(CSelectionDialog::IDD);
}

CSelectionDialog::~CSelectionDialog()
{
}

void CSelectionDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO_SINGLE, m_nSelection);
}


BEGIN_MESSAGE_MAP(CSelectionDialog, CDialog)
	ON_BN_CLICKED(IDOK, &CSelectionDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CSelectionDialog::OnBnClickedCancel)
END_MESSAGE_MAP()


// CSelectionDialog 消息处理程序

void CSelectionDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_pView != NULL)
	{
		UpdateData(TRUE);
		m_pView->PostMessage(WM_GOODBYE, IDOK);
		this->DestroyWindow();
	}
	else
		CDialog::OnOK();
}

void CSelectionDialog::OnBnClickedCancel()
{
	CDialog::OnCancel();
}
