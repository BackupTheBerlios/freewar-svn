//
// tag_action.cpp for freewar in /u/ept2/petitc_s
// 
// Made by stephane petitcolas
// Login   <petitc_s@epita.fr>
// 
// Started on  Mon Jun 28 14:13:10 2004 stephane petitcolas
// Last update Sat Jul  3 20:50:26 2004 
//

#include "freewar.h"

char		*is_action(SDLKey key)
{
  if (key == SDLK_ESCAPE)
    return("exit");
  return(0);
}

#define NB_OFF_MOVE (15)

int		get_pos(int xfin, int yfin, t_coord *actual_pos,
			t_coord *actual_off, t_cfg cfg)
{
	int	flag;

	flag = 0;
  if (xfin <= SCROLL_X)
    {
      actual_off->x -= NB_OFF_MOVE;
      if (actual_off->x < 0)
	{
	  actual_pos->x--;
	  actual_off->x += CASE_SIZE_X;
	}
      if (actual_pos->x < 0)
	{
	  actual_pos->x = 0;
	  actual_off->x = 0;
	}
	flag = 1;
    }
  else if (xfin >= cfg.Screen[0] - SCROLL_X)
    {
      actual_off->x += NB_OFF_MOVE;
      if (actual_off->x > CASE_SIZE_X)
	{
	  actual_pos->x++;
	  actual_off->x -= CASE_SIZE_X;
	}
	flag = 1;
    }
 if (yfin <= SCROLL_Y)
    {
      actual_off->y -= NB_OFF_MOVE;
      if (actual_off->y < 0)
	{
	  actual_pos->y--;
	  actual_off->y += CASE_SIZE_Y;
	}
      if (actual_pos->y < 0)
	{
	  actual_pos->y = 0;
	  actual_off->y = 0;
	}
	return (1);
    }
 else if (yfin >= cfg.Screen[1] - SCROLL_Y)
    {
        actual_off->y += NB_OFF_MOVE;
      if (actual_off->y > CASE_SIZE_Y)
	{
	  actual_pos->y++;
	  actual_off->y -= CASE_SIZE_Y;
	}
	return (1);
    }
 return(flag);
}
