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
// init_globals.cpp for freewar in /u/ept2/huot_j/Freewar
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Mon May 17 14:11:57 2004 jonathan huot
// Last update Sun Jun  6 21:18:17 2004 jonathan huot
//

#include "freewar.h"

int		init_globals(t_engine *e)
{
  int		i;
  int		n;
  int		nb;
  int		nbm;

  nb = 0;
  e->globals = (t_meter*)xmalloc(sizeof(*e->globals));
  e->meters = (t_meter**)xmalloc(sizeof(*e->meters) * (e->nb_players + 1));
  for (n = 0; n < e->nb_players; n++)
    {
      nbm = 0;
      e->meters[n] = 0;
      for (i = 0; i < e->db.nb_meters; i++)
	if (e->db.meters[i].type && !strcmp("global", e->db.meters[i].type))
	  {
	    if (!n)
	      {
		e->globals[nb].meter = &(e->db.meters[i]);
		e->globals[nb++].value = e->db.meters[i].value;
		e->globals = (t_meter*)xrealloc(e->globals, sizeof(*e->globals)
						* (nb + 1));
	      }
	  }
	else
	  {
	    if (!e->meters[n])
	      e->meters[n] = (t_meter*)xmalloc(sizeof(**e->meters)
					       * (nbm + 1));
	    e->meters[n][nbm].meter = &(e->db.meters[i]);
	    e->meters[n][nbm++].value = e->db.meters[i].value;
	    e->meters[n] = (t_meter*)xrealloc(e->meters[n], sizeof(**e->meters)
					       * (nbm + 1));
	  }
      e->meters[n][nbm].meter = 0;
    }
  e->meters[n] = 0;
  e->globals[nb].meter = 0;
  return (0);
}
