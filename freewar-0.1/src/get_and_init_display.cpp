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
// get_and_init_display.cpp for freewar in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Fri May  7 16:33:29 2004 jonathan huot
// Last update Fri Jun  4 19:13:00 2004 jonathan huot
//

#include "freewar.h"

int		update_video_param(t_trame *req, t_cfg *cfg)
{
  int		param[3];

  if (req->len != sizeof(int) * 3)
    return (put_error("size missmatch of trame for change cfg"));
  memcpy((void*)param, req->msg, req->len);
  cfg->Screen[0] = param[0];
  cfg->Screen[1] = param[1];
  cfg->Mode = param[2];
  return (0);
}

int		get_and_init_display(t_cfg *cfg)
{
  t_trame	*req = 0;
  int		open;
  int		lock_cfg;

  return (0);
  lock_cfg = 0;
  open = 0;
  //init_display(); ??? aparement pas besoin
//   recv_client_req(&cnt->clients[0], req);
//   while (is_valid_trame(req, TAG_INIT_DISPLAY_DONE))
//     {
//       if (!lock_cfg && is_valid_trame(req, TAG_INIT_DISPLAY_NEWS_PARAM))
// 	update_video_param(req, cfg);
//       else if (open == 0 && is_valid_trame(req, TAG_INIT_DISPLAY_CREATE_AND_OPEN_SCREEN))
// 	{
// 	  // ouvre la fenetre 800x600 en 32bit par ex
// 	  create_and_open_screen(cfg->Screen[0], cfg->Screen[1], cfg->Mode, cfg->Type);
// 	  lock_cfg = 1;
// 	  open = 1;
// 	}
//       else if (open == 1 && is_valid_trame(req, TAG_INIT_DISPLAY_NEW_SURFACE))
// 	{
// 	  // cree une surface avec la profondeur, sa position et sa surface et transparence 0/1
// 	  int	param[4];

// 	  if (req->len != sizeof(int) * 4)
// 	    return (put_error("Sizes mismatchs"));
// 	  memcpy((void*)param, req->msg, sizeof(int) * 4);
// 	  //		 width	     height	depth   color
// 	  create_surface(param[0], param[1], param[2], param[3]);
// 	}
//       else if (open == 1 && is_valid_trame(req, TAG_INIT_DISPLAY_LOAD_SURFACE))
// 	{
// 	  // charge une image dans la surface (ex: HUD)
// 	  ;
// 	}
//       else if (open == 1 && is_valid_trame(req, TAG_INIT_DISPLAY_EDIT_SURFACE))
// 	{
// 	  // modifie la position de la surface (et sa visibilite 0/1)
// 	  int	param[5];

// 	  if (req->len != sizeof(int) * 5)
// 	    return (put_error("Sizes mismatchs."));
// 	  memcpy((void*)param, req->msg, sizeof(int) * 5);
// 	  //	      id_surface    x	      y		show	alpha
// 	  edit_surface(param[0], param[1], param[2], param[3], param[4]);
// 	}
//       // else if (is_valid_trame(req, TAG_INIT_DISPLAY_))
// // 	; autres ...
// #ifdef FW_DEBUG
//       else
// 	put_error("trame loss from local game in get_and_init_display");
// #endif
//       recv_client_req(&cnt->clients[0], req);
//     }
	return (0);
}
