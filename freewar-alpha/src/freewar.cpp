//
// freewar.cpp for freewar in /u/ept2/huot_j/Freewar/src/Network
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Thu May  6 14:15:10 2004 jonathan huot
// Last update Thu Jul  1 17:38:33 2004 jonathan huot
//

#include "freewar.h"

extern t_gfx	*gfx;

void		tmp_init(t_engine *e, t_cfg *cfg, t_game *g)
{
  int		sc;
  int		i;

  fprintf(fd_log, "tmp_init start\n");
  gfx->win->res_h = cfg->Screen[1];
  gfx->win->res_w = cfg->Screen[0];
  gfx->win->redraw = 0;
  init_selection(e);
  init_minimap(e);
  e->gfx_null = create_surface(0, 0, 0, 0, 0);
  e->g.arena_lands = create_surface(cfg->Screen[0], cfg->Screen[1] - 100,
				    2, 0x0, 1);
  e->g.arena_select = create_surface(cfg->Screen[0], cfg->Screen[1] - 100,
				    3, 0x0, 1);
  e->g.arena_units = (int*)xmalloc(sizeof(*e->g.arena_units) *
				   e->db.nb_layers);
  for (i = 0; i < e->db.nb_layers; i++)
    e->g.arena_units[i] = create_surface(cfg->Screen[0], cfg->Screen[1] - 100,
					 4 + i, 0x0, 1);
  e->g.arena_sfx = create_surface(cfg->Screen[0], cfg->Screen[1] - 100,
				  5 + i, 0x0, 1);
  e->g.hud = create_surface(cfg->Screen[0], cfg->Screen[1],
			    6 + i, 0x0, 1);
  e->g.event_ok = 1;
  e->g.w_main = (cfg->Screen[0]) / CASE_SIZE_X;
  e->g.h_main = (cfg->Screen[1] - 100) / CASE_SIZE_Y;
  e->g.offw_main = (cfg->Screen[0]) % CASE_SIZE_X;
  e->g.offh_main = (cfg->Screen[1] - 100) % CASE_SIZE_X;
  e->g.pos_arena.x = 0;
  e->g.pos_arena.y = 1;
  e->g.off_arena.x = 20;
  e->g.off_arena.y = 20;
  for (i = 0; i < e->db.nb_layers; i++)
    edit_surface(e->g.arena_units[i], 0, 0, 1, 255);
  edit_surface(e->g.arena_select, 0, 0, 1, 255);
  edit_surface(e->g.arena_lands, 0, 0, 1, 255);
  edit_surface(e->g.arena_sfx, 0, 0, 1, 255);
  edit_surface(e->g.hud, 0, 0, 1, 255);
  fprintf(fd_log, "initie surf: %d, %d, %d\n", e->g.arena_units,
	  e->g.arena_lands, e->g.arena_select);
  sc = create_sprite("hud_sc.png");
  sc = create_gfx_entity(sc);
  edit_entity_on_surface(sc, e->g.hud, 0, cfg->Screen[1] -
	  165, 255);
  printf("HUD Loaded %d %d, %d, %d\n", cfg->Screen[0], cfg->Screen[1],
	  cfg->Mode, 1);fflush(stdout);
}

int			freewar()
{
  int		ret;
  t_cfg		*cfg;
  t_db_info	*db_info;
  t_game_param	*game_param;
  t_engine	*engine;
#ifndef WIN32
  int		status;
#endif

  cfg = (t_cfg*)xmalloc(sizeof(*cfg));
  db_info = (t_db_info*)xmalloc(sizeof(*db_info));
  game_param = (t_game_param*)xmalloc(sizeof(*game_param));
  engine = (t_engine*)xmalloc(sizeof(*engine));
  if (init_log("debug.log"))
    return (1);
  if (SDL_Init(SDL_INIT_TIMER |
	       SDL_INIT_AUDIO |
	       SDL_INIT_VIDEO) < 0)
    {
      fprintf(fd_log, "SDL_Init: %s\n", SDL_GetError()); 
      return (0);
    }
  atexit(SDL_Quit);
  if (get_cfg(cfg))
    return (1);
  if (load_db_init(db_info, cfg))
     return (1);
  if (init_connection(NET_GAME_PORT))
    return (1);
  if (launch_game(cfg))
    return (1);
  if (open_connection_to_the_game())
    return (1); 
  SDL_Delay(420);
  if (give_info_to_game(db_info))
    return (1);
  engine->nb_players = 1;
  // attente de AFC qui decide du type de partie (avec qui, etc..)
	if ((ret = before_starting_game(game_param)))
    {
      if (ret == HOME || ret == REMOTE)
	{
	  //initialise et remplit les structures necessaire
	  //map y compris
	  init_engine(engine);
	  create_and_open_screen(cfg->Screen[0], cfg->Screen[1], cfg->Mode,
				 SDL_HWSURFACE|SDL_DOUBLEBUF);
	  if (load_db_data(engine, game_param, cfg))
	    return (1);
	  tmp_init(engine, cfg, &engine->g);
	  //initialise et remplit les structures necessaire (db)
	  fprintf(fd_log, "Launching demo\n");
	  if (demo(gfx->win))
	    return (1);
	  fprintf(fd_log, "Finished demo\n");
	  fprintf(fd_log, "Loading menu...\n");
	  //if (run_menu(gfx->win))
	  //  {
	  //    fprintf(fd_log, "%s: Quitting game...\n", NAME);
	  //    return (1);
	  //  }
		if (cnt->host)
		{
			init_connection(cnt->host, NET_GAME_PORT);
			stock_msg(&(cnt->clients[1]), TAG_JOIN, 0, NULL);
			ret = REMOTE;
		}
	  engine->server = ((ret == HOME) ? (true) : (false));
	  init_players_for_game(engine, ret);
	  // charge la map
	  if (load_map_data(engine, game_param->id_map))
	    return (put_error("Load map failed"));
	  if (load_map(engine))
	    return (put_error("Load map failed."));
	}
      if (ret == HOME)
	{
	  //lancement du moteur server
	  if (engine_server(engine, cfg, game_param))
	    return (1);
	}
      else if (ret == REMOTE)
	{
	  //lancement du moteur client
	  if (engine_client(engine, cfg, game_param))
	    return (1);
	}
      else
	return (1); // quit
    }
  close_connection();
  SDLNet_Quit();
  SDL_Quit();
#ifdef WIN32
 CloseHandle(cfg->GamePid.hProcess);
 CloseHandle(cfg->GamePid.hThread);
#else
  if (cfg->GamePid)
    waitpid(cfg->GamePid, &status, 0);
  fprintf(fd_log, "fin de afc ($?: %d)\n", status);
#endif
  close_log();
  free(engine);
  free(game_param);
  free(db_info);
  free(cfg);
  return (0);
}

#ifndef WIN32

int		main(int ac, char **av)
{
  int		err;

  err = freewar();
  printf("ended\n");
  fflush(stdout);
  return (err);
}

#else

/*int _tmain(int argc, _TCHAR* argv[])
{
  return 0;
}*/

#endif
