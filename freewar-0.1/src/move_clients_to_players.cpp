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

int	move_clients_to_players(t_engine *e, t_game_param *game_param)
{
  int	i;
  t_tmp	*list;

  i = 1;
  for (list = cnt->newclient; list; list = list->next)
    {
      cnt->clients = (t_client*)xrealloc(cnt->clients, sizeof(*cnt->clients) *
					 i + 2);
      if (!list->state)
	memcpy(&cnt->clients[i], &list->c, sizeof(list->c));
      i++;
    }
  init_client(&cnt->clients[i]);
  return (0);
}
