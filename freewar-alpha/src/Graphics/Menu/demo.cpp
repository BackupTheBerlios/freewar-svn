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
  //  SDL_Delay(2000);
  win->alpha = 0;
  win->delta_alpha = 7;
  win->img = IMG_Load("AFirstChaos/img/menu/freewar_logo.png");
  if (launch_logo(win, 300, 250, 30))
    {
      puts("erreur lors du lancement du logo\n");
      return(1);
    }
  win->img = IMG_Load("AFirstChaos/img/menu/texte.png");
  if (launch_logo(win, 220, 400, 30))
    {
      puts("erreur lors du lancement du logo\n");
      return(1);
    }
  return(0);
}
