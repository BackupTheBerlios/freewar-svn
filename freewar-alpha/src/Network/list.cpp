/*
** list.c for zappy in /u/ept2/huot_j
** 
** Made by jonathan huot
** Login   <huot_j@epita.fr>
** 
** Started on  Tue May 25 13:29:21 2004 jonathan huot
** Last update Wed Jun 23 15:39:04 2004 jonathan huot
*/

#include "network.h"

void	free_list_client(t_tmp *newclt)
{
  t_tmp	*next;

  while (newclt)
    {
      next = newclt->next;
      free(newclt);
      newclt = next;
    }
}

t_tmp	*del_in_list(t_tmp *newclt, t_client *c)
{
  t_tmp	*prev;
  t_tmp	*next;
  t_tmp	*first;

  if (!newclt)
    return (0);
  first = newclt;
  prev = 0;
  while (newclt)
    {
      if (&newclt->c == c)
	{
	  next = newclt->next;
	  free(newclt);
	  if (!prev)
	    return (next);
	  prev->next = next;
	  break;
	}
      prev = newclt;
      newclt = newclt->next;
    }
  return (first);
}

void	put_in_tmp_client(t_tmp **begin, t_client *c)
{
  t_tmp	*newclt;

  newclt = (t_tmp*)xmalloc(sizeof(*newclt));
  memcpy(&newclt->c, c, sizeof(newclt->c));
  newclt->state = c->loss;
  c->loss = 0;
  newclt->next = *begin;
  *begin = newclt;
}

void	put_in_client(t_tmp **begin, TCPsocket sock, int state)
{
  t_tmp	*newclt;

  newclt = (t_tmp*)xmalloc(sizeof(*newclt));
  init_client(&newclt->c);
  newclt->c.sock = sock;
  newclt->state = state;
  newclt->next = *begin;
  *begin = newclt;
}
