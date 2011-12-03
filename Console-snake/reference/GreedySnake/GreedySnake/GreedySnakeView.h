/*
////////////////////////////////////////////////////////

Team member:
	��ɭ ĪС�� ���Ʋ� �·��� ������ ������ ��� 

Date:
	3.2008 ~ 5.2008

����Ȩ�޹� cqu. mstc. Team Satan ����.

////////////////////////////////////////////////////////
*/

// GreedySnakeView.h : CGreedySnakeView ��Ľӿ�
//


#pragma once
class CSelectionDialog;

class CGreedySnakeView : public CView
{
protected: // �������л�����
	CGreedySnakeView();
	DECLARE_DYNCREATE(CGreedySnakeView)

// ����
public:
	CGreedySnakeDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CGreedySnakeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // GreedySnakeView.cpp �еĵ��԰汾
inline CGreedySnakeDoc* CGreedySnakeView::GetDocument() const
   { return reinterpret_cast<CGreedySnakeDoc*>(m_pDocument); }
#endif

