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
// unpack.cpp for freewar in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Sat May 15 19:24:19 2004 jonathan huot
// Last update Sat Jun 26 19:29:06 2004 jonathan huot
//

#include "freewar.h"

int		unpack_sprite(char *s)
{
  int		ret;

  if (!s)
    return (-1);
  if ((ret = create_sprite(s)) < 0)
    put_error("Warning, sprite can't be loaded");
  return (ret);
}

int		unpack_taunt(char *s)
{
  if (s)
    put_error("Warning, taunt is not implemented");
  return (0);
}
