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

Err		game_mousemotion(t_info *info, SDL_Event e)
{
  // souris a gauche
  if (e.motion.x <= info->mysdl.screen->w - (info->mysdl.screen->w / 10) * 9)
    info->game.mousehoriz = -SCROLL_STEP;
  // souris a droite
  else if (e.motion.x >= info->mysdl.screen->w - info->mysdl.screen->w / 10)
    info->game.mousehoriz = SCROLL_STEP;
  else
    info->game.mousehoriz = 0;
  // souris en haut
  if (e.motion.y <= info->mysdl.screen->h - (info->mysdl.screen->h / 10) * 9)
    info->game.mouseverti = -SCROLL_STEP;
  // souris en bas
  else if (e.motion.y >= info->mysdl.screen->h - info->mysdl.screen->h / 10)
    info->game.mouseverti = SCROLL_STEP;
  else
    info->game.mouseverti = 0;
  return (update_gamespace(info));
}

Err			game_mousebutton(t_info *info, SDL_Event e)
{
  unsigned short	x;
  unsigned short	y;

  x = (e.button.x + info->game.pos_x) / CASE_SIZE_X;
  y = (e.button.y + info->game.pos_y) / CASE_SIZE_Y;
  if (get_land(info->selection) == true)
    info->data.data[y][x].land = info->selection;
  else
    info->data.data[y][x].item = info->selection;
  return (0);
}
