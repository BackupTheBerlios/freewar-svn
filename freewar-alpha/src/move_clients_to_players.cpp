#include "freewar.h"

int	move_clients_to_players(t_engine *e, t_game_param *game_param)
{
  int	i;
  t_tmp	*list;

  i = 1;
  for (list = cnt->newclient; list; list = list->next)
    {
      cnt->clients = (t_client*)xrealloc(cnt->clients, sizeof(*cnt->clients) *
					 i + 2);
      if (!list->state)
	memcpy(&cnt->clients[i], &list->c, sizeof(list->c));
      i++;
    }
  init_client(&cnt->clients[i]);
  return (0);
}
