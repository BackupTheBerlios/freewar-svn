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
// std_trame.cpp for freewar in /u/ept2/huot_j/freewar/engine/src/Network
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Tue May  4 14:44:15 2004 jonathan huot
// Last update Fri Jun 18 11:16:45 2004 jonathan huot
//

#include "freewar.h"

int		trame_loss(t_trame *req, char *s)
{
  fprintf(stderr, "trame tag[%i]", (int)req->tag);
  return (put_error(s));
  return (0);
}

void			fill_trame(t_trame *t, unsigned char tag,
				   unsigned short len, void *value)
{
  if (len > NET_BUF_LEN - sizeof(tag) - sizeof(len))
    put_error("fill_trame: len too big, segfault/bus error soon..");
  t->tag = tag;
  t->len = len;
  memcpy((void*)t->value, value, len);
}

int			is_valid_trame(t_trame *t, short tag)
{
  if (tag != t->tag)
    return (0);
  if (t->len > NET_BUF_LEN - sizeof(t->tag) - sizeof(t->len))
    return (0);
  return (1);
}

void			send_trame(TCPsocket sock, t_trame *tlv)
{
  t_ctrame		*crypt;

  crypt = pack(tlv);
  if (!put_msg(sock, (void*)crypt))
    {
      printf("putMsg failed (socket closed?)\n");
      return;
    }
}

int			recv_trame(t_connections *cnt, t_client *client,
				   t_trame *trame)
{
  if (SDLNet_CheckSockets(cnt->sset, 100) < 0)
    fprintf(stderr, "SDLNet_CheckSockets: %s\n", SDLNet_GetError());
  else if (SDLNet_SocketReady(client->sock) && get_msg(client, trame))
    return (1);
  return (0);
}
