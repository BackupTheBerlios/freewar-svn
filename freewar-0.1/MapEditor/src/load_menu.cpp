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

Err			load_menu(t_info *info)
{
  int			i;
  int			n;
  Uint32		color;
  SDL_Rect		dest;

  color = SDL_MapRGB(info->mysdl.screen->format, 0, 0, 0);
  dest.x = 0;
  dest.y = 0;
  dest.w = info->mysdl.screen->w;
  dest.h = info->mysdl.screen->h;
  SDL_FillRect(info->mysdl.screen, &dest, color);
  SDL_Flip(info->mysdl.screen);
  for (i = 0; i < NB_MENU; i++)
    for (n = 0; n < NB_IMG_MENU; n++)
      load_bmp(&(info->menu[i].img[n]), info->menu[i].img_name[n]);
  info->menu_over = 0;
  update_menu(info);
  return (0);
}
