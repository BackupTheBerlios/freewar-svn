//
// calc_case.cpp for freewar in /u/ept2/huot_j/Freewar/src/Pathfinding
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Sat Jun 12 15:57:15 2004 jonathan huot
// Last update Sun Jul  4 14:45:23 2004 
//

#include "freewar.h"

void		calc_case(t_pathfinding *c, t_coord *fast, int best, int step)
{
  int		d_peon;
  int		d_peon_fast;
  t_checked	my;

  d_peon = abs(c->y - c->peon_y) + abs(c->x - c->peon_x);
  d_peon_fast = abs(fast->y - c->peon_y) + abs(fast->x - c->peon_x);
  c->open[fast->y][fast->x].poid = c->open[c->y][c->x].poid + 
	((int)c->mymap[best][fast->y][fast->x] * step);
  c->open[fast->y][fast->x].cost_from = c->open[c->y][c->x].cost_from + step;
  c->open[fast->y][fast->x].cost_to = c->open[c->y][c->x].cost_to;
  if (d_peon_fast < d_peon)
    c->open[fast->y][fast->x].cost_to += step;
  else if (d_peon_fast > d_peon)
    c->open[fast->y][fast->x].cost_to -= step;
  c->open[fast->y][fast->x].total = c->open[fast->y][fast->x].cost_from +
    c->open[fast->y][fast->x].cost_to + c->open[fast->y][fast->x].poid;
  c->open[fast->y][fast->x].best_path = c->open[c->y][c->x].best_path;
  my.x = fast->x;
  my.y = fast->y;
  my.total = c->open[fast->y][fast->x].total;
  c->checked->push_front(my);
}

void		calc_one_case(t_pathfinding *c, int addx, int addy, int step)
{
  t_coord	my;
  int		best;

  my.x = c->x + addx;
  my.y = c->y + addy;
  if (my.x < c->map_w && my.x >= 0 &&
      my.y < c->map_h && my.y >= 0)
  {
	if ((best = get_best_type(c, my.x, my.y)) >= 0 &&
		c->mymap[best][my.y][my.x] != 0
		&& c->open[my.y][my.x].close == 0 
 		&& c->open[my.y][my.x].total == 0)
      {
	calc_case(c, &my, best, step);
	my_put_in_path(&(c->open[my.y][my.x].best_path),
		       my.x, my.y);
      }
  }
}

void		calc_case_info(t_pathfinding *c)
{
  c->open[c->y][c->x].close = 1;
  calc_one_case(c, 1, 0, 10);
  calc_one_case(c, 0, 1, 10);
  calc_one_case(c, 1, 1, 14);
  calc_one_case(c, 1, -1, 14);
  calc_one_case(c, -1, 0, 10);
  calc_one_case(c, 0, -1, 10);
  calc_one_case(c, -1, -1, 14);
  calc_one_case(c, -1, 1, 14);
}
