//
// demo.cpp for freewar in /u/ept2/skondr_m
// 
// Made by mael skondras
// Login   <skondr_m@epita.fr>
// 
// Started on  Tue May 11 18:47:40 2004 mael skondras
// Last update Tue May 25 17:36:39 2004 stephane petitcolas
//

#include "freewar.h"

int	demo(t_display *win)
{
  int	logo_h;

  win->alpha = 0;
  win->delta_alpha = 7;
  win->img = IMG_Load("AFirstChaos/img/menu/freewar_logo.png");
  logo_h = win->img->h;
  if (launch_logo(win, (win->res_w - win->img->w) / 2,
		  (win->res_h - win->img->h) / 2, 60))
  {
	  puts("erreur lors du lancement du logo\n");
      return(1);
  }
  win->text = load_string("A First Chaos ...", FONT, 42);
  if (!win->text)
  {
	fprintf(fd_log, "Error loading font..\n");
	exit(1);
  }
  win->dest.x = (win->res_w - win->text->w) / 2;
  win->dest.y = (win->res_h - win->text->h) / 2 + logo_h + 42;
  aff_surf(win->text, 255);
  SDL_FreeSurface(win->text);
  return(0);
}
