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
#include "freewar.h"

void		preload_menu(t_info *info)
{
  info->menu[0].x = 440;
  info->menu[0].y = 380;
  info->menu[0].w = 200;
  info->menu[0].h = 100;
  info->menu[0].img_name[0] = "img/exit_unselect.bmp";
  info->menu[0].img_name[1] = "img/exit_over.bmp";
  info->menu[0].img_name[2] = "img/exit_select.bmp";
  info->menu[0].select = menu_exit;
  info->menu[1].x = 440;
  info->menu[1].y = 180;
  info->menu[1].w = 200;
  info->menu[1].h = 100;
  info->menu[1].img_name[0] = "img/play_unselect.bmp";
  info->menu[1].img_name[1] = "img/play_over.bmp";
  info->menu[1].img_name[2] = "img/play_select.bmp";
  info->menu[1].select = menu_play;
  info->menu[2].x = 440;
  info->menu[2].y = 280;
  info->menu[2].w = 200;
  info->menu[2].h = 100;
  info->menu[2].img_name[0] = "img/options_unselect.bmp";
  info->menu[2].img_name[1] = "img/options_over.bmp";
  info->menu[2].img_name[2] = "img/options_select.bmp";
  info->menu[2].select = menu_options;
}
/*
//   info->menu[NB_MENU] =
//     {
//       {200, 200, 200, 100,
//        {"img/exit_unselect.bmp",
// 	"img/exit_over.bmp",
// 	"img/exit_select.bmp"},
//        menu_exit,
//        {0, 0, 0}},
//       {0, 0, 200, 100,
//        {"img/play_unselect.bmp",
// 	"img/play_over.bmp",
// 	"img/play_select.bmp"},
//        menu_exit,
//        {0, 0, 0}}
//     };
*/
