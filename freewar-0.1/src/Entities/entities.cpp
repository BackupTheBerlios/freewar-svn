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
// entities.cpp for freewar in /u/ept2/ribas_j/Freewar/src
// 
// Made by jonathan ribas
// Login   <ribas_j@epita.fr>
// 
// Started on  Fri May 28 13:36:32 2004 jonathan ribas
// Last update Mon Jul 12 18:00:45 2004 
//

#include "freewar.h"

/*
  STD
*/
t_base_entity	*get_base(t_engine *e, char *name)
{
  int	i;
  
  for (i = 0; i < e->db.nb_entities; i++)
    if (!strcmp(e->db.entities[i].name, name))
      return (&e->db.entities[i]);
  fprintf(fd_log, "ERROR: get_base failed\n");
  return (0);
}
      
t_entity	*create_entity(t_engine *e, t_base_entity *base, int app,
			    t_coord pos)
{
  t_entity	*n;

  n = (t_entity*)xmalloc(sizeof(*n));
  n->data = base;
  n->action = ACTION_NONE;
  n->queued = 0;
  n->direction = get_random(NB_DIR);
  n->time = 0;
  n->against = 0;
  n->where.x = 0;
  n->where.y = 0;
  n->pos.x = pos.x;
  n->pos.y = pos.y;
  n->off.x = 0;
  n->off.y = 0;
  n->idgfx = create_gfx_entity(base->idsprite);
  n->app = app;
  n->id = e->id++;
  n->buff[0] = BUFF_NULL;
  if (base->meters)
    {
      int		i;
      
      for (i = 0; base->meters[i].name; i++)
	;
      n->meter = (t_meter*)xmalloc(sizeof(*(n->meter)) * (i + 1));
      for (i = 0; base->meters[i].name; i++)
	{
	  n->meter[i].value = base->meters[i].value;
	  n->meter[i].meter = base->meters + i;
	}
      n->meter[i].meter = 0;
      n->update = true;
    }
  else
     {
       n->meter = false;
       n->update = false;
    }
  n->next = e->entity;
  e->entity = n;
  fw_send_create_ent(e, n);
  fw_send_dir(e, n);
  return (n);
}

int		put_entity(t_engine *e, t_base_entity *base, int app,
			    t_coord pos, t_coord offset)
{
  int		i;
  t_entity	*n;
  
  if (pos.x > e->map_data.w)
    return (1);
  else if (pos.y > e->map_data.h)
    return (1);
  n = create_entity(e, base, app, pos);
  if (!n)
    return (1);
  for (i = 0; e->scales[pos.y][pos.x].tab[i]; i++)
    ;
  e->scales[pos.y][pos.x].tab[i] = n;
  e->scales[pos.y][pos.x].coord[i].x = offset.x;
  e->scales[pos.y][pos.x].coord[i].y = offset.y;
  return (0);
}

int		get_place_of_entity(t_engine *e, unsigned long id)
{
  int		i;
  t_entity	*t;
  
  t = e->entity;
  for (i = 0; t; i++)
    {
      if (t->id == id)
	return (i);
      t = t->next;
    }
  return (-1);
}

t_entity	*find_entity(t_engine *e, unsigned long id)
{
  t_entity	*t;

  for (t = e->entity; t; t = t->next)
    {
      if (t->id == id)
	return (t);
    }
  return (0);
}

int		del_entity_on_all_actions(t_engine *e, t_entity *t)
{
  t_do_action	*a;
  t_do_action	*next;
  
  a = e->actions;
  while (a)
    {
      next = a->next;
      if (a->entity == t)
	{
	  if (del_action(e, a->id))
	    fprintf(fd_log, "ERROR: del_entity_on_all_actions: del_action failed\n");
	}
      else if (a->tag == ACTION_ATTACK && a->attaked == t)
	{
	  a->entity->action = ACTION_NONE;
	  fw_send_action(e, a->entity);
	  if (del_action(e, a->id))
	    fprintf(fd_log, "ERROR: del_entity_on_all_actions: del_action failed\n");
	}
      a = next;
    }
   return (0);
}

int		erase_entity(t_engine *e, t_entity *t)
{
  del_next_actions(e, t);
  del_empty_selection(e, t);
  destroy_gfx_entity(t->idgfx);
  del_entity_on_all_actions(e, t);
  if (del_entity_in_map(e, t))
    {
      fprintf(fd_log, " /!\\ ERROR: del_entity failed\n");
      free(t);
      return (1);
    }
  free(t);
  return (0);
}

int		del_entity(t_engine *e, unsigned long id)
{
  t_entity	*t;
  t_entity	*last;
  int		i;
  int		cpt;

  i = get_place_of_entity(e, id);
  if (i == -1)
    {
      fprintf(fd_log, " /!\\ ERROR: del_entity failed\n");
      return (1);
    }
  t = e->entity;
  if (t->id == id)
    {
      e->entity = t->next;
      fw_send_del_ent(e, t);
      if (erase_entity(e, t))
	return (1);
      return (0);
    }
  if (!(t->next))
    {
      fprintf(fd_log, " /!\\ ERROR: del_entity failed\n");
      return (1);
    }
  last = t;
  t = t->next;
  for (cpt = 1; cpt <= i; cpt++)
    {
      if (cpt == i)
	{
	  last->next = t->next;
	  fw_send_del_ent(e, t);
	  if (erase_entity(e, t))
	    return (1);
	  break ;
	}
      last = t;
      t = t->next;
    }
  if (i != cpt)
    {
      fprintf(fd_log, " /!\\ ERROR: del_entity failed\n");
      return (1);
    }
  return (0);
}

/*
  INIT
*/

int		init_entities(t_engine *e, t_game_param *game_param)
{
  int		p;
  t_coord	*start;
  t_coord	pos;
  t_coord	off;
  t_base_entity *center;
  t_base_entity *peon;
  t_base_entity	*vulture;
  t_base_entity	*phoenix;
  t_base_entity	*dropship;
  t_base_entity	*footman;
  
  // placer les town-hall et les 4 peons par joueurs sur la map
  // sera remplacer apres kan le map editor sera complet.
  start = (t_coord*)xmalloc(sizeof(*start) * e->nb_players);
  off.x = 0;
  off.y = 0;
  peon = get_base(e, PEON);
  center = get_base(e, CENTER);
  vulture = get_base(e, "vulture");
  phoenix = get_base(e, "phoenix");
  dropship = get_base(e, "dropship");
  footman = get_base(e, "footman");
  for (p = 0; p < 20; p++)
  {
	pos.x = get_random(e->map_data.w);
	pos.y = get_random(e->map_data.h);
	put_entity(e, vulture, p, pos, off);
	pos.x = get_random(e->map_data.w);
	pos.y = get_random(e->map_data.h);
	put_entity(e, phoenix, p, pos, off);
	pos.x = get_random(e->map_data.w);
	pos.y = get_random(e->map_data.h);
	put_entity(e, dropship, p, pos, off);
	pos.x = get_random(e->map_data.w);
	pos.y = get_random(e->map_data.h);
	put_entity(e, footman, p, pos, off);
  }
  for (p = 0; p < e->nb_players; p++)
    {
      start[p].y = get_random(e->map_data.h);
      start[p].x = get_random(e->map_data.w);
      while (start[p].x < START_LENGHT || start[p].x > e->map_data.w - START_LENGHT ||
	     start[p].y < START_LENGHT || start[p].y > e->map_data.h - START_LENGHT)
	{
	  start[p].y = get_random(e->map_data.h);
	  start[p].x = get_random(e->map_data.w);
	}
      // autres fontions pour verifier l'emplacement de debut ptet..
      pos.x = start[p].x;
      pos.y = start[p].y;
      put_entity(e, center, p, pos, off);
      pos.y--;
      put_entity(e, peon, p, pos, off);
      pos.x++;
      put_entity(e, peon, p, pos, off);
      pos.x++;
      put_entity(e, peon, p, pos, off);
      pos.x++;
      put_entity(e, peon, p, pos, off);
    }
  free(start);
  return (0);
}

/*
  MANAGE
*/

int		entity_is_die(t_entity *t)
{
  int		i;
  
  for (i = 0; t->meter[i].meter; i++)
    {
      if (!strcmp(METER_LIFE, t->meter[i].meter->name))
	{
	  if (t->meter[i].value <= 0)
	    return (1);
	  else
	    return (0);
	}
    }
  return (0); // l'unitee n'as pas de vie
}

int		del_corpse(t_engine *e)
{
  t_entity	*t;
  t_entity	*next;

  t = e->entity;
  while (t)
    {
      next = t->next;
      if (entity_is_die(t))
	{
	  printf("UNE ENTITEE EST MOOOOORTTTEEEEE :) :)\n");fflush(stdout);
	  if (del_entity(e, t->id))
	    printf("pas reussi a enlever le mort =/\n");fflush(stdout);
	}
      t = next;
    }
  return (0);
}

int		manage_entities(t_engine *e, t_game_param *game_param)
{  
  
  // pour les actions, faire un systeme du genre, kan une actio
  // est creeer, renvoyer l'id au jeu, kan elle se fini, le dire au jeu
  // ^^ a faire

  // a faire :  -boucler sur les entitees a boucler pour updater les meters
  //		-boucler sur la queue des actions
  //		-boucler pour tej les entitees avec zero de vie
  //		-updater les metters globaux
  //		-autres ?
  update_actions(e);
  del_corpse(e);
  return (0);
}
