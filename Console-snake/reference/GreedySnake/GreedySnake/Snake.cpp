#include "stdafx.h"
#include "Snake.h"

Snake::Snake(std::list<CPoint>& lBody, DIRECTION direct)
{
	iDeserveLength = SNAKE_ORIGINAL_LENGTH;
	std::list<CPoint>::iterator itr;
	for (itr = lBody.begin(); itr != lBody.end(); ++itr)
		this->lBody.push_back(CPoint((*itr).x, (*itr).y));
	this->direct = direct;
}

Snake::~Snake()
{
}

int Snake::move()
{
	CPoint PHeadOfSnake = *(lBody.begin());
	LONG XCrood = PHeadOfSnake.x;
	LONG YCrood = PHeadOfSnake.y;

	switch (direct)
	{
	case LEFT:
		PHeadOfSnake.y = YCrood-1;
		break;

	case RIGHT:
		PHeadOfSnake.y = YCrood+1;
		break;

	case UP:
		PHeadOfSnake.x = XCrood-1;
		break;

	case DOWN:
		PHeadOfSnake.x = XCrood+1;
		break;
	};

	lBody.push_front(PHeadOfSnake);

	if((int)lBody.size() > iDeserveLength)
		lBody.pop_back();

	if (Manager::theManager()->isFruit(PHeadOfSnake))
		return FLAG_FRUIT;
	else if (Manager::theManager()->isLegal(PHeadOfSnake))
		return FLAG_SAFE;
	else
		return FLAG_OVER;
}

void Snake::setDirection(DIRECTION direction)
{
	direct = direction;
}

DIRECTION Snake::getDirection()
{
	return direct;
}