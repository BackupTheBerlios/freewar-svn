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
/*
** main.c for main in /u/ept2/petitc_s/freewar/pathfinding
** 
** Made by stephane petitcolas
** Login   <petitc_s@epita.fr>
** 
** Started on  Sun Feb 15 15:39:03 2004 stephane petitcolas
// Last update Sun Jul  4 14:44:43 2004 
*/

#include "freewar.h"

t_path			*pathfinding(t_engine *e, t_entity *t, t_coord *dest)
{
  static t_pathfinding	*pf;
  static t_case_info	**open;
  static int		first = 1;
#ifdef PATHFIND_DEBUG
  char			buf[512];
  Uint32		next_time;
#endif

  if (first)
    {
      init_open(&pf, &open, e);
      pf->open = open;
      first = 0;
    }
  init_values(pf, t, dest);
  open[pf->y][pf->x].poid = 10;
#ifdef PATHFIND_DEBUG
  next_time = SDL_GetTicks();
#endif
  if (pf->move_x >= pf->map_w || pf->move_x < 0 ||
      pf->move_y >= pf->map_h || pf->move_y < 0 ||
	  get_best_type(pf, pf->move_x, pf->move_y) < 0)
    return (0);
  while (42)
    {
      if (pf->x == pf->move_x && pf->y == pf->move_y)
	break;
      calc_case_info(pf);
      if (searchsmall(pf) < 0)
	return (0);
    }
#ifdef PATHFIND_DEBUG
  sprintf(buf, "DEBUG: pathtime: %d avec (%d,%d) vers (%d,%d)",
	  SDL_GetTicks() - next_time, pf->peon_x, pf->peon_y,
	  pf->move_x, pf->move_y);
  put_error(buf);
#endif
  my_put_in_path(&(open[pf->move_y][pf->move_x].best_path),
		 pf->move_x, pf->move_y);
  return (my_pathdup(open[pf->move_y][pf->move_x].best_path));
}
