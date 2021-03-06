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
  stock_msg(&(cnt->clients[e->assos_clients[src]]), TAG_SELECT_MOVE_REPLY, sizeof(req), &req);
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
 stock_msg(&(cnt->clients[e->assos_clients[src]]), TAG_SELECT_MOVE_REPLY, sizeof(req), &req);
 return (0);
}
