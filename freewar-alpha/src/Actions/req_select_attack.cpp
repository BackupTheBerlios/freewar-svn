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
  stock_msg(&(cnt->clients[e->assos_clients[src]]), TAG_SELECT_ATTACK_REPLY, sizeof(req), &req);
  return (0);
}
