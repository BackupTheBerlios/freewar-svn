#include "freewar.h"

void		free_menu(t_info *info)
{
  int			i;
  int			n;

  for (i = 0; i < NB_MENU; i++)
    for (n = 0; n < NB_IMG_MENU; n++)
      SDL_FreeSurface(info->menu[i].img[n]);
}
