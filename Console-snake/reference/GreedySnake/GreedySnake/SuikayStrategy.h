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
#include "Strategy.h"

class SuikayStrategy :	public Strategy
{
public:
	SuikayStrategy(void);
	~SuikayStrategy(void);

	DIRECTION chooseDirection(CPoint snakeHead);
};
