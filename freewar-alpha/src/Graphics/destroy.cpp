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
