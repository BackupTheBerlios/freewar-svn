//
// open_connection_to_the_game.cpp for freewar in /u/ept2/huot_j/Freewar/src
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Thu May  6 11:07:58 2004 jonathan huot
// Last update Tue Jun 29 19:24:00 2004 jonathan huot
//

#include "freewar.h"

int			open_connection_to_the_game()
{
  Uint32		waited;

  waited = SDL_GetTicks();
  while (69)
    {
      int		rdy;
      t_trame		trame;

      if ((rdy = check_select(200)))
	{
	  if (exec_msg(&cnt->newclient->c, &trame))
	    {
	      if (is_valid_trame(&trame, TAG_WELCOME))
		{
		  cnt->clients =
		    (t_client*)xmalloc(sizeof(*cnt->clients) * 2);
		  memcpy(&cnt->clients[0], &cnt->newclient->c,
			 sizeof(*cnt->clients));
		  init_client(&cnt->clients[1]);
		  cnt->newclient = del_in_list(cnt->newclient,
					       &cnt->newclient->c);
		  fprintf(fd_log, "Game found\n");
		  return (0);
		}
	    }
	  fprintf(fd_log, "Activity %d\n", rdy);
	}
      if (SDL_GetTicks() - waited > 5005)
	{
	  fprintf(fd_log, "Can't connect with the game\n");
	  return (1);
	}
    }
  return (0);
}
