#include "freewar.h"

int		get_best_type(t_pathfinding *c, int x, int y)
{
  int		i;
  int		n;
  int		max;
  int		res;
  t_coord	tmp;

  max = 10000000;
  res = -1;
  tmp.x = x;
  tmp.y = y;
  if (is_collision(c->engine, c->entity, &tmp))
    return (-1);
  for (n = 0; c->entity->data->type[n]; n++)
    for (i = 0; i < c->engine->db.nb_types; i++)
      {
	if (&c->engine->db.types[i] == c->entity->data->type[n])
	  {
	    if (c->mymap[i][y][x] && c->mymap[i][y][x] < max)
	      res = i;
	  }
      }
  return (res);
}
