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

void			init_pixel_format(t_info *info)
{
  const SDL_VideoInfo	*VideoInfo;

  info->mysdl.video_flags = SDL_HWPALETTE;
  info->mysdl.video_flags |= SDL_RESIZABLE;
  if ((VideoInfo = SDL_GetVideoInfo()) == NULL)
    put_error(SDL_GetError());
  if (VideoInfo->hw_available)
    {
      info->mysdl.video_flags |= SDL_HWSURFACE;
      info->mysdl.video_flags |= SDL_DOUBLEBUF;
    }
  else
    info->mysdl.video_flags |= SDL_SWSURFACE;
  if (VideoInfo->blit_hw)
    info->mysdl.video_flags |= SDL_HWACCEL;
}

Err		init_sdl(t_info *info)
{
  if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
    {
      put_error(SDL_GetError());
      return (-1);
    }
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    info->mysdl.rmask = 0xff000000;
    info->mysdl.gmask = 0x00ff0000;
    info->mysdl.bmask = 0x0000ff00;
    info->mysdl.amask = 0x000000ff;
#else
    info->mysdl.rmask = 0x000000ff;
    info->mysdl.gmask = 0x0000ff00;
    info->mysdl.bmask = 0x00ff0000;
    info->mysdl.amask = 0xff000000;
#endif
  atexit(SDL_Quit);
  init_pixel_format(info);
  return (0);
}
