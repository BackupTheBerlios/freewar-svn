//
// attack_is_valid.cpp for freewar in /u/ept2/huot_j/Freewar/src
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Sat Jun 12 14:47:23 2004 jonathan huot
// Last update Sun Jul  4 16:36:48 2004 
//

#include "freewar.h"

int		attack_is_valid(t_engine *e, t_entity *origin,
				t_entity *attacked)
{
  int			i;
  int			n;
  int			t;
  double		x;
  double		y;
  double		len;
  
  return (1);
  for (i = 0; origin->data->actions.attack[i].against; i++)
	if (origin->data->actions.attack[i].against == attacked->data)
	  break;
  if (!origin->data->actions.attack[i].against)
    return (0);
  x = (origin->pos.x > attacked->pos.x) ? (origin->pos.x - attacked->pos.x) :
    (attacked->pos.x - origin->pos.x);
  y = (origin->pos.y > attacked->pos.y) ? (origin->pos.y - attacked->pos.y) :
    (attacked->pos.y - origin->pos.x);
  len = sqrt((x * x) + (y * y));
  for (i = 0; attacked->data->type[i]; i++)
    for (n = 0; origin->data->weapon[n]; n++)
      for (t = 0; origin->data->weapon[n]->allowed[t]; t++)
	if (origin->data->weapon[n]->allowed[t] == attacked->data->type[i])
	  return (1);
  return (0);
}
