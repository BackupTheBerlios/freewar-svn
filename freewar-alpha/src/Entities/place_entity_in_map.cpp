//
// place_entity_in_map.cpp for freewar in /root/Freewar/src
// 
// Made by 
// Login   <root@epita.fr>
// 
// Started on  Sun Jun 27 18:05:49 2004 
// Last update Sat Jul 10 14:23:53 2004 
//

#include "freewar.h"

int		place_entity_in_map(t_engine *e, t_entity *t, t_coord *pos)
{
  int		i;

  printf("place_entity_in_map: je bouge l'entiree:%d\n", (int)t);
  if (pos->x < 0 || pos->x >= e->map_data.w ||
      pos->y < 0 || pos->y >= e->map_data.h)
    {
      fprintf(fd_log, "ERROR: place_entity_in_map: failed\n");
      return (1);
    }
  //  t->direction = get_direction(&(t->pos), pos);
  for (i = 0; i < MAX_ENTITY_ON_SCALE; i++)
    {
      if (!e->scales[pos->y][pos->x].tab[i])
	{
	  e->scales[pos->y][pos->x].tab[i] = t;
	  if (i + 1 < MAX_ENTITY_ON_SCALE)
	    e->scales[pos->y][pos->x].tab[i + 1] = 0;
	  t->pos.x = pos->x;
	  t->pos.y = pos->y;
	  e->scales[pos->y][pos->x].coord[i].x = t->off.x;
	  e->scales[pos->y][pos->x].coord[i].y = t->off.y;
	  fw_send_pos(e, t);
	  return (0);
	}
    }
  return (1);
}

int		move_off_in_map(t_engine *e, t_entity *t, t_coord off)
{
  int		i;
 
  printf("move_off_in_map: je bouge l'entiree:%d\n", (int)t);
  for (i = 0; i < MAX_ENTITY_ON_SCALE && e->scales[t->pos.y][t->pos.x].tab[i]; i++)
    {
      if (t == e->scales[t->pos.y][t->pos.x].tab[i])
	{
	  e->scales[t->pos.y][t->pos.x].coord[i].x = off.x;
	  e->scales[t->pos.y][t->pos.x].coord[i].y = off.y;
	  t->off.x = off.x;
	  t->off.y = off.y;
	  fw_send_off(e, t);
	  return (0);
	}
    }
  return (1);
}
