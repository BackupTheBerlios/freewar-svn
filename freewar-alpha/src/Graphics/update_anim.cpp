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
