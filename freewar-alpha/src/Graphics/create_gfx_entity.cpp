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
