#ifndef _DEFINE_H_
#define _DEFINE_H_

/*
** freewar
*/
#define MAP_HEIGHT (64)
#define MAP_WIDTH (64)
#define NAME_ICO ("freewar.ico")
#define WIN_DEFAULT_WIDTH (640)
#define WIN_DEFAULT_HEIGHT (480)
#define CASE_SIZE_X (32)
#define CASE_SIZE_Y (32)
#define MAX_ENTITY_BY_CASE (42)
#define SCROLL_STEP (10)
#define ACTIONS_MAX (10)
#define GAME_MAP ("map.fw")
#include "img_game.h"

/*
** communications moteur
*/
#define CMD_CREATE_WINDOW (42)
#define CMD_CLOSE_WINDOW (43)

/*
** divers
*/
#define SCREEN_DEPTH (32)

/*
** optimisations:
*/
#define BUF_LEN (512)

/*
** menu
*/
#define NB_MENU (3)

#define NB_IMG_MENU (3)
#define IMG_MENU_UNSELECT (0)
#define IMG_MENU_OVER (1)
#define IMG_MENU_SELECT (2)

/*
** items
*/
#define NB_ITEMS (11)
#define DEFAULT_ID (1)

#endif
