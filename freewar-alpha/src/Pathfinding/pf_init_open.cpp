//
// pf_init_open.cpp for freewar in /u/ept2/huot_j/Freewar/src/Pathfinding
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Sat Jun 12 15:58:34 2004 jonathan huot
// Last update Sun Jul  4 11:33:22 2004 
//

#include "freewar.h"

int		pf_init_maps_types(t_engine *e, t_pathfinding *pf)
{
  int		nb_types;
  int		i;
  int		n;
  int		f;
  int		lnd;
  t_base_land	*land;

  pf->engine = e;
  pf->mymap = (int***)xmalloc(sizeof(int**) * (e->db.nb_types));
  for (nb_types = 0; nb_types < e->db.nb_types; nb_types++)
    {
      pf->mymap[nb_types] = (int**)xmalloc(sizeof(int*) * (e->map_data.h + 1));
      for (i = 0; i < e->map_data.h; i++)
	{
	  pf->mymap[nb_types][i] = (int*)xmalloc(sizeof(int) * (e->map_data.w + 1));
	  for (n = 0; n < e->map_data.w; n++)
	    {
	      pf->mymap[nb_types][i][n] = 0;
	      for (f = 0; f < GAME_MAX_FACTOR &&
		     e->db.types[nb_types].speed[f].type; f++)
		{
		  if (e->db.types[nb_types].speed[f].type == FACTOR_SURFACE)
		    {
		      for (lnd = 0; e->db.types[nb_types].speed[f].factor[lnd].condition.ptr; lnd++)
			{
			  land = e->db.types[nb_types].speed[f].factor[lnd].condition.ptr;
			  if (land == e->scales[i][n].land)
			    {
			      pf->mymap[nb_types][i][n] = (int)
				(1000.0 - e->db.types[nb_types].speed[f].factor[lnd].coef * 100);
			      break;
			    }
			}
		      break;
		    }
		}
	    }
	}
    }
  return (0);
}


void		init_open(t_pathfinding **pf,
			  t_case_info ***open,
			  t_engine *e)
{
  int		i;
  int		n;

  *pf = (t_pathfinding*)xmalloc(sizeof(**pf));
  (*pf)->checked = new list<t_checked>;
  *open = (t_case_info**)xmalloc(sizeof(t_case_info*) * (e->map_data.h + 1));
  for (i = 0; i < e->map_data.h; i++)
  {
		  (*open)[i] = (t_case_info*)xmalloc(sizeof(t_case_info) * e->map_data.w);
		  for (n = 0; n < e->map_data.w; n++)
		  {
			  (*open)[i][n].close = 0;
			  (*open)[i][n].best_path = 0;
		  }
  }
  pf_init_maps_types(e, *pf);
  (*open)[i] = 0;
  (*pf)->map_w = e->map_data.w;
  (*pf)->map_h = e->map_data.h;  
}
