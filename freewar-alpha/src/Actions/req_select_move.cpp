//
// req_select_move.cpp for freewar in /root/Freewar/src
// 
// Made by 
// Login   <root@epita.fr>
// 
// Started on  Sat Jul  3 09:47:19 2004 
// Last update Sun Jul  4 21:25:52 2004 
//

#include "freewar.h"

int			req_select_move(t_engine *e, t_trame *trame, int src)
{
  t_game_select_move	game;
  t_req_select_move	req;
  int		i;

  if (trame->len != sizeof(game))
    {
      fprintf(stderr, "ERROR: req_select_move: failed\n");
      return (1);
    }
  memcpy(&game, trame->msg, sizeof(game));
  req.id_req = game.id_req;
  if (!e->select[0][src])
    {
      fprintf(stderr, "ERROR: req_select_move: failed\n");
      req.id_action = -1;
    }
  for (i = 0; i < FW_MAX_SELECT && e->select[i][src]; i++)
    if (src == e->select[i][src]->app)
      req.id_action = create_action(e, e->select[i][src], game.pos);
  stock_msg(&(cnt->clients[e->assos_clients[src]]), TAG_SELECT_MOVE_REPLY, sizeof(req), &req);
  return (0);
}
