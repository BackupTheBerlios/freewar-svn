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
// pf_init_values.cpp for freewar in /u/ept2/huot_j/Freewar/src/Pathfinding
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Sat Jun 12 15:59:01 2004 jonathan huot
// Last update Sun Jul  4 11:32:43 2004 
//

#include "freewar.h"

void		init_values(t_pathfinding *pf,
			    t_entity *t,
			    t_coord *dest)
{
  int		i;
  int		n;

  for (i = 0; i < pf->map_h; i++)
    for (n = 0; n < pf->map_w; n++)
      {
 	pf->open[i][n].close = 0;
	if (pf->open[i][n].best_path)
	  {
	    free(pf->open[i][n].best_path);
	    pf->open[i][n].best_path = 0;
	  }
	pf->open[i][n].cost_from = 0;
	pf->open[i][n].cost_to = 0;
 	pf->open[i][n].total = 0;
      }
  pf->entity = t;
  pf->move_x = dest->x;
  pf->move_y = dest->y;
  pf->peon_x = t->pos.x;
  pf->peon_y = t->pos.y;
  pf->x = pf->peon_x;
  pf->y = pf->peon_y;
  pf->checked->clear();
  pf->open[pf->y][pf->x].cost_to = abs(pf->move_x - pf->peon_x) +
    abs(pf->move_y - pf->peon_y);
}
