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
// update_actions.cpp for freewar in /root/Freewar/src/Actions
// 
// Made by 
// Login   <root@epita.fr>
// 
// Started on  Wed Jul 14 11:42:03 2004 
// Last update Wed Jul 14 16:18:32 2004 
//

#include "freewar.h"

int		update_actions(t_engine *e)
{
  t_do_action	*a;
  t_do_action	*next;
  int		ret;
  
  for (a = e->actions; a; a = next)
    {
      next = a->next;
      ret = 0;
      if (a->entity->action_fail >= MAX_ACTION_FAIL)
	{
	  a->entity->action_fail = 0;
	  if (a->entity->action == ACTION_MOVE && a->path)
	    {
	      free(a->path);
	      a->path = NULL;
	    }
	  a->entity->action = ACTION_NONE;
	  fw_send_action(e, a->entity);
	  if (del_action(e, a->id))
	    fprintf(fd_log, "ERROR: update_actions: del_action feiled\n");
	  return (0);
	}
      else if (a->tag == ACTION_ATTACK)
	{
	  a->cpt_time++;
	  if (a->cpt_time >= a->time_take)
	    {
	      a->cpt_time = 0;
	      if (!range_is_valide(e, a->entity, a->attaked, a->range))
		{
		  printf("jsuis plus a portee de tir, je m'arrete\n");
		  a->entity->action = ACTION_NONE;
		  fw_send_action(e, a->entity);
		  if (del_action(e, a->id))
		    fprintf(fd_log, "ERROR: update_actions: del_action failed\n");
		}
	      else
		{
		  ret = make_dammage(e, a->attaked, a->damages);
		  if (ret == 1)
		    {
		      fprintf(fd_log, "ERROR: update_actions: attque: pas de meter METER_LIFE"
			      " trouver dans l'entitee attaquee :(\n");
		      a->entity->action = ACTION_NONE;
		      fw_send_action(e, a->entity);
		      if (del_action(e, a->id))
			fprintf(fd_log, "ERROR: update_actions: del_action failed\n");
		    }
		  else if (ret == DIE)
		    {
		      do_next_action(e, a->entity);
		      printf("PAN ! T MORT ! hehe :p(%d)\n", (int)a->entity);
		      if (del_action(e, a->id))
			fprintf(fd_log, "ERROR: update_actions: del_action failed\n");
		    }
		}
	    }
	}
      else if (a->tag == ACTION_MOVE)// jen suis la
	{
 	  printf("update_actions: MOVE --->\n");fflush(stdout);
	  a->cpt_time++;
	  //	  printf("a->cpt_time[%d] a->speed[%d] a->cpt_path[%d] a->length_of_path[%d]\n", 
	  //	 a->cpt_time, a->speed, a->cpt_path, a->length_of_path);fflush(stdout);
	  if (a->cpt_time >= a->time_take)
	    {
	      a->cpt_time = 0;
	      if (replace_entity(e, a)) // si c'est bloqué
		continue;
	      printf("j'avance d'une case :p\n");fflush(stdout);
	    }
	  if (a->cpt_path >= a->length_of_path - 1)
	    {
	     printf("jsuis arriver au bout du chemin, c'etait pas facil ! :)\n");fflush(stdout);
	     if (a->path)
	       {
		 free(a->path);
		 a->path = NULL;
	       }
	     do_next_action(e, a->entity);
	     if (del_action(e, a->id))
	       fprintf(fd_log, "ERROR: update_actions: del_action failed\n");
	     printf("-->\n");fflush(stdout);
	    }
	}
      else if (a->tag == ACTION_CREATE_BUILDING || a->tag == ACTION_CREATE_UNITS)
	{
	  a->cpt_time++;
	  if (a->cpt_time >= a->time_take)
	    {
	      t_coord	pos;
	      t_coord	off;

	      a->cpt_time++;
	      a->nb_construct++;
	      off.x = off.y = 0;
	      if (a->tag == ACTION_CREATE_UNITS)
		get_pos_for_construct(e, a->entity, &pos);
	      else
		pos = a->pos;
	      if (put_entity(e, a->entity_c, a->entity->app, pos, off))
		{
		  fprintf(fd_log, "ERROR: update_actions: construction: failed\n");
		  if (del_action(e, a->id))
		    fprintf(fd_log, "ERROR: update_actions: del_action failed\n");
		  a->entity->action = ACTION_NONE;
		  fw_send_action(e, a->entity);
		}
	      if (a->nb_must_make == a->nb_construct || a->tag == ACTION_CREATE_BUILDING)
		{
		  do_next_action(e, a->entity);
		  if (del_action(e, a->id))
		    fprintf(fd_log, "ERROR: update_actions: del_action failed\n");
		}
	    }
	}
      else if (a->tag == ACTION_WAIT)
	{
	  a->cpt_time++;
	  if (a->cpt_time >= a->time_take)
	    {
	      do_next_action(e, a->entity);
	      if (del_action(e, a->id))
		fprintf(fd_log, "ERROR: del_wait_action failed\n");
	    }
	}
    }
  return (0);
}
