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
// edit_entity_on_surface.cpp for graphics in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Fri Jun  4 18:18:42 2004 jonathan huot
// Last update Tue Jun 29 15:44:47 2004 
//

#include "graphics.h"

extern t_gfx	*gfx;

int     edit_entity_on_surface(int id, int surf, int x, int y, int alpha)
{
  if (id < 0 || id > MAXENTITY || surf < 0 || surf > MAXSUBSCREEN ||
      gfx->entity[id].id_sprite == -1)
    return (-1);
  if (gfx->surface[surf].arena)
    {
      if (x >= 0)
	gfx->entity[id].x = x;
      if (y >= 0)
	gfx->entity[id].y = y;
    }
  else
    {
      if (!(x < 0 || x > gfx->surface[surf].w))
	gfx->entity[id].x = x;
      if (!(y < 0 || y > gfx->surface[surf].h))
	gfx->entity[id].y = y;
    }
  gfx->entity[id].id_surf = surf;
  gfx->entity[id].alpha = (alpha < 0) ? (0) :
    ((alpha > 255) ? (255) : (alpha)) ;
  return (0);
}

int     edit_square_on_surface(int id, int surf,
			       t_coord *c1, t_coord *c2,
			       Uint32 color)
{
  if (id < 0 || id > MAXSQUARE || surf < 0 || surf > MAXSUBSCREEN ||
      gfx->square[id].exist == false)
    return (-1);
  if (gfx->surface[surf].arena)
    {
      if (c1)
	{
	  if (c1->x >= 0)
	    gfx->square[id].x1 = c1->x;
	  if (c1->y >= 0)
	    gfx->square[id].y1 = c1->y;
	}
      if (c2)
	{
	  if (c2->x >= 0)
	    gfx->square[id].x2 = c2->x;
	  if (c2->y >= 0)
	    gfx->square[id].y2 = c2->y;
	}
    }
  else
    {
      if (c1)
	{
	  if (!(c1->x < 0 || c1->x > gfx->surface[surf].w))
	    gfx->square[id].x1 = c1->x;
	  if (!(c1->y < 0 || c1->y > gfx->surface[surf].h))
	    gfx->square[id].y1 = c1->y;
	}
      if (c2)
	{
	  if (!(c2->x < 0 || c2->x > gfx->surface[surf].w))
	    gfx->square[id].x2 = c2->x;
	  if (!(c2->y < 0 || c2->y > gfx->surface[surf].h))
	    gfx->square[id].y2 = c2->y;
	}
    }
  gfx->square[id].id_surf = surf;
  gfx->square[id].color = color;
  return (0);
}
