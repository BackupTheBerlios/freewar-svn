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
// get_surf.cpp for freewar in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Tue May 11 18:19:18 2004 jonathan huot
// Last update Fri May 28 18:23:29 2004 jonathan huot
//

#include "freewar.h"

SDL_Surface	*get_surf(t_info *info, unsigned int id)
{
  unsigned int	i;

  for (i = 0; i < NB_ITEMS; i++)
    if (gl_items[i].id == id)
      return (info->img[i]);
  printf("id %d\n", (int)id);
  put_error("pewt");
  return (0);
}

bool		get_land(unsigned int id)
{
  unsigned int	i;

  for (i = 0; i < NB_ITEMS; i++)
    if (gl_items[i].id == id)
      return (gl_items[i].land);
  return (false);
}
