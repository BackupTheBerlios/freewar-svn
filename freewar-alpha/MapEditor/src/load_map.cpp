//
// load_map.cpp for freewar in /u/ept2/huot_j/Freewar/src
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Mon May 10 18:15:28 2004 jonathan huot
// Last update Tue May 11 22:27:52 2004 jonathan huot
//

#include "freewar.h"

int		load_map_header(t_info *info, FILE *fd)
{
  if (xfread((void*)&info->data.w, sizeof(unsigned short), 1, fd))
    return (1);
  if (xfread((void*)&info->data.h, sizeof(unsigned short), 1, fd))
    return (1);
  if (xfread((void*)&info->data.nb_players, sizeof(unsigned short), 1, fd))
    return (1);
  return (0);
}

int		load_map_start_point(t_info *info, FILE *fd)
{
  int		i;

  info->data.start_point =
    (t_coord*)xmalloc(sizeof(*info->data.start_point)
		      * info->data.nb_players);
  for (i = 0; i < info->data.nb_players; i++)
    {
      if (xfread((void*)&info->data.start_point[i], sizeof(t_coord), 1, fd))
	return (1);
    }
  return (0);
}

int		load_map_data_scale(t_info *info, FILE *fd)
{
  int		y;
  int		x;

  info->data.data = (t_map_data_scale**)xmalloc(sizeof(*info->data.data) *
						 info->data.h);
  for (y = 0; y < info->data.h; y++)
    {
      info->data.data[y] =
	(t_map_data_scale*)xmalloc(sizeof(**info->data.data) * info->data.w);
      for (x = 0; x < info->data.w; x++)
	{
	  if (xfread((void*)&(info->data.data[y][x]),
		     sizeof(t_map_data_scale), 1, fd))
	    return (1);
	}
    }
  return (0);
}

int		load_map_data(t_info *info, FILE *fd)
{
  if (load_map_header(info, fd))
    return (1);
  if (load_map_start_point(info, fd))
    return (1);
  if (load_map_data_scale(info, fd))
    return (1);
  return (0);
}
