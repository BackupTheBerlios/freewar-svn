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
// destroy.cpp for graphics in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Fri Jun  4 19:02:57 2004 jonathan huot
// Last update Fri Jun  4 19:33:21 2004 jonathan huot
//

#include "graphics.h"

extern t_gfx	*gfx;

void		destroy_surface(int id)
{
  if (id < 0 || id > MAXSUBSCREEN)
    return;
  gfx->surface[id].exist = false;
}

void		destroy_sprite(int id)
{
  if (id < 0 || id > MAXSPRITE)
    return;
  SDL_FreeSurface(gfx->spk[id].sprite);
  gfx->spk[id].sprite = 0;
}

void		destroy_gfx_entity(int id)
{
  if (id < 0 || id > MAXENTITY)
    return;
  gfx->entity[id].id_sprite = -1;
}
