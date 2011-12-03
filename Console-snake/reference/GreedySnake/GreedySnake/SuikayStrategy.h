/*
////////////////////////////////////////////////////////

Team member:
	ÄôÉ­ ÄªĞ¡ç÷ ÅíÔÆ²¨ ³Â·ÉÓî ÒüÂ×ÇÙ ³ÂÇßÜç Àî³¯³¯ 

Date:
	3.2008 ~ 5.2008

ËùÓĞÈ¨ÏŞ¹é cqu. mstc. Team Satan ËùÓĞ.

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
