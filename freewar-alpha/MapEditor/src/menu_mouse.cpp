#include "freewar.h"

Err		menu_mousemotion(t_info *info, SDL_Event e)
{
  int		i;

  for (i = 0; i < NB_MENU; i++)
    {
      if (info->menu_over != i &&
	  e.motion.x >= info->menu[i].x &&
	  e.motion.x <= (info->menu[i].x + info->menu[i].w) &&
	  e.motion.y >= info->menu[i].y &&
	  e.motion.y <= (info->menu[i].y + info->menu[i].h))
	{
	  display_menu(info, &(info->menu[i]), IMG_MENU_OVER);
	  display_menu(info, &(info->menu[info->menu_over]), IMG_MENU_UNSELECT);
	  info->menu_over = i;
	  break;
	}
    }
  return (0);
}

Err		menu_mousebutton(t_info *info, SDL_Event e)
{
  int		i;

  if (e.button.button == SDL_BUTTON_LEFT)
    for (i = 0; i < NB_MENU; i++)
      {
	if (e.button.x >= info->menu[i].x &&
	    e.button.x <= (info->menu[i].x + info->menu[i].w) &&
	    e.button.y >= info->menu[i].y &&
	    e.button.y <= (info->menu[i].y + info->menu[i].h))
	  {
	    display_menu(info, &(info->menu[i]), IMG_MENU_SELECT);
	    display_menu(info, &(info->menu[info->menu_over]), IMG_MENU_UNSELECT);
	    info->menu_over = i;
	    info->menu[i].select(info);
	    break;
	  }
      }
  return (0);
}
