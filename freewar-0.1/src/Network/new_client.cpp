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
/*
** new_client.c for zappy in /u/ept2/huot_j
** 
** Made by jonathan huot
** Login   <huot_j@epita.fr>
** 
** Started on  Mon May 24 18:37:42 2004 jonathan huot
// Last update Tue Jun 29 18:36:19 2004 jonathan huot
*/

#include "network.h"
#include "tag.h"

int		new_client(t_tmp **newclt)
{
  TCPsocket	newsock;

  NETDEBUG("Un nouveau client s'est connecté\n");
  newsock = SDLNet_TCP_Accept(cnt->server.sock);
  if (!newsock)
    fprintf(fd_log, "accept: %s\n", SDLNet_GetError());
  else
    {
      put_in_client(newclt, newsock, STATE_NEW);
      stock_msg(&((*newclt)->c), TAG_WELCOME, 0, NULL);
      return (1);
    }
  return (0);
}
