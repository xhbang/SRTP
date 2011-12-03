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
#include "Snake.h"

//人控制的蛇的类
//CtrledSnake的方向是由UI根据键盘事件来控制的
class CtrledSnake : public Snake
{
public:
	CtrledSnake(std::list<CPoint>& lBody, DIRECTION direct);
	~CtrledSnake(void);
};
