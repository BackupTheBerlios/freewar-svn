/*
** map.h for freewar in /u/ept2/huot_j/Freewar/src
** 
** Made by jonathan huot
** Login   <huot_j@epita.fr>
** 
** Started on  Thu May 13 18:04:30 2004 jonathan huot
** Last update Wed Jun 30 15:10:33 2004 
*/

#ifndef _MAP_H_
#define _MAP_H_
#include "freewar.h"

typedef struct		s_map_data_scale
{
  unsigned int		land;
  unsigned int		item;
}			t_map_data_scale;

typedef struct		s_map_data
{
  unsigned short	w;
  unsigned short	h;
  unsigned short	nb_players;
  t_coord		*start_point;
  t_map_data_scale	**data;
}			t_map_data;

typedef struct		s_scale
{
  unsigned char		*fog; // [NB_PLAYER];
  // fog-> 0:je voi 1:je voi plus 2:c'est noir com dans mon c..(sans les pwals)
  t_base_land	*land;
  int			idgfxentity;
  t_entity		*tab[MAX_ENTITY_ON_SCALE];
  t_instant		*tab_ephemere[MAX_EPHEM];
  /* offsets */
  t_coord		coord[MAX_ENTITY_ON_SCALE];
  t_coord		coord_ephemere[MAX_EPHEM];
}			t_scale;

#endif
