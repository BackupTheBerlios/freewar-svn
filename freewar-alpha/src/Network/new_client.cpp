/*
** new_client.c for zappy in /u/ept2/huot_j
** 
** Made by jonathan huot
** Login   <huot_j@epita.fr>
** 
** Started on  Mon May 24 18:37:42 2004 jonathan huot
// Last update Tue Jun 29 18:36:19 2004 jonathan huot
*/

#include "network.h"
#include "tag.h"

int		new_client(t_tmp **newclt)
{
  TCPsocket	newsock;

  NETDEBUG("Un nouveau client s'est connecté\n");
  newsock = SDLNet_TCP_Accept(cnt->server.sock);
  if (!newsock)
    fprintf(fd_log, "accept: %s\n", SDLNet_GetError());
  else
    {
      put_in_client(newclt, newsock, STATE_NEW);
      stock_msg(&((*newclt)->c), TAG_WELCOME, 0, NULL);
      return (1);
    }
  return (0);
}
