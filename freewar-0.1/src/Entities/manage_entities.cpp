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
#include "freewar.h"

int		entity_is_die(t_entity *t)
{
  int		i;
  
  for (i = 0; t->meter[i].meter; i++)
    {
      // quelle horreur, il faudra vite changer
      // ca ... !!!!!!!! (kv pas pour les chiens)
      if (!strcmp(METER_LIFE, t->meter[i].meter->name))
	{
	  if (t->meter[i].value <= 0)
	    return (1);
	  else
	    return (0);
	}
    }
  return (0); // l'unitee n'as pas de vie
}

int		del_corpse(t_engine *e)
{
  t_entity	*t;
  t_entity	*next;

  t = e->entity;
  while (t)
    {
      next = t->next;
      if (entity_is_die(t))
	{
	  printf("UNE ENTITEE EST MOOOOORTTTEEEEE :) :)\n");fflush(stdout);
	  if (del_entity(e, t->id))
	    printf("pas reussi a enlever le mort =/\n");fflush(stdout);
	}
      t = next;
    }
  return (0);
}

int		manage_entities(t_engine *e, t_game_param *game_param)
{  
  
  // pour les actions, faire un systeme du genre, kan une actio
  // est creeer, renvoyer l'id au jeu, kan elle se fini, le dire au jeu
  // ^^ a faire

  // a faire :  -boucler sur les entitees a boucler pour updater les meters
  //		-boucler sur la queue des actions
  //		-boucler pour tej les entitees avec zero de vie
  //		-updater les metters globaux
  //		-autres ?
  update_actions(e);
  del_corpse(e);
  return (0);
}
