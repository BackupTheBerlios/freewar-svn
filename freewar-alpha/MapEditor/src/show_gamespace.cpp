#include "freewar.h"

Err		show_gamespace(t_info *info)
{
  xSDL_BlitSurface(info->game.gamespace, NULL,
		  info->mysdl.screen, NULL);
  SDL_Flip(info->mysdl.screen);
  return (0);
}
