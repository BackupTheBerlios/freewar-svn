#include "freewar.h"

void		game_verif_pos(t_info *info)
{ 
  info->game.pos_x += info->game.keyleft +
    info->game.keyright + info->game.mousehoriz;
  info->game.pos_y += info->game.keyup +
    info->game.keydown + info->game.mouseverti;
  if (info->game.pos_x < 0)
    info->game.pos_x = 0;
  else if (info->game.pos_x >
	   (info->data.w * CASE_SIZE_X) - info->mysdl.screen->w)
    info->game.pos_x = (info->data.w * CASE_SIZE_X) - info->mysdl.screen->w;
  if (info->game.pos_y < 0)
    info->game.pos_y = 0;
  else if (info->game.pos_y >
	   (info->data.h * CASE_SIZE_Y) - info->mysdl.screen->h)
    info->game.pos_y = (info->data.h * CASE_SIZE_Y) - info->mysdl.screen->h;
}
