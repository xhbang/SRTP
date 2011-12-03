#include "StdAfx.h"
#include "SuikayStrategy.h"
#include "Manager.h"

SuikayStrategy::SuikayStrategy(void)
{
}

SuikayStrategy::~SuikayStrategy(void)
{
}

DIRECTION SuikayStrategy::chooseDirection(CPoint snakeHead)
{
	CPoint PFruit = Manager::theManager()->getFruitPalce();

	if (Manager::theManager()->isLegal(CPoint(snakeHead.x+1, snakeHead.y)) &&
		snakeHead.x < PFruit.x)
		return DOWN;

	if (Manager::theManager()->isLegal(CPoint(snakeHead.x-1, snakeHead.y)) &&
		snakeHead.x > PFruit.x)
		return UP;

	if (Manager::theManager()->isLegal(CPoint(snakeHead.x, snakeHead.y+1)) &&
		snakeHead.y < PFruit.y)
		return RIGHT;

	if (Manager::theManager()->isLegal(CPoint(snakeHead.x, snakeHead.y-1)) &&
		snakeHead.y > PFruit.y)
		return LEFT;

	//////////////////////////////////////////////////////////////////////////
	if (Manager::theManager()->isLegal(CPoint(snakeHead.x+1, snakeHead.y)))
		return DOWN;

	if (Manager::theManager()->isLegal(CPoint(snakeHead.x-1, snakeHead.y)))
		return UP;

	if (Manager::theManager()->isLegal(CPoint(snakeHead.x, snakeHead.y+1)))
		return RIGHT;

	return LEFT;
}
