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
#include "freewar.h"

Err		menu_key_move(t_info *info, SDL_Event e)
{
  display_menu(info, &(info->menu[info->menu_over]), IMG_MENU_UNSELECT);
  if (e.key.keysym.sym == SDLK_UP ||
      e.key.keysym.sym == SDLK_LEFT)
    {
      if (info->menu_over > 0)
	info->menu_over--;
      else
	info->menu_over = NB_MENU - 1;
    }
  else if (e.key.keysym.sym == SDLK_DOWN ||
	   e.key.keysym.sym == SDLK_RIGHT)
    {
      if (info->menu_over < NB_MENU - 1)
	info->menu_over++;
      else
	info->menu_over = 0;
    }
  display_menu(info, &(info->menu[info->menu_over]), IMG_MENU_OVER);
  return (0);
}

Err		menu_key(t_info *info, SDL_Event e)
{
  Err		err;

  err = 0;
  if (e.key.keysym.sym == SDLK_ESCAPE)
    info->exit = 1;
  else if (e.key.keysym.sym == SDLK_RETURN)
    err = info->menu[info->menu_over].select(info);
  else
    err = menu_key_move(info, e);
  return (err);
}
