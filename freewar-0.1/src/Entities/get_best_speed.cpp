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
// get_best_speed.cpp for freewar in /root/Freewar/src/Actions
// 
// Made by 
// Login   <root@epita.fr>
// 
// Started on  Wed Jul 14 17:14:57 2004 
// Last update Wed Jul 14 17:14:59 2004 
//

#include "freewar.h"

int	get_best_speed(t_engine *e, t_entity *t)
{
  float	coef;
  int	speed;

  coef = get_best_speed_factor(e, t);
  if (coef != 0.0)
    speed = (int)(t->data->actions.move_speed * (float)coef);
  else
    speed = -1;
  return (speed);
}
