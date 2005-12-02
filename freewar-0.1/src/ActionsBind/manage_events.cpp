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
// revoir rapidement ce fichier avant de faire une
// crise cardiaque

#include "freewar.h"

#include <iostream>
using namespace std;

void		get_pos_verif_move(int *pos, int *off,
				   int size, int move,
				   int posmax)
{
  *off += move;
  // verif offset limit:
  if (*off < 0)
    {
      (*pos)--;
      // verif position limit:
      if (*pos < 0)
	{
	  *pos = 0;
	  *off = 0;
	}
      else
	*off += size;
    }
  if (*off > size)
    {
      (*pos)++;
      // verif position limit:
      if (*pos >= posmax)
	{
	  *pos = posmax - 1;
	  *off = size;
	}
      else
	*off -= size;
    }
}

void		get_pos_inertie(int *inertie, int negative)
{
#define MAX_INERTIE (20)

  if (negative)
    {
      if (*inertie > 0)
	*inertie = -(*inertie);
      if (*inertie > -MAX_INERTIE)
	*inertie += (*inertie) ? (*inertie) : (-1);
    }
  else
    {
      if (*inertie < 0)
	*inertie = -(*inertie);
      if (*inertie < MAX_INERTIE)
	*inertie += (*inertie) ? (*inertie) : (1);
    }
}

int		get_pos(t_engine *e, int xfin, int yfin)
{
  static int	inertie_x = 0;
  static int	inertie_y = 0;

  // FIXME: the size of deplacement between left and right is not the same.
  // (left is bigger)

  // inertie for X
  if (xfin <= SCROLL_X)
    get_pos_inertie(&inertie_x, 1);
  else if (xfin >= e->g.w_main - SCROLL_X)
    get_pos_inertie(&inertie_x, 0);
  else if (inertie_x)
    inertie_x /= 2;

  // inertie for Y
  if (yfin <= SCROLL_Y)
    get_pos_inertie(&inertie_y, 1);
  else if (yfin >= e->g.h_main - SCROLL_Y)
    get_pos_inertie(&inertie_y, 0);
  else if (inertie_y)
    inertie_y /= 2;

  // move pos and off
  // for x:
  if (inertie_x)
    get_pos_verif_move(&(e->g.pos_arena.x), &(e->g.off_arena.x),
		       CASE_SIZE_X, inertie_x,
		       e->map_data.w - e->g.w_main);
  // for y:
  if (inertie_y)
    get_pos_verif_move(&(e->g.pos_arena.y), &(e->g.off_arena.y),
		       CASE_SIZE_Y, inertie_y,
		       e->map_data.h - e->g.h_main);

  // return if change:
  return ((inertie_x || inertie_y) ? (1) : (0));
}

void		manage_events(t_engine *e)
{
  // TODO: Modifier ça pour rendre le clic de nouveau utilisable.
  get_pos(e, e->events->xfin / CASE_SIZE_X,
	  e->events->yfin / CASE_SIZE_Y);

	//if (e->events->mousepose[0].button)
	//{
  // Pour debug le deplacement de souris uniquement:
	//}
	//  req_select_move(e, &trame, t);
	//  req_select_attack(e, &trame, t);
	//  req_select_create_units(e, &trame, t);
	//  req_select_create_building(e, &trame, t);
	//  manage_selection(e, &trame, t);
}
