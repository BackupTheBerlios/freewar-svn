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
#include "freewar.h"

int	db_layers(t_engine *e)
{
  int	i;
  int	n;
  char	*shared;

  if (!xml_next("layers"))
    return (put_error("Not found layers in xml"));
  i = 0;
  while (i < e->db.nb_layers)
    {
      if (!xml_next("layer"))
	return (put_error("Not enough layer with the index table"));
      e->db.layers[i].name = xml_getstr("name");
      e->db.layers[i].depth = xml_getint("depth");
      if (xml_next("units"))
	{
	  e->db.layers[i].max_units = xml_getint("max");
	  shared = xml_getstr("share");
	  for (n = 0; n < e->db.nb_layers; n++)
	    if (!strcmp(shared, e->db.layers[i].name))
	      break;
	  free(shared);
	  if (n == e->db.nb_layers)
	    return (put_error("Layer \"shared\" inexistant"));
	  e->db.layers[i].shared = &e->db.layers[i];
	  xml_out();
	}
      else
	{
	  e->db.layers[i].max_units = 0;
	  e->db.layers[i].shared = 0;
	}
      i++;
      xml_out();
    }
  e->db.layers[i].name = 0;
  xml_out();
  return (0);
}
