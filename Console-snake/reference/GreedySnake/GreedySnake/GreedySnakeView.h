/*
////////////////////////////////////////////////////////

Team member:
	聂森 莫小琪 彭云波 陈飞宇 尹伦琴 陈沁茜 李朝朝 

Date:
	3.2008 ~ 5.2008

所有权限归 cqu. mstc. Team Satan 所有.

////////////////////////////////////////////////////////
*/

// GreedySnakeView.h : CGreedySnakeView 类的接口
//


#pragma once
class CSelectionDialog;

class CGreedySnakeView : public CView
{
protected: // 仅从序列化创建
	CGreedySnakeView();
	DECLARE_DYNCREATE(CGreedySnakeView)

// 属性
public:
	CGreedySnakeDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CGreedySnakeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

private:
	CSelectionDialog* m_pDlg;
public:
	afx_msg void OnGameStart();
	afx_msg LRESULT OnGoodbye(WPARAM wParam, LPARAM lParam);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
private:
	void drawMap(CDC*, CDC*);
	void drawBackgound(CDC*, CDC*, CRect&);
	void drawGameOver();
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
private:
	bool setGame(void);
	BOOL m_bClose;
	CBitmap m_bmpBackGound;
	CBitmap m_bmpBrick;
	CBitmap m_bmpSnakeBody;
	CBitmap m_bmpSnakeHead;
	CBitmap m_bmpFruit;
	CBitmap m_bmpGameOver;
public:
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // GreedySnakeView.cpp 中的调试版本
inline CGreedySnakeDoc* CGreedySnakeView::GetDocument() const
   { return reinterpret_cast<CGreedySnakeDoc*>(m_pDocument); }
#endif

