#include "freewar.h"

Err		load_gamespace(t_info *info)
{
  info->game.gamespace = SDL_DisplayFormatAlpha(info->mysdl.screen);
  if (!info->game.gamespace)
    {
      put_error(SDL_GetError());
      exit(1);
    }
  info->game.pos_x = 0;
  info->game.pos_y = 0;
  return (update_gamespace(info));
}

Err		load_game(t_info *info)
{
  int		i;

  info->selection = DEFAULT_ID;
  info->game.keyshift = 0;
  info->game.keydown = 0;
  info->game.keyup = 0;
  info->game.keyleft = 0;
  info->game.keyright = 0;
  info->game.mousehoriz = 0;
  info->game.mouseverti = 0;
  info->game.exit = 0;
  for (i = 0; i < NB_ITEMS; i++)
    if (gl_items[i].path)
      load_bmp(&(info->img[i]), gl_items[i].path);
    else
      info->img[i] = 0;
  if ((i = init_map(info, info->file)))
    return (i);
  return (load_gamespace(info));
}
