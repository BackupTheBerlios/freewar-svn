/*
** close_connection.c for network engine in /u/ept2/huot_j/network_engine
** 
** Made by jonathan huot
** Login   <huot_j@epita.fr>
** 
** Started on  Wed Jun 23 14:55:12 2004 jonathan huot
** Last update Wed Jun 23 15:03:20 2004 jonathan huot
*/

#include "network.h"

void		close_connection()
{
  t_tmp		*list;
  t_tmp		*next;
  int		i;

  if (cnt->server.sock)
    SDLNet_TCP_Close(cnt->server.sock);
  list = cnt->newclient;
  while (list)
    {
      next = list->next;
      if (list->c.sock)
	SDLNet_TCP_Close(list->c.sock);
      free_client(&list->c);
      free(list);
      list = next;
    }
  list = cnt->deadclient;
  while (list)
    {
      next = list->next;
      if (list->c.sock)
	SDLNet_TCP_Close(list->c.sock);
      free_client(&list->c);
      free(list);
      list = next;
    }
  for (i = 0; cnt->clients[i].sock; i++)
    {
      SDLNet_TCP_Close(cnt->clients[i].sock);
      free_client(&cnt->clients[i]);
    }
  free(cnt->clients);
  cnt = 0;
}
