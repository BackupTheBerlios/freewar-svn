#include "freewar.h"

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
