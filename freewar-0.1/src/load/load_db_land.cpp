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
// load_db_land.cpp for freewar in /u/ept2/huot_j/Freewar/src
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Fri May 14 15:31:39 2004 jonathan huot
// Last update Fri Jun  4 19:46:24 2004 jonathan huot
//

#include "freewar.h"

int		db_base_land(t_engine *e, t_db_ind *ind)
{
  int		i;

  if (!xml_next("lands"))
    return (put_error("Not found lands in xml"));
  for (i = 0; i < ind->nb[TYPE_LANDS]; i++)
    {
      if (!xml_next("land"))
	return (put_error("Not enough land with the index table\n"));
      e->db.lands[i].name = xml_getstr("name");
      e->db.lands[i].idmapedit = xml_getint("idmapedit");
      e->db.lands[i].idsprite = unpack_sprite(xml_getstr("sprite"));
      xml_out();
    }
  xml_out();
  return (0);
}
