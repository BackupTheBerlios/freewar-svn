// Copyright (C) 2004 Freewar Team <doomsday@freewar.net>

// This file is part of Freewar.

// Freewar is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.

// Freewar is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with Freewar; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
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
