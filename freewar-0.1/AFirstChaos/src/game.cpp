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
//
// game.cpp for freewar in /u/ept2/skondr_m
// 
// Made by mael skondras
// Login   <skondr_m@epita.fr>
// 
// Started on  Tue May 11 18:44:01 2004 mael skondras
// Last update Tue Jun 29 19:03:20 2004 jonathan huot
//

#include "freewar.h"

int		afirstchaos()
{
  t_game_goodies	*nfo;

  nfo = (t_game_goodies*)xmalloc(sizeof(*nfo));
  nfo->db_info = (t_db_info*)xmalloc(sizeof(*(nfo->db_info)));
  nfo->events = (t_event*)xmalloc(sizeof(*(nfo->events)));
  init_log("afirstchaos.log");
  fprintf(fd_log, "%s: A First Chaos starting...\n", NAME);
  if (init_game(nfo))
    return (1);
  if (run_game(nfo))
    return (1);
  SDLNet_Quit();
  SDL_Quit();
  fprintf(fd_log, "%s: bye bye\n", NAME);
  return (0);
}
