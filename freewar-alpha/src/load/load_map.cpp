//
// load_map.cpp for freewar in /u/ept2/huot_j/Freewar/src
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Mon May 10 18:15:28 2004 jonathan huot
// Last update Tue Jun 29 18:45:52 2004 jonathan huot
//

#include "freewar.h"

int		load_map_header(t_engine *e, FILE *fd)
{

  // regarder si ya soucis de BIG/LITTLE endian avec les shorts et les fread
  if (xfread((void*)&e->map_data.w, sizeof(unsigned short), 1, fd))
    return (1);
  if (xfread((void*)&e->map_data.h, sizeof(unsigned short), 1, fd))
    return (1);
  if (xfread((void*)&e->map_data.nb_players, sizeof(unsigned short), 1, fd))
    return (1);
  return (0);
}

int		load_map_start_point(t_engine *e, FILE *fd)
{
  int		i;
  
  // <tmp>, en attendant que le mapeditor puisse packer les nb_player..
  e->map_data.nb_players = 2;
  // </tmp>
  e->map_data.start_point =
    (t_coord*)xmalloc(sizeof(*e->map_data.start_point)
		      * e->map_data.nb_players);
  for (i = 0; i < e->map_data.nb_players; i++)
    {
  //     if (xfread((void*)&e->map_data.start_point[i], sizeof(t_coord), 1, fd))
      //return (1);
      ;
    }
  return (0);
}

int		load_map_data_scale(t_engine *e, FILE *fd)
{
  int		y;
  int		x;

  e->map_data.data = (t_map_data_scale**)xmalloc(sizeof(*e->map_data.data) *
						 e->map_data.h);
  for (y = 0; y < e->map_data.h; y++)
    {
      e->map_data.data[y] =
	(t_map_data_scale*)xmalloc(sizeof(**e->map_data.data) * e->map_data.w);
      for (x = 0; x < e->map_data.w; x++)
	{
	  if (xfread((void*)&(e->map_data.data[y][x]),
		     sizeof(t_map_data_scale), 1, fd))
	    return (1);  
	}    
    }
  return (0);
}

int		load_map_data(t_engine *e, int id)
{
  FILE		*fd;
  char		mymap[512];

//mymap = get_path_of_map(id);
  strcpy(mymap, "mymap.fwm");
  if (!(fd = xfopen(mymap, "r")))
    return (1);
  if (load_map_header(e, fd))
    return (1);
  if (load_map_start_point(e, fd))
    return (1);
  if (load_map_data_scale(e, fd))
    return (1);
  fclose(fd);
  return (0);
}


int		load_map(t_engine *e)
{
  t_coord	pos;

  if (e->scales)
    free_map(e);
  e->scales = (t_scale**)xmalloc(sizeof(*e->scales) * e->map_data.h);
  e->entity = 0;
  for (pos.y = 0; pos.y < e->map_data.h; pos.y++)
    {
      e->scales[pos.y] = (t_scale*)xmalloc(sizeof(**e->scales) *
					   e->map_data.w);
      for (pos.x = 0; pos.x < e->map_data.w; pos.x++)
	{
	  if (!(e->scales[pos.y][pos.x].land =
		  get_land(e, e->map_data.data[pos.y][pos.x].land)))
	  {
	      fprintf(fd_log, "Land unknown x:%d, y:%d, land:%d\n",
		      pos.x, pos.y, e->map_data.data[pos.y][pos.x].land);
	      exit(1);
	  }	    
	  e->scales[pos.y][pos.x].idgfxentity =
			create_gfx_entity(e->scales[pos.y][pos.x].land->idsprite);
	  memset(e->scales[pos.y][pos.x].tab, 0, MAX_ENTITY_ON_SCALE *
		 sizeof(t_entity*));
	  memset(e->scales[pos.y][pos.x].coord, 0, MAX_ENTITY_ON_SCALE *
		 sizeof(t_coord));
	  if (e->map_data.data[pos.y][pos.x].item)
	    if (!get_entity(e, e->map_data.data[pos.y][pos.x].item, pos))
	      fprintf(fd_log, "error on map (unknown entity %d)\n",
		      e->map_data.data[pos.y][pos.x].item);
	  e->scales[pos.y][pos.x].fog =
	    (unsigned char*)xmalloc(sizeof(*e->scales[pos.y][pos.x].fog) *
				    e->map_data.nb_players);
	  memset(e->scales[pos.y][pos.x].fog, FOG_BLACK,
		 e->map_data.nb_players *
		 sizeof(*e->scales[pos.y][pos.x].fog));
	  memset(e->scales[pos.y][pos.x].tab_ephemere, 0, MAX_EPHEM *
		 sizeof(t_instant*));
	  memset(e->scales[pos.y][pos.x].coord_ephemere, 0, MAX_EPHEM *
		 sizeof(t_coord));
	}
    }
  return (0);
}

int		free_map(t_engine *e)
{
  int		y;
  int		x;

  if (e->scales)
    {
      for (y = 0; y < e->map_data.h; y++)
	{
	  for (x = 0; x < e->map_data.w; x++)
	    free(e->scales[y][x].fog);
	  free(e->scales[y]);
	}
      free(e->scales);
      e->scales = 0;
    }
  return (0);
}
