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
