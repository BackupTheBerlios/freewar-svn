//
// add_client.cpp for freewar in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Thu May  6 11:05:37 2004 jonathan huot
// Last update Fri May  7 14:45:44 2004 jonathan huot
//

#include "freewar.h"

void			add_client(t_connections *cnt)
{
  TCPsocket		newsock;

  newsock = SDLNet_TCP_Accept(cnt->server.sock);
  if (!newsock)
    fprintf(stderr, "SDLNet_TCP_Accept: %s\n", SDLNet_GetError());
  else if (cnt->nb_clients < FW_MAX_CLIENTS - 1)
    {
      SDLNet_TCP_AddSocket(cnt->sset, newsock);
      cnt->clients[cnt->nb_clients].sock = newsock;
      cnt->clients[cnt->nb_clients].loss = 0;
      cnt->clients[cnt->nb_clients].ping_msec = 0;
      cnt->clients[cnt->nb_clients].pos = 0;
      cnt->nb_clients++;
    }
  cnt->newclient = &cnt->clients[cnt->nb_clients - 1];
}
