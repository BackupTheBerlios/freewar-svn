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
// actions.cpp for freewar in /u/ept2/ribas_j/Freewar/src
// 
// Made by jonathan ribas
// Login   <ribas_j@epita.fr>
// 
// Started on  Wed Jun  2 11:30:12 2004 jonathan ribas
// Last update Wed Jul 14 17:51:08 2004 
//

#include "freewar.h"

/*
  -il va falloir boucler les attaque, et decrementer la vie de l'attaquee
  (essayer de voir ou se passe l'incrementation des meters de l'attaquant,
  ex : un peon qui ramasse du bois ..)
  - boucler sur les actions de deplacement, et updater la pace des entitees
  - boucler sur la construction, et une foi le temps fini, faire un
  put_entitee la ou il fait (l'endroit le plus proche du createur, vide)
*/

int		make_dammage(t_engine *e, t_entity *t, int damages)
{
  int		i;
  
  for (i = 0; t->meter[i].meter->name; i++)
    {
      if (!strcmp(t->meter[i].meter->name, METER_LIFE))
	{
	  printf("l'entitee avec %d de vie se prends un coup de %d damage et n'as plus que %d de vie\n", 
		 t->meter[i].value, damages, t->meter[i].value - damages);
	  fflush(stdout);
	  t->meter[i].value -= damages;
	  fw_send_ent_meter(e, t, METER_LIFE, t->meter[i].value);
	  if (t->meter[i].value <= 0)
	    return (DIE);
	  return (0);
	}
    }
  return (1);
}

int		get_pos_for_construct(t_engine *e, t_entity *t, t_coord *pos)
{
  static int	x = 5;
  
  if (x >= e->map_data.w)
    x = 0;
  pos->x = x++;
  pos->y = 6;
	return (0);
}

int		replace_entity(t_engine *e, t_do_action *a)
{
//   int		last_mini_scale;

  if (is_collision(e, a->entity, &(a->path[a->cpt_path])))
    {
      a->entity->action_fail++;
      pop_action(e, a->entity, a);
      return (1);
    }
  printf("-----------------------\n");fflush(stdout);
//   last_mini_scale = a->mini_scale_before_next;
  a->mini_scale_before_next -= a->mini_increment_size;
  if (a->mini_scale_before_next <= 0)
    {
      t_coord	off_tmp;

      off_tmp.x = off_tmp.y = 0;
      a->entity->off = off_tmp;
      fw_send_del_ent_in_map(e, a->entity);
      del_entity_in_map(e, a->entity);
      place_entity_in_map(e, a->entity, &(a->path[a->cpt_path]));
      move_off_in_map(e, a->entity, off_tmp);
      
      a->cpt_path++;
      a->entity->direction = get_direction(a->entity->direction, &(a->entity->pos), &(a->path[a->cpt_path]));
      fw_send_dir(e, a->entity);
      a->dir.x = a->dir.y = 1;
      a->w = abs((a->entity->pos.x * CASE_SIZE_X + a->entity->off.x) - (a->path[a->cpt_path].x * CASE_SIZE_X));
      a->h = abs((a->entity->pos.y * CASE_SIZE_Y + a->entity->off.y) - (a->path[a->cpt_path].y * CASE_SIZE_Y));
      if (a->cpt_path < a->length_of_path)
	a->mini_scale_before_next = get_move_in_scale(a->entity, &(a->path[a->cpt_path]), &off_tmp);
      else
	a->mini_scale_before_next = 0;
      a->move_on_scale_len = a->mini_scale_before_next;
      a->speed = get_best_speed(e, a->entity);
      printf("mini_increment_size %d\n", a->mini_increment_size);fflush(stdout);
      a->mini_increment_size = get_increment_size(a);
      a->first_off = 0;
    }
  else
    {
      // je l'avance juste l'off
      t_coord	off;
      t_coord	pos;
      
      pos = a->entity->pos;
      if (a->entity->direction <= 2 ||  a->entity->direction == 14)
	a->dir.y = -1;
      if (a->entity->direction > 8)
	a->dir.x = -1;
      off.x = (((a->move_on_scale_len - a->mini_scale_before_next) * a->w) / a->move_on_scale_len) * a->dir.x;
      off.y = (((a->move_on_scale_len - a->mini_scale_before_next) * a->h) / a->move_on_scale_len) * a->dir.y;
      if (a->w && a->entity->off.x == abs(off.x))
	off.x += a->dir.x; 
      if (a->h && a->entity->off.y == abs(off.y))
	off.y += a->dir.y;
      if (!a->first_off)
	{
	  a->first_off = 1;
	  if (off.x < 0 && off.y < 0)
	    {
	      printf("\t\tje vais a gauche et en hauuuuuuuuuuuuut\n");
	      pos.x--;
	      pos.y--;
	      fw_send_del_ent_in_map(e, a->entity);
	      del_entity_in_map(e, a->entity);
	      place_entity_in_map(e, a->entity, &pos);
	    }
	  else if (off.x < 0)
	    {
	      printf("\t\tje v a gacuuuuheeeeeeeeeee\n");
	      pos.x--;
	      fw_send_del_ent_in_map(e, a->entity);
	      del_entity_in_map(e, a->entity);
	      place_entity_in_map(e, a->entity, &pos);
	    }
	  else if (off.y < 0)
	    {
	      printf("\t\tje monteeeeeeeeeeeeee\n");
	      pos.y--;
	      fw_send_del_ent_in_map(e, a->entity);
	      del_entity_in_map(e, a->entity);
	      place_entity_in_map(e, a->entity, &pos);
	    } 
	}
      //   off.x = (((a->move_on_scale_len - a->mini_scale_before_next) * a->w) / a->move_on_scale_len);// * a->dir.x;
     if (a->dir.y == -1)
	{
	  //printf("je puuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu\n");
	  off.y = CASE_SIZE_Y - abs(off.y);
	}
     if (a->dir.x == -1)
	{
	  //printf("je puuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu\n");
	  off.x = CASE_SIZE_X - abs(off.x);
	}
      
      //      off.y = (((a->move_on_scale_len - a->mini_scale_before_next) * a->h) / a->move_on_scale_len);// * a->dir.y;
    
      a->entity->off = off;
      move_off_in_map(e, a->entity, off);
      printf("nouvelle position : offx[%d] offy[%d]\n", off.x, off.y);
     }
  return (0);
}
