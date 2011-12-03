/*
////////////////////////////////////////////////////////

Team member:
	聂森 莫小琪 彭云波 陈飞宇 尹伦琴 陈沁茜 李朝朝 

Date:
	3.2008 ~ 5.2008

所有权限归 cqu. mstc. Team Satan 所有.

////////////////////////////////////////////////////////
*/

#pragma once
#include "GSdefs.h"
#include <vector>

class Fruit;
class Snake;
class Map;
class Manager
{
public:
	void addSnake(Snake* s);	//在地图中添加蛇
	void deleteSnake(std::vector<Snake*>::iterator itr);	//将蛇从地图中删除	
	bool isLegal(CPoint& p);		//判断将要到达的位置是否合法

	~Manager(void);
private:
	int iBlocks[MAP_HEIGHT][MAP_WIDTH];
	static Manager* instance;
	Manager();
	std::vector<Snake*> vpSnakes;
	Fruit* fruit;
	Map* map;

public:
	static Manager* theManager()
	{
		if(instance == NULL)
			instance = new Manager();
		return instance;
	}

public:
	int** getBlocks();		//获取地图信息
	bool initialGame();
	void refresh(void);
	bool isFruit(CPoint& p);
	void changeFruitPlace();
	void refreshBlocks();
	void setSnakeDirection(int iOder, DIRECTION direct);
	bool isAllDead();
	CPoint getFruitPalce();
};
