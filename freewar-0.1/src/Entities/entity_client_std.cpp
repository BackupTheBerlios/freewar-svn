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
// put_entity_client.cpp for freewar in /root/Freewar/src
// 
// Made by 
// Login   <root@epita.fr>
// 
// Started on  Sat Jul 10 16:28:37 2004 
// Last update Mon Jul 12 14:35:53 2004 
//

#include "freewar.h"

t_entity	*create_entity_client(t_engine *e, t_base_entity *base,
				      unsigned long id, int app,
				      t_coord pos, t_coord off)
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
  n->pos = pos;
  n->off = off;
  n->idgfx = create_gfx_entity(base->idsprite);
  n->app = app;
  n->id = id;
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
  return (n);
}
 

int		put_entity_client(t_engine *e, unsigned long id, char *name, 
				  int app, t_coord pos, t_coord off)
{
  int		i; 
  t_entity	*n;
  t_base_entity *base;
  
  printf("put_entity_client id%d", id);fflush(stdout);
  base = get_base(e, name);
  if (!base)
    return (1);
  if (pos.x > e->map_data.w || pos.y > e->map_data.h)
    return (1);
  n = create_entity_client(e, base, id, app, pos, off);
  if (!n)
    return (1);
  for (i = 0; e->scales[pos.y][pos.x].tab[i]; i++)
    ;
  e->scales[pos.y][pos.x].tab[i] = n;
  e->scales[pos.y][pos.x].coord[i].x = off.x;
  e->scales[pos.y][pos.x].coord[i].y = off.y;
  return (0);
}

int		erase_entity_client(t_engine *e, t_entity *t)
{
//   del_next_actions(e, t);
  del_empty_selection(e, t);
  destroy_gfx_entity(t->idgfx);
//   del_entity_on_all_actions(e, t);
  if (del_entity_in_map(e, t))
    {
      fprintf(fd_log, " /!\\ ERROR: del_entity failed\n");
      free(t);
      return (1);
    }
  free(t);
  return (0);
}

int		del_entity_client(t_engine *e, unsigned long id)
{
  t_entity	*t;
  t_entity	*last;
  int		i;
  int		cpt;

  printf("del_entity_client id%d", id);fflush(stdout);
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
      if (erase_entity_client(e, t))
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
	  if (erase_entity_client(e, t))
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
