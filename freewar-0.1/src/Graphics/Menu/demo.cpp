// Copyright (C) 2004 Freewar Team <doomsday@freewar.net>

// This file is part of Freewar.

// Freewar is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.

// Freewar is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with Freewar; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
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
