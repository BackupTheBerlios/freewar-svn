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
// save_map.cpp for freewar in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Tue May 11 21:01:24 2004 jonathan huot
// Last update Tue May 11 22:15:14 2004 jonathan huot
//

#include "freewar.h"

int		save_map(t_info *info)
{
  int		i;
  int		n;
  FILE		*file;

  file = xfopen(info->file, "w");
  if (!file)
    return (put_error("Sauvegarde de la map failed\n"));

  if (xfwrite((void*)&info->data.w, sizeof(unsigned short), 1, file))
    return (1);
  if (xfwrite((void*)&info->data.h, sizeof(unsigned short), 1, file))
    return (1);
  if (xfwrite((void*)&info->data.nb_players, sizeof(unsigned short), 1, file))
    return (1);
  for (i = 0; i < info->data.nb_players; i++)
    if (xfwrite((void*)&info->data.start_point[i],
		 sizeof(*info->data.start_point), 1, file))
      return (1);
  for (n = 0; n < info->data.h; n++)
    for (i = 0; i < info->data.w; i++)
      if (xfwrite((void*)&info->data.data[n][i],
		   sizeof(**info->data.data), 1, file))
	return (1);
  fclose(file);
  put_error("file saved");
  return (0);
}
