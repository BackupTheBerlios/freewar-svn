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
