#include "freewar.h"

int		wait_engine(char *app)
{
  Uint32	drop;
  t_trame	trame;

  drop = SDL_GetTicks();
  while (42)
    if (check_select(1000))
      {
	while (exec_msg(&(cnt->clients[0]), &trame))
	  if (is_valid_trame(&trame, TAG_PLAYER_INFO))
	  {
	    memcpy(app, trame.msg, trame.len);
		fprintf(fd_log, "app got: %d\n", *app);
	  }
	  else if (is_valid_trame(&trame, TAG_PLAYERS_READY))
	    return (0);
      }
    else if (SDL_GetTicks() - drop > 30000)
      return (1);
  return (0);
}
