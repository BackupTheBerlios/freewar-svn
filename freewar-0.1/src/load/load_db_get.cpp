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
// load_db_get.cpp for freewar in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Sun May 16 19:01:30 2004 jonathan huot
// Last update Sun May 16 19:01:37 2004 jonathan huot
//

#include "freewar.h"

t_type		**db_get_types(t_engine *e)
{
  int		i;
  char		*buf;
  t_type	**res;
  int		nb;

  nb = 0;
  res = (t_type**)xmalloc(sizeof(*res));
  while (xml_next("type"))
    {
      buf = xml_getstr("name");
      for (i = 0; i < e->db.nb_types; i++)
	if (!strcmp(e->db.types[i].name, buf))
	  break;
      if (i && i >= e->db.nb_types)
	{
	  put_error("Bad type");
	  return (0);
	}
      res[nb++] = &e->db.types[i];
      res = (t_type**)xrealloc(res, sizeof(*res) * (nb + 1));
      xml_out();
    }
  res[nb] = 0;
  return (res);
}
