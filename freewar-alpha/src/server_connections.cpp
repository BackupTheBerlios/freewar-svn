//
// server_connections.cpp for freewar in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Fri May  7 13:39:27 2004 jonathan huot
// Last update Sun May 16 11:14:40 2004 jonathan huot
//

#include "freewar.h"

int		server_connections(t_game_param *game_param)
{
//   static int	nb_connects = 0;
//   static int	time = 0;

//   if (!nb_connects)
//     {
//       nb_connects = connections->nb_clients;
//       // un nouveau joueur est entrer dans la partie.
//       if (listen_and_init_one_connection(connections))
// 	return (1);
//       time = SDL_GetTicks();
//     }
//   if (nb_connects < connections->nb_clients)
//     {
//       t_trame	req;

//       if (recv_trame(connections, connections->newclient, &req))
// 	{
// 	  if (play_is_full(connections))
// 	    return (kick_last_player(connections));
// 	  else if (!check_hash5_db_valide()) //va verifier le nom puis le md5
// 	    {
// 	      if (!is_valid_trame(&req, TAG_JOIN))
// 		return (put_error("Incomprehension"));
// 	      add_player(game_param, pos, connections, &req);
// 	      send_db_to_player(connections); //dans un premier temps, non implementer.
// 	      nb_connects = 0;
// 	    }
// 	}
//       else if (time + NET_TIMEOUT_NEWCLIENT > (int)SDL_GetTicks())
// 	{
// 	  nb_connects = 0;
// 	  drop_client(connections, nb_connects);
// 	}
//     }
//   else
//     nb_connects = 0;
  return (0);
}
