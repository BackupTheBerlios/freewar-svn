#include "freewar.h"

Err		menu_key_move(t_info *info, SDL_Event e)
{
  display_menu(info, &(info->menu[info->menu_over]), IMG_MENU_UNSELECT);
  if (e.key.keysym.sym == SDLK_UP ||
      e.key.keysym.sym == SDLK_LEFT)
    {
      if (info->menu_over > 0)
	info->menu_over--;
      else
	info->menu_over = NB_MENU - 1;
    }
  else if (e.key.keysym.sym == SDLK_DOWN ||
	   e.key.keysym.sym == SDLK_RIGHT)
    {
      if (info->menu_over < NB_MENU - 1)
	info->menu_over++;
      else
	info->menu_over = 0;
    }
  display_menu(info, &(info->menu[info->menu_over]), IMG_MENU_OVER);
  return (0);
}

Err		menu_key(t_info *info, SDL_Event e)
{
  Err		err;

  err = 0;
  if (e.key.keysym.sym == SDLK_ESCAPE)
    info->exit = 1;
  else if (e.key.keysym.sym == SDLK_RETURN)
    err = info->menu[info->menu_over].select(info);
  else
    err = menu_key_move(info, e);
  return (err);
}
