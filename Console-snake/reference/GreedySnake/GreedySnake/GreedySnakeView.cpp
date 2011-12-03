// GreedySnakeView.cpp : CGreedySnakeView 类的实现
//

#include "stdafx.h"
#include "GreedySnake.h"

#include "GreedySnakeDoc.h"
#include "GreedySnakeView.h"
#include "SelectionDialog.h"

#include "Manager.h"
#include "Snake.h"
#include "CtrledSnake.h"
#include "AutoSnake.h"
#include "Strategy.h"
#include "SuikayStrategy.h"

#define TIMER1 1
#define TIMER2 2

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGreedySnakeView

IMPLEMENT_DYNCREATE(CGreedySnakeView, CView)

BEGIN_MESSAGE_MAP(CGreedySnakeView, CView)
	ON_COMMAND(ID_32771, &CGreedySnakeView::OnGameStart)
	ON_MESSAGE(WM_GOODBYE, OnGoodbye)
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()

LRESULT CGreedySnakeView::OnGoodbye(WPARAM wParam, LPARAM lParam)
{
	m_bClose = FALSE;
	m_pDlg->DestroyWindow();
	setGame();

	//Manager::theManager()->refreshBlocks();
	//Invalidate(FALSE);
	SetTimer(TIMER1, TIME_RUN_INTERVAL, NULL);
	SetTimer(TIMER2, TIME_SWITCH_MAP, NULL);
	return 0L;
}

// CGreedySnakeView 构造/析构

CGreedySnakeView::CGreedySnakeView()
: m_bClose(FALSE)
{
	// TODO: 在此处添加构造代码
	m_pDlg = new CSelectionDialog(this);
	m_bmpBackGound.LoadBitmap(IDB_BITMAP1);
	m_bmpBrick.LoadBitmap(IDB_BITMAP4);
	m_bmpSnakeBody.LoadBitmap(IDB_BITMAP5);
	m_bmpFruit.LoadBitmap(IDB_BITMAP3);
	m_bmpSnakeHead.LoadBitmap(IDB_BITMAP2);
	m_bmpGameOver.LoadBitmap(IDB_BITMAP6);
}

CGreedySnakeView::~CGreedySnakeView()
{
	delete m_pDlg;
	m_bmpBackGound.DeleteObject();
	m_bmpBrick.DeleteObject();
	m_bmpSnakeBody.DeleteObject();
	m_bmpSnakeHead.DeleteObject();
	m_bmpFruit.DeleteObject();
	m_bmpGameOver.DeleteObject();
}

BOOL CGreedySnakeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	return CView::PreCreateWindow(cs);
}

// CGreedySnakeView 绘制

void CGreedySnakeView::OnDraw(CDC* pDC)
{
	// TODO: 在此处为本机数据添加绘制代码
	CDC memDC;
	CDC tempDC;
	CBitmap memBmp;

	CRect rectClient;
	GetClientRect(rectClient);

	memDC.CreateCompatibleDC(pDC);
	tempDC.CreateCompatibleDC(pDC);
	memBmp.CreateCompatibleBitmap(pDC, rectClient.right, rectClient.bottom);
	memDC.SelectObject(&memBmp);

	drawBackgound(&tempDC, &memDC, rectClient);
	drawMap(&tempDC, &memDC);

	pDC->BitBlt(0, 0, rectClient.right, rectClient.bottom, &memDC, 0, 0, SRCCOPY);
	tempDC.DeleteDC();
	memDC.DeleteDC();
	pDC->SelectStockObject(BLACK_BRUSH);
}

void CGreedySnakeView::drawBackgound(CDC* tempDC, CDC* memDC, CRect& rectClient)
{
	tempDC->SelectObject(&m_bmpBackGound);
	memDC->BitBlt(0, 0, rectClient.right, rectClient.bottom, tempDC, 0, 0, SRCCOPY);
}

void CGreedySnakeView::drawMap(CDC* tempDC, CDC* memDC)
{
	int tempMap[MAP_HEIGHT][MAP_WIDTH];
	memcpy(tempMap,Manager::theManager()->getBlocks(),sizeof(tempMap));
	// Manger 构造函数中调用initialGame 已经loadMap

	for (int i = 0; i < MAP_HEIGHT; ++i)
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			switch(tempMap[i][j])
			{
			case MAP_OBSTACLE:
				tempDC->SelectObject(&m_bmpBrick);
				memDC->BitBlt(j*10, i*10, 10, 10, tempDC, 0, 0, SRCCOPY);
				break;

			case MAP_FRUIT:
				tempDC->SelectObject(&m_bmpFruit);
				memDC->BitBlt(j*10, i*10, 10, 10, tempDC, 0, 0, SRCCOPY);
				break;

			case MAP_SNAKE_BODY:
				tempDC->SelectObject(&m_bmpSnakeBody);
				memDC->BitBlt(j*10, i*10, 10, 10, tempDC, 0, 0, SRCCOPY);
				break;

			case MAP_SNAKE_HEAD:
				tempDC->SelectObject(&m_bmpSnakeHead);
				memDC->BitBlt(j*10, i*10, 10, 10, tempDC, 0, 0, SRCCOPY);
				break;
			}
		}
}

void CGreedySnakeView::drawGameOver()
{
	CClientDC dc(this);
	CDC memDC;
	CRect rectClient;
	GetClientRect(rectClient);

	memDC.CreateCompatibleDC(&dc);
	memDC.SelectObject(&m_bmpGameOver);

	dc.BitBlt(0, 0, rectClient.right, rectClient.bottom, &memDC, 400, 400, SRCCOPY);

	CFont font;
	font.CreateFont(120, 0, 0, 0, FW_NORMAL,
		FALSE, FALSE, 0,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS, _T("Arial"));

	dc.SelectObject(&font);
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(::GetSysColor( COLOR_3DHILIGHT));
	dc.DrawText( _T("   Game Over!   "), CRect(12, 230, 800, 330), 
		DT_SINGLELINE | DT_LEFT |DT_VCENTER|DT_CENTER);
	dc.SelectStockObject(BLACK_BRUSH);
	font.DeleteObject();

	memDC.DeleteDC();
}

// CGreedySnakeView 诊断

#ifdef _DEBUG
void CGreedySnakeView::AssertValid() const
{
	CView::AssertValid();
}

void CGreedySnakeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGreedySnakeDoc* CGreedySnakeView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGreedySnakeDoc)));
	return (CGreedySnakeDoc*)m_pDocument;
}
#endif //_DEBUG


// CGreedySnakeView 消息处理程序

void CGreedySnakeView::OnGameStart()
{
	// TODO: 在此添加命令处理程序代码
	if (m_pDlg->GetSafeHwnd() == NULL)
	{
		m_pDlg->Create();
	}
}

void CGreedySnakeView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_bClose == FALSE && nIDEvent == TIMER1)
	{
		if(!Manager::theManager()->isAllDead())
		{
			Manager::theManager()->refresh();
			Invalidate(FALSE);
		}
		else
		{
			m_bClose = TRUE;
			drawGameOver();
			/*if(Manager::theManager()->initialGame())
			{
				setGame();
				Invalidate(FALSE);
			}*/
		}
	}
	else if(m_bClose == FALSE && nIDEvent == TIMER2)
	{
		if(Manager::theManager()->initialGame())
		{
			setGame();
			Invalidate(FALSE);
		}
		else
		{
			m_bClose = TRUE;
			drawGameOver();
		}
	}

	CView::OnTimer(nIDEvent);
}


void CGreedySnakeView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch(nChar)
	{
	case VK_LEFT:
		Manager::theManager()->setSnakeDirection(0, LEFT);
		break;
	case VK_RIGHT:
		Manager::theManager()->setSnakeDirection(0, RIGHT);
		break;
	case VK_UP:
		Manager::theManager()->setSnakeDirection(0, UP);
		break;
	case VK_DOWN:
		Manager::theManager()->setSnakeDirection(0, DOWN);
		break;
	}

	if(m_pDlg->m_nSelection != MODE_SINGLE)
	{
		switch(nChar)
		{
		case MOVE_LEFT1: case MOVE_LEFT2:
			Manager::theManager()->setSnakeDirection(1, LEFT);
			break;
		case MOVE_RIGHT1: case MOVE_RIGHT2:
			Manager::theManager()->setSnakeDirection(1, RIGHT);
			break;
		case MOVE_UP1: case MOVE_UP2:
			Manager::theManager()->setSnakeDirection(1, UP);
			break;
		case MOVE_DOWN1: case MOVE_DOWN2:
			Manager::theManager()->setSnakeDirection(1, DOWN);
			break;
		}
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

bool CGreedySnakeView::setGame(void)
{
	/*if(!Manager::theManager()->initialGame())
		return false;*/

	Snake *p1, *p2, *p3, *p4;
	if (m_pDlg->m_nSelection == MODE_SINGLE)
	{
		std::list<CPoint> l1;
		l1.push_back(CPoint(1, 1));
		DIRECTION d1 = RIGHT;
		p1 = new CtrledSnake(l1, d1);

		Strategy* strategy1 = new SuikayStrategy();
		std::list<CPoint> l2;
		l2.push_back(CPoint(MAP_HEIGHT-2, 1));
		DIRECTION d2 = RIGHT;
		p2 = new AutoSnake(l2, d2, strategy1);

		Strategy* strategy2 = new SuikayStrategy();
		std::list<CPoint> l3;
		l3.push_back(CPoint(1, MAP_WIDTH-2));
		DIRECTION d3 = LEFT;
		p3 = new AutoSnake(l3, d3, strategy2);

		Strategy* strategy3 = new SuikayStrategy();
		std::list<CPoint> l4;
		l4.push_back(CPoint(MAP_HEIGHT-2, MAP_WIDTH-2));
		DIRECTION d4 = LEFT;
		p4 = new AutoSnake(l4, d4, strategy3);
	}
	else
	{
		std::list<CPoint> l1;
		l1.push_back(CPoint(1, 1));
		DIRECTION d1 = RIGHT;
		p1 = new CtrledSnake(l1, d1);

		std::list<CPoint> l2;
		l2.push_back(CPoint(MAP_HEIGHT-2, 1));
		DIRECTION d2 = RIGHT;
		p2 = new CtrledSnake(l2, d2);

		Strategy* strategy1 = new SuikayStrategy();
		std::list<CPoint> l3;
		l3.push_back(CPoint(1, MAP_WIDTH-2));
		DIRECTION d3 = LEFT;
		p3 = new AutoSnake(l3, d3, strategy1);

		Strategy* strategy2 = new SuikayStrategy();
		std::list<CPoint> l4;
		l4.push_back(CPoint(MAP_HEIGHT-2, MAP_WIDTH-2));
		DIRECTION d4 = LEFT;
		p4 = new AutoSnake(l4, d4, strategy2);
	}
	Manager::theManager()->addSnake(p1);
	Manager::theManager()->addSnake(p2);
	Manager::theManager()->addSnake(p3);
	Manager::theManager()->addSnake(p4);

	return true;
}

void CGreedySnakeView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CView::OnPaint()
	OnDraw(&dc);
}
