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
** loss_client.c for network engine in /u/ept2/huot_j/network_engine
** 
** Made by jonathan huot
** Login   <huot_j@epita.fr>
** 
** Started on  Wed Jun 23 14:51:21 2004 jonathan huot
// Last update Tue Jun 29 20:02:37 2004 jonathan huot
*/

#include "network.h"
#include "tag.h"

int		loss_client(t_client *c)
{
  int		i;

  for (i = 0; cnt->clients[i].sock; i++)
    if (cnt->clients[i].sock == c->sock)
      break;
  if (!cnt->clients[i].sock)
    return (0);
  if (cnt->clients[i].loss == STATE_DROP)
    {
      free_client(&cnt->clients[i]);
      SDLNet_TCP_Close(cnt->clients[i].sock);
    }
  else if (cnt->clients[i].loss == STATE_DEAD ||
	   cnt->clients[i].loss == STATE_FAIL_RECV)
  {
    put_in_tmp_client(&cnt->deadclient, &cnt->clients[i]);
	stock_msg(&(cnt->deadclient->c), TAG_DEAD, 0, NULL);
  }
  else
    fprintf(fd_log, "warning: unknown state (%d)\n", cnt->clients[i].loss);
  move_last_player(i);
  return (1);
}
