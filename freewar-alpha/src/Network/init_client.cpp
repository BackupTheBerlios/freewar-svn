/*
** init_client.c for network engine in /u/ept2/huot_j/network_engine
** 
** Made by jonathan huot
** Login   <huot_j@epita.fr>
** 
** Started on  Tue Jun 22 18:18:56 2004 jonathan huot
** Last update Tue Jun 22 18:19:11 2004 jonathan huot
*/

#include "network.h"

void		init_client(t_client *client)
{
  int		i;

  client->pos_recv = 0;
  client->pos_exec = 0;
  client->pos_send = 0;
  client->pos_stock = 0;
  for (i = 0; i < NET_MAX_MSG; i++)
    {
      init_msg(&(client->recv[i]));
      init_msg(&(client->send[i]));
    }
  client->sock = 0;
  client->loss = 0;
}
