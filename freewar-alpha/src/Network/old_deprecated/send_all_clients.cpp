//
// cekivabien.cpp for freewar in /u/ept2/ribas_j/freewar/src
// 
// Made by jonathan ribas
// Login   <ribas_j@epita.fr>
// 
// Started on  Mon May  3 17:21:47 2004 jonathan ribas
// Last update Thu May  6 13:47:52 2004 jonathan huot
//

#include "freewar.h"

void			send_all_clients(t_connections *cnt, void *recv)
{
  unsigned short	i;
#ifdef FW_DEBUG
  t_trame	*trame;

  trame = unpack((t_ctrame*)recv);
  printf("send all players: tag: %d len: %d)\n", trame->tag, trame->len);
  free(trame);
#endif
  for (i = 0; i < cnt->nb_clients; i++)
    put_msg(cnt->clients[i].sock, recv);
}
