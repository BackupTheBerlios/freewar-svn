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
#include "freewar.h"

extern t_gfx	*gfx;
int				init_selection(t_engine *e)
{
  int				i;
  int				n;

  		    //  gfx->spk[gfx->entity[e->select_gfx[s]].id_sprite].sprite = zoomSurface(gfx->spk[e->select_img].sprite,
								//			     2.0, 2.0, 1);
		      //gfx->spk[gfx->entity[e->select_gfx[s]].id_sprite].w = gfx->spk[e->select_img].sprite->w;
		      //gfx->spk[gfx->entity[e->select_gfx[s]].id_sprite].h = gfx->spk[e->select_img].sprite->h;

  e->select_img = create_sprite("select.png");
  e->select_img_neutral = create_sprite("select_neutral.png");
  e->select_img_ennemy = create_sprite("select_ennemy.png");
  for (i = 0; i < FW_MAX_SELECT; i++)
    {
      e->select[i] = (t_entity**)xmalloc(sizeof(t_entity**) * e->nb_players);
      for (n = 0; n < e->nb_players; n++)
	e->select[i][n] = 0;
      e->select_gfx[i] = create_gfx_entity(e->select_img);
      e->select_sfx[i] = create_square_entity();
      edit_entity_on_surface(e->select_gfx[i], e->gfx_null, 0, 0, 0);
      edit_square_on_surface(e->select_sfx[i], e->gfx_null, 0, 0, 0);
    }
  return (0);
}

int				del_empty_selection(t_engine *e, t_entity *t)
{
  int				s;
  int				p;
  int				o;

  p = 0;
  for (p = 0; p < e->nb_players; p++)
    for (s = 0; s < FW_MAX_SELECT && e->select[s][p]; s++)
      {
	if (e->select[s][p] == t)
	  {
	    for (o = s; o < FW_MAX_SELECT && e->select[o][p]; o++)
	      ;
	    e->select[s][p] = e->select[o - 1][p];
	    e->select[o - 1][p] = 0;
	    if (!p)
	      edit_entity_on_surface(e->select_gfx[s], e->gfx_null, 0, 0, 0);
	    edit_square_on_surface(e->select_sfx[s], e->gfx_null, 0, 0, 0);
	    return (1);
	  }
      }
  return (0);
}

int				manage_selection(t_engine *e, t_trame *t,
						 int player)
{
  int				nb_select;
  int				i;
  int				i_msg;
  unsigned long			entity;
  int				id_trame;

  nb_select = (t->len - sizeof (int)) / sizeof(unsigned long);
  if (!player && !e->server)
    stock_msg(&(cnt->clients[1]), t->tag, t->len, t->msg);
  if (nb_select > FW_MAX_SELECT)
    nb_select = FW_MAX_SELECT;
  i = 0;
  i_msg = 0;
  memcpy(&id_trame, t->msg, sizeof(id_trame));
  printf("selection: %d (%dpl)\n", nb_select, player);
  while (nb_select--)
    {
      memcpy(&entity, t->msg + (sizeof(unsigned long) * i_msg)
	     + sizeof(id_trame), sizeof(unsigned long));
      if ((e->select[i][player] = find_entity(e, entity)))
	i++;
      i_msg++;
    }
  while (i < FW_MAX_SELECT)
    {
      if (!player)
	{
	  edit_entity_on_surface(e->select_gfx[i], e->gfx_null, 0, 0, 0);
	  edit_square_on_surface(e->select_sfx[i], e->gfx_null, 0, 0, 0);
	}
      e->select[i][player] = 0;
      i++;
    }
  stock_msg(&cnt->clients[e->assos_clients[player]],
	    TAG_SELECT, sizeof(id_trame), &id_trame);
  return (0);
}
