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
// req_select_create.cpp for freewar in /root/Freewar/src
// 
// Made by 
// Login   <root@epita.fr>
// 
// Started on  Sat Jul  3 11:45:01 2004 
// Last update Sat Jul  3 13:31:39 2004 
//

#include "freewar.h"

int		req_select_create_units(t_engine *e, t_trame *trame, int src)
{
  t_game_select_create_units	game; 
  t_req_select_create_units	req;
  t_base_entity			*base;

  if (trame->len != sizeof(game))
    {
      fprintf(stderr, "ERROR: req_select_create_units: failed\n");
      return (1);
    }
  memcpy(&game, trame->msg, sizeof(game));
  req.id_req = game.id_req;
  base = get_base(e, game.name);
  if (!base)
    {
      fprintf(stderr, "ERROR: req_select_create_units: failed\n");
      req.id_action = -1;
    }
  else
    req.id_action = create_action(e, e->select[0][src], base, game.nb_units);
  stock_msg(e->players[src].client, TAG_SELECT_MOVE_REPLY, sizeof(req), &req);
  return (0);
}


int		req_select_create_building(t_engine *e, t_trame *trame, int src)
{
 t_game_select_create_building	game; 
 t_req_select_create_building	req;
 t_base_entity			*base;
 
 if (trame->len != sizeof(game))
   {
     fprintf(stderr, "ERROR: req_select_create_building: failed\n");
     return (1);
   }
 memcpy(&game, trame->msg, sizeof(game));
 req.id_req = game.id_req;
 base = get_base(e, game.name);
 if (!base)
   {
     fprintf(stderr, "ERROR: req_select_create_building: failed\n");
     req.id_action = -1;
   }
 else
   req.id_action = create_action(e, e->select[0][src], base, &game.pos);
 stock_msg(e->players[src].client, TAG_SELECT_MOVE_REPLY, sizeof(req), &req);
 return (0);
}
