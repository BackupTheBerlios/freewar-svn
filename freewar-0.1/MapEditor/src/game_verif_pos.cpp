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

void		game_verif_pos(t_info *info)
{ 
  info->game.pos_x += info->game.keyleft +
    info->game.keyright + info->game.mousehoriz;
  info->game.pos_y += info->game.keyup +
    info->game.keydown + info->game.mouseverti;
  if (info->game.pos_x < 0)
    info->game.pos_x = 0;
  else if (info->game.pos_x >
	   (info->data.w * CASE_SIZE_X) - info->mysdl.screen->w)
    info->game.pos_x = (info->data.w * CASE_SIZE_X) - info->mysdl.screen->w;
  if (info->game.pos_y < 0)
    info->game.pos_y = 0;
  else if (info->game.pos_y >
	   (info->data.h * CASE_SIZE_Y) - info->mysdl.screen->h)
    info->game.pos_y = (info->data.h * CASE_SIZE_Y) - info->mysdl.screen->h;
}
