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


int		get_events(t_engine *e)
{
  // pecho les events
  if (e->g.event_ok)
    {
      if (event(e->events, e->other_events))
	return (1);
      if (e->other_events->quit)
	{
	  fprintf(fd_log, "EXIT\n");
	  if (!(cnt->clients[e->assos_clients[0]].sock))
	    fprintf(fd_log, "ouai, bah c'est con, ta pas de clients !\n");
	  else
	    stock_msg(&cnt->clients[e->assos_clients[0]], TAG_EXIT, 0, NULL);
	  // fermer toutes les connections 
	  close_connection();
	  free_engine(e);
	  return (1);
	}
      // envoyer au jeu les events
      if (e->console == true)
	{}
      else if (!(cnt->clients[e->assos_clients[0]].sock))
	fprintf(fd_log, "ouai, bah c'est con, ta pas de clients !\n");
      else
	{
		// avec le systeme pourri:
//	  stock_msg(&cnt->clients[e->assos_clients[0]], TAG_EVENTS, sizeof(*(e->events)), e->events);
//	  e->g.event_ok = 0;
		// maintenant:
		manage_events(e);
	}
    }
  return (0);
}
