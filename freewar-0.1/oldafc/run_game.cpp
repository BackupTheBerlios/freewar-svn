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
// run_game.cpp for freewar in /u/ept2/skondr_m
// 
// Made by mael skondras
// Login   <skondr_m@epita.fr>
// 
// Started on  Fri Jun  4 15:36:05 2004 mael skondras
// Last update Sun Jul  4 16:22:10 2004 stephane petitcolas
//

#include "freewar.h"

void	free_play(t_game_goodies *nfo)
{
  free(nfo->db_info);
  nfo->db_info = 0;
  free(nfo->events);
  nfo->events = 0;
  free(nfo);
}
void	calc_pos_click(t_game_goodies *nfo,t_coord *actual_pos, 
		   t_coord *actual_off, int i, t_id_req *id_req)
{
  t_coord		click;
  t_game_select_move	dest;
  t_game_info_scale	scale;
  t_coord		tmp1[2];

  if (nfo->events->mousepose[i].button == SDL_BUTTON_RIGHT)
    {
      click.x = (nfo->events->mousepose[i].x - 5);
      click.y = (nfo->events->mousepose[i].y - 349);
      memcpy(&(dest.pos), &click, sizeof(click));
      click.x = 0;
      click.y = 0;
      memcpy(&(dest.off), &click, sizeof(click));
      scale.id_req = id_req->info_scale;
      stock_msg(&cnt->clients[0], TAG_SELECT_MOVE,
		sizeof(dest), (void*)&dest);
    }
  else if (nfo->events->mousepose[i].button == SDL_BUTTON_LEFT)
    {
      actual_pos->x = (nfo->events->mousepose[i].x - 5) - ((640/CASE_SIZE_X) / 2);
      actual_pos->y = (nfo->events->mousepose[i].y - 349) - ((380/CASE_SIZE_Y) / 2);
      if (actual_pos->x < 0)
	actual_pos->x = 0;
      if (actual_pos->y < 0)
	actual_pos->y = 0;
      if (actual_pos->x > (96 - (640/CASE_SIZE_X)))
	actual_pos->x = 96 - (640/CASE_SIZE_X);
      if (actual_pos->y > (96 - (380/CASE_SIZE_Y)))
	actual_pos->y = 96 - (380/CASE_SIZE_Y);
      actual_off->x = 0;
      actual_off->y = 0;
      memcpy(&(tmp1[0]), actual_pos, sizeof(*actual_pos));
      memcpy(&(tmp1[1]), actual_off, sizeof(*actual_off));
      stock_msg(&(cnt->clients[0]), TAG_EDIT_ARENA_SURFACE,
		sizeof(t_coord) * 2, tmp1);
    }
}

void	calc_selection(t_game_goodies *nfo,t_coord *actual_pos, 
		       t_coord *actual_off, int i, t_id_req *id_req, t_info_scale *sel,
		       t_game_info_scale *select, t_game_info_scale *save)
{
  int			d;
  t_coord		click;
  t_game_info_scale	scale;

  nfo->events->mousepose[i].x += (actual_pos->x * CASE_SIZE_X) + actual_off->x;
  nfo->events->mousepose[i].y += (actual_pos->y * CASE_SIZE_Y) + actual_off->y;
  click.x = nfo->events->mousepose[i].x/CASE_SIZE_X;
  click.y = nfo->events->mousepose[i].y/CASE_SIZE_Y;
  memcpy(&(scale.pos), &click, sizeof(click));
  click.x = nfo->events->mousepose[i].x%CASE_SIZE_X;
  click.y = nfo->events->mousepose[i].y%CASE_SIZE_Y;
  memcpy(&(scale.off), &click, sizeof(click));
  scale.id_req = id_req->info_scale;
  stock_msg(&cnt->clients[0], TAG_INFO_SCALE,
	    sizeof(scale), (void*)&scale);
  if (nfo->events->mousepose[i].button == SDL_BUTTON_LEFT && !(nfo->events->mod & KMOD_SHIFT))
    for (d = 0; d <= FW_MAX_SELECT - 1; d++)
      sel[d].id = -1;
  if (nfo->events->mousepose[i].button == SDL_BUTTON_RIGHT)
    {
      for (d = 0; save[d].id_req != -1 && d < MAX_SAVE_EVENTS; d++)
	;
      if (d != 0)
	memcpy(&(save[d - 1]), &scale, sizeof(scale));
      else
	memcpy(&(save[d]), &scale, sizeof(scale));
    }
  if (nfo->events->mod & KMOD_SHIFT && nfo->events->mousepose[i].button == SDL_BUTTON_LEFT)
    {
      
      for (d = 0; select[d].id_req != -1 && d <= FW_MAX_SELECT; d++)
	;
      if (d != 0)
	memcpy(&(select[d - 1]), &scale, sizeof(scale));
      else
	memcpy(&(select[d]), &scale, sizeof(scale));
    }
}

void	exec_event(t_game_goodies *nfo, t_cfg cfg, t_coord *actual_pos, 
		   t_coord *actual_off, t_trame *trame, t_id_req *id_req,
		   t_game_info_scale *save, t_game_info_scale *select, t_info_scale *sel)
{
  t_coord		tmp[2];
  t_coord		tmp1[2];
  t_coord		click;
  t_game_select_move	dest;
  int			i;
  int			d;
  t_game_info_scale	scale;


  memcpy(nfo->events, trame->msg, trame->len);
  if (nfo->events->mousepose[0].button != 0)
    {
      for (i = 0;  nfo->events->mousepose[i].x != -1 && i != MAXMOUSEEVENT; i++)
	if ((nfo->events->mousepose[i].button == SDL_BUTTON_LEFT ||
	    nfo->events->mousepose[i].button == SDL_BUTTON_RIGHT)
	    && nfo->events->mousepose[i].type == 0)
	  {
	    if (nfo->events->mousepose[i].x >= 5 && nfo->events->mousepose[i].x <= 5 + 96 && 
		nfo->events->mousepose[i].y >= 349 && nfo->events->mousepose[i].y <= 349+96)
	      {
		calc_pos_click(nfo, actual_pos, actual_off, i, id_req);
	      }
	    else
	      {
		calc_selection(nfo, actual_pos, actual_off, i, id_req, sel, select, save);
	      }
	    id_req->info_scale++;
	  }
    }
  else if (get_pos(nfo->events->xfin, nfo->events->yfin, 
		   actual_pos, actual_off, cfg))
    {
      memcpy(&(tmp[0]), actual_pos, sizeof(*actual_pos));
      memcpy(&(tmp[1]), actual_off, sizeof(*actual_off));
      stock_msg(&(cnt->clients[0]), TAG_EDIT_ARENA_SURFACE,
		sizeof(t_coord) * 2, tmp);
    }
  else if (nfo->events->key[0] != 0)
    {
      char	*str;
      
      for (i = 0; i < MAXKEYPRESS; i++)
	if ((str = is_action(nfo->events->key[i])))
	  stock_msg(&cnt->clients[0], TAG_EXECUTION,
		    sizeof(str), (void*)str);
    }
  stock_msg(&cnt->clients[0], TAG_EVENT_OK, 0, NULL);
}

void	get_good_entity(t_trame *trame, t_id_req *id_req, t_game_info_scale *save, t_game_info_scale *select,
			t_info_scale *sel, int app)
{
  char			*tmp;
  int			i;
  int			d;
  int			flag_sel;
  int			flag_att;
  t_req_info_scale	scale;
  t_game_select_move	dest;
  char			*attack;
  int			len;
  int           c;

  flag_sel = 0;
  flag_att = 0;
  memcpy(&scale, trame->msg, trame->len);
  tmp = fill_data(sizeof(int), (char*)&id_req->select);
  len = sizeof(int);
  attack = fill_data(sizeof(int), (char*)&id_req->attac);
  for (i = 0; i < (int)scale.nb_ent; i++)
    {
      for (c = 0; c <= FW_MAX_SELECT - 1 && sel[c].id != -1; c++)
	;
      for (d = 0; d <= FW_MAX_SELECT - 1; d++)
	if (select[d].id_req == scale.id_req)
	  {
	    memcpy(&(sel[c]), &scale.ent[i], sizeof(scale.ent[i]));
	    select[d].id_req = -1;
	    c++;
	    flag_sel = 1;
	    break;
	  }
      for (d = 0; d < MAX_SAVE_EVENTS; d++)
	if (save[d].id_req == scale.id_req)
	  {
	    attack = add_to_data(sizeof(int), (char*)attack,
				 sizeof(scale.ent[i].id), (char*)&scale.ent[i].id);
	    flag_att = 1;
	    break;
	  }
      if (d == MAX_SAVE_EVENTS && flag_sel != 1)
	{
	  memcpy(&(sel[c]), &scale.ent[i], sizeof(scale.ent[i]));
	  flag_sel = 1;
	}
    }
  if (flag_sel == 1)
    {
      for (c = 0; c <= FW_MAX_SELECT - 1 && sel[c].id != -1; c++)
	{
	  ;
	  tmp = add_to_data(len, (char*)tmp,
			    sizeof(sel[c].id), (char*)&sel[c].id);
	  len += sizeof(sel[c].id);
	}
      stock_msg(&cnt->clients[0], TAG_SELECT, len
		, (void*)tmp);
      id_req->select++;
    }
  else if (flag_att == 1 && scale.ent[i - 1].app != app)
    {
      fprintf(stderr, "spy === %i\n", scale.ent[i].app);
      stock_msg(&cnt->clients[0], TAG_SELECT_ATTACK, sizeof(int) + sizeof(scale.ent[i].id)
		, (void*)attack);
      id_req->attac++;
    }
  if (i == 0)
    for (d = 0; d < MAX_SAVE_EVENTS; d++)
      if (save[d].id_req == scale.id_req)
	{
	  memcpy(&(dest), &save[d], sizeof(save[d]));
	  stock_msg(&cnt->clients[0], TAG_SELECT_MOVE, sizeof(dest)
		    , (void*)&dest);
	}
  free(tmp);
  free(attack);
}

void	init(t_id_req *id_req, t_game_info_scale *save, t_game_info_scale *select, t_info_scale *sel)
{
  int	i;
  
  id_req->select = 0;
  id_req->info_scale = 0;
  id_req->attac = 0;
  for (i = 0; i < MAX_SAVE_EVENTS; i++)
      save[i].id_req = -1;
  for (i = 0; i <= FW_MAX_SELECT - 1; i++)
  {
      select[i].id_req = -1;
	  sel[i].id = -1;
  }
}

int	run_game(t_game_goodies *nfo)
{
  bool			draw = 1;
  Uint32		ticks;
  t_trame		trame;
  t_coord		actual_pos;
  t_coord		actual_off;
  t_cfg			cfg;
  int			ret;
  t_id_req		id_req;
  t_game_info_scale	*save;
  t_game_info_scale *select;
  t_info_scale  *sel;
  char			app;

  app = 0;
  actual_pos.x = 0;
  actual_pos.y = 1;
  actual_off.x = 20;
  actual_off.y = 20;
  cfg.Screen[0] = 640;
  cfg.Screen[1] = 480;
  fprintf(fd_log, "%s: Loading game...\n", NAME);
  ticks = SDL_GetTicks();
  fflush(fd_log);
  save = (t_game_info_scale*)xmalloc(sizeof(*save) * MAX_SAVE_EVENTS);
  select = (t_game_info_scale*)xmalloc(sizeof(*save) * (FW_MAX_SELECT + 1));
  sel = (t_info_scale*)xmalloc(sizeof(*sel) * (FW_MAX_SELECT + 1));
  init(&id_req, save, select, sel);
  if (wait_engine(&app))
   return (1);
  while (42)
    {
      //if ((ret = check_select(1000000)))
	//while (exec_msg(&(cnt->clients[0]), &trame))
	//  {
	//    fprintf(fd_log, "got trame %d\n", trame.tag);	 
	//	fflush(fd_log);
	//    if (is_valid_trame(&trame, TAG_EVENTS))
	//	exec_event(nfo, cfg, &actual_pos, &actual_off, 
	//	  &trame, &id_req, save, select, sel);
	//    else if (is_valid_trame(&trame, TAG_INFO_SCALE_REPLY))
	//      get_good_entity(&trame, &id_req, save, select, sel, app);
	//	if (trame.msg)
	//	  free(trame.msg);
	//  }
 //     if (!cnt->clients[0].sock)
	//break;
    }
  fprintf(fd_log, "Déconnecté du moteur\n");
  fflush(fd_log);
  free_play(nfo);
  return (0);
}
