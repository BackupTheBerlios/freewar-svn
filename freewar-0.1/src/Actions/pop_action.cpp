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
// pop_action.cpp for freewar in /root/Freewar/src/Actions
// 
// Made by 
// Login   <root@epita.fr>
// 
// Started on  Wed Jul 14 11:43:43 2004 
// Last update Wed Jul 14 11:44:09 2004 
//

#include "freewar.h"

int		pop_action(t_engine *e, t_entity *t, t_do_action *a)
{
  put_next_action(&t->queued);
  t->queued->tag = a->tag;
  if (a->tag == ACTION_MOVE)
    {
      if (a->path)
	{
	  free(a->path);
	  a->path = NULL;
	}
      t->queued->dest = a->end_of_path;
      t->queued->off = a->end_off;
    }
  else if (a->tag == ACTION_CREATE_UNITS)
    {
      t->queued->what = a->entity_c;
      t->queued->arg = a->nb_must_make;
    }
  else if (a->tag == ACTION_ATTACK)
    t->queued->against = a->attaked;
  else if (a->tag == ACTION_CREATE_BUILDING)
    {
      t->queued->what = a->entity_c;
      t->queued->dest = a->pos;
    }
  else
    fprintf(fd_log, "Unknown next action :%d\n", a->tag);
  del_action(e, a->id);
  t->action = ACTION_NONE;
  create_action(e, t, 4);
  return (0);
}
