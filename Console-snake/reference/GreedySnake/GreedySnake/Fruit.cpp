#include "stdafx.h"
#include "Fruit.h"
#include "GSdefs.h"
#include <cstdlib>
#include <ctime>
#define RAND(x) (rand()%(x))

Fruit::Fruit(void)
{
	lLastTime = FRUIT_LASTTIME;
	TRACE(_T("lLastTime = %d\n"), lLastTime);
	PPlace.x = MAP_HEIGHT/2, PPlace.y = MAP_WIDTH/2;
}

Fruit::~Fruit(void)
{
}

CPoint Fruit::getFruitPosition()	//����fruit��λ��
{
	return PPlace;
}

bool Fruit::isOver()			//�ж�fruit�Ƿ񻹴���
{
	lLastTime--;
	return lLastTime < 0;
}

void Fruit::recreatePosition()
{
	lLastTime = FRUIT_LASTTIME;
	srand((UINT)time(NULL));
	while(true)
	{
		PPlace.x = RAND(MAP_HEIGHT);
		PPlace.y = RAND(MAP_WIDTH);
		if(Manager::theManager()->isLegal(PPlace))
			break;
	}
}
