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

class Strategy
{
	//int base[MAP_HEIGHT][MAP_WIDTH];
public:
	Strategy();

	//在makeDecision中调用map的getBlocks来获取地图信息
	//再按照_aSnake的蛇头位置进行方向的改变
	virtual DIRECTION chooseDirection(CPoint snakeHead) = 0;

	virtual ~Strategy(void) = 0;
};
