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
#include "GSdefs.h"

class Strategy
{
	//int base[MAP_HEIGHT][MAP_WIDTH];
public:
	Strategy();

	//��makeDecision�е���map��getBlocks����ȡ��ͼ��Ϣ
	//�ٰ���_aSnake����ͷλ�ý��з���ĸı�
	virtual DIRECTION chooseDirection(CPoint snakeHead) = 0;

	virtual ~Strategy(void) = 0;
};
