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

Err		game_key_move(t_info *info, SDL_Event e)
{
  if (e.key.keysym.sym == SDLK_UP)
    info->game.keyup = -SCROLL_STEP;
  else if (e.key.keysym.sym == SDLK_LEFT)
    info->game.keyleft = -SCROLL_STEP;
  else if (e.key.keysym.sym == SDLK_DOWN)
    info->game.keydown = SCROLL_STEP;
  else if (e.key.keysym.sym == SDLK_RIGHT)
    info->game.keyright = SCROLL_STEP;
  else
    return (0);
  return (update_gamespace(info));
}

Err		game_key(t_info *info, SDL_Event e)
{
  Err		err;
  int		i;

  err = 0;
  if (e.key.keysym.sym == SDLK_ESCAPE)
    info->game.exit = 1;
  else if (e.type == SDL_KEYDOWN)
    err = game_key_move(info, e);
  else if (e.type == SDL_KEYUP)
    {
      if (e.key.keysym.sym == SDLK_UP)
	info->game.keyup = 0;
      else if (e.key.keysym.sym == SDLK_DOWN)
	info->game.keydown = 0;
      else if (e.key.keysym.sym == SDLK_LEFT)
	info->game.keyleft = 0;
      else if (e.key.keysym.sym == SDLK_RIGHT)
	info->game.keyright = 0;
      else if (e.key.keysym.sym == SDLK_s)
	save_map(info);
      else
	for (i = 0; i < NB_ITEMS; i++)
	  if (e.key.keysym.sym == gl_items[i].key)
	    info->selection = gl_items[i].id;
    }
  return (err);
}
