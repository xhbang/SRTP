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
#include "Strategy.h"
#include <list>

//���Կ��Ƶ��ߵ���
class AutoSnake : public Snake
{
	Strategy* strategy;	//�ߵĲ���ģʽ

public:
	//iChoose�ǵڼ�������,�粻ָ�������һ�������
	AutoSnake(std::list<CPoint>& lBody, DIRECTION direct, Strategy* strategy);
	~AutoSnake(void);

	//��move�е���tragedy��makeDecision��������directions�ı�
	//Ȼ�����directionǰ��һ������ǰ�����ϰ��򷵻�false֮��map����ɾ��
	int move();
};