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
// create_and_open_screen.cpp for graphics in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Fri Jun  4 16:38:49 2004 jonathan huot
// Last update Fri Jun  4 19:28:21 2004 jonathan huot
//

#include "freewar.h"

t_gfx		*gfx = 0;

int		init_fonts()
{
  if (TTF_Init() < 0)
    return (fprintf(fd_log, "%s: Error: Couldn't initialize SDL_TTF: %s\n",
		    NAME, SDL_GetError()));
  gfx->win->font = 0;
  //  if (!(gfx->win->font = TTF_OpenFont(FONT, SIZE)))
  //    fprintf(fd_log, "%s: Error: TTF_OpenFont: %s\n", NAME, TTF_GetError());
 return (0);
}

void		init_gfx()
{
  int		i;

  for (i = 0; i < MAXSPRITE; i++)
    gfx->spk[i].sprite = 0;
  for (i = 0; i < MAXENTITY; i++)
    gfx->entity[i].id_sprite = -1;
  for (i = 0; i < MAXDEBUG; i++)
    gfx->debug[i].id_sprite = -1;
  for (i = 0; i < MAXSUBSCREEN; i++)
  {
    gfx->surface[i].exist = false;
    gfx->surface[i].x = 0;
    gfx->surface[i].y = 0;
    gfx->surface[i].w = 0;
    gfx->surface[i].h = 0;
    gfx->surface[i].depth = 0;
    gfx->surface[i].arena = 0;
    gfx->surface[i].zoom = 0;
    gfx->surface[i].scale.x = 0;
    gfx->surface[i].scale.y = 0;
    gfx->surface[i].off.x = 0;
    gfx->surface[i].off.y = 0;
    gfx->surface[i].show = 0;
  }
}

int		create_and_open_screen(int sizex, int sizey, int bpp, int mode)
{
  static bool	first = true;
  static bool	dofree = false;

  if (dofree == true)
    {
      dofree = false;
      SDL_FreeSurface(gfx->buff);
    }
  if (first == true)
    {
      if (!(gfx = (t_gfx*)malloc(sizeof(*gfx))))
	{
	  printf("Out of memory.\n");
	  exit(42);
	}
      gfx->videoinfo = (SDL_VideoInfo *)SDL_GetVideoInfo();
      first = false;
    }
  gfx->win = (t_display*)xmalloc(sizeof(*(gfx->win)));  
#ifdef GRAPHICS_DEBUG
  fprintf(fd_log, "Checking mode %dx%d@%dbpp.\n", sizex, sizey, bpp);
#endif
  gfx->bpp = SDL_VideoModeOK(sizex, sizey, bpp, mode);
  if(!gfx->bpp)
    {
#ifdef GRAPHICS_DEBUG
      fprintf(fd_log, "Mode not available, trying another..\n");
#endif
      gfx->bpp = SDL_VideoModeOK(sizex, sizey, bpp, SDL_ANYFORMAT);
      if (!gfx->bpp)
	return (-1);
	  if (!(gfx->main = SDL_SetVideoMode(sizex, sizey, bpp, mode | SDL_GLSDL)))
	    return (-1);
    }
  else if (!(gfx->main = SDL_SetVideoMode(sizex, sizey, bpp, mode | SDL_GLSDL)))
    return (-1);
  gfx->win->sdlMainScreen = gfx->main;
  gfx->win->text = NULL;
  SDL_WM_SetCaption("Freewar", "fw.ico");
  gfx->buff = xSDL_DisplayFormatAlpha(gfx->main);
  init_gfx();
  if (init_fonts())
    return (-1);
  dofree = true;
  return (0);
}
