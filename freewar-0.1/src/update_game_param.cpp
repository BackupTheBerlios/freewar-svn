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
// update_game_param.cpp for freewar in /u/ept2/ribas_j/freewar/src
// 
// Made by jonathan ribas
// Login   <ribas_j@epita.fr>
// 
// Started on  Mon May  3 13:41:52 2004 jonathan ribas
// Last update Thu May  6 19:27:55 2004 jonathan huot
//

#include "freewar.h"

int		update_game_param(t_trame *req, t_game_param *game_params)
{
  int		no;

  // fonction qui va regarder la requete, et les connection, et
  // modifier en consequence la structure game_params !
  if (req->tag == TAG_GP_PLAYERS)
    {
      if ((sizeof(no) + sizeof(*game_params->players)) != req->len)
	return (put_error("Incomprehension client/server"));
      memcpy((void*)(&no), req->msg, sizeof(no));
      memcpy((void*)(&(game_params->players[no])), req->msg + sizeof(no),
	     sizeof(*game_params->players));
    }
  /*else if (req->tag == TAG_LEAVE)
    {
      if (sizeof(no) != req->len)
	return (put_error("Incomprehension client/server2"));
      no = req->value;
      game_params->players[
    }*/
  return (0);
}
