//
// find_entity.cpp for freewar in /u/ept2/ribas_j/Freewar/src
// 
// Made by jonathan ribas
// Login   <ribas_j@epita.fr>
// 
// Started on  Fri May 28 13:36:32 2004 jonathan ribas
// Last update Mon Jul 12 17:57:57 2004 
//

#include "freewar.h"

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
