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
//
// can_construct.cpp for freewar in /u/ept2/ribas_j/Freewar/src
// 
// Made by jonathan ribas
// Login   <ribas_j@epita.fr>
// 
// Started on  Sat Jun 12 15:31:36 2004 jonathan ribas
// Last update Sun Jun 13 17:07:57 2004 jonathan ribas
//

#include "freewar.h"

int		check_prequesite(t_engine *e, t_entity *t, t_create c)
{
  
  return (0);
}

t_cost		*add_cost(t_cost *c, int val, char *name, char *type)
{
  int		i;
  int		n;
  t_cost	*new_c;
  
  for (i = 0; c[i].name; i++)
    if (!strcmp(name, c[i].name) &&
	!strcmp(type, c[i].type))
      {
	c[i].value += val;
	return (0);
      }
  new_c = (t_cost*)xmalloc(sizeof(*new_c) * (i + 1));
  for (n = 0; n < i; n++)
    {
      new_c[n].value = c[n].value;
      new_c[n].name = c[n].name;
      new_c[n].type = c[n].type;
    }
  new_c[n].value = val;
  new_c[n].name = name;
  new_c[n].type = type;
  new_c[n + 1].name = 0;
  return (0);
}

t_meter		*get_meter(t_engine *e, char *name, char *type, int app)
{
  int		i;
  
  if (!type && e->meters[app]) // ressources du joueur
    {
      for (i = 0; e->meters[app][i].meter; i++)
	if (!strcmp(name, e->meters[app][i].meter->name))
	  return (&(e->meters[app][i]));
    }
  else if (!strcmp(type, COST_GLOBAL)) // ressources globales
    {
      for (i = 0; e->globals[i].meter; i++)
	if (!strcmp(name, e->globals[i].meter->name))
	  return (&(e->globals[i]));
    }
  return (0); // ressource non trouvee
}

int		buy_entity(t_engine *e, t_entity *t, t_create c, t_base_entity *b)
{
  int		app;
  int		i;
  t_cost	*cost;
  t_meter	*m;
  
  cost = (t_cost*)xmalloc(sizeof(*cost));
  cost->name = 0;
  app = t->app;
  
  for (i = 0; c.cost[i].name; i++) // ajout des couts du constructeur
    cost = add_cost(cost, c.cost[i].value, c.cost[i].name, c.cost[i].type);
  for (i = 0; b->costs[i].name; i++) // ajout des couts du construit
    cost = add_cost(cost, b->costs[i].value, b->costs[i].name, b->costs[i].type);
  for (i = 0; cost[i].name; i++) // verification de la disponibilitee des ressources
    {
      m = get_meter(e, cost[i].name, cost[i].type, app);
      if (!m || m->value - cost[i].value < 0)
	{
	  free(cost);
	  return (1);
	}
    }
  for (i = 0; cost[i].name; i++) // et maintenant je debite
    {
      m = get_meter(e, cost[i].name, cost[i].type, app);
      m->value -= cost[i].value;
    }
  free(cost);
  return (0);
}

int		can_construct(t_engine *e, t_entity *t, t_base_entity *b, int nb)
{
  int		i;
  t_create	*c;
  
  c = t->data->actions.create;
  for (i = 0; 51; i++)
    {
      if (!(c[i].base))
	break ;
      if (c[i].base == b) // l'entitee a le droit de construire la demande
	{
	  if (check_prequesite(e, t, c[i]))
	    return (0);
	  if (buy_entity(e, t, c[i], b))
	    return (0);
	  return (1);
	}
    }
  return (0);
}
