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
// get_and_init_sound.cpp for freewar in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Fri May  7 18:26:54 2004 jonathan huot
// Last update Fri May  7 19:04:07 2004 jonathan huot
//

#include "freewar.h"

int		update_sound_param(t_trame *req, t_cfg *cfg)
{
  int		param[2];

  if (req->len != sizeof(int) * 2)
    return (put_error("size missmatch of trame for change cfg."));
  memcpy((void*)param, req->msg, req->len);
  cfg->Sound[0] = param[0];
  cfg->Sound[1] = param[1];
  return (0);
}

int		get_and_init_sound(t_cfg *cfg)
{
  t_trame	*req = 0;
  int		open;
  int		lock_cfg;
  
  return (0);
  lock_cfg = 0;
  open = 0;
  // TODO: a mettre dans handlers (et appeler check_select)
//   recv_client_req(&cnt->clients[0], req);
//   while (is_valid_trame(req, TAG_INIT_SOUND_DONE))
//     {
//       if (!lock_cfg && is_valid_trame(req, TAG_INIT_SOUND_NEWS_PARAM))
// 	update_sound_param(req, cfg);
//       else if (open == 0 && is_valid_trame(req, TAG_INIT_SOUND_OPEN_DEVICE))
// 	{
// 	  //open_device();
// 	  lock_cfg = 1;
// 	  open = 1;
// 	}
//       // else if (is_valid_trame(req, TAG_INIT_SOUND_))
// // 	; autres ...
// #ifdef FW_DEBUG
//       else
// 	put_error("trame loss from local game in get_and_init_sound");
// #endif
//       recv_client_req(&cnt->clients[0], req);
//     }
	return (0);
}
