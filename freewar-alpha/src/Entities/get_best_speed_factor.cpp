#include "freewar.h"

float		get_best_speed_factor(t_engine *e, t_entity *t)
{
  int		i;
  int		d;
  t_base_land	*land;
  int		c;
  float		coef;

  coef = 0.0;
  land = e->scales[t->pos.y][t->pos.x].land;
  for (i = 0; t->data->type[i] != 0; i++)
    {
      for (d = 0; d < GAME_MAX_FACTOR; d++)
		if (t->data->type[i]->speed[d].type == FACTOR_SURFACE)
		{
		for (c = 0; t->data->type[i]->speed[d].factor[c].condition.ptr != 0; c++)
	      if (t->data->type[i]->speed[d].factor[c].condition.ptr == land)
		{
		  if (t->data->type[i]->speed[d].factor[c].coef > coef)
		    coef = t->data->type[i]->speed[d].factor[c].coef;
		  break;
		}
	    break;
	  }
    }
  return(coef);
}
