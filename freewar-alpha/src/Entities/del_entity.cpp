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
