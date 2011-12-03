/****************************************************************************
* Copyright (C) 2008 Wurzer Roland											*
* 																			*
* Consnake is free software: you can redistribute it and/or modify			*
* it under the terms of the GNU General Public License as published by		*
* the Free Software Foundation, either version 3 of the License.			*
*																			*
* Consnake is distributed in the hope that it will be useful,				*
* but WITHOUT ANY WARRANTY; without even the implied warranty of			*
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the			*
* GNU General Public License for more details.								*
*																			*
* You should have received a copy of the GNU General Public License		*
* along with Consnake.  If not, see .		*
* *************************************************************************/

#include 
#include 
#include 
#include 
#include 
#include 
#include 
#include 

#define GAMEWINDOW_WIDTH 40
#define GAMEWINDOW_HEIGHT 20
#define STATUSWINDOW_WIDTH 20
#define STATUSWINDOW_HEIGHT 8
#define TOPLIST_WIDTH 50
#define TOPLIST_HEIGHT 14
#define SNAKE_STARTSIZE 4
#define SNAKE_STARTDELAY 200

enum SnackType
{
	SNACK_POINTS,
	SNACK_FASTER,
	SNACK_SLOWER,
	SNACK_GROW,
	SNACK_SHRINK
};

enum SnakeDirection
{
	SNAKE_LEFT,
	SNAKE_RIGHT,
	SNAKE_DOWN,
	SNAKE_UP
};

struct SnakeUnit
{
	int x,y;
	SnakeDirection direction;
	SnakeUnit *next;
};

struct Snack
{
	int x,y;
	SnackType type;
};

class Snake
{
	char grow, shrink;
	SnakeUnit *snake_unit;
public:
	Snake(int size);
	~Snake(void);
	int Tick(void);
	SnakeUnit* GetSnakeUnit(void);
	int Grow(void);
	int Shrink(void);
	int Direction(SnakeDirection newDirection);
	int GetHeadPosition(int &x, int &y);
};

struct ToplistUnit
{
	char name[100];
	int points;
	ToplistUnit *next;
};

class Toplist
{
	ToplistUnit *tlu;
	char filename[100];

	int Insert(char *name, int points);
public:
	Toplist(char *file);
	~Toplist(void);
	int Save(void);
	int Update(char *name, int points);
	ToplistUnit *GetToplistUnit(void);
};

struct Game
{
	int delay;
	int points;
	char name[100];
	Snake *snake;
	Snack snack;
	Toplist *toplist;
};

int draw_init(void);
int draw_start_window(Game*);
int draw_game_window(Game*);
int draw_status_window(Game*);
int draw_toplist_window(Game*);
int draw_deinit(void);

Game* game_new(void);
int game_reset(Game*);
int game_main_loop(Game*);
int game_check_gameover(Game*);
int game_new_snack(Game*);
int game_check_snack_eaten(Game*);
int game_end(Game*);
