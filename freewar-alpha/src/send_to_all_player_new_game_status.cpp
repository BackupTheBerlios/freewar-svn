//
// send_to_all_player_new_game_status.cpp for freewar in /u/ept2/huot_j/Freewar/src
// 
// Made by jonathan huot le ... ?
// Login   <huot_j@epita.fr>
// 
// Started on  Thu May  6 11:12:00 2004 jonathan huot
// Last update Thu May  6 15:03:33 2004 jonathan ribas
//

#include "freewar.h"

int		send_to_all_player_new_game_status(t_game_param *gp)
{
  int		i;

  for (i = 0; cnt->clients[i].sock; i++)
    stock_msg(&cnt->clients[i], TAG_GAME_STATUS, sizeof(*gp), (void*)gp);
  return (0);
}
