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

float		get_best_speed_factor(t_engine *e, t_entity *t)
{
  int		i;
  int		d;
  t_base_land	*land;
  int		c;
  float		coef;

  coef = 0.0;
  land = e->scales[t->pos.y][t->pos.x].land;
  for (i = 0; t->data->type[i] != 0; i++)
    {
      for (d = 0; d < GAME_MAX_FACTOR; d++)
		if (t->data->type[i]->speed[d].type == FACTOR_SURFACE)
		{
		for (c = 0; t->data->type[i]->speed[d].factor[c].condition.ptr != 0; c++)
	      if (t->data->type[i]->speed[d].factor[c].condition.ptr == land)
		{
		  if (t->data->type[i]->speed[d].factor[c].coef > coef)
		    coef = t->data->type[i]->speed[d].factor[c].coef;
		  break;
		}
	    break;
	  }
    }
  return(coef);
}
