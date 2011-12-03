/*
////////////////////////////////////////////////////////

Team member:
	��ɭ ĪС�� ���Ʋ� �·��� ������ ������ ��� 

Date:
	3.2008 ~ 5.2008

����Ȩ�޹� cqu. mstc. Team Satan ����.

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

	//����directionǰ��һ������ǰ�����ϰ��򷵻�false֮��map����ɾ��
	virtual int move();
	void eatFruit()
	{
		iDeserveLength += SNAKE_GROWN;
	}

private:
	//���ݼ����¼����˹����ܲ��������ߵķ���
	void setDirection(DIRECTION direction);

	/*//ʵ���ߵķ���ת��
	bool moveLeft();
	bool moveRight();
	bool moveUp();
	bool moveDown();*/

protected:
	//Ӧ�еĳ���,�����ƻ����iDeserveLength += 3
	int iDeserveLength;

	//�ߵ�������Ϣ,��lBody.begin()��������ͷ
	std::list<CPoint> lBody;
	
	//�ߵķ���
	DIRECTION direct;

public:
	DIRECTION getDirection();
};
