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
// erase_entity.cpp for freewar in /root/Freewar/src/Actions
// 
// Made by 
// Login   <root@epita.fr>
// 
// Started on  Wed Jul 14 11:33:18 2004 
// Last update Wed Jul 14 11:33:19 2004 
//

#include "freewar.h"

int		erase_entity(t_engine *e, t_entity *t)
{
  del_next_actions(e, t);
  del_empty_selection(e, t);
  destroy_gfx_entity(t->idgfx);
  del_entity_on_all_actions(e, t);
  if (del_entity_in_map(e, t))
    {
      fprintf(fd_log, " /!\\ ERROR: del_entity failed\n");
      free(t);
      return (1);
    }
  free(t);
  return (0);
}
