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

void		free_game(t_info *info)
{
  int		i;
  
  if (info->game.gamespace)
    SDL_FreeSurface(info->game.gamespace);
  for (i = 0; i < NB_ITEMS; i++)
    if (info->img[i])
      SDL_FreeSurface(info->img[i]);
}

Err		game(t_info *info)
{
  Err		err;

  if ((err = load_game(info)))
    return (err);
  put_error("Launching game..");
  while (!info->game.exit)
    {
      SDL_Delay(10);
      while (SDL_PollEvent(&(info->mysdl.event)))
	{
	  if (info->mysdl.event.type == SDL_MOUSEMOTION)
	    game_mousemotion(info, info->mysdl.event);
	  else if (info->mysdl.event.type == SDL_MOUSEBUTTONDOWN)
	    game_mousebutton(info, info->mysdl.event);
	  else if (info->mysdl.event.type == SDL_KEYDOWN ||
		   info->mysdl.event.type == SDL_KEYUP)
	    game_key(info, info->mysdl.event);
	  else if (info->mysdl.event.type == SDL_QUIT)
	    {
	      info->game.exit = 1;
	      info->exit = 1;
	    }
	  else if (info->mysdl.event.type == SDL_VIDEORESIZE)
	    {
	      resize_window(info, info->mysdl.event.resize.w, 
			    info->mysdl.event.resize.h);
	      update_gamespace(info);
	    }
	  else
	    break;
	}
      game_verif_pos(info);
      update_gamespace(info);
    }
  free_game(info);
  return (0);
}
