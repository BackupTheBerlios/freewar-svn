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
// create_action.cpp for freewar in /u/ept2/ribas_j/Freewar/src/Graphics
// 
// Made by jonathan ribas
// Login   <ribas_j@epita.fr>
// 
// Started on  Mon Jun 14 17:07:57 2004 jonathan ribas
// Last update Sun Jul 18 19:24:45 2004 
//

#include "freewar.h"



/*
facteur dont on aura besoin pour calculer les damages
base_entity ->  armureS
		armeS
		typeS -> factors

MAIS ! dans un premier temps,on va faire simple:
attaque - defence = damage.
on va ossi se limiter a UNE arme par entitee, et UNE armure par entitee,
si yen a plusieurs, c'est la premiere qui sera prise en compet pour les degats
*/

int		finish_move(t_engine *e, t_entity *t)
{
  t_do_action	*a;
    
  a = e->actions;
  while (a)
    {
      if (a->entity == t)
	{
	  a->length_of_path = a->cpt_path + 2;
	  printf("\t\tTA CHAAATTTEEEEEEEEEEEEEEEEEEEEE\n");fflush(stdout);
	  return (0);
	}
      a = a->next;
    }
  return (1);
}

/* ATTAQUE */
int		create_action(t_engine *e, t_entity *t, t_entity *attaked)
{
  int		id;
  s_do_action	*a;
  char		*w;
//   int		pop;
  
//   pop = 0;
//   if (t->action == ACTION_MOVE)
//     {
//       // raccourci le chemin
//       finish_move(e, t);
//       pop = 1;
//       // rajoute l'action dans la queue
//     }
//   else
    if (t->action != ACTION_NONE)
    reset_actions(e, t);
  if (!attack_is_valid(e, t, attaked))
    return (-1);
  w = get_weapon(e, t, attaked);
  if (!w)
    return (-1);
  printf("ATTACKKKKKEE :p\n");fflush(stdout);
 //  if (!pop)
//     {
      t->action = ACTION_ATTACK;
      fw_send_action(e, t);
//     }
  id = e->id_action++;
  a = (s_do_action*)xmalloc(sizeof(*a));
  a->id = id;
  a->tag = ACTION_ATTACK;
  a->entity = t;
  a->entity->action_fail = 0;
  t->direction = get_direction(t->direction, &(t->pos), &(attaked->pos));
  fw_send_dir(e, a->entity);
  a->attaked = attaked;
  a->cpt_time = 0;
  a->range = get_range(e, t, w);
  a->damages = get_damages(e, t, w); // <-- a revoir plus tard
  a->time_take = get_rof(e, t, w); // <-- a revoir plus tard
//   if (pop)
//     {
//       pop_action(e, t, a);
//       printf("\t\t\t\t\t\tje pop :)\n");fflush(stdout);
//     }
//   else
//     {
      a->next = e->actions;
      e->actions = a;
//     }
  fflush(stderr);
  return (id);
}

/* DEPLACEMENT */
int		create_action(t_engine *e, t_entity *t, t_coord goal)
{
  int		id;
  s_do_action	*a;
  t_coord	off_tmp; // << a changer !!!
  t_coord	*path;
//   int		pop;
  
//   pop = 0;
//   if (t->action == ACTION_MOVE)
//     {
//       // raccourci le chemin
//       finish_move(e, t);
//       pop = 1;
//       // rajoute l'action dans la queue
//     }
//   else
    if (t->action != ACTION_NONE)
    {
      //   cat_action(e, t);
      //put_next_action();
      reset_actions(e, t);
    }
  printf("=================================\n");
  off_tmp.x = off_tmp.y = 0;
 if (!moove_is_valide(e, t, goal)) // <-- a revoir plus tard
    return (-1);
  path = get_path(e, t, goal);
  if (!path)
   return (-1);
 //  if (!pop)
//     {
      t->action = ACTION_MOVE;
      fw_send_action(e, t);
//     }
  printf("jenvoi l'unitee %d-%d a %d-%d\n",
	 t->pos.x, t->pos.y, goal.x, goal.y);fflush(stdout);
  id = e->id_action++;
  a = (s_do_action*)xmalloc(sizeof(*a));
  a->id = id;
  a->tag = ACTION_MOVE;
  a->entity = t;
  a->entity->action_fail = 0;
  a->path = path;
  a->cpt_time = 0;
  a->time_take = 1; // le nb de cycle avant de se deplacer.
  printf("avant\n");fflush(stdout);
  a->speed = get_best_speed(e, t);
  printf("apres\n");fflush(stdout);

  a->end_off.x = 0;        /// <<< a modifier plus tard !!!
  a->end_off.y = 0;        /// <<<
  a->end_of_path = goal;

  t->direction = get_direction(t->direction, &(t->pos), a->path);
//   if (!pop)
    fw_send_dir(e, a->entity);
  a->w = abs((a->entity->pos.x * CASE_SIZE_X + a->entity->off.x) - (a->path[0].x * CASE_SIZE_X));
  a->h = abs((a->entity->pos.y * CASE_SIZE_Y + a->entity->off.y) - (a->path[0].y * CASE_SIZE_Y));
    fprintf(fd_log, "start: a->w %d a->h %d\n", a->w, a->h);
    fprintf(fd_log, "start: a->path[0].x %d a->path[0].y %d\n", a->path[0].x, a->path[0].y);
  a->dir.x = a->dir.y = 1;
  a->length_of_path = get_length_of_path(a->path);
  fprintf(fd_log, "len of path: %d start[%d][%d]\n",
	 a->length_of_path, a->path[1].x, a->path[1].y);fflush(stdout);
  if (a->length_of_path > 1)
    a->mini_scale_before_next = get_move_in_scale(t, &(a->path[0]), &off_tmp);
  else
    a->mini_scale_before_next = 0;
  a->move_on_scale_len = a->mini_scale_before_next;
  a->mini_increment_size = get_increment_size(a);
  printf("########## mini_increment_size %d\n", a->mini_increment_size);
  fprintf(fd_log, "a->mini_scale_before_next[%d]  a->mini_increment_size[%d]\n",
	  a->mini_scale_before_next, a->mini_increment_size);
  a->cpt_path = 0;
  a->first_off = 0;
  fflush(stderr);
//    if (pop)
//     {
//       pop_action(e, t, a);
//       printf("\t\t\t\t\t\tje pop :)\n");fflush(stdout);
//     }
//   else
//     {
      a->next = e->actions;
      e->actions = a;
//     }
   fflush(stderr);
  return (id);
}

/* CONSTRUCTION UNITS*/
int		create_action(t_engine *e, t_entity *t,
			      t_base_entity *base, int nb_construct)
{
  int		id;
  s_do_action	*a;
   
  if (t->action == ACTION_MOVE)
    {
      // raccourci le chemin
      finish_move(e, t);
      return (0);
      // rajoute l'action dans la queue
    }
  if (t->action != ACTION_NONE)
    reset_actions(e, t);
  if (!can_construct(e, t, base, nb_construct))
    return (-1);
  t->action = ACTION_CREATE;
  fw_send_action(e, t);
  id = e->id_action++;
  a = (s_do_action*)xmalloc(sizeof(*a));
  a->id = id;
  a->tag = ACTION_CREATE_UNITS;
  a->entity = t;
  a->entity->action_fail = 0;
  a->nb_construct = 0;
  a->nb_must_make = nb_construct;
  a->entity_c = base;
  a->time_take = 30;
  a->next = e->actions;
  e->actions = a;
  fflush(stderr);
  return (id);
}

/* CONSTRUCTION BUILGUING*/
int		create_action(t_engine *e, t_entity *t,
			      t_base_entity *base, t_coord *pos)
{
  int		id;
  s_do_action	*a;
  
  if (t->action == ACTION_MOVE)
    {
      // raccourci le chemin
      finish_move(e, t);
      return (0);
      // rajoute l'action dans la queue
    }
  if (t->action != ACTION_NONE)
    reset_actions(e, t);
  if (!can_construct(e, t, base, 1))
    return (-1);
  fw_send_action(e, t);
  t->action = ACTION_CREATE;
  id = e->id_action++;
  a = (s_do_action*)xmalloc(sizeof(*a));
  a->id = id;
  a->tag = ACTION_CREATE_BUILDING;
  a->entity = t;
  a->entity->action_fail = 0;
  a->nb_construct = 0;
  a->nb_must_make = -1;
  a->entity_c = base;
  a->time_take = 90;
  a->cpt_time = 0;
  a->speed = 2;
  a->next = e->actions;
  e->actions = a;
  fflush(stderr);
  return (id);
}

/* WAIT ACTION */
int			create_action(t_engine *e, t_entity *t, int wait)
{
  int			id;
  s_do_action		*a;
 //  int			pop;
  
//   pop = 0;
//   if (t->action == ACTION_MOVE)
//     {
//       // raccourci le chemin
//       finish_move(e, t);
//       pop = 1;
//       // rajoute l'action dans la queue
//     }
//   else 
    if (t->action != ACTION_NONE)
    reset_actions(e, t);
 // if (!pop)
//    {
     t->action = ACTION_WAIT;
     fw_send_action(e, t);
 //   }
  id = e->id_action++;
  a = (s_do_action*)xmalloc(sizeof(*a));
  a->id = id;
  a->entity = t;
  a->tag = ACTION_WAIT;
  a->time_take = wait;
  a->cpt_time = 0;
 //  if (pop)
//     {
//       pop_action(e, t, a);
//       printf("\t\t\t\t\t\tje pop :)\n");fflush(stdout);
//     }
//   else
//     {
      a->next = e->actions;
      e->actions = a;
 //    }
  fflush(stderr);
  return (id);
}
