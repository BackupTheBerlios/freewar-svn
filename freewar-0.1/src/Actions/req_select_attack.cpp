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
// req_select_attack.cpp for freewar in /root/Freewar/src
// 
// Made by 
// Login   <root@epita.fr>
// 
// Started on  Sat Jul  3 11:20:31 2004 
// Last update Sun Jul  4 13:42:53 2004 
//

#include "freewar.h"

int			req_select_attack(t_engine *e, t_trame *trame, int src)
{
  t_game_select_attack	game;
  t_entity		*attacked;
  t_req_select_attack	req;
  int		i;

  if (trame->len != sizeof(game))
    {
      fprintf(stderr, "ERROR: req_select_attack: failed\n");
      return (1);
    }
  memcpy(&game, trame->msg, sizeof(game));
  req.id_req = game.id_req;
  attacked = find_entity(e, game.id_attacked);
  if (!attacked || !e->select[0][src])
    {
      fprintf(stderr, "ERROR: req_select_attack: failed\n");
      req.id_action = -1;
    }
  for (i = 0; i < FW_MAX_SELECT && e->select[i][src]; i++)
    if (src == e->select[i][src]->app)
      req.id_action = create_action(e, e->select[i][src], attacked);
  stock_msg(e->players[src].client,
	    TAG_SELECT_ATTACK_REPLY, sizeof(req), &req);
  return (0);
}
