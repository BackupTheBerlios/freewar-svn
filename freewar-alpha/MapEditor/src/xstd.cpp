#include "freewar.h"

void		xSDL_BlitSurface(SDL_Surface *src,
				 SDL_Rect *srcrect,
				 SDL_Surface *dest,
				 SDL_Rect *destrect)
{
  if (SDL_BlitSurface(src, srcrect, dest, destrect) < 0)
    put_error(SDL_GetError());
}
