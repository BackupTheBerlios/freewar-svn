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
