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
#include "strategy.h"

class RSuikayStrategy :	public Strategy
{
public:
	RSuikayStrategy(void);
	~RSuikayStrategy(void);

	DIRECTION chooseDirection(CPoint snakeHead);
};
