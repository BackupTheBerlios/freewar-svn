#include "network.h"

void		free_client(t_client *c)
{
  int		i;

  for (i = 0; i < NET_MAX_MSG; i++)
    {
      if (c->recv[i].msg)
	free(c->recv[i].msg);
      c->recv[i].msg = 0;
    }
  for (i = 0; i < NET_MAX_MSG; i++)
    {
      if (c->send[i].msg)
	free(c->send[i].msg);
      c->send[i].msg = 0;
    }
}
