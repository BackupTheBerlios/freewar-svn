/*
** check_sockets.c for zappy in /u/ept2/huot_j
** 
** Made by jonathan huot
** Login   <huot_j@epita.fr>
** 
** Started on  Tue May 25 13:08:39 2004 jonathan huot
// Last update Tue Jun 29 18:03:45 2004 jonathan huot
*/

#include "network.h"

int		manage_client(t_client *client, fd_set *maskr, fd_set *maskw,
			      int *res)
{
  if (FD_ISSET(client->sock->channel, maskw))
    {
      (*res)--;
      if (!put_msg(client))
	return (-1);
    }
  if (*res > 0 && FD_ISSET(client->sock->channel, maskr))
    {
      (*res)--;
      if (get_msg(client))
	{
	  cnt->last_recv = client;
	  return (1);
	}
      if (client->loss)
	return (-1);
    }
  return (0);
}

int		check_tmp(t_tmp **newclt, fd_set *maskr, fd_set *maskw,
			  int *res)
{
  t_tmp		*list;
  t_tmp		*next;
  int		flg;
  int		ret;

  flg = 0;
  for (list = *newclt; *res > 0 && list; list = next)
    {
      next = list->next;
      if ((ret = manage_client(&list->c, maskr, maskw, res)) < 0)
	{
	  free_client(&list->c);
	  SDLNet_TCP_Close(list->c.sock);
	  *newclt = del_in_list(*newclt, &list->c);
	}
	if (ret == 1)
		flg = 1;
      if (*res <= 0)
	return (flg);
      list = next;
    }
  return (flg);
}

int		check_clients(fd_set *maskr, fd_set *maskw, int *res)
{
  int		i;
  int		ret;
  int		flg;

  flg = 0;
  for (i = 0; *res > 0 && cnt->clients[i].sock; i++)
    {
      if ((ret = manage_client(&cnt->clients[i], maskr, maskw, res)) < 0)
	{
	  loss_client(&cnt->clients[i]);
	  i = -1;
	}
      if (ret == 1)
        flg = 1;
      if (*res <= 0)
	return (flg);
    }
  return (flg);
}

int		check_server(fd_set *maskr, fd_set *maskw, int *res)
{
  if (cnt->server.sock)
    if (*res > 0 && FD_ISSET(cnt->server.sock->channel, maskr))
      {
	(*res)--;
	if (new_client(&cnt->newclient))
	  cnt->last_recv = &cnt->newclient->c;
	return (1);
      }
  return (0);
}
