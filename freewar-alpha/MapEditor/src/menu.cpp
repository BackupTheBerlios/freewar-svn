#include "freewar.h"

Err			menu(t_info *info)
{
  preload_menu(info);
  load_menu(info);
  info->exit = 0;
  info->menu_over = 0;
  while (!info->exit)
    {
      SDL_Delay(10);
      while (SDL_PollEvent(&(info->mysdl.event)))
	{
	  if (info->mysdl.event.type == SDL_MOUSEMOTION)
	    menu_mousemotion(info, info->mysdl.event);
	  else if (info->mysdl.event.type == SDL_MOUSEBUTTONDOWN)
	    menu_mousebutton(info, info->mysdl.event);
	  else if (info->mysdl.event.type == SDL_KEYDOWN)
	    menu_key(info, info->mysdl.event);
	  else if (info->mysdl.event.type == SDL_VIDEORESIZE)
	    {
	      resize_window(info, info->mysdl.event.resize.w,
			    info->mysdl.event.resize.h);
	      update_menu(info);
	    }
	  else if (info->mysdl.event.type == SDL_QUIT)
	    info->exit = 1;
	    break;
	}
    }
  free_menu(info);
  SDL_Quit();
  return (0);
}
