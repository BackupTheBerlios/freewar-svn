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

int		wait_engine(char *app)
{
  Uint32	drop;
  t_trame	trame;

  drop = SDL_GetTicks();
  while (42)
    if (check_select(1000))
      {
	while (exec_msg(&(cnt->clients[0]), &trame))
	  if (is_valid_trame(&trame, TAG_PLAYER_INFO))
	  {
	    memcpy(app, trame.msg, trame.len);
		fprintf(fd_log, "app got: %d\n", *app);
	  }
	  else if (is_valid_trame(&trame, TAG_PLAYERS_READY))
	    return (0);
      }
    else if (SDL_GetTicks() - drop > 30000)
      return (1);
  return (0);
}
