#include "stdafx.h"
#include "AutoSnake.h"

AutoSnake::AutoSnake(std::list<CPoint>& lBody, DIRECTION direct, Strategy* strategy)
: Snake(lBody, direct)
{
	this->strategy = strategy;
}

int AutoSnake::move()
{
	CPoint PHeadOfSnake = *(lBody.begin());
	LONG XCrood = PHeadOfSnake.x;
	LONG YCrood = PHeadOfSnake.y;

	this->direct = this->strategy->chooseDirection(PHeadOfSnake);
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

AutoSnake::~AutoSnake(void)
{
	SAFE_DELETE(strategy);
}
