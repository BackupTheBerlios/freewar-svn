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
// del_action.cpp for freewar in /root/Freewar/src/Actions
// 
// Made by 
// Login   <root@epita.fr>
// 
// Started on  Wed Jul 14 11:44:25 2004 
// Last update Wed Jul 14 11:45:01 2004 
//

#include "freewar.h"


int		del_action(t_engine *e, int id)
{
  t_do_action	*a;
  t_do_action	*last;
  int		i;
  int		cpt;
  
  i = get_place_of_action(e, id);
  if (i == -1)
    {
      fprintf(fd_log, " /!\\ ERROR: del_action failed\n");
      return (1);
    }
  a = e->actions;
  if (a->id == id)
    {
      e->actions = a->next;
      if (a->tag == ACTION_MOVE && a->path)
	{
	  free(a->path);
	  a->path = NULL;
	}
      free(a);
      return (0);
    }
  if (!(a->next))
    {
      fprintf(fd_log, " /!\\ ERROR: del_action failed\n");
      return (1);
    }
  last = a;
  a = a->next;
  for (cpt = 1; cpt <= i && a; cpt++)
    {
      if (cpt == i)
	{
	  last->next = a->next;
	  if (a->tag == ACTION_MOVE && a->path)
	    {
	      free(a->path);
	      a->path = NULL;
	    }
	  free(a);
	  break ;
	}
      last = a;
      a = a->next;
    }
  if (i != cpt)
    {
      fprintf(fd_log, " /!\\ ERROR: del_action failed\n");
      return (1);
    }
  return (0);
}
