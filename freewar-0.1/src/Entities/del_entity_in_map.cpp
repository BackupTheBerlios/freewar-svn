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
// del_entity_in_map.cpp for freewar in /root/Freewar/src
// 
// Made by 
// Login   <root@epita.fr>
// 
// Started on  Sun Jun 27 18:09:02 2004 
// Last update Mon Jul  5 12:51:10 2004 
//

#include "freewar.h"

int		del_entity_in_map(t_engine *e, t_entity *t)
{
  int		i;
  int		last;

  if (t <= 0 || t->pos.x < 0 || t->pos.x >= e->map_data.w ||
      t->pos.y < 0 || t->pos.y >= e->map_data.h)
    return (1);
  for (last = 0; last < MAX_ENTITY_ON_SCALE; last++)
    if (!e->scales[t->pos.y][t->pos.x].tab[last])
      break ;
  for (i = 0; i < MAX_ENTITY_ON_SCALE; i++)
    {
      if (e->scales[t->pos.y][t->pos.x].tab[i] == t)
	{
		if (last - 1 != i)
		{
			e->scales[t->pos.y][t->pos.x].tab[i] =
			e->scales[t->pos.y][t->pos.x].tab[last - 1];
			e->scales[t->pos.y][t->pos.x].coord[i] =
			e->scales[t->pos.y][t->pos.x].coord[last - 1];
		}
	  e->scales[t->pos.y][t->pos.x].tab[last - 1] = 0;
	  //printf("jai del l'entity numero %d, le max etant de %d\n", i, last);fflush(stdout);
	  return (0);
	}
    }
  return (1);
}
