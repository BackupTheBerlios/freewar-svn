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
// get_path.cpp for freewar in /u/ept2/huot_j/Freewar/src
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Sat Jun 12 15:29:37 2004 jonathan huot
// Last update Sun Jul  4 14:43:28 2004 
//

#include "freewar.h"

t_coord			*get_path(t_engine *e, t_entity *t, t_coord g)
{
  t_coord		*res;
  t_path		*path;
  t_path		*next;
  int			i;

  res = (t_coord*)xmalloc(sizeof(*res) *
			  e->map_data.w *
			  e->map_data.h + 1);
  i = 0;
  path = pathfinding(e, t, &g);
  if (!path)
    {
      free(res);
      return (0);
    }
  while (path)
    {
      next = path->next;
      res[i].x = path->x;
      res[i].y = path->y;
      i++;
      free(path);
      path = next;
    }
  res[i].x = -1;
  res[i].y = -1;
  return (res);
}
