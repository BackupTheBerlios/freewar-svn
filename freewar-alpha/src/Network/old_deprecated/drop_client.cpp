//
// drop_client.cpp for freewra in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Thu May  6 11:05:15 2004 jonathan huot
// Last update Thu May  6 11:05:23 2004 jonathan huot
//
#include "freewar.h"

void			drop_client(t_connections *cnt, unsigned short i)
{
  printf("Client %i dropped\n", i);
  memmove((void*)&cnt->clients[i], (void*)&cnt->clients[cnt->nb_clients - 1],
	  sizeof(*cnt->clients));
  cnt->nb_clients--;
  SDLNet_TCP_DelSocket(cnt->sset, cnt->clients[i].sock);
  SDLNet_TCP_Close(cnt->clients[i].sock);
}
