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

#include "freewar.h"

// le curseur de la souris est considéré comme une entitée ordinaire

int		aff_mouse(t_engine *e)
{
  Uint8		ret;
  int		x;
  int		y;
  static int	sprite = 0;
  static int	entity = 0;
  static int	sprite_targ = 0;
  static int	entity_targ = 0;
  t_coord	pos;
  t_req_info_scale	*req_info_scale;
  t_game_info_scale	game_info_scale;

  ret = SDL_GetMouseState(&x, &y);

  pos.x = x + e->g.pos_arena.x * CASE_SIZE_X + e->g.off_arena.x;
  pos.y = y + e->g.pos_arena.y * CASE_SIZE_Y + e->g.off_arena.y;

  if (!sprite)
    {
      if ((sprite = create_sprite("img/freewar_cursor.png")) < 0)
	return (0);
      if ((sprite_targ = create_sprite("img/freewar_cursor_target.png")) < 0)
	return (0);
      if ((entity = create_gfx_entity(sprite)) < 0)
	return (0);
      if ((entity_targ = create_gfx_entity(sprite_targ)) < 0)
	return (0);
      SDL_ShowCursor(SDL_DISABLE);
    }

  game_info_scale.pos.x = pos.x / CASE_SIZE_X;
  game_info_scale.pos.y = pos.y / CASE_SIZE_Y;
  game_info_scale.off.x = pos.x % CASE_SIZE_X;
  game_info_scale.off.y = pos.y % CASE_SIZE_Y;
  req_info_scale = info_scale(e, &game_info_scale);

  if (req_info_scale->nb_ent > 0)
    {
      edit_entity_on_surface(entity, e->g.arena_select, 0, 0, 0);
      edit_entity_on_surface(entity_targ, e->g.arena_select, pos.x - 16, pos.y - 16, 255);
    }
  else
    {
      edit_entity_on_surface(entity, e->g.arena_select, pos.x, pos.y, 255);
      edit_entity_on_surface(entity_targ, e->g.arena_select, 0, 0, 0);
    }

  return (0);
}
