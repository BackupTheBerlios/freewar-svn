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
// get_db_info.cpp for freewar in /u/ept2/huot_j/Freewar/AFirstChaos/src
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Mon Jun 14 15:05:14 2004 jonathan huot
// Last update Tue Jun 29 19:54:11 2004 jonathan huot
//

#include "freewar.h"

int		get_db_info(t_game_goodies *nfo)
{
  t_trame	trame;
  Uint32	ticks;
  int		ret;

  ticks = SDL_GetTicks();
  stock_msg(&cnt->clients[0], TAG_WELCOME, 0, NULL);
  fprintf(fd_log, "in\n");
  while (42)
    {
      if ((ret = check_select(100)))
	{
	  if (exec_msg(&cnt->clients[0], &trame))
	    {
	      if (is_valid_trame(&trame, TAG_WELCOME))
		{
			fprintf(fd_log, "AFirstChaos: Coucou from server\n");
		}
	      else if (is_valid_trame(&trame, TAG_INFO))
		{
		  memcpy((void*)nfo->db_info, trame.msg,
			 sizeof(*(nfo->db_info)));
		  free(trame.msg);
		  fprintf(fd_log, "out\n");
		  return (0);
		}
	      else
		fprintf(fd_log, "AFirstChaos: Trame unused: %d\n", trame.tag);
	    }
	  else
	    fprintf(fd_log, "Activity from ? (%d)\n", ret);
	}
	if (!cnt->clients[0].sock)
	  return (1);
      if ((SDL_GetTicks() - ticks) > (50000 * SEC_IN_MS))
	{
	  fprintf(fd_log, "drop out\n");
	  return (1);
	}
    }
  return (1);
}
