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
#include "freewar.h"

int		join_game(t_trame *req)
{
  char		*ip;
  int		len;
  int		port;

  len = req->len - sizeof(port);
  ip = (char*)xmalloc(len);
  memcpy(ip, req->msg, len);
  memcpy(&port, req->msg + len, sizeof(port));
  fprintf(fd_log, "Join la partie ip(%s:%d)\n", ip, port);
  init_connection(ip, port);
  stock_msg(&(cnt->clients[1]), TAG_JOIN, 0, NULL);
  return (0);
}
