//
// edit_surface.cpp for graphics in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Fri Jun  4 17:52:20 2004 jonathan huot
// Last update Tue Jun 29 18:43:14 2004 jonathan huot
//

#include "graphics.h"

extern t_gfx	*gfx;

int		edit_surface(int i, int x, int y, int show, int alpha)
{
  if (i < 0 || i >= MAXSUBSCREEN || gfx->surface[i].exist == false)
    return (-1);
  gfx->surface[i].x = x;
  gfx->surface[i].y = y;
  gfx->surface[i].show = show;
  return (0);
}
