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
// put_entity.cpp for freewar in /root/Freewar/src/Actions
// 
// Made by 
// Login   <root@epita.fr>
// 
// Started on  Wed Jul 14 18:23:50 2004 
// Last update Wed Jul 14 18:23:51 2004 
//

#include "freewar.h"

int		put_entity(t_engine *e, t_base_entity *base, int app,
			   t_coord pos, t_coord offset)
{
  int		i;
  t_entity	*n;

  if (pos.x > e->map_data.w)
    return (1);
  else if (pos.y > e->map_data.h)
    return (1);
  n = create_entity(e, base, app, pos);
  if (!n)
    return (1);
  for (i = 0; e->scales[pos.y][pos.x].tab[i]; i++)
    ;
  e->scales[pos.y][pos.x].tab[i] = n;
  e->scales[pos.y][pos.x].coord[i].x = offset.x;
  e->scales[pos.y][pos.x].coord[i].y = offset.y;
  return (0);
}
