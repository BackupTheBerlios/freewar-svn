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
// aff_game.cpp for freewar in /u/ept2/huot_j/Freewar/src
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Fri May 28 12:28:45 2004 jonathan huot
// Last update Sat Jul  3 16:12:07 2004 
//

#include "freewar.h"

extern t_gfx	*gfx;

int		aff_square_minimap(t_engine *e)
{
  static int	startx = 5;
  static int	starty = 349;
  static int	sizex = 96;
  static int	sizey = 96;
  static int	sizemaxx = 124;
  static int	sizemaxy = 126;
  int		i;
  int		n;
  int		t;
  int		s;
  int		got_select;

  boxColor(gfx->buff, startx, starty,
	   sizemaxx + startx, sizemaxy + starty, 0xCCCCCCFF);
  boxColor(gfx->buff, startx, starty,
	   startx + sizex, starty + sizey, 0x000000FF);
  for (i = 0; i < e->map_data.h; i++)
    {
      for (n = 0; n < e->map_data.w; n++)
	{
	  got_select = 0;
	  for (s = 0; s < FW_MAX_SELECT && e->select[s][0]; s++)
	    {
	      for (t = 0; e->scales[i][n].tab[t]
		     && t < MAX_ENTITY_ON_SCALE; t++)
		if (e->select[s][0] == e->scales[i][n].tab[t])
		  {
		    boxColor(gfx->buff, startx + n, starty + i,
			     startx + n + 1, starty + i + 1, 0x00FF00FF);
		    got_select = 1;
		    break;
		  }
	      if (got_select)
		break;
	    }
	  if (!got_select && e->scales[i][n].tab[0])
	    {
	      boxColor(gfx->buff, startx + n, starty + i,
		       startx + n + 1, starty + i + 1, 0xFFFFFFFF);
	    }
	}
    }
  rectangleColor(gfx->buff, startx + e->g.pos_arena.x,
		 starty + e->g.pos_arena.y,
		 startx + e->g.pos_arena.x + e->g.w_main,
		 starty + e->g.pos_arena.y + e->g.h_main, 0xFFFF00FF);
  return (0);
}

int			aff_life(t_engine *e, t_entity *t,
				 int id_sfx, t_coord *real)
{
  t_coord		c1;
  t_coord		c2;
  t_spk			*spk;
  int			state;

  if (t->action == ACTION_NONE ||
	  t->action == ACTION_WAIT)
    spk = &gfx->spk[t->data->idsprite];
  else
    spk = &gfx->spk[t->data->actions.idsprite[t->action]];
  c1.x = real->x;
  c1.y = real->y;
  c2.x = real->x + (spk->w * t->meter[0].value /
		t->data->meters[0].value);
  c2.y = real->y + 3;
  state = (t->meter[0].value * 3) / t->data->meters[0].value;
  if (state > 2)
    edit_square_on_surface(id_sfx,
			   e->g.arena_sfx, &c1, &c2, 0x00FF00FF);
  else if (state > 1)
    edit_square_on_surface(id_sfx,
			   e->g.arena_sfx, &c1, &c2, 0xFFFF00FF);
  else
    edit_square_on_surface(id_sfx,
			   e->g.arena_sfx, &c1, &c2, 0xFF0000FF);
  return (0);
}

int			edit_img_selection(t_engine *e, int sprite, t_entity *t)
{
 // double	x;
 // double	y;

 // x = (double)gfx->spk[gfx->entity[t->idgfx].id_sprite].w / (double)gfx->spk[sprite].w;
 // y = (double)gfx->spk[gfx->entity[t->idgfx].id_sprite].h / (double)gfx->spk[sprite].h;
 // if (x < 1.0000 || x > 1.0000)
 // {
	//gfx->spk[sprite].sprite = zoomSurface(gfx->spk[sprite].sprite, x, y, 0);
	//gfx->spk[sprite].w = gfx->spk[sprite].sprite->w;
	//gfx->spk[sprite].h = gfx->spk[sprite].sprite->h;
 // }
  return (0);
}

int		aff_game(t_engine *e, t_game *g)
{
  int		i;
  int		n;
  int		t;
  int		s;
  int		max_h;
  int		max_w;
  static int	x = 0;
  t_coord	real;

#ifdef GRAPHICS_TIME
  timer_count("GFX: ma boucle en bois (aff_game)", true);
#endif
  edit_arena(e->g.arena_lands, &e->g.pos_arena, &e->g.off_arena, 100);
  for (i = 0; i < e->db.nb_layers; i++)
    edit_arena(e->g.arena_units[i], &e->g.pos_arena, &e->g.off_arena, 100);
  edit_arena(e->g.arena_select, &e->g.pos_arena, &e->g.off_arena, 100);
  edit_arena(e->g.arena_sfx, &e->g.pos_arena, &e->g.off_arena, 100);
  max_h = g->h_main + g->pos_arena.y;
  max_w = g->w_main + g->pos_arena.x;
  s = 0;
  i = g->pos_arena.y;
  for (t = 0; t < 2, i > 0; t++)
    i--;
  for (; i < max_h + 2 && i < e->map_data.h; i++)
    {
      n = g->pos_arena.x;
      for (t = 0; t < 2, n > 0; t++)
	n--;
      for (; n < max_w + 2 && n < e->map_data.w; n++)
	{
	  edit_entity_on_surface
	    (e->scales[i][n].idgfxentity, g->arena_lands,
	     n * CASE_SIZE_X, i * CASE_SIZE_Y, 255);
	  for (t = 0; e->scales[i][n].tab[t] && t < MAX_ENTITY_ON_SCALE; t++)
	    {
	      real.x = n * CASE_SIZE_X + e->scales[i][n].coord[t].x;
	      real.y = i * CASE_SIZE_Y + e->scales[i][n].coord[t].y;
	      for (s = 0; s < FW_MAX_SELECT && e->select[s][0]; s++)
		{
		  if (e->select[s][0] == e->scales[i][n].tab[t])
		    {
		      gfx->entity[e->select_gfx[s]].id_sprite = (e->scales[i][n].tab[t]->app < 0) ?
			(e->select_img_neutral) : ((e->scales[i][n].tab[t]->app == e->id_player) ?
						   (e->select_img) : (e->select_img_ennemy));
		      edit_img_selection(e, gfx->entity[e->select_gfx[s]].id_sprite,
					 e->select[s][0]);
		      edit_entity_on_surface(e->select_gfx[s],
					     e->g.arena_select, real.x, real.y, 255);
		      aff_life(e, e->scales[i][n].tab[t], e->select_sfx[s], &real);
		      break;
		    }
		}
	      edit_entity_on_surface
		(e->scales[i][n].tab[t]->idgfx,
		 g->arena_units[(*(e->scales[i][n].tab[t]->data->layer))->depth],
		 real.x, real.y, 255);
	      get_action_anim(e->scales[i][n].tab[t]);
	    }
	}
    }
#ifdef GRAPHICS_TIME
  timer_count("..", false);
  timer_count("update_surf", true);
#endif
   update_surf(GFX_MIN_DEPTH, GFX_MAX_DEPTH);
#ifdef GRAPHICS_TIME
   timer_count("update_surf", false);
#endif
#ifdef GRAPHICS_TIME
   timer_count("aff_squae&minimap", true);
#endif
   aff_square_minimap(e);
#ifdef GRAPHICS_TIME
   timer_count("aff_square&minimap", false);
#endif
#ifdef GRAPHICS_TIME
   timer_count("aff_screen", true);
#endif
   aff_screen();
#ifdef GRAPHICS_TIME
   timer_count("aff_screen", false);
#endif
  return (0);
}
