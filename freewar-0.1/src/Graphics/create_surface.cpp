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
// create_surface.cpp for graphics in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Fri Jun  4 17:27:53 2004 jonathan huot
// Last update Tue Jun 29 18:43:28 2004 jonathan huot
//

#include "graphics.h"

extern t_gfx	*gfx;

int		create_surface(int width, int height, int depth, Uint32 color, int arena)
{
  int		i;

  for (i = 0; i < MAXSUBSCREEN && gfx->surface[i].exist == true; i++)
    ;
  if (i == MAXSUBSCREEN)
    return (-1);
  gfx->surface[i].exist = true;
  if (arena)
    {
      gfx->surface[i].zoom = 100;
      gfx->surface[i].off.x = 0;
      gfx->surface[i].off.y = 0;
      gfx->surface[i].scale.x = 0;
      gfx->surface[i].scale.y = 0;
    }
  else
  {
	  gfx->surface[i].color = color;
	  gfx->surface[i].s = SDL_CreateRGBSurface(SDL_HWSURFACE |
		  SDL_SRCCOLORKEY, width, height, gfx->buff->format->BitsPerPixel,
		  gfx->buff->format->Rmask, gfx->buff->format->Gmask,
		  gfx->buff->format->Bmask, gfx->buff->format->Amask);
	  //if (color)
	  //{
		  SDL_FillRect(gfx->surface[i].s, NULL, color);
	  //}
  }
  gfx->surface[i].w = width;
  gfx->surface[i].h = height;
  gfx->surface[i].arena = arena;
  gfx->surface[i].depth = depth;
  gfx->surface[i].show = 0;
  return (i);
}
