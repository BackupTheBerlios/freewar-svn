//
// update_game_param.cpp for freewar in /u/ept2/ribas_j/freewar/src
// 
// Made by jonathan ribas
// Login   <ribas_j@epita.fr>
// 
// Started on  Mon May  3 13:41:52 2004 jonathan ribas
// Last update Thu May  6 19:27:55 2004 jonathan huot
//

#include "freewar.h"

int		update_game_param(t_trame *req, t_game_param *game_params)
{
  int		no;

  // fonction qui va regarder la requete, et les connection, et
  // modifier en consequence la structure game_params !
  if (req->tag == TAG_GP_PLAYERS)
    {
      if ((sizeof(no) + sizeof(*game_params->players)) != req->len)
	return (put_error("Incomprehension client/server"));
      memcpy((void*)(&no), req->msg, sizeof(no));
      memcpy((void*)(&(game_params->players[no])), req->msg + sizeof(no),
	     sizeof(*game_params->players));
    }
  /*else if (req->tag == TAG_LEAVE)
    {
      if (sizeof(no) != req->len)
	return (put_error("Incomprehension client/server2"));
      no = req->value;
      game_params->players[
    }*/
  return (0);
}
