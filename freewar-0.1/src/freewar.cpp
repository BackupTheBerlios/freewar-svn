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
// freewar.cpp for freewar in /u/ept2/huot_j/Freewar/src/Network
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Thu May  6 14:15:10 2004 jonathan huot
// Last update Thu Jul  1 17:38:33 2004 jonathan huot
//

#include "freewar.h"

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
  if (get_cfg(cfg))
    return (1);
  if (load_db_init(db_info, cfg))
     return (1);
  init_engine(engine);
  if (open_windows(engine, db_info, cfg))
    return (1);
  if (launch_demo())
    return (1);
  engine->nb_players = 1;
  // attente du menu qui decide du type de partie (avec qui, etc..)
  if ((ret = before_starting_game(game_param)) != ERROR)
    {
      if (ret == HOME || ret == REMOTE)
	{
	  if (init_global_game(engine, game_param, cfg, ret))
	    return (1);
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
    }
  close_connection();
  SDLNet_Quit();
  SDL_Quit();
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
