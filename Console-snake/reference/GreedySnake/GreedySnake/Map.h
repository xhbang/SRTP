/*
////////////////////////////////////////////////////////

Team member:
��ɭ ĪС�� ���Ʋ� �·��� ������ ������ ��� 

Date:
5.2008
����Ȩ�޹� cqu. mstc. Team Satan ����.

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
	bool loadMap();		//��ȡ��ͼ��Ϣ,���������ߵĳ�ʼλ�úͳ�ʼ����
	int** getBlocks();
	Map(void);
	~Map(void);

	//���صڼ����ߵĳ�ʼλ�úͳ�ʼ����
	//void getOriginalPlace(std::list<CPoint>& lBody,DIRECTION& d,int iSnakeOrder);
};
