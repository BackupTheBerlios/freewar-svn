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
// receive_one_request.cpp for freewar in /u/ept2/huot_j/freewar/engine/src/Network
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Tue May  4 14:43:51 2004 jonathan huot
// Last update Mon Jun 14 18:23:28 2004 jonathan huot
//

#include "freewar.h"

int			receive_one_request(t_trame *req,
					    t_connections *cnt)
{
  unsigned short	i;

  while (42)
    {
      if (SDLNet_CheckSockets(cnt->sset, (unsigned int)-1) < 0)
	{
	  fprintf(stderr, "SDLNet_CheckSockets: %s\n", SDLNet_GetError());
	  return (0);
	}
      for (i = 0; i < cnt->nb_clients; i++)
	{
	  if (recv_trame(cnt, &(cnt->clients[i]), req))
	    {
	      cnt->last_recv = &(cnt->clients[i]);
	      return (1);
	    }
	  if (cnt->clients[i].loss > NET_MAXLOSS)
	    return (0);
	}
    }
  // ne devrait pas en arriver jusque la:
  return (0);
}
