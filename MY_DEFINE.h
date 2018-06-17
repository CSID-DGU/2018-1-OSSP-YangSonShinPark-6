#pragma once

#define __D_FRAME_TIMER__ 30
#define __D_SCREEN_WIDTH__ 480
#define __D_SCREEN_HEIGHT__ 800

typedef struct __ST_POS__
{
	int _x;
	int _y;
	__ST_POS__() {_x = 0; _y = 0;}
	__ST_POS__(const int& x, const int& y)
			: _x(x), _y(y) { }
} stPos;

typedef struct __ST_ITEM_INFO__
{
	stPos _position;
	char _type;
	__ST_ITEM_INFO__(const stPos pos, const char& t)
		: _position(pos), _type(t) { }
} stItemInfo;

typedef enum __E_GAME_STATE__
{
	__E_MENU__ = 0,
	__E_GAME__,
	__E_OPTION__,
	__E_OVER__,
} eGameState;


typedef enum __E_ITEM_TYPE__
{
	__E_ITEM_MOUSE__ = 0,
	__E_ITEM_BUG__,
	__E_ITEM_ROCK__,
	__E_ITEM_STICK__,
	__E_ITEM_STONE__,
	__E_ITEM_THORN__,
	__E_ITEM_BONE__,
	__E_ITEM_BORN__,
	__E_ITEM_SUPER__,
	__E_ITEM_MAX__,
} eItem;

typedef enum __E_KEY_STATE__
{
	__E_LEFT__ = 0,
	__E_RIGHT__,
	__E_UP__,
	__E_DOWN__,
	__E_KEY_MAX__,
} eKeyState;

extern int g_eState;
extern int g_nLevel;
extern int g_nType;
extern int g_nBoost;
extern bool g_bMulti;
extern bool g_bMake;
extern bool g_bLoop;
extern bool g_bSound;
extern bool g_bKeyState[__E_KEY_MAX__];
