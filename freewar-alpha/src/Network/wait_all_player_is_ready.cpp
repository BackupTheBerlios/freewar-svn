//
// wait_all_player_is_ready.cpp for freewar in /u/ept2/huot_j/Freewar/src
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Thu May  6 11:10:01 2004 jonathan huot
// Last update Thu May  6 13:58:23 2004 jonathan huot
//

#include "freewar.h"

int		wait_all_player_is_ready(t_engine *e)
{
  unsigned char	nb;
  unsigned char	i;
  int		max;
  t_trame	recv;

  nb = 0;
  max = 3131313;
  while (nb < e->nb_players - 1)
    {
      if (check_select(1000))
	  {
		for (i = 0; cnt->clients[i].sock; i++)
	  {
	    while (exec_msg(&(cnt->clients[i]), &recv))
	      {
		if (is_valid_trame(&recv, TAG_PLAYERS_READY))
		  {
		    if (++nb >= max)
		      return (0);
		  }
		else
		  fprintf(fd_log, "recu %d from %d player\n", recv.tag, i);
	      }
	  }
      max = i;
	  }
    }
  for (i = 0; cnt->clients[i].sock; i++)
    stock_msg(&(cnt->clients[i]), TAG_PLAYERS_READY, 0, NULL);
  return (0);
}
