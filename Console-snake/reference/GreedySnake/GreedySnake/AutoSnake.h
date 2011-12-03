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
#include "Strategy.h"
#include <list>

//电脑控制的蛇的类
class AutoSnake : public Snake
{
	Strategy* strategy;	//蛇的策略模式

public:
	//iChoose是第几个策略,如不指明则分配一个随机的
	AutoSnake(std::list<CPoint>& lBody, DIRECTION direct, Strategy* strategy);
	~AutoSnake(void);

	//在move中调用tragedy的makeDecision函数，将directions改变
	//然后根据direction前进一步，如前方是障碍则返回false之后map将其删除
	int move();
};