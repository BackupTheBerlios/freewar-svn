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
// create_sprite.cpp for create_sprite in /u/ept2/petitc_s/sprite_package/create_sprite
// 
// Made by stephane petitcolas
// Login   <petitc_s@epita.fr>
// 
// Started on  Wed Jun  9 10:34:16 2004 stephane petitcolas
// Last update Thu Jun 17 11:49:03 2004 stephane petitcolas
//

#include	"create_package.h"

int		i = 2;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
	Uint32 rmask = 0xff000000;
	Uint32 gmask = 0x00ff0000;
	Uint32 bmask = 0x0000ff00;
	Uint32 amask = 0x000000ff;
#else
	Uint32 rmask = 0x000000ff;
	Uint32 gmask = 0x0000ff00;
	Uint32 bmask = 0x00ff0000;
	Uint32 amask = 0xff000000;
#endif

Uint32 getpixel(SDL_Surface *surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        return *p;

    case 2:
        return *(Uint16 *)p;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;

    case 4:
        return *(Uint32 *)p;

    default:
        return 0;       /* shouldn't happen, but avoids warnings */
    }
}

void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to set */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        *p = pixel;
        break;

    case 2:
        *(Uint16 *)p = pixel;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
            p[0] = (pixel >> 16) & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = pixel & 0xff;
        } else {
            p[0] = pixel & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = (pixel >> 16) & 0xff;
        }
        break;

    case 4:
        *(Uint32 *)p = pixel;
        break;
    }
}

SDL_Surface	*flip(SDL_Surface *surf)
{
  int		x;
  int		y;
  SDL_Surface	*tmp;
  Uint32	pix;
  SDL_Rect	pouet;

  tmp = SDL_CreateRGBSurface(SDL_SWSURFACE, surf->w, surf->h,
				  32,
				  rmask,gmask,bmask,amask);
  if (SDL_BlitSurface(surf, NULL, tmp, NULL) == -1)
    puts(SDL_GetError());
  SDL_LockSurface(tmp);
  SDL_LockSurface(surf);
  for (x = 0; x < tmp->w; x++)
    for (y = 0; y < tmp->h; y++)
      {
	pix = getpixel(tmp, x, y);
	putpixel(surf, (tmp->w - x) - 1, y, pix);
      }
  puts("je sort");
  SDL_UnlockSurface(surf);
  SDL_UnlockSurface(tmp);
  return(surf);
}

SDL_Surface	*create_sprite_pof(char *path, SDL_Rect *dest, 
			       SDL_Surface *surf, int a, int b)
{
  SDL_Surface	*tmp;
  SDL_Rect	dest_tmp;

  tmp = IMG_Load(path);
  if (!tmp)
    {
      puts(SDL_GetError());
      return(surf);
    }
  if (dest->x == 0 && dest->y == 0)
    {
      fflush(stdout);
      surf = SDL_CreateRGBSurface(SDL_SWSURFACE, tmp->w * a, tmp->h * b,
				  32,
				  rmask,gmask,bmask,amask);
      dest->w = tmp->w;
      dest->h = tmp->h;
    }
  if (tmp->w != dest->w || tmp->h != dest->h)
    {
      printf("Les tailles doivent etre constantes\n");
      exit(1);
    }
  dest_tmp.x = dest->x;
  dest_tmp.y = dest->y;
  dest->x += tmp->w;
  dest_tmp.w = dest->w;
  dest_tmp.h = dest->h;
  if (SDL_BlitSurface(tmp, NULL, surf, &dest_tmp) == -1)
    puts(SDL_GetError());
  if (dest->x / tmp->w == a)
    {
      dest->x = 0;
      dest->y += tmp->h;
    }
  return(surf);
}

SDL_Surface	*create_sprite(char *path, SDL_Rect *dest, 
			       SDL_Surface *surf, int a, int b)
{
  SDL_Surface	*tmp;
  SDL_Rect	dest_tmp;

  tmp = IMG_Load(path);
  if (!tmp)
    {
      puts(SDL_GetError());
      return(surf);
    }
  if (dest->x == 0 && dest->y == 0)
    {
      fflush(stdout);
      surf = SDL_CreateRGBSurface(SDL_SWSURFACE, tmp->w * a, tmp->h * b,
				  32,
				  rmask,gmask,bmask,amask);
      dest->w = tmp->w;
      dest->h = tmp->h;
    }
  if (tmp->w != dest->w || tmp->h != dest->h)
    {
      printf("Les tailles doivent etre constantes\n");
      exit(1);
    }
  if (i == 2)
    {
      dest_tmp.x = dest->x;
      dest_tmp.y = dest->y;
      dest->x += tmp->w;
      i = 1;
    }
  else if (i == 1)
   {
     dest_tmp.x = (surf->w) - dest->x;
     dest_tmp.y = dest->y;
     tmp = flip(tmp);
     i = 2;
    }
  if (i == 2 || i == 1)
    {
      dest_tmp.w = dest->w;
      dest_tmp.h = dest->h;
      if (SDL_BlitSurface(tmp, NULL, surf, &dest_tmp) == -1)
	puts(SDL_GetError());
    }
  if (dest->x / tmp->w == (a / 2) + 1)
    {
      dest->x = 0;
      dest->y += tmp->h;
      i = 2;
    }
  return(surf);
}

int		main(int ac, char **av)
{
  char		*path;
  int		i;
  char		*str;
  int		cpt;
  char		*tmp;
  SDL_Rect	dest;
  SDL_Surface	*surf;

  dest.x = 0;
  dest.y = 0;
  surf = 0;
  if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_MOUSEMOTION) < 0)
    {
      fprintf(stderr,
	      "Couldn't initialize SDL: %s\n", SDL_GetError());
      return(0);
    }
  atexit(SDL_Quit);
  if (ac > 3)
    {
      if (strcmp(av[1], "-r"))
	for (i = 3; av[i]; i++)
	  surf = create_sprite(av[i], &dest, surf, atoi(av[1]), atoi(av[2]));
      else
	{
	  for (i = 4; av[i]; i++)
	    surf = create_sprite_pof(av[i], &dest, surf, atoi(av[2]), atoi(av[3]));
	  puts("pouet");
	}
      if (surf == 0)
	exit(0);
      if (SDL_SaveBMP(surf, "test.bmp") == -1)
	puts(SDL_GetError());
      puts("fini");
    }
  else
    puts("Syntax error : ./create_sprite col line paths");
  return(0);
}
