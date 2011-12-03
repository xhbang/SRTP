#include "StdAfx.h"
#include "RSuikayStrategy.h"
#include "Manager.h"
#include <algorithm>

RSuikayStrategy::RSuikayStrategy(void)
{
}

RSuikayStrategy::~RSuikayStrategy(void)
{
}

DIRECTION RSuikayStrategy::chooseDirection(CPoint snakeHead)
{
	CPoint PFruit = Manager::theManager()->getFruitPalce();

	int num[] = {1, 2, 3, 4, 5, 6, 7, 8};
	std::random_shuffle(num, num+8);

	for(int i = 0; i < 8; ++i)
	{
		if ((num[i] == 1 || num[i] == 5)&&
			Manager::theManager()->isLegal(CPoint(snakeHead.x+1, snakeHead.y)) &&
			snakeHead.x < PFruit.x)
			return DOWN;

		if ((num[i] == 2 || num[i] == 6)&&
			Manager::theManager()->isLegal(CPoint(snakeHead.x-1, snakeHead.y)) &&
			snakeHead.x > PFruit.x)
			return UP;

		if ((num[i] == 3 || num[i] == 7) &&
			Manager::theManager()->isLegal(CPoint(snakeHead.x, snakeHead.y+1)) &&
			snakeHead.y < PFruit.y)
			return RIGHT;

		if ((num[i] == 4 || num[i] == 8) &&
			Manager::theManager()->isLegal(CPoint(snakeHead.x, snakeHead.y-1)) &&
			snakeHead.y > PFruit.y)
			return LEFT;
	}

	//////////////////////////////////////////////////////////////////////////
	if (Manager::theManager()->isLegal(CPoint(snakeHead.x+1, snakeHead.y)))
		return DOWN;

	if (Manager::theManager()->isLegal(CPoint(snakeHead.x-1, snakeHead.y)))
		return UP;

	if (Manager::theManager()->isLegal(CPoint(snakeHead.x, snakeHead.y+1)))
		return RIGHT;

	return LEFT;
}
