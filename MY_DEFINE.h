#pragma once

#define __D_SCREEN_WIDTH__ 480
#define __D_SCREEN_HEIGHT__ 720

typedef struct __ST_POS__
{
	int _x;
	int _y;
} stPos;

typedef enum __E_GAME_STATE__
{
	__E_MENU__ = 0,
	__E_GAME__,
	__E_OPTION__,
	__E_OVER__,
} eGameState;

typedef enum __E_KEY_STATE__
{
	__E_LEFT__ = 0,
	__E_RIGHT__,
	__E_UP__,
	__E_DOWN__,
	__E_KEY_MAX__,
} eKeyState;

extern int g_eState;
extern bool g_bLoop;
