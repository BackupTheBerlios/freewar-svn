#include "freewar.h"

Err		game_key_move(t_info *info, SDL_Event e)
{
  if (e.key.keysym.sym == SDLK_UP)
    info->game.keyup = -SCROLL_STEP;
  else if (e.key.keysym.sym == SDLK_LEFT)
    info->game.keyleft = -SCROLL_STEP;
  else if (e.key.keysym.sym == SDLK_DOWN)
    info->game.keydown = SCROLL_STEP;
  else if (e.key.keysym.sym == SDLK_RIGHT)
    info->game.keyright = SCROLL_STEP;
  else
    return (0);
  return (update_gamespace(info));
}

Err		game_key(t_info *info, SDL_Event e)
{
  Err		err;
  int		i;

  err = 0;
  if (e.key.keysym.sym == SDLK_ESCAPE)
    info->game.exit = 1;
  else if (e.type == SDL_KEYDOWN)
    err = game_key_move(info, e);
  else if (e.type == SDL_KEYUP)
    {
      if (e.key.keysym.sym == SDLK_UP)
	info->game.keyup = 0;
      else if (e.key.keysym.sym == SDLK_DOWN)
	info->game.keydown = 0;
      else if (e.key.keysym.sym == SDLK_LEFT)
	info->game.keyleft = 0;
      else if (e.key.keysym.sym == SDLK_RIGHT)
	info->game.keyright = 0;
      else if (e.key.keysym.sym == SDLK_s)
	save_map(info);
      else
	for (i = 0; i < NB_ITEMS; i++)
	  if (e.key.keysym.sym == gl_items[i].key)
	    info->selection = gl_items[i].id;
    }
  return (err);
}
