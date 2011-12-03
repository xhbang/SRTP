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

#define MAP_FRUIT 1  //����
#define MAP_OBSTACLE 2   //�ϰ�
#define MAP_SAFESPACE 3   //�հ�
#define MAP_SNAKE_BODY 4  //����
#define MAP_SNAKE_HEAD 5  //��ͷ

#define MAP_WIDTH 80 //��������
#define MAP_HEIGHT 65 //������߶�

#define MAP_FRAME_X MAP_WIDTH*10+12
#define MAP_FRAME_Y MAP_HEIGHT*10+58

#define NUM_OF_MAPS 4

#define FLAG_FRUIT 0
#define FLAG_OVER 1
#define FLAG_SAFE 2


enum DIRECTION
{
	LEFT = -1,
	RIGHT = 1,
	UP = -2, 
	DOWN = 2
};

#define MOVE_LEFT1 65
#define MOVE_LEFT2 97
#define MOVE_UP1 87
#define MOVE_UP2 119
#define MOVE_RIGHT1 68
#define MOVE_RIGHT2 100
#define MOVE_DOWN1 83
#define MOVE_DOWN2 115

#define TIME_RUN_INTERVAL 100
#define FRUIT_LASTTIME 65
#define TIME_SWITCH_MAP 1000*30

#define SNAKE_ORIGINAL_LENGTH 5
#define SNAKE_GROWN 3

#define SAFE_DELETE(p) {if(p) {delete p; p = NULL;}}
#define SAFE_DELETE_ARRAY(p) {if(p) {delete []p; p = NULL;}}

#define MODE_SINGLE 0

/*
enum STATE
{
STATE_UP,
STATE_RIGHT,
STATE_LEFT,
STATE_DOWN
};
*/

/*
#define BACKGOUND_COLOR RGB(135, 206, 235)
#define OBSTABLE_COLOR RGB(128, 138, 135)
#define SNAKE_BODY_COLOR RGB(138, 54, 15)
#define FRUIT_COLOR RGB(227, 27, 13)
#define SNAKE_HEAD_COLOR RGB(124, 252, 0)
*/