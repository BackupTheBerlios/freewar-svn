// revoir rapidement ce fichier avant de faire une
// crise cardiaque

#include "freewar.h"
#define NB_OFF_MOVE (5)

int		get_pos(t_engine *e, int xfin, int yfin)
{
	int	flag;

	flag = 0;
  if (xfin <= SCROLL_X)
    {
      e->g.off_arena.x -= NB_OFF_MOVE;
      if (e->g.off_arena.x < 0)
	{
	  e->g.pos_arena.x--;
	  e->g.off_arena.x += CASE_SIZE_X;
	}
      if (e->g.pos_arena.x < 0)
	{
	  e->g.pos_arena.x = 0;
	  e->g.off_arena.x = 0;
	}
	flag = 1;
    }
  else if (xfin >= e->g.w_main - SCROLL_X)
    {
      e->g.off_arena.x += NB_OFF_MOVE;
      if (e->g.off_arena.x > CASE_SIZE_X)
	{
	  e->g.pos_arena.x++;
	  e->g.off_arena.x -= CASE_SIZE_X;
	}
	flag = 1;
    }
 if (yfin <= SCROLL_Y)
    {
      e->g.off_arena.y -= NB_OFF_MOVE;
      if (e->g.off_arena.y < 0)
	{
	  e->g.pos_arena.y--;
	  e->g.off_arena.y += CASE_SIZE_Y;
	}
      if (e->g.pos_arena.y < 0)
	{
	  e->g.pos_arena.y = 0;
	  e->g.off_arena.y = 0;
	}
	return (1);
    }
 else if (yfin >= e->g.h_main - SCROLL_Y)
    {
        e->g.off_arena.y += NB_OFF_MOVE;
      if (e->g.off_arena.y > CASE_SIZE_Y)
	{
	  e->g.pos_arena.y++;
	  e->g.off_arena.y -= CASE_SIZE_Y;
	}
	return (1);
    }
 return(flag);
}

void		manage_events(t_engine *e)
{
	//if (e->events->mousepose[0].button)
	//{
	get_pos(e, e->events->xfin / CASE_SIZE_X, e->events->yfin / CASE_SIZE_Y);

	//}
	//else if (is_valid_trame(&trame, TAG_EXECUTION))
	//  ;
	//else if (is_valid_trame(&trame, TAG_INFO_SCALE))
	//  req_info_scale(e, &trame, t);
	//else if (is_valid_trame(&trame, TAG_SELECT_MOVE))
	//  req_select_move(e, &trame, t);
	//else if (is_valid_trame(&trame, TAG_SELECT_ATTACK))
	//  req_select_attack(e, &trame, t);
	//else if (is_valid_trame(&trame, TAG_SELECT_CREATE_UNITS))
	//  req_select_create_units(e, &trame, t);
	//else if (is_valid_trame(&trame, TAG_SELECT_CREATE_BUILDING))
	//  req_select_create_building(e, &trame, t);
	//else if (is_valid_trame(&trame, TAG_SELECT))
	//  {
	//    puts("SELECT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	//    manage_selection(e, &trame, t);
	//  }
}
