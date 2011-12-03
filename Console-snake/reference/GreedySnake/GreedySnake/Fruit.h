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
#include "Manager.h"

class Fruit
{
private:
	long lLastTime;	//fruit的存在时间
	CPoint PPlace;	//fruit的位置

public:
	Fruit(void);			//随机产生fruit的位置,ps:用isLegal判断位置是否合法
	CPoint getFruitPosition();	//返回fruit的位置
	bool isOver();			//判断fruit是否还存在
	void recreatePosition();
	~Fruit(void);
};