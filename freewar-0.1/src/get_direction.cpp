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
// get_direction.cpp for freewar in /root/Freewar/src
// 
// Made by 
// Login   <root@epita.fr>
// 
// Started on  Mon Jun 28 12:51:25 2004 
// Last update Tue Jun 29 18:38:55 2004 jonathan huot
//

#include "freewar.h"

#define DIRECTION_UP		(0)
#define DIRECTION_UP_RIGHT	(2)
#define DIRECTION_RIGHT		(4)
#define DIRECTION_DOWN_RIGHT	(6)
#define DIRECTION_DOWN		(8)
#define DIRECTION_DOWN_LEFT	(10)
#define DIRECTION_LEFT		(12)
#define DIRECTION_UP_LEFT	(14)

int		get_direction(int def, t_coord *src, t_coord *dst)
{
  if (src->x == dst->x && src->y > dst->y)
    return (DIRECTION_UP);
  else if (src->x < dst->x && src->y > dst->y)
    return (DIRECTION_UP_RIGHT);
  else if (src->x < dst->x && src->y == dst->y)
    return (DIRECTION_RIGHT);
  else if (src->x < dst->x && src->y < dst->y)
    return (DIRECTION_DOWN_RIGHT);
  else if (src->x == dst->x && src->y < dst->y)
    return (DIRECTION_DOWN);
  else if (src->x > dst->x && src->y < dst->y)
    return (DIRECTION_DOWN_LEFT);
  else if (src->x > dst->x && src->y == dst->y)
    return (DIRECTION_LEFT);
  else if (src->x > dst->x && src->y > dst->y)
    return (DIRECTION_UP_LEFT);
  return (def);
  //fprintf(fd_log, "ERROR: get_direction coder avec les pieds\n");
  //return (-1);
}
