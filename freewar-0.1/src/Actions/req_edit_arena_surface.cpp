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

int		req_edit_arena_surface(t_engine *e, t_trame *trame,
				       int player)
{
  if (player)
    return (0);
  memcpy(&e->g.pos_arena, trame->msg, sizeof(e->g.pos_arena));
  memcpy(&e->g.off_arena, trame->msg + sizeof(e->g.pos_arena),
	 sizeof(e->g.off_arena));
  if (e->g.pos_arena.x < 0)
    e->g.pos_arena.x = 0;
  else if (e->g.pos_arena.x + e->g.w_main >= e->map_data.w)
    {
      e->g.pos_arena.x = e->map_data.w - e->g.w_main - 
	((e->g.offw_main) ? (1) : (0));
      e->g.off_arena.x = e->g.offw_main;
    }
  else if (e->g.pos_arena.x + e->g.w_main >= e->map_data.w - 1 &&
	   e->g.off_arena.x >= e->g.offw_main)
    {
      e->g.pos_arena.x = e->map_data.w - e->g.w_main -
	((e->g.offw_main) ? (2) : (1));
      e->g.off_arena.x = e->g.offw_main - 1;
    }
  if (e->g.pos_arena.y < 0)
    e->g.pos_arena.y = 0;
  else if (e->g.pos_arena.y + e->g.h_main >= e->map_data.h)
    {
      e->g.pos_arena.y = e->map_data.h - e->g.h_main - 
	((e->g.offh_main) ? (1) : (0));
      e->g.off_arena.y = e->g.offh_main;
    }
  else if (e->g.pos_arena.y + e->g.h_main >= e->map_data.h - 1 &&
	   e->g.off_arena.y >= e->g.offh_main)
    {
      e->g.pos_arena.y = e->map_data.h - e->g.h_main -
	((e->g.offh_main) ? (2) : (1));
      e->g.off_arena.y = e->g.offh_main - 1;
    }
  return (0);
}

int		req_edit_arena_surface(t_engine *e, t_coord *pos,
							   t_coord *off)
{
  e->g.pos_arena.x = pos->x;
  e->g.off_arena.x = pos->x;
  e->g.pos_arena.x = pos->x;
  e->g.off_arena.x = pos->y;
  if (e->g.pos_arena.x < 0)
    e->g.pos_arena.x = 0;
  else if (e->g.pos_arena.x + e->g.w_main >= e->map_data.w)
    {
      e->g.pos_arena.x = e->map_data.w - e->g.w_main - 
	((e->g.offw_main) ? (1) : (0));
      e->g.off_arena.x = e->g.offw_main;
    }
  else if (e->g.pos_arena.x + e->g.w_main >= e->map_data.w - 1 &&
	   e->g.off_arena.x >= e->g.offw_main)
    {
      e->g.pos_arena.x = e->map_data.w - e->g.w_main -
	((e->g.offw_main) ? (2) : (1));
      e->g.off_arena.x = e->g.offw_main - 1;
    }
  if (e->g.pos_arena.y < 0)
    e->g.pos_arena.y = 0;
  else if (e->g.pos_arena.y + e->g.h_main >= e->map_data.h)
    {
      e->g.pos_arena.y = e->map_data.h - e->g.h_main - 
	((e->g.offh_main) ? (1) : (0));
      e->g.off_arena.y = e->g.offh_main;
    }
  else if (e->g.pos_arena.y + e->g.h_main >= e->map_data.h - 1 &&
	   e->g.off_arena.y >= e->g.offh_main)
    {
      e->g.pos_arena.y = e->map_data.h - e->g.h_main -
	((e->g.offh_main) ? (2) : (1));
      e->g.off_arena.y = e->g.offh_main - 1;
    }
  return (0);
}
