// Copyright (C) 2004 Freewar Team <doomsday@freewar.net>

// This file is part of Freewar.

// Freewar is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.

// Freewar is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with Freewar; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
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
