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

Err			menu(t_info *info)
{
  preload_menu(info);
  load_menu(info);
  info->exit = 0;
  info->menu_over = 0;
  while (!info->exit)
    {
      SDL_Delay(10);
      while (SDL_PollEvent(&(info->mysdl.event)))
	{
	  if (info->mysdl.event.type == SDL_MOUSEMOTION)
	    menu_mousemotion(info, info->mysdl.event);
	  else if (info->mysdl.event.type == SDL_MOUSEBUTTONDOWN)
	    menu_mousebutton(info, info->mysdl.event);
	  else if (info->mysdl.event.type == SDL_KEYDOWN)
	    menu_key(info, info->mysdl.event);
	  else if (info->mysdl.event.type == SDL_VIDEORESIZE)
	    {
	      resize_window(info, info->mysdl.event.resize.w,
			    info->mysdl.event.resize.h);
	      update_menu(info);
	    }
	  else if (info->mysdl.event.type == SDL_QUIT)
	    info->exit = 1;
	    break;
	}
    }
  free_menu(info);
  SDL_Quit();
  return (0);
}
