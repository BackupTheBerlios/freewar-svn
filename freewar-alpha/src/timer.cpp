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
