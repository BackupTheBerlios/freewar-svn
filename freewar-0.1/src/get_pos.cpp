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
// get_pos.cpp for freewar in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Thu May  6 18:53:46 2004 jonathan huot
// Last update Fri May  7 12:09:04 2004 jonathan huot
//

#include "freewar.h"

int		get_pos_of_socket(TCPsocket socket)
{
  int		i;

  for (i = 0; cnt->clients[i].sock; i++)
    if (cnt->clients[i].sock == socket)
      return (i);
  return (-1);
}

//int		get_pos_of_player(t_pos *pos, int client)
//{
//  int		i;
//
//  for (i = 0; i < FW_MAX_CLIENTS; i++)
//    if (pos[i].client == client)
//      return (pos[i].player);
//  put_error("get_pos_of_player failed");
//  return (-1);
//}

int	get_pos_of_empty_slot(t_game_param *game_param)
{
  int	i;
  
  for (i = 0; i < FW_MAX_CLIENTS; i++)
    if (game_param->players[i].type == TYPE_OPEN)
      return (i);
  return (-1);
}
