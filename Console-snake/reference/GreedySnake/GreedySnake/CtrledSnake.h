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
#include "Snake.h"

//�˿��Ƶ��ߵ���
//CtrledSnake�ķ�������UI���ݼ����¼������Ƶ�
class CtrledSnake : public Snake
{
public:
	CtrledSnake(std::list<CPoint>& lBody, DIRECTION direct);
	~CtrledSnake(void);
};
