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
// find_entity.cpp for freewar in /u/ept2/ribas_j/Freewar/src
// 
// Made by jonathan ribas
// Login   <ribas_j@epita.fr>
// 
// Started on  Fri May 28 13:36:32 2004 jonathan ribas
// Last update Mon Jul 12 17:57:57 2004 
//

#include "freewar.h"

t_entity	*find_entity(t_engine *e, unsigned long id)
{
  t_entity	*t;

  for (t = e->entity; t; t = t->next)
    {
      if (t->id == id)
	return (t);
    }
  return (0);
}
