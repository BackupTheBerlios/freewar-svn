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
