#include "freewar.h"

int		open_windows(t_engine *engine, t_db_info *db,
			     t_cfg *cfg)
{
  return (create_and_open_screen(cfg->Screen[0], cfg->Screen[1], cfg->Mode,
				 SDL_SWSURFACE));
				 //SDL_HWSURFACE|SDL_DOUBLEBUF));
}
