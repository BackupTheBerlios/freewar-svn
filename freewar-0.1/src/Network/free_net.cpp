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
