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
