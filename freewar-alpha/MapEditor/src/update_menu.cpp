#include "freewar.h"

Err		update_menu(t_info *info)
{
  int		i;

  for (i = 0; i < NB_MENU; i++)
    display_menu(info, &(info->menu[i]), IMG_MENU_UNSELECT);
  display_menu(info, &(info->menu[info->menu_over]), IMG_MENU_OVER);
  SDL_Flip(info->mysdl.screen);
  return (0);
}
