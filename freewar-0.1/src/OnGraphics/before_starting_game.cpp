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
// before_starting_game.cpp for freewar in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Fri May  7 13:37:58 2004 jonathan huot
// Last update Sun Jul 11 18:08:36 2004 
//

#include "freewar.h"

extern t_gfx	*gfx;
int		init_server_connection(t_trame *req);
int		server_connections(t_game_param *gp);

int		before_starting_game(t_game_param *game_param)//t_engine *e, t_game_param *game_param)
{
  t_trame	*req;
  int		who_serve;
  int		send;
  int		update_param;

//   //considere que le jeu cree une partie tout seul:
//   printf("before start\n");
//   fflush(fd_log);
  return (HOME);
  // TODO: TOUT ca a revoir une fois l'interface du menu defini:
  fprintf(fd_log, "Loading menu...\n");
  if (run_menu(gfx->win))
    {
      fprintf(fd_log, "%s: Quitting game...\n", NAME);
      return (ERROR);
    }
  req = (t_trame*)xmalloc(sizeof(*req));
  for (who_serve = NONE, send = 0, update_param = 0;
       42; send = 0, update_param = 0)
    /* < va gerer les requetes que va envoyer le jeu pour la creation
       de partie jusque a le lancemant de la partie; et les requetes des
       autres moteur.*/
    {
      printf("ESSAI\n");fflush(stdout);
      fflush(fd_log);
      if (check_select(10000))
	{
	  printf("DEDAN\n");fflush(stdout);
	  if (exec_msg(&cnt->clients[0], req))
	    {
	      if (is_valid_trame(req, TAG_JOIN))
		{
		  join_game(req);
// 		  send_hash5_to_server(); // une
		  //if (!ok)              // seule
		  //  upgrade_BDD;        // fois
// 		  get_game_param_from_server(req, game_param);
		  who_serve = REMOTE;
// 		  send_to_all_player_new_game_status(game_param);
		  // ^ envoi au client local les parametre de la partie
		}
	      else if (is_valid_trame(req, TAG_CREATE))
		{
// 		  init_game_param(game_param, req, (t_pos*)&pos);
		  who_serve = HOME;
// 		  send_to_all_player_new_game_status(game_param);
		}
// 	      else if (who_serve && is_valid_trame(req, TAG_LAUNCH_GAME))
// 		return (who_serve);
	      else if (who_serve == HOME)
		//rentre ici quand le jeu est server.
		{
		  /* GERAGE DES CONNECTIONS */
// 		  server_connections(game_param, (t_pos*)&pos);
		  if (is_valid_trame(req, TAG_LAUNCH_GAME))
		    {
		      t_tmp	*list;

		      for (list = cnt->newclient; list; list = list->next)
			stock_msg(&list->c, TAG_LAUNCH_GAME, 0, NULL);
//		      move_clients_to_players(e, game_param);
		      return (who_serve);
		    }
		  /* GERAGE DE LA REQUETE */
// 		  if (update_game_param(req, game_param, pos) ||
		      // va gerer les changements de param
		      // ot_chose()) || //finctions qui va gerer les autres requetes
// 		      send_to_all_player_new_game_status(game_param))
// 		    return (put_error("trame gerage failed"));
		  if (is_valid_trame(req, TAG_LEAVE))
		    who_serve = NONE;
		}
	      else if (who_serve == REMOTE)
		{
		  // verifier que l'on soit tjrs connecter au server
		  if (cnt->server.sock)
		    who_serve = NONE;
// 		  if (cnt->last_recv->sock == cnt->server.sock &&
// 		      is_valid_trame(req, TAG_GAME_STATUS))
// 		    {
// 		      if (copy_game_param(req, game_param))
// 			return (put_error("update_game_param failed"));
// 		    }
// 		  else if (cnt->last_recv->sock == cnt->clients[0].sock &&
// 			   is_valid_trame(req, TAG_GP_PLAYERS))
// 		    {
// 		      if (send_to_all_player_new_game_status(game_param))
// 			return (put_error("send_to_all_player_new_game_status failed"));
// 		    }
		  if (is_valid_trame(req, TAG_LEAVE))
		    who_serve = NONE;
		}
	    }
	  else
	    {
	      t_tmp	*list;
	      
	      printf("DANS LE ELSE\n");fflush(stdout);
	      for (list = cnt->newclient; list; list = list->next)
		{
		  if (exec_msg(&list->c, req))
		    {
		      if (is_valid_trame(req, TAG_JOIN))
			{
			  fprintf(fd_log, "un joueur est la\n");
			  list->state = STATE_PLAYER;
			  return (HOME);
			}
		      else
			fprintf(fd_log, "un nouveau client me parle :%d.. alors qu'il devrait attendre"
				"sagement\n", req->tag);
		    }
		}
	      fprintf(fd_log, "les autres joueurs parlent\n");
	      // d'autres requetes ? (READY...)
	    }
	}
    }
  return (ERROR);
}
