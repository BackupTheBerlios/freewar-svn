#include "freewar.h"

Err			load_menu(t_info *info)
{
  int			i;
  int			n;
  Uint32		color;
  SDL_Rect		dest;

  color = SDL_MapRGB(info->mysdl.screen->format, 0, 0, 0);
  dest.x = 0;
  dest.y = 0;
  dest.w = info->mysdl.screen->w;
  dest.h = info->mysdl.screen->h;
  SDL_FillRect(info->mysdl.screen, &dest, color);
  SDL_Flip(info->mysdl.screen);
  for (i = 0; i < NB_MENU; i++)
    for (n = 0; n < NB_IMG_MENU; n++)
      load_bmp(&(info->menu[i].img[n]), info->menu[i].img_name[n]);
  info->menu_over = 0;
  update_menu(info);
  return (0);
}
