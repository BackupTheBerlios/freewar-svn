//
// init_map.cpp for freewar in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Tue May 11 22:12:02 2004 jonathan huot
// Last update Fri Jun  4 14:27:07 2004 jonathan huot
//

#include "freewar.h"

Err		init_map(t_info *info, char *file)
{
  FILE		*fd;
  int		i;
  int		n;

  if ((fd = fopen(file, "r")) == 0)
    {
      if ((info->data.w = info->width) <= 0)
	info->data.w = MAP_WIDTH;
      if ((info->data.h = info->height) <= 0)
	info->data.h = MAP_HEIGHT;
      info->data.data =	(t_map_data_scale**)
	xmalloc(sizeof(*info->data.data) * info->data.h);
      for (i = 0; i < info->data.h; i++)
	{
	  info->data.data[i] = (t_map_data_scale*)
	    xmalloc(sizeof(**info->data.data) * info->data.w);
	  info->data.nb_players = 0;
	  for (n = 0; n < info->data.w; n++)
	    {
	      info->data.data[i][n].land = DEFAULT_ID;
	      info->data.data[i][n].item = 0;
	    }
	}
    }
  else
    {
      load_map_data(info, fd);
      fclose(fd);
    }
  return (0);
}
