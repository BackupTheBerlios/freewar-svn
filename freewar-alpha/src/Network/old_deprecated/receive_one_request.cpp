//
// receive_one_request.cpp for freewar in /u/ept2/huot_j/freewar/engine/src/Network
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Tue May  4 14:43:51 2004 jonathan huot
// Last update Mon Jun 14 18:23:28 2004 jonathan huot
//

#include "freewar.h"

int			receive_one_request(t_trame *req,
					    t_connections *cnt)
{
  unsigned short	i;

  while (42)
    {
      if (SDLNet_CheckSockets(cnt->sset, (unsigned int)-1) < 0)
	{
	  fprintf(stderr, "SDLNet_CheckSockets: %s\n", SDLNet_GetError());
	  return (0);
	}
      for (i = 0; i < cnt->nb_clients; i++)
	{
	  if (recv_trame(cnt, &(cnt->clients[i]), req))
	    {
	      cnt->last_recv = &(cnt->clients[i]);
	      return (1);
	    }
	  if (cnt->clients[i].loss > NET_MAXLOSS)
	    return (0);
	}
    }
  // ne devrait pas en arriver jusque la:
  return (0);
}
