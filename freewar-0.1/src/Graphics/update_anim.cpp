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
** update_anim.c for freewar in /u/ept2/huot_j
** 
** Made by jonathan huot
** Login   <huot_j@epita.fr>
** 
** Started on  Fri Jun 11 12:06:09 2004 jonathan huot
// Last update Mon Jun 14 16:13:23 2004 stephane petitcolas
*/

#include "freewar.h"

extern t_gfx	*gfx;

int	update_anim(int id, int row, int dir, int newsprite)
{
  if (id < 0 || id > MAXENTITY || gfx->entity[id].id_sprite == -1)
    return (-1);
  if (newsprite > MAXSPRITE)
    return (-1);
  if (newsprite != -1)
    gfx->entity[id].id_sprite = newsprite;
  if (dir < gfx->spk[gfx->entity[id].id_sprite].col && dir >= 0)
    gfx->entity[id].col = dir;
  if (row >= 1)
    if (++gfx->entity[id].row >= gfx->spk[gfx->entity[id].id_sprite].row)
      gfx->entity[id].row = 0;
  return (0);
}
