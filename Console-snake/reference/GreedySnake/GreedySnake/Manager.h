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
#include <vector>

class Fruit;
class Snake;
class Map;
class Manager
{
public:
	void addSnake(Snake* s);	//�ڵ�ͼ�������
	void deleteSnake(std::vector<Snake*>::iterator itr);	//���ߴӵ�ͼ��ɾ��	
	bool isLegal(CPoint& p);		//�жϽ�Ҫ�����λ���Ƿ�Ϸ�

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
	int** getBlocks();		//��ȡ��ͼ��Ϣ
	bool initialGame();
	void refresh(void);
	bool isFruit(CPoint& p);
	void changeFruitPlace();
	void refreshBlocks();
	void setSnakeDirection(int iOder, DIRECTION direct);
	bool isAllDead();
	CPoint getFruitPalce();
};
