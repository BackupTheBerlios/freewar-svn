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
// req_info_scale.cpp for freewar in /root/Freewar/src
// 
// Made by 
// Login   <root@epita.fr>
// 
// Started on  Wed Jun 30 16:30:21 2004 
// Last update Wed Jul 14 18:34:06 2004 
//

#include "freewar.h"

extern t_gfx	*gfx;

int		is_on_click(t_entity *t, t_game_info_scale *game)
{
  int		clickx;
  int		clicky;
  int		entx;
  int		enty;
  int		entw;
  int		enth;

  clickx = game->pos.x * CASE_SIZE_X + game->off.x;
  clicky = game->pos.y * CASE_SIZE_Y + game->off.y;
  entx = t->pos.x * CASE_SIZE_X + t->off.x;
  enty = t->pos.y * CASE_SIZE_Y + t->off.y;
  entw = gfx->spk[gfx->entity[t->idgfx].id_sprite].w;
  enth = gfx->spk[gfx->entity[t->idgfx].id_sprite].h;
  if (clickx >= entx &&
      clickx < entx + entw &&
      clicky >= enty &&
      clicky < enty + enth)
    return (1);
  return (0);
}

int			search_entity_on_click(t_engine *e, t_game_info_scale *game, int *len,
					      char **data, t_coord *pos)
{
  int			t;
  int			cpt_ent;
  t_info_scale		info;
  
  for (t = 0, cpt_ent = 0; t < MAX_ENTITY_ON_SCALE && e->scales[pos->y][pos->x].tab[t]; t++)
    {
      if (is_on_click(e->scales[pos->y][pos->x].tab[t], game))
	{
	  info.action = e->scales[pos->y][pos->x].tab[t]->action;
	  info.app = e->scales[pos->y][pos->x].tab[t]->app;
	  info.id = e->scales[pos->y][pos->x].tab[t]->id;
	  strncpy((char*)info.name, e->scales[pos->y][pos->x].tab[t]->data->name, NAME_SIZE);
	  //printf("name [%s]\n", info.name);fflush(stdout);
	  if (!data)
	    data[0] = fill_data(sizeof(info), (char*)&info);
	  else
	    data[0] = add_to_data(len[0], (char*)data[0], sizeof(info), (char*)&info);
	  len[0] += sizeof(info);
	  cpt_ent++;
	}
    }
  return (cpt_ent);
}

int			req_info_scale(t_engine *e, t_trame *trame, int src)
{
  t_game_info_scale	game;
  t_req_info_scale	req;
  t_coord		pos;
  int			len;
  char			*data;
  int			t;

  data = 0;
  if (trame->len != sizeof(game))
    {
      fprintf(stderr, "ERROR: req_info_scale: failed\n");
      return (1);
    }
  memcpy(&game, trame->msg, sizeof(game));
  req.id_req = game.id_req;
  if (game.pos.x < 0 || game.pos.x >= e->map_data.w ||
      game.pos.y < 0 || game.pos.y >= e->map_data.h)
    {
      fprintf(stderr, "ERROR: req_info_scale: failed\n");
      req.nb_ent = -1;
      stock_msg(&(cnt->clients[e->assos_clients[src]]),
		TAG_INFO_SCALE_REPLY, sizeof(int) + sizeof(char), &req);
      return (1);
    }
  len = 0;
  t = 0;
  pos = game.pos;
  // v regarde la case du click
  t += search_entity_on_click(e, &game, &len, &data, &pos);
  if (pos.x > 1) // regarde la case a gauche
    {
      pos.x--;
      t += search_entity_on_click(e, &game, &len, &data, &pos);
      pos.x++;
    }
  if (pos.y > 1) // regarde la case au dessus
    {
      pos.y--;
      t += search_entity_on_click(e, &game, &len, &data, &pos);
      pos.y++;
    }
  if (pos.x > 1 && pos.y > 1) // regarde la case en haut a gauche
    {
      pos.x--;
      pos.y--;
      t += search_entity_on_click(e, &game, &len, &data, &pos);
      pos.x++;
      pos.y++;
    }

  if (data)
    memcpy(&(req.ent), data, len);
  req.nb_ent = t;
  fprintf(stderr, "nombre d'entitees retournees:\t\t[%d]\n", t);fflush(stderr);
  stock_msg(&(cnt->clients[e->assos_clients[src]]), TAG_INFO_SCALE_REPLY,
	    sizeof(int) + sizeof(char) + len, &req);
 
  // printf("len [%d] t[%d] t*sizeof(t_info_scale) [%d]\n", len, t, sizeof(t_info_scale) * t);
//   printf("len totale: [%d]\n", sizeof(int) + sizeof(char) + len);
  return (0);
}
