#include "freewar.h"

int		init_player(t_player *player)
{
  player->type = TYPE_HUMAN;
  strcpy(player->name, PLAYER_NAME_DEFAULT);
  player->color = 0xFFFF00FF;
  player->race = 0;
  player->team = -1;
  return (0);
}

int				init_players_for_game(t_engine *e, int who)
{
  t_tmp			*list;
  t_tmp			*next;
  int			i;
  t_info_player	info_player;

  e->assos_clients[0] = 0;
  info_player.id_player = 0;
  stock_msg(&(cnt->clients[0]), TAG_PLAYER_INFO,
		sizeof(info_player), &info_player);
  init_player(&e->players[0]);
  i = 1;
  if (who == HOME)
    {
	  //while (i < 2)
	  //{
		  check_select(1000);
		  for (list = cnt->newclient; list; list = next)
 		  {
 			next = list->next;
 			//if (list->state == STATE_PLAYER)
 			//{
 				cnt->clients =
 				(t_client*)xrealloc(cnt->clients, sizeof(*cnt->clients) * (i + 2));
 				memcpy(&cnt->clients[i], &list->c, sizeof(list->c));
				e->assos_clients[i] = i;
				info_player.id_player = i;
				stock_msg(&(cnt->clients[i]), TAG_PLAYER_INFO,
					sizeof(info_player), &info_player);
				fprintf(fd_log, "find one client\n");
 				cnt->newclient = del_in_list(cnt->newclient,
 											&list->c);
 				i++;
 			//}
 		  }
	      init_client(&cnt->clients[i]);
	  //}
    }
  e->nb_players = i;
  return (0);
}
