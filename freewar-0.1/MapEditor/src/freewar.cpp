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

Err		get_args(t_info *info, t_args *args,
			 int ac, char **av)
{
  int		w, h;

  w = WIN_DEFAULT_WIDTH;
  h = WIN_DEFAULT_HEIGHT;
  args->cmd = CMD_CREATE_WINDOW;
  args->size = sizeof(w) + sizeof(h);
  memcpy(args->data, &w, sizeof(w));
  memcpy(args->data + sizeof(w), &h, sizeof(h));
  if (ac < 1)
    {
      printf("Syntax error\n");
      exit(10);
    }
  if (ac < 2)
    {
      info->file = av[0];
      info->width = 0;
    }
  else if (ac > 2)
    {
      info->file = av[0];
      info->width = atoi(av[1]);
      info->height = atoi(av[2]);
      if (info->width <= 0 || info->height <= 0)
	{
	  printf("Syntax error (null/negative integer?)\n");
	  exit(13);
	}
    }
  return (0);
}

Err		freewar(int ac, char **av)
{
  t_info	info;
  t_args	args;
  Err		err;

  if ((err = get_args(&info, &args, ac, av)))
    return (err);
  if ((err = open_window(&info, &args)))
    return (err);
  if ((err = menu(&info)))
	return (err);
  quit(&info);
  return (0);
}
