//
// searchsmall.cpp for freewar in /u/ept2/huot_j/Freewar/src/Pathfinding
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Sat Jun 12 16:03:27 2004 jonathan huot
// Last update Sat Jun 12 17:19:22 2004 jonathan huot
//

#include "freewar.h"

int			searchsmall(t_pathfinding *c)
{
  unsigned int			save;
  list<t_checked>::iterator	i;
  list<t_checked>::iterator	backup;

  save = UINT_MAX;
  for (i = c->checked->begin(); i != c->checked->end(); i++)
    if (i->total > 0 && (unsigned int)i->total < save)
      {
	backup = i;
	save = i->total;
	c->y = i->y;
	c->x = i->x;
      }
  if (save != UINT_MAX)
    c->checked->erase(backup);
  return ((save == UINT_MAX) ? (-1) : (0));
}
