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
// get_events.cpp for freewar in /u/ept2/ribas_j/Freewar/src/Graphics
// 
// Made by jonathan ribas
// Login   <ribas_j@epita.fr>
// 
// Started on  Mon Jun 14 13:26:48 2004 jonathan ribas
// Last update Sat Jul  3 14:57:33 2004 stephane petitcolas
//

#include "freewar.h"

//tmp
int		manage_console(t_engine *e);
  // pecho les events
int		get_events(t_engine *e)
{
  // TODO: ne PLUS passer par une structure a nous d'event, 
  // mais utiliser directement celle de la SDL (ou une interface qui
  // se sert directement).
  if (event(e->events, e->other_events))
    return (1);
  if (e->other_events->quit)
    {
      // TODO: Ne pas quitter directement dans cette fonction

      fprintf(fd_log, "EXIT\n");
      // TODO: en informer les autres joueurs:
      // stock_msg(&cnt->clients[e->assos_clients[0]], TAG_EXIT, 0, NULL);
      close_connection();      // fermer toutes les connections 
      free_engine(e);
      return (1);
    }
  // Pour tester la console:
  e->console = true;
  // envoyer au jeu les events
  if (e->console == true)
    manage_console(e);
  else
    {
      // avec le systeme pourri:
      //	  stock_msg(&cnt->clients[e->assos_clients[0]], TAG_EVENTS, sizeof(*(e->events)), e->events);
      //	  e->g.event_ok = 0;
      // maintenant:
      manage_events(e);
    }
  return (0);
}
