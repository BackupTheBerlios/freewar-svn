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

extern t_gfx	*gfx;

int		is_collision(t_engine *e, t_entity *t, t_coord *pos)
{
  int		topx;
  int		topy;
  int		botx;
  int		boty;
  int		i;
  int		n;
  int		v;
  t_entity	*on;
  t_base_entity *b;
  t_spk		*spk;

  botx = -gfx->spk[gfx->entity[t->idgfx].id_sprite].w / CASE_SIZE_X;
  boty = -gfx->spk[gfx->entity[t->idgfx].id_sprite].h / CASE_SIZE_Y;
  for (topy = 4; topy > boty; topy--)
    for (topx = 4; topx > botx; topx--)
      if (pos->y - topy >= 0 && pos->x - topx >= 0 &&
		  pos->y - topy < e->map_data.h && pos->x - topx < e->map_data.w)
	for (i = 0; i < MAX_ENTITY_ON_SCALE &&
	       e->scales[pos->y - topy][pos->x - topx].tab[i]; i++)
	  if (e->scales[pos->y - topy][pos->x - topx].tab[i] != t)
	    {
		  on = e->scales[pos->y - topy][pos->x - topx].tab[i];
	      b = on->data;
		  spk = &(gfx->spk[gfx->entity[on->idgfx].id_sprite]);
	      fprintf(fd_log, "spk:%d (%d %d)\n", spk, spk->w, spk->h);
	      if (spk->w / CASE_SIZE_X > topx && spk->h / CASE_SIZE_Y > topy)
		for (n = 0; b->layer[n]; n++)
		  for (v = 0; t->data->layer[v]; v++)
		    if (b->layer[n] == t->data->layer[v])
		      return (1);
	    }
  return (0);
}
