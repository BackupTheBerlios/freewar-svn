// Copyright (C) 2004 Freewar Team <doomsday@freewar.net>

// This file is part of Freewar.

// Freewar is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.

// Freewar is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with Freewar; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
/*
** pathfinding.h for freewar in /u/ept2/huot_j/Freewar/src/Pathfinding
** 
** Made by jonathan huot
** Login   <huot_j@epita.fr>
** 
** Started on  Sat Jun 12 16:00:17 2004 jonathan huot
** Last update Mon Jun 14 14:01:07 2004 jonathan huot
*/

#ifndef _PATHFINDING_H_
#define _PATHFINDING_H_

#include <list>

using namespace		std;

typedef struct		s_path
{
  int			x;
  int			y;
  struct s_path		*next;
}			t_path;

typedef struct		s_checked
{
  int			x;
  int			y;
  int			total;
}			t_checked;

typedef	struct		s_case_info
{
  int			poid;
  int			close;
  unsigned int		cost_from;
  unsigned int		cost_to;
  unsigned long		total;
  t_path		*best_path;
/*   list<t_coord>		best_path; */
}			t_case_info;

typedef	struct		s_pathfinding
{
  int			x;
  int			y;
  int			peon_x;
  int			peon_y;
  int			move_x;
  int			move_y;
  t_case_info	**open;
  int			***mymap; // une map 2D par types d'entitees
  t_engine		*engine;
  t_entity		*entity;
  int			map_w;
  int			map_h;
  list<t_checked>	*checked;
}			t_pathfinding;

void		init_open(t_pathfinding **pf, t_case_info ***open,
			  t_engine *e);
void		init_values(t_pathfinding *pf,
			    t_entity *t,
			    t_coord *dest);
int		searchsmall(t_pathfinding *c);

void		calc_case(t_pathfinding *c, t_coord *fast, int best, int step);
void		calc_one_case(t_pathfinding *c, int addx, int addy, int step);
void		calc_case_info(t_pathfinding *c);
void		my_put_in_path(t_path **b, int x, int y);
t_path		*my_pathdup(t_path *begin);
t_path          *my_rev_free_path(t_path *begin);
t_path          *my_rev_path(t_path *begin);
void		free_path(t_path *b);
t_path		*pathfinding(t_engine *e, t_entity *t, t_coord *dest);
int			get_best_type(t_pathfinding *c, int x, int y);
t_coord		*get_path(t_engine *e, t_entity *t, t_coord g);
#endif
