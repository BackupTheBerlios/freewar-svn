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
#include "graphics.h"

extern t_gfx	*gfx;

int     edit_arena(int i, t_coord *scale, t_coord *offset, int zoom)
{
  if (i < 0 || i >= MAXSUBSCREEN || gfx->surface[i].exist == false)
    return (-1);
  if (scale)
    {
      gfx->surface[i].scale.x = scale->x;
      gfx->surface[i].scale.y = scale->y;
    }
  if (offset)
    {
      gfx->surface[i].off.x = offset->x;
      gfx->surface[i].off.y = offset->y;
    }
  if (zoom > 0)
    gfx->surface[i].zoom = zoom;
  return (0);
}
