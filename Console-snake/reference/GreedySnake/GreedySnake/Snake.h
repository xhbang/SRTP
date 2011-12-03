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
#include "Manager.h"
#include <list>

class Snake
{
public:
	friend class Manager;
	Snake(std::list<CPoint>& lBody, DIRECTION direct);
	virtual ~Snake(void) = 0;

	//根据direction前进一步，如前方是障碍则返回false之后map将其删除
	virtual int move();
	void eatFruit()
	{
		iDeserveLength += SNAKE_GROWN;
	}

private:
	//根据键盘事件或人工智能策略设置蛇的方向
	void setDirection(DIRECTION direction);

	/*//实现蛇的方向转换
	bool moveLeft();
	bool moveRight();
	bool moveUp();
	bool moveDown();*/

protected:
	//应有的长度,如吃了苹果后iDeserveLength += 3
	int iDeserveLength;

	//蛇的身体信息,用lBody.begin()来代表蛇头
	std::list<CPoint> lBody;
	
	//蛇的方向
	DIRECTION direct;

public:
	DIRECTION getDirection();
};
