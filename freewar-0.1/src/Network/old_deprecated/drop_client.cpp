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
// drop_client.cpp for freewra in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Thu May  6 11:05:15 2004 jonathan huot
// Last update Thu May  6 11:05:23 2004 jonathan huot
//
#include "freewar.h"

void			drop_client(t_connections *cnt, unsigned short i)
{
  printf("Client %i dropped\n", i);
  memmove((void*)&cnt->clients[i], (void*)&cnt->clients[cnt->nb_clients - 1],
	  sizeof(*cnt->clients));
  cnt->nb_clients--;
  SDLNet_TCP_DelSocket(cnt->sset, cnt->clients[i].sock);
  SDLNet_TCP_Close(cnt->clients[i].sock);
}
