#include "freewar.h"

extern t_gfx	*gfx;

void		tmp_init(t_engine *e, t_cfg *cfg, t_game *g)
{
  int		sc;
  int		i;

  fprintf(fd_log, "tmp_init start\n");
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
  sc = create_sprite("img/hud_sc.png");
  sc = create_gfx_entity(sc);
  edit_entity_on_surface(sc, e->g.hud, 0, cfg->Screen[1] -
	  165, 255);
  printf("HUD Loaded %d %d, %d, %d\n", cfg->Screen[0], cfg->Screen[1],
	  cfg->Mode, 1);fflush(stdout);
}

int		init_global_game(t_engine *e, t_game_param *gp,
				 t_cfg *cfg, int type)
{
  //initialise et remplit les structures necessaire
  //map y compris
  if (load_db_data(e, gp, cfg))
    return (1);
  tmp_init(e, cfg, &e->g);// TODO: une horreur a changer
//   init_players_for_game(e, type);// TODO: a adapter
  // charge la map
  if (load_map_data(e, gp->id_map))
    return (put_error("Load map failed"));
  if (load_map(e))
    return (put_error("Load map failed."));
  return (0);
}
