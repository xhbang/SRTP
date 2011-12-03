#include "stdafx.h"
#include "Manager.h"
#include "Snake.h"
#include "Fruit.h"
#include "Map.h"
#include <algorithm>

Manager* Manager::instance = NULL;

Manager::Manager()
{
	fruit = new Fruit();
	map = new Map();
	this->initialGame();
}

bool Manager::isFruit(CPoint& p)
{
	if(!isLegal(p))
		return false;
	return iBlocks[p.x][p.y] == MAP_FRUIT;
}

bool Manager::initialGame()
{
	std::vector<Snake*>::iterator pos = vpSnakes.begin();
	int  index = (int)vpSnakes.size();
	for(int i = index-1; i >= 0; --i)
		deleteSnake(pos + i);

	if(!map->loadMap())
		return false;
	int** pMap = map->getBlocks();
	memcpy(iBlocks, pMap, sizeof(iBlocks));
	return true;
}

Manager::~Manager(void)
{
	std::vector<Snake*>::iterator itr;
	for(itr = vpSnakes.begin(); itr != vpSnakes.end(); ++itr)
		SAFE_DELETE(*itr);
	SAFE_DELETE(map);
	SAFE_DELETE(fruit);
}

void Manager::addSnake(Snake* s)
{
	vpSnakes.push_back(s);
}

void Manager::deleteSnake(std::vector<Snake*>::iterator itr)
{
	//(*itr)->iDeserveLength = 0;
	SAFE_DELETE(*itr);
	vpSnakes.erase(itr);
}

bool Manager::isLegal(CPoint& p)
{
	if (p.x < 0 || p.x >= MAP_HEIGHT || p.y < 0 || p.y >= MAP_WIDTH)
		return false;
	return (iBlocks[p.x][p.y] == MAP_FRUIT || iBlocks[p.x][p.y] == MAP_SAFESPACE);
}

int** Manager::getBlocks()
{
	return (int**)iBlocks;
}

void Manager::changeFruitPlace()
{
	fruit->recreatePosition();
}

void Manager::refresh(void)
{
	bool *record = new bool[vpSnakes.size()+5];
	memset(record, 0, sizeof(record));

	std::vector<Snake*>::iterator itr = vpSnakes.begin();
	for(; itr != vpSnakes.end(); ++itr)
	{
		int flag = (*itr)->move();

		if(flag == FLAG_OVER)
			record[distance(vpSnakes.begin(), itr)] = true;
		else if (flag == FLAG_FRUIT)
		{
			(*itr)->eatFruit();
			changeFruitPlace();
		}
	}
	
	std::vector<Snake*>::iterator pos = vpSnakes.begin();
	for(int i = (int)vpSnakes.size()-1; i >= 0; --i)
		if(i >= 0 && record[i])
			deleteSnake(pos + i);
	SAFE_DELETE_ARRAY(record);

	if (fruit->isOver())
		changeFruitPlace();

	refreshBlocks();
}

void Manager::refreshBlocks()
{
	int** pMap = map->getBlocks();
	memcpy(iBlocks, pMap, sizeof(iBlocks));

	std::vector<Snake*>::iterator itr;
	for(itr = vpSnakes.begin(); itr != vpSnakes.end(); ++itr)
	{
		//if((*itr)->iDeserveLength == 0)
		//	continue;
		std::list<CPoint>::iterator pos = (*itr)->lBody.begin();
		iBlocks[pos->x][pos->y] = MAP_SNAKE_HEAD;
		pos++;

		for(; pos != (*itr)->lBody.end(); ++pos)
			iBlocks[pos->x][pos->y] = MAP_SNAKE_BODY;
	}

	iBlocks[fruit->getFruitPosition().x][fruit->getFruitPosition().y]\
		= MAP_FRUIT;
}

void Manager::setSnakeDirection(int iOder, DIRECTION direct)
{
	if (iOder < (int)vpSnakes.size() && vpSnakes[iOder]->getDirection() != -direct)
		vpSnakes[iOder]->setDirection(direct);
}

bool Manager::isAllDead()
{
	return this->vpSnakes.size() == 0;
}

CPoint Manager::getFruitPalce()
{
	return fruit->getFruitPosition();
}