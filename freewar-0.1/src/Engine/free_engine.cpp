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
// free.cpp for freewar in /u/ept2/ribas_j/Freewar/src/Graphics
// 
// Made by jonathan ribas
// Login   <ribas_j@epita.fr>
// 
// Started on  Mon Jun 14 15:16:56 2004 jonathan ribas
// Last update Mon Jun 14 15:19:43 2004 jonathan ribas
//

#include "freewar.h"

int		free_engine(t_engine *e)
{
  int		i;
  
  for (i = 0; i < e->nb_players; i++)
    {
      if (e->meters[i])
	free (e->meters[i]);
    }
  if (e->meters)
    free(e->meters);
  // rajouter les autres free plus tards .
  return (0);
}
