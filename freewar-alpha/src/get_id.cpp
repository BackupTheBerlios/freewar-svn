//
// get_id.cpp for freewar in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Sun May 30 16:38:34 2004 jonathan huot
// Last update Tue Jun 29 17:24:10 2004 jonathan huot
//

#include "freewar.h"

t_base_land *get_land(t_engine *e, unsigned int land)
{
  int		i;

  for (i = 0; i < e->db.nb_lands; i++)
    if (e->db.lands[i].idmapedit == land)
      return (&e->db.lands[i]);
  return (0);
}

int			get_entity(t_engine *e, unsigned int item, t_coord pos)
{
  int		i;
  t_coord	off;

  off.x = 0;
  off.y = 0;
  for (i = 0; i < e->db.nb_entities; i++)
    if (e->db.entities[i].idmapedit == item)
      {
	put_entity(e, &(e->db.entities[i]), -1, pos, off);
	return (1);
      }
  return (0);
}
