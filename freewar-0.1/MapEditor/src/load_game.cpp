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

Err		load_gamespace(t_info *info)
{
  info->game.gamespace = SDL_DisplayFormatAlpha(info->mysdl.screen);
  if (!info->game.gamespace)
    {
      put_error(SDL_GetError());
      exit(1);
    }
  info->game.pos_x = 0;
  info->game.pos_y = 0;
  return (update_gamespace(info));
}

Err		load_game(t_info *info)
{
  int		i;

  info->selection = DEFAULT_ID;
  info->game.keyshift = 0;
  info->game.keydown = 0;
  info->game.keyup = 0;
  info->game.keyleft = 0;
  info->game.keyright = 0;
  info->game.mousehoriz = 0;
  info->game.mouseverti = 0;
  info->game.exit = 0;
  for (i = 0; i < NB_ITEMS; i++)
    if (gl_items[i].path)
      load_bmp(&(info->img[i]), gl_items[i].path);
    else
      info->img[i] = 0;
  if ((i = init_map(info, info->file)))
    return (i);
  return (load_gamespace(info));
}
