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
// give_info_to_game.cpp for freewar in /u/ept2/huot_j/Freewar/src
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Thu May  6 11:12:41 2004 jonathan huot
// Last update Tue Jun 29 19:51:49 2004 jonathan huot
//

#include "freewar.h"

int             give_info_to_game(t_db_info *db_info)
{
  int		first;
  Uint32	ticks;

  ticks = SDL_GetTicks();
  first = cnt->clients[0].pos_send;
  stock_msg(&cnt->clients[0], TAG_INFO, sizeof(*db_info), (void*)db_info);
  fflush(fd_log);
  while (32)
    {
      printf("pif\n");fflush(stdout);
      check_select(5313);
      printf("pof\n");fflush(stdout);
      if (cnt->clients[0].pos_send != first)
	{
	  fprintf(fd_log, "db sent!\n");
	  return (0);
	}
      if (SDL_GetTicks() - ticks > 9320)
	{
	  fprintf(fd_log, "db not send\n");
	  return (0);
	}
    }
  return (0);
}
