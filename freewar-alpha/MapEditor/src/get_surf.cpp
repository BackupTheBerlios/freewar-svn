//
// get_surf.cpp for freewar in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Tue May 11 18:19:18 2004 jonathan huot
// Last update Fri May 28 18:23:29 2004 jonathan huot
//

#include "freewar.h"

SDL_Surface	*get_surf(t_info *info, unsigned int id)
{
  unsigned int	i;

  for (i = 0; i < NB_ITEMS; i++)
    if (gl_items[i].id == id)
      return (info->img[i]);
  printf("id %d\n", (int)id);
  put_error("pewt");
  return (0);
}

bool		get_land(unsigned int id)
{
  unsigned int	i;

  for (i = 0; i < NB_ITEMS; i++)
    if (gl_items[i].id == id)
      return (gl_items[i].land);
  return (false);
}
