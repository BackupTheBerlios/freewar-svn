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
// load_img.cpp for freewar in /u/ept2/ribas_j/Freewar/src
// 
// Made by jonathan ribas
// Login   <ribas_j@epita.fr>
// 
// Started on  Thu May 13 11:29:56 2004 jonathan ribas
// Last update Tue Jun 29 18:42:44 2004 jonathan huot
//

#include "freewar.h"

int			load_img(SDL_Surface **img, char *name)
{
  *img = IMG_Load(name);
  if (*img == NULL)
    {
      fprintf(fd_log, "Warning: loading %s failed: %s\n",
	      name, SDL_GetError());
      return (-1);
    }
  return (0);
}
