#include "freewar.h"

Err		game_mousemotion(t_info *info, SDL_Event e)
{
  // souris a gauche
  if (e.motion.x <= info->mysdl.screen->w - (info->mysdl.screen->w / 10) * 9)
    info->game.mousehoriz = -SCROLL_STEP;
  // souris a droite
  else if (e.motion.x >= info->mysdl.screen->w - info->mysdl.screen->w / 10)
    info->game.mousehoriz = SCROLL_STEP;
  else
    info->game.mousehoriz = 0;
  // souris en haut
  if (e.motion.y <= info->mysdl.screen->h - (info->mysdl.screen->h / 10) * 9)
    info->game.mouseverti = -SCROLL_STEP;
  // souris en bas
  else if (e.motion.y >= info->mysdl.screen->h - info->mysdl.screen->h / 10)
    info->game.mouseverti = SCROLL_STEP;
  else
    info->game.mouseverti = 0;
  return (update_gamespace(info));
}

Err			game_mousebutton(t_info *info, SDL_Event e)
{
  unsigned short	x;
  unsigned short	y;

  x = (e.button.x + info->game.pos_x) / CASE_SIZE_X;
  y = (e.button.y + info->game.pos_y) / CASE_SIZE_Y;
  if (get_land(info->selection) == true)
    info->data.data[y][x].land = info->selection;
  else
    info->data.data[y][x].item = info->selection;
  return (0);
}
