//
// aff_screen.cpp for graphics in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Fri Jun  4 19:00:33 2004 jonathan huot
// Last update Fri Jun  4 19:02:09 2004 jonathan huot
//

#include "graphics.h"

extern t_gfx	*gfx;

int				manage_cursor()
{
  return (0);
}

int				aff_screen()
{
  manage_cursor();
  if (xSDL_BlitSurface(gfx->buff, NULL, gfx->main, NULL) < 0)
    return (-1);
  if (SDL_Flip(gfx->main) < 0)
    return (-1);
  return (0);
}
