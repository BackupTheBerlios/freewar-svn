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
// load_db_meters.cpp for freewar in /u/ept2/huot_j/Freewar
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Mon May 17 14:20:14 2004 jonathan huot
// Last update Sat Jun 26 19:24:46 2004 jonathan huot
//

#include "freewar.h"

int		db_meters(t_engine *e)
{
  int		i;

  if (!xml_next("meters"))
    return (put_error("Not found meters in xml"));
  e->db.meters = (t_base_meter*)xmalloc(sizeof(*e->db.meters));
  i = 0;
  while (i < e->db.nb_meters)
    {
      if (!xml_next("meter"))
	return (put_error("Not enough meter with the index table\n"));
      e->db.meters[i].name = xml_getstr("name");
      e->db.meters[i].type = xml_getstr("type");
      e->db.meters[i].value = xml_getint("value");
      e->db.meters[i].rr = xml_getint("rr");
      e->db.meters[i].is = xml_getint("is");
      e->db.meters[i].sr = xml_getint("sr");
      e->db.meters[i].sx = xml_getint("sx");
      e->db.meters[i].kv = xml_getint("kv");
      e->db.meters[i].min = xml_getint("min");
      e->db.meters[i++].max = xml_getint("max");
      e->db.meters = (t_base_meter*)xrealloc(e->db.meters,
					     sizeof(*e->db.meters) * (i + 1));
      xml_out();
    }
  e->db.meters[i].name = 0;
  xml_out();
  return (0);
}
