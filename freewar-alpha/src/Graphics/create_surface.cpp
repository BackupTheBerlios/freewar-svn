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
