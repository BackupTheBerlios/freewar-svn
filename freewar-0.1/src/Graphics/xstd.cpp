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

int		xSDL_BlitSurface(SDL_Surface *src,
				 SDL_Rect *srcrect,
				 SDL_Surface *dest,
				 SDL_Rect *destrect)
{
  if (SDL_BlitSurface(src, srcrect, dest, destrect) < 0)
    {
      put_error(SDL_GetError());
      return (-1);
    }
  return (0);
}

SDL_Surface	*xSDL_DisplayFormatAlpha(SDL_Surface *s)
{
  SDL_Surface	*ret;

  ret = SDL_DisplayFormatAlpha(s);
  if (!ret)
    {
      fprintf(fd_log, "Out of memory: %s\n", SDL_GetError());
      exit(42);
    }
  return (ret);
}

int		xSDL_SetAlpha(SDL_Surface *s, Uint32 flag, Uint8 alpha)
{
  if (SDL_SetAlpha(s, SDL_SRCALPHA, alpha) < 0)
    {
      fprintf(fd_log, "Alpha can't be modified: %s\n", SDL_GetError());
      return (-1);
    }
  return (0);
}
