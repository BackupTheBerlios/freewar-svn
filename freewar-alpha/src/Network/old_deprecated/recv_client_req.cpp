//
// recv_client_req.cpp for freewar in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Fri May  7 18:36:34 2004 jonathan huot
// Last update Mon Jun 14 18:17:27 2004 jonathan huot
//

#include "freewar.h"

int			recv_client_req(t_client *clt, t_trame *req)
{
  SDLNet_SocketSet	sset;

  sset = SDLNet_AllocSocketSet(1);
  SDLNet_TCP_AddSocket(sset, clt->sock);
  while (32)
    {
      if (SDLNet_CheckSockets(sset, (Uint32)-1) < 0)
	return (put_error("recv_client_req failed"));
      if (SDLNet_SocketReady(clt->sock) && get_msg(clt, req))
	return (0);
      else if (clt->loss > NET_MAXLOSS)
	return (1);
    }
  return (0);
}
