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
      if (check_select(100))
	{
	  manage_requests(e);
      /*
	une boucle pour gerer toutes les requettes de tous les players
	et d'y repondre. (yaura un max qd meme)
      */
	}
      /*
	- gestion des entitees, boucle qui 
	va faire toutes les actions necessaires ..
	mouvements, attaques, construction etc ..
      */
      manage_player();
      /*
	si un player n'a plu d'entitees en vie .. il meur X)
      */
#ifdef GRAPHICS_TIME
      Uint32 ticks=SDL_GetTicks();
#endif
      if (timer_wait(e))
	{
	  manage_entities(e, game_param);
	  if (get_events(e))
	    return (1);
	  aff_game(e, &e->g);
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
      // synchro players(); apriori, non necessaire
    }  
  return (0);
}
