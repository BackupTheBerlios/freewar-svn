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

Err		menu_mousemotion(t_info *info, SDL_Event e)
{
  int		i;

  for (i = 0; i < NB_MENU; i++)
    {
      if (info->menu_over != i &&
	  e.motion.x >= info->menu[i].x &&
	  e.motion.x <= (info->menu[i].x + info->menu[i].w) &&
	  e.motion.y >= info->menu[i].y &&
	  e.motion.y <= (info->menu[i].y + info->menu[i].h))
	{
	  display_menu(info, &(info->menu[i]), IMG_MENU_OVER);
	  display_menu(info, &(info->menu[info->menu_over]), IMG_MENU_UNSELECT);
	  info->menu_over = i;
	  break;
	}
    }
  return (0);
}

Err		menu_mousebutton(t_info *info, SDL_Event e)
{
  int		i;

  if (e.button.button == SDL_BUTTON_LEFT)
    for (i = 0; i < NB_MENU; i++)
      {
	if (e.button.x >= info->menu[i].x &&
	    e.button.x <= (info->menu[i].x + info->menu[i].w) &&
	    e.button.y >= info->menu[i].y &&
	    e.button.y <= (info->menu[i].y + info->menu[i].h))
	  {
	    display_menu(info, &(info->menu[i]), IMG_MENU_SELECT);
	    display_menu(info, &(info->menu[info->menu_over]), IMG_MENU_UNSELECT);
	    info->menu_over = i;
	    info->menu[i].select(info);
	    break;
	  }
      }
  return (0);
}
