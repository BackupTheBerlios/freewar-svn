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
#include "network.h"

void		move_last_player(int no)
{
  int		last;

  for (last = 0; cnt->clients[last].sock; last++)
    ;
  if (!last)
    return;
  if (--last != no)
    memcpy(&cnt->clients[no], &cnt->clients[last], sizeof(*cnt->clients));
  cnt->clients = (t_client*)xrealloc(cnt->clients,
				     sizeof(*cnt->clients) * (last + 1));
  init_client(&cnt->clients[last]);
}
