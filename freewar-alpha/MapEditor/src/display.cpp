#include "freewar.h"

void		display_menu(t_info *info, t_menu *menu, int nb)
{
  SDL_Rect	dest;

  dest.x = menu->x;
  dest.y = menu->y;
  dest.w = menu->w;
  dest.h = menu->h;
  xSDL_BlitSurface(menu->img[nb], NULL, info->mysdl.screen, &dest);
  SDL_UpdateRect(info->mysdl.screen, menu->x, menu->y, menu->w, menu->h);
}
