#include "network.h"

void		move_last_player(int no)
{
  int		last;

  for (last = 0; cnt->clients[last].sock; last++)
    ;
  if (!last)
    return;
  if (--last != no)
    memcpy(&cnt->clients[no], &cnt->clients[last], sizeof(*cnt->clients));
  cnt->clients = (t_client*)xrealloc(cnt->clients,
				     sizeof(*cnt->clients) * (last + 1));
  init_client(&cnt->clients[last]);
}
