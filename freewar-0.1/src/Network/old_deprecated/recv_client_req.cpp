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
// recv_client_req.cpp for freewar in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Fri May  7 18:36:34 2004 jonathan huot
// Last update Mon Jun 14 18:17:27 2004 jonathan huot
//

#include "freewar.h"

int			recv_client_req(t_client *clt, t_trame *req)
{
  SDLNet_SocketSet	sset;

  sset = SDLNet_AllocSocketSet(1);
  SDLNet_TCP_AddSocket(sset, clt->sock);
  while (32)
    {
      if (SDLNet_CheckSockets(sset, (Uint32)-1) < 0)
	return (put_error("recv_client_req failed"));
      if (SDLNet_SocketReady(clt->sock) && get_msg(clt, req))
	return (0);
      else if (clt->loss > NET_MAXLOSS)
	return (1);
    }
  return (0);
}
