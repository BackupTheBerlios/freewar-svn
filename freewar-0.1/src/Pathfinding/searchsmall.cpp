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
// searchsmall.cpp for freewar in /u/ept2/huot_j/Freewar/src/Pathfinding
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Sat Jun 12 16:03:27 2004 jonathan huot
// Last update Sat Jun 12 17:19:22 2004 jonathan huot
//

#include "freewar.h"

int			searchsmall(t_pathfinding *c)
{
  unsigned int			save;
  list<t_checked>::iterator	i;
  list<t_checked>::iterator	backup;

  save = UINT_MAX;
  for (i = c->checked->begin(); i != c->checked->end(); i++)
    if (i->total > 0 && (unsigned int)i->total < save)
      {
	backup = i;
	save = i->total;
	c->y = i->y;
	c->x = i->x;
      }
  if (save != UINT_MAX)
    c->checked->erase(backup);
  return ((save == UINT_MAX) ? (-1) : (0));
}
