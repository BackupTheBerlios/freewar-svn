//
// put_entity.cpp for freewar in /root/Freewar/src/Actions
// 
// Made by 
// Login   <root@epita.fr>
// 
// Started on  Wed Jul 14 18:23:50 2004 
// Last update Wed Jul 14 18:23:51 2004 
//

#include "freewar.h"

int		put_entity(t_engine *e, t_base_entity *base, int app,
			   t_coord pos, t_coord offset)
{
  int		i;
  t_entity	*n;

  if (pos.x > e->map_data.w)
    return (1);
  else if (pos.y > e->map_data.h)
    return (1);
  n = create_entity(e, base, app, pos);
  if (!n)
    return (1);
  for (i = 0; e->scales[pos.y][pos.x].tab[i]; i++)
    ;
  e->scales[pos.y][pos.x].tab[i] = n;
  e->scales[pos.y][pos.x].coord[i].x = offset.x;
  e->scales[pos.y][pos.x].coord[i].y = offset.y;
  return (0);
}
