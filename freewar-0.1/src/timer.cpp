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
// timer.cpp for freewar in /root/Freewar/src/Actions
// 
// Made by 
// Login   <root@epita.fr>
// 
// Started on  Wed Jul 14 12:15:59 2004 
// Last update Wed Jul 14 12:27:38 2004 
//

#include "freewar.h"

#define FPS_MSEC (60)

int			timer_count(char *s, bool start)
{
	static	Uint32	time = 0;

	if (!s)
	 return (1);
	if (start == true)
	{
		fprintf(fd_log, "TIMER: %s start\n", s);
		time = SDL_GetTicks();
	}
	else
	{
		fprintf(fd_log, "TIMER: %s step ---> %d miliseconds\n",
			s, SDL_GetTicks() - time);
	}
	return (0);
}
int			reset_timer(t_engine *e)
{
  e->time = SDL_GetTicks();
  return (0);
}

int	timer_wait(t_engine *e)
{
  Uint32	tmp;

  tmp = SDL_GetTicks();
  if (tmp > e->time + FPS_MSEC)
    return (1);
  return (0);
}
