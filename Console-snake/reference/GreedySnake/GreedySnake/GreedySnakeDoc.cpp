// GreedySnakeDoc.cpp : CGreedySnakeDoc ���ʵ��
//

#include "stdafx.h"
#include "GreedySnake.h"

#include "GreedySnakeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGreedySnakeDoc

IMPLEMENT_DYNCREATE(CGreedySnakeDoc, CDocument)

BEGIN_MESSAGE_MAP(CGreedySnakeDoc, CDocument)
END_MESSAGE_MAP()


// CGreedySnakeDoc ����/����

CGreedySnakeDoc::CGreedySnakeDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CGreedySnakeDoc::~CGreedySnakeDoc()
{
}

BOOL CGreedySnakeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CGreedySnakeDoc ���л�

void CGreedySnakeDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CGreedySnakeDoc ���

#ifdef _DEBUG
void CGreedySnakeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGreedySnakeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CGreedySnakeDoc ����
