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

int		get_best_type(t_pathfinding *c, int x, int y)
{
  int		i;
  int		n;
  int		max;
  int		res;
  t_coord	tmp;

  max = 10000000;
  res = -1;
  tmp.x = x;
  tmp.y = y;
  if (is_collision(c->engine, c->entity, &tmp))
    return (-1);
  for (n = 0; c->entity->data->type[n]; n++)
    for (i = 0; i < c->engine->db.nb_types; i++)
      {
	if (&c->engine->db.types[i] == c->entity->data->type[n])
	  {
	    if (c->mymap[i][y][x] && c->mymap[i][y][x] < max)
	      res = i;
	  }
      }
  return (res);
}
