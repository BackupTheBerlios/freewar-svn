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
// update_surf.cpp for graphics in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Fri Jun  4 18:22:49 2004 jonathan huot
// Last update Thu Jul  1 18:02:12 2004 
//

#include "graphics.h"
#include "SDL_gfxPrimitives.h"

extern t_gfx	*gfx;

int		zoom_x(t_surface *s)
{
  return ((CASE_SIZE_X * s->zoom) / 100);
}

int		zoom_y(t_surface *s)
{
  return ((CASE_SIZE_Y * s->zoom) / 100);
}

int		get_src(t_gfx_entity *ent, t_spk *spk, t_surface *s, SDL_Rect *src)
{
  src->x = ent->col * spk->w;
  src->y = ent->row * spk->h;
  src->w = spk->w;
  src->h = spk->h;
  if (ent->x < s->scale.x * zoom_x(s) + s->off.x) // l'entitee est sur la premiere colone
    {
      src->x += s->off.x;
      src->w -= s->off.x;
    }
  else if (ent->x >= s->scale.x * zoom_x(s) + s->w - spk->w + s->off.x) // l'entitee est sur la derniere colone
    src->w = s->scale.x * zoom_x(s) + s->w - ent->x + s->off.x;
  if (ent->y < s->scale.y * zoom_y(s) + s->off.y) // l'entitee est sur la premiere ligne
    {
      src->y += s->off.y;
      src->h -= s->off.y;
    }
  else if (ent->y >= s->scale.y * zoom_y(s) + s->h - spk->h + s->off.y) // l'entitee est sur la derniere ligne
    src->h = s->scale.y * zoom_y(s) + s->h - ent->y + s->off.y;
  return (0);
}

int		get_dst(t_gfx_entity *ent, t_spk *spk, t_surface *s, SDL_Rect *dst, SDL_Rect *src)
{
  dst->w = src->w;
  dst->h = src->h;
  dst->x = s->x + ent->x - s->scale.x * zoom_x(s);
  dst->y = s->y + ent->y - s->scale.y * zoom_y(s);
  if (!(ent->x >= s->scale.x * zoom_x(s) &&
      ent->x < s->scale.x * zoom_x(s) + s->off.x)) // l'entitee est sur la premiere colone
    {
      dst->x -= s->off.x;
    }
  if (!(ent->y >= s->scale.y * zoom_y(s) &&
	ent->y < s->scale.y * zoom_y(s) + s->off.y)) // l'entitee est sur la premiere ligne
    {
      dst->y -= s->off.y;
    }
  return (0);
}

int		update_animation(t_gfx_entity *ent, t_spk *spk, t_surface *s)
{
  SDL_Rect	src;
  SDL_Rect	dest;

  if (!ent->alpha)
    return (0);
  if (!s->arena)
    {
      src.w = spk->w;
      src.h = spk->h;
      src.x = ent->col * spk->w;
      src.y = ent->row * spk->h;
      dest.w = src.w;
      dest.h = src.h;
      dest.x = ent->x;// + s->x;
	  dest.y = ent->y;// + s->y;
	  xSDL_BlitSurface(spk->sprite, &src, s->s, &dest);
	}
  else if (ent->x >= s->scale.x * zoom_x(s) &&
	   ent->x < s->scale.x * zoom_x(s) + s->w + s->off.x &&
	   ent->y >= s->scale.y * zoom_y(s) &&
	   ent->y < s->scale.y * zoom_y(s) + s->h + s->off.y)
    {
      get_src(ent, spk, s, &src);
      get_dst(ent, spk, s, &dest, &src);
	  xSDL_BlitSurface(spk->sprite, &src, gfx->buff, &dest);
    }
  else
    return (1);
  return (0);
}

int		update_entities(int id)
{
  int		i;

  for (i = 0; i < MAXENTITY; i++)
    {
      if (gfx->entity[i].id_sprite >= 0)
	{
	  if (gfx->entity[i].id_surf == id)
	    {
	      if (update_animation(&gfx->entity[i],
				   &gfx->spk[gfx->entity[i].id_sprite],
				   &gfx->surface[id]) < 0)
		return (-1);
	    }
	}
    }
  return (0);
}

int		update_squares(int id)
{
  int		i;

  for (i = 0; i < MAXSQUARE; i++)
    {
      if (gfx->square[i].exist == true)
	{
	  if (gfx->square[i].id_surf == id)
	    {
			if (!gfx->surface[id].arena)
				boxColor(gfx->buff, gfx->square[i].x1,
					gfx->square[i].y1, gfx->square[i].x2,
					gfx->square[i].y2, gfx->square[i].color);
			else
			{
				boxColor(gfx->buff, gfx->square[i].x1 -
					gfx->surface[id].scale.x * CASE_SIZE_X -
					gfx->surface[id].off.x,
					gfx->square[i].y1 -
					gfx->surface[id].scale.y * CASE_SIZE_Y -
					gfx->surface[id].off.y,
					gfx->square[i].x2 -
					gfx->surface[id].scale.x * CASE_SIZE_X - 
					gfx->surface[id].off.x,
					gfx->square[i].y2 -
					gfx->surface[id].scale.y * CASE_SIZE_Y - 
					gfx->surface[id].off.y, gfx->square[i].color);	
			}
	    }
	}
    }
  return (0);
}

int		show_surface(int id)
{  
  SDL_Rect	dest;

#ifdef GRAPHICS_TIME
  Uint32 ticks = SDL_GetTicks();
#endif
  if (update_entities(id) < 0)
    return (-1);
  if (update_squares(id) < 0)
	return (-1);
  if (!gfx->surface[id].arena)
  {
	  dest.h = gfx->surface[id].h;
	  dest.w = gfx->surface[id].w;
	  dest.x = gfx->surface[id].x;
	  dest.y = gfx->surface[id].y;
	  xSDL_BlitSurface(gfx->surface[id].s, NULL, gfx->buff, &dest);
  }
#ifdef GRAPHICS_TIME
  fprintf(stderr, "update_entities: %d\n", SDL_GetTicks() - ticks);
#endif
  return (0);
}

int		update_surf(int mini, int maxi)
{
  int		max;
  int		min;
  int		i;
  int		d;
  int		nbsurf;
  static int	*save = 0;
  int		previous;

  if (mini < GFX_MIN_DEPTH || mini > maxi)
    mini = GFX_MIN_DEPTH;
  if (maxi > GFX_MAX_DEPTH || maxi < mini)
    maxi = GFX_MAX_DEPTH;
  max = maxi;
  min = mini;
  previous = maxi;
  if (!save)
    if (!(save = (int*)malloc(sizeof (*save) * (MAXSAMESURFACE))))
      {
	printf("Out of memory\n");
	exit(42);
      }
  nbsurf = 0;
  while (previous != min)
    {
      previous = min;
      for (i = 0; i < MAXSUBSCREEN && nbsurf < MAXSAMESURFACE; i++)
	{
	  if (gfx->surface[i].show)
	    {
	      if (gfx->surface[i].depth < max &&
		  gfx->surface[i].depth > min)
		{
		  max = gfx->surface[i].depth;
		  save[nbsurf] = i;
		}
	      if (gfx->surface[i].depth == min)
		{
		  save[nbsurf] = i;
		  nbsurf++;
		}
	    }
	}
      min = max;
      max = maxi;
    }
  for (d = 0; d < nbsurf; d++)
    if (show_surface(save[d]) < 0)
      return (-1);
  show_debug();
  return (0);
}
