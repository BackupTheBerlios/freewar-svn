#include "freewar.h"


Err		create_windows(t_info *info, int w, int h)
{
  resize_window(info, w, h);
  SDL_WM_SetCaption("Freewar: a first chaos..", NAME_ICO);
  SDL_WM_SetIcon(SDL_LoadBMP(NAME_ICO), 0);
  return (0);
}

Err		open_window(t_info *info, t_args *args)
{
  Err		err;
  int		w, h;

  memcpy(&w, args->data, sizeof(w));
  memcpy(&h, args->data + sizeof(w), sizeof(h));
  if ((err = init_sdl(info)))
    return (err);
  if ((err = create_windows(info, w, h)))
    return (err);
  return (0);
}
