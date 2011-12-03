/*
////////////////////////////////////////////////////////

Team member:
聂森 莫小琪 彭云波 陈飞宇 尹伦琴 陈沁茜 李朝朝 

Date:
5.2008
所有权限归 cqu. mstc. Team Satan 所有.

////////////////////////////////////////////////////////
*/

#pragma once
#include "GSdefs.h"
#include <list>

class Map
{
	static int iMapsOrder;
	int iBlocks[MAP_HEIGHT][MAP_WIDTH];
public:
	bool loadMap();		//获取地图信息,包括几条蛇的初始位置和初始方向
	int** getBlocks();
	Map(void);
	~Map(void);

	//返回第几个蛇的初始位置和初始方向
	//void getOriginalPlace(std::list<CPoint>& lBody,DIRECTION& d,int iSnakeOrder);
};
