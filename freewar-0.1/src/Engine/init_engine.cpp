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

int		init_sdl()
{
  if (SDL_Init(SDL_INIT_TIMER |
	       SDL_INIT_AUDIO |
	       SDL_INIT_VIDEO) < 0)
    {
      fprintf(fd_log, "SDL_Init: %s\n", SDL_GetError()); 
      return (0);
    }
  atexit(SDL_Quit);
  if (SDLNet_Init() == -1)
    {
      fprintf(fd_log, "SDLNet_Init: %s\n", SDLNet_GetError());
      return (1);
    }
  atexit(SDLNet_Quit);
  return (0);
}

void		init_engine(t_engine *e)
{
  init_sdl();
  memset(e->select, 0, sizeof(t_entity*) * FW_MAX_SELECT);
  e->console = false;
  e->scales = 0;
  e->globals = 0;
  e->actions = 0;
  e->id_player = 0;
  e->id = 0;
  e->events = (t_event*)xmalloc(sizeof(*(e->events)));
  memset(e->events->mousepose, 0, sizeof(*e->events->mousepose) *
	 MAXMOUSEEVENT);
  memset(e->events->key, 0, sizeof(*e->events->key) * MAXKEYPRESS);
  e->events->xfin = 0;
  e->events->yfin = 0;
  e->other_events = (t_other_events*)xmalloc(sizeof(*(e->other_events)));
  e->other_events->quit = 0;
}
