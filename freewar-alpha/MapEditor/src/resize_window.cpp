#include "freewar.h"

Err		resize_window(t_info *info, int w, int h)
{
  info->mysdl.screen = SDL_SetVideoMode(w, h, SCREEN_DEPTH,
					info->mysdl.video_flags);
  if (!info->mysdl.screen)
    return (put_error(SDL_GetError()));
  return (0);
}
