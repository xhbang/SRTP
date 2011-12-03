// GreedySnakeDoc.cpp : CGreedySnakeDoc 类的实现
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


// CGreedySnakeDoc 构造/析构

CGreedySnakeDoc::CGreedySnakeDoc()
{
	// TODO: 在此添加一次性构造代码

}

CGreedySnakeDoc::~CGreedySnakeDoc()
{
}

BOOL CGreedySnakeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CGreedySnakeDoc 序列化

void CGreedySnakeDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CGreedySnakeDoc 诊断

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


// CGreedySnakeDoc 命令
