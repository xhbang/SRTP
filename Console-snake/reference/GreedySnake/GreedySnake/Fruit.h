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
#include "Manager.h"

class Fruit
{
private:
	long lLastTime;	//fruit�Ĵ���ʱ��
	CPoint PPlace;	//fruit��λ��

public:
	Fruit(void);			//�������fruit��λ��,ps:��isLegal�ж�λ���Ƿ�Ϸ�
	CPoint getFruitPosition();	//����fruit��λ��
	bool isOver();			//�ж�fruit�Ƿ񻹴���
	void recreatePosition();
	~Fruit(void);
};