//
// get_best_speed.cpp for freewar in /root/Freewar/src/Actions
// 
// Made by 
// Login   <root@epita.fr>
// 
// Started on  Wed Jul 14 17:14:57 2004 
// Last update Wed Jul 14 17:14:59 2004 
//

#include "freewar.h"

int	get_best_speed(t_engine *e, t_entity *t)
{
  float	coef;
  int	speed;

  coef = get_best_speed_factor(e, t);
  if (coef != 0.0)
    speed = (int)(t->data->actions.move_speed * (float)coef);
  else
    speed = -1;
  return (speed);
}
