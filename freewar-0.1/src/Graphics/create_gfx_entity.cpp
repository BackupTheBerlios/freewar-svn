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
// create_entity.cpp for graphics in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Fri Jun  4 18:14:17 2004 jonathan huot
// Last update Tue Jun 29 18:44:43 2004 jonathan huot
//

#include "graphics.h"

extern t_gfx	*gfx;

int	create_gfx_entity(int id)
{
  int	t;

  if (id < 0 || id > MAXSPRITE)
    return (-1);
  for (t = 0; t < MAXENTITY && gfx->entity[t].id_sprite != -1; t++)
    ;
  if (t == MAXENTITY)
    {
      fprintf(fd_log, "Too much gfx entity\n");
      return (-1);
    }
  gfx->entity[t].id_sprite = id;
  gfx->entity[t].id_surf = -1;
  gfx->entity[t].x = 0;
  gfx->entity[t].y = 0;
  gfx->entity[t].alpha = 0;
  gfx->entity[t].row = 0;
  gfx->entity[t].col = 0;
  return (t);
}

int	create_square_entity()
{
  int	t;

  for (t = 0; t < MAXSQUARE && gfx->square[t].exist == true; t++)
    ;
  if (t == MAXSQUARE)
    {
      fprintf(fd_log, "Too much square entity\n");
      return (-1);
    }
  gfx->square[t].exist = true;
  gfx->square[t].id_surf = -1;
  gfx->square[t].color = 0;
  gfx->square[t].x1 = 0;
  gfx->square[t].y1 = 0;
  gfx->square[t].x2 = 0;
  gfx->square[t].x2 = 0;
  return (t);
}
