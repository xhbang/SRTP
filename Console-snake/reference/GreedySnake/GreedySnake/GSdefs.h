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

#define MAP_FRUIT 1  //果子
#define MAP_OBSTACLE 2   //障碍
#define MAP_SAFESPACE 3   //空白
#define MAP_SNAKE_BODY 4  //蛇身
#define MAP_SNAKE_HEAD 5  //蛇头

#define MAP_WIDTH 80 //主界面宽度
#define MAP_HEIGHT 65 //主界面高度

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