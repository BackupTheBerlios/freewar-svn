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
// add_client.cpp for freewar in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Thu May  6 11:05:37 2004 jonathan huot
// Last update Fri May  7 14:45:44 2004 jonathan huot
//

#include "freewar.h"

void			add_client(t_connections *cnt)
{
  TCPsocket		newsock;

  newsock = SDLNet_TCP_Accept(cnt->server.sock);
  if (!newsock)
    fprintf(stderr, "SDLNet_TCP_Accept: %s\n", SDLNet_GetError());
  else if (cnt->nb_clients < FW_MAX_CLIENTS - 1)
    {
      SDLNet_TCP_AddSocket(cnt->sset, newsock);
      cnt->clients[cnt->nb_clients].sock = newsock;
      cnt->clients[cnt->nb_clients].loss = 0;
      cnt->clients[cnt->nb_clients].ping_msec = 0;
      cnt->clients[cnt->nb_clients].pos = 0;
      cnt->nb_clients++;
    }
  cnt->newclient = &cnt->clients[cnt->nb_clients - 1];
}
