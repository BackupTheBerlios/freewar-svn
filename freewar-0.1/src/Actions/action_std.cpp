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
// action_std.cpp for freewar in /u/ept2/ribas_j/Freewar/src/Graphics
// 
// Made by jonathan ribas
// Login   <ribas_j@epita.fr>
// 
// Started on  Mon Jun 14 17:09:02 2004 jonathan ribas
// Last update Sun Jul 18 18:50:06 2004 
//

#include "freewar.h"

int		get_length_of_path(t_coord *p)
{
  int		i;
  
  for (i = 0; p[i].x != -1; i++)
    ;
  return (i);
}

int		moove_is_valide(t_engine *e, t_entity *t, t_coord g)
{
  
  return (1);
}


int		get_place_of_action(t_engine *e, unsigned long id)
{
  int		i;
  t_do_action	*a;
  
  a = e->actions;;
  for (i = 0; a; i++)
    {
      if (a->id == id)
	return (i);
      a = a->next;
    }
  return (-1);
}

int		get_move_in_scale(t_entity *t, t_coord *pos, t_coord *off)
{
  int		res;
  int		a;
  int		b;

//   printf("depart:[%d][%d]\tcase d'apres-> [%d][%d]\n", t->pos.x, t->pos.y, pos->x, pos->y);
  a = abs((t->pos.x * CASE_SIZE_X + t->off.x) - (pos->x * CASE_SIZE_X + off->x));
  b = abs((t->pos.y * CASE_SIZE_Y + t->off.y) - (pos->y * CASE_SIZE_Y + off->y));
  if (a > CASE_SIZE_X)
    a = a % CASE_SIZE_X;
  if (b > CASE_SIZE_Y)
    b = b % CASE_SIZE_Y;
  printf("A:%d (%d-%d)\tB:%d (%d-%d)\n",
	 a, (t->pos.x * CASE_SIZE_X + t->off.x), (pos->x * CASE_SIZE_X + off->x), 
	 b, (t->pos.y * CASE_SIZE_Y + t->off.y), (pos->y * CASE_SIZE_Y + off->y));
  res = (int)(double)sqrt((double)((a * a) + (b * b)));
  printf("res -> %d\n", res);
  return (res);
}


int		get_damages(t_engine *e, t_entity *t, char *w_name)
{
  int		w;

  for (w = 0; t->data->weapon[w]->name; w++)
    {
      if (!strcmp(t->data->weapon[w]->name, w_name))
	return (t->data->weapon[w]->dmg);
    }
  fprintf(stderr, "ERROR: get_rof: failed\n");
  return (-1);
}

int		get_rof(t_engine *e, t_entity *t, char *w_name)
{
  int		w;

  for (w = 0; t->data->weapon[w]->name; w++)
    {
      if (!strcmp(t->data->weapon[w]->name, w_name))
	return (t->data->weapon[w]->rof);
    }
  fprintf(stderr, "ERROR: get_rof: failed\n");
  return (-1);
}

int		get_range(t_engine *e, t_entity *t, char *w_name)
{
  int		w;

  for (w = 0; t->data->weapon[w]->name; w++)
    {
      if (!strcmp(t->data->weapon[w]->name, w_name))
	return (t->data->weapon[w]->range);
    }
  fprintf(stderr, "ERROR: get_rof: failed\n");
  return (-1);
}

char		*get_weapon(t_engine *e, t_entity *t, t_entity *attaked)
  // integrer plus tard la verification que l'arme soit compatible a la
  // cible ..
{
  int		w;
  int		damage_max;
  int		best_w;
  
  damage_max = -1;
  best_w = -1;
  for (w = 0; t->data->weapon[w]; w++)
    {
      if (t->data->weapon[w]->dmg > damage_max)
	{
	  damage_max = t->data->weapon[w]->dmg;
	  best_w = w;
	}
    }
  if (best_w < 0)
    return (0);
  else
    return (t->data->weapon[best_w]->name);
}

int		reset_actions(t_engine *e, t_entity *t)
{
  t_do_action	*a;
  t_do_action	*next;
  
  del_next_actions(e, t);
  a = e->actions;
  while (a)
    {
      next = a->next;
      if (a->entity == t)
	if (del_action(e, a->id))
	  fprintf(fd_log, "ERROR: del_entity_on_all_actions: del_action failed\n");
      a = next;
    }
  t->action = ACTION_NONE;
  fw_send_action(e, t);
  return (0);
}

int		range_is_valide(t_engine *e, t_entity *t, t_entity *attaked, int range)
{
  int		w;
  int		h;
  int		dist;

  printf("tachatte\n");fflush(stdout);
  w = abs(t->pos.x - attaked->pos.x);
  h = abs(t->pos.y - attaked->pos.y);
  printf("range_is_valide : w[%d] h[%d] res[%d]\n",
	 w, h, (int)(double)sqrt((double)(w * w + h * h)));fflush(stdout);
  if ((int)(double)sqrt((double)(w * w + h * h)) > range)
    return (0);
  return (1);
}

int		get_increment_size(t_do_action *a)
{
//   if (a->speed <= 0)
//     a->speed = 20;
  printf("$$$$$$$$$$$$$$$$$$$$ speed:%d\n", a->speed);fflush(stdout);
  return ((int)((int)((double)
		      sqrt((double)((CASE_SIZE_X * CASE_SIZE_X) + (CASE_SIZE_Y * CASE_SIZE_Y))
			   / a->speed)) + 1));
}
