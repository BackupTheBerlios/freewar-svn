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

int		wait_all_player_is_ready(t_engine *e);
int		engine_server(t_engine *e, t_cfg *cfg,
			      t_game_param *game_param)
{
  fflush(fd_log);
  // initialise en fonction des demandes du jeu:
  // v
//   get_and_init_display(cfg, g);
//   get_and_init_sound(cfg);
  // ^
  wait_all_player_is_ready(e);
  init_entities(e, game_param);
  reset_timer(e);
  while (69)
    {
      // TODO: modifier la lib network pour ajouter des handlers de fct.
      // Ca aura pour but d'integrer l'execution de manage_requests dans
      // check_select.. (optimisation) 
      // TODOupdate: c'est mainteannt dans process.c
      if (check_select(100))
	;
      // si un player n'a plu d'entitees en vie .. il meur X)
      manage_player();
#ifdef GRAPHICS_TIME
      Uint32 ticks=SDL_GetTicks();
#endif
      if (get_events(e))
	return (1);
      aff_game(e, &e->g);

      if (timer_wait(e))
	{
	  /*
	    - gestion des entitees, boucle qui 
	    va faire toutes les actions necessaires ..
	    mouvements, attaques, construction etc ..
	  */
	  manage_entities(e, game_param);
#ifdef GRAPHICS_TIME
	  //printf("aff_game TOTAL: %d\n---------\n", SDL_GetTicks() - ticks);
	  put_error("aff_game\n---------\n");
#endif
	  /*
	    - une boucle pour donner les elements 
	    necessaire a l'affichage pour chaque joueurs.
	  */
	  play_sound();
	  /*
	    - une boucle pour envoyer l'ordre 
	    des sons a jouer a tous les joueurs.
	  */
	  reset_timer(e);
    	}
      // synchro_players(); apriori, non necessaire
    }  
  return (0);
}
