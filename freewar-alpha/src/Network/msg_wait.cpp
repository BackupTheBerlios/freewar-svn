/*
** msg_wait.c for network engine in /u/ept2/huot_j/network_engine
** 
** Made by jonathan huot
** Login   <huot_j@epita.fr>
** 
** Started on  Tue Jun 22 17:52:38 2004 jonathan huot
// Last update Tue Jun 29 19:25:24 2004 jonathan huot
*/

#include "network.h"

int		msg_wait(t_client *client)
{
  if (!client)
    return (0);
  if (TAG_EXEC(client) >= 0 &&
      POS_EXEC(client) >= (LEN_EXEC(client) * sizeof(*MSG_EXEC(client))) +
      sizeof(TAG_EXEC(client)) + sizeof(LEN_EXEC(client)))
    return (1);
  return (0);
}
