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
// load_db_armor.cpp for freewar in /u/ept2/huot_j/Freewar/src
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Fri May 14 17:15:49 2004 jonathan huot
// Last update Mon May 17 11:16:47 2004 jonathan huot
//

#include "freewar.h"

int		db_armor(t_engine *e, t_db_ind *ind)
{
  int		i;

  if (!xml_next("armors"))
    return (put_error("Armors not found in xml"));
  for (i = 0; i < ind->nb[TYPE_ARMORS]; i++)
    {
      if (!xml_next("armor"))
	return (put_error("Not enough armor in xml"));
      if (!(e->db.armors[i].name = xml_getstr("name")))
	return (put_error("Armor has no name !"));
      e->db.armors[i].defense = xml_getint("defense");
      if (!xml_next("types"))
	return (put_error("Armor without type was found"));
      e->db.armors[i].allowed = db_get_types(e);
      xml_out();
      xml_out();
    }
  xml_out();
  return (0);
}
