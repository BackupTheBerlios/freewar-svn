#include "freewar.h"

Err			load_bmp(SDL_Surface **img, char *name)
{
  *img = IMG_Load(name);
  if (*img == NULL)
    {
      fprintf(stderr, "Couldn't load %s: %s\n", name, SDL_GetError());
      return (-1);
    }
  return (0);
}
