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
// game_param.cpp for freewar in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Thu May  6 17:08:04 2004 jonathan huot
// Last update Fri May  7 13:51:37 2004 jonathan huot
//

#include "freewar.h"

//int	copy_game_param(t_trame *req, t_game_param *game_params)
//{
//  if (req->len != sizeof(*game_params))
//    return (put_error("tu pue"));
//  memcpy((void*)game_params, (void*)req->msg, req->len);
//  return (0);
//}
//
//int		get_game_param_from_server(t_trame *req,
//					   t_game_param *game_params)
//{
//  t_trame	newreq;
//  int		err;
//
//  if (!recv_client_req(&cnt->clients[1], &newreq))
//    if (is_valid_trame(&newreq, TAG_GAME_STATUS))
//      {
//	int	i;
//
//	if ((err = copy_game_param(&newreq, game_params)))
//	  return (err);
//	for (i = 0; i < FW_MAX_CLIENTS; i++)
//	  if (game_params->players[i].type == TYPE_OPEN)
//	    {
//	      memcpy((void*)game_params->players[i].name, (void*)req->msg, NAME_SIZE);
//	      game_params->players[i].type = TYPE_HUMAN;
//	      return (0);
//	    }
//	return (put_error("je devais etre vire' \\o/"));
//      }	
//  return (1);
//}

//int	init_game_param(t_game_param *game_params, t_trame *req)
//{
//  int	i;
//
//  // on pourrait prendre les dernieres preferences de creation du joueur
//  game_params->id_map = 0;
//  for (i = 0; i < FW_MAX_CLIENTS; i++)
//    game_params->players[i].type = TYPE_OPEN;
//  game_params->players[0].type = TYPE_HUMAN;
//  game_params->players[0].color = 0;
//  game_params->players[0].race = 0;
//  game_params->players[0].team = 1;
//  memcpy((void*)game_params->name, (void*)(req->msg), NAME_SIZE);
//  memcpy((void*)game_params->players[0].name, (void*)(req->msg + NAME_SIZE),
//	 NAME_SIZE);
//  for (i = 0; i < FW_MAX_CLIENTS; i++)
//    {
//      pos[i].player = -1;
//      pos[i].client = -1;
//    }
//  return (0);
//}


// uniquement cote serveur

// par exemple le changement dune race d un player
// ou si un client quitte la partie
//int		update_game_param(t_trame *req, t_game_param *game_params)
//{
//  // fonction qui va regarder la requete, et les connection, et
//  // modifier en consequence la structure game_params !
//  if (req->tag == TAG_GP_PLAYERS)
//    {
//      if ((sizeof(*game_params->players)) != req->len)
//	return (put_error("Incomprehension client/server"));
//      memcpy((void*)&game_params->players
//	     [get_pos_of_player(pos, get_pos_of_socket(cnt->last_recv->sock))],
//	     req->msg, sizeof(*game_params->players));
//    }
//   else if (req->tag == TAG_LEAVE)
//     {
//       if (sizeof(no) != req->len)
// 	return (put_error("Incomprehension client/server2"));
//       memcpy((void*)no, req->msg, sizeof(no));
//       game_params->players[];
//     }
//  return (0);
//}
