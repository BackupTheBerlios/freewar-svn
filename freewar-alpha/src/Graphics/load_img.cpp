//
// load_img.cpp for freewar in /u/ept2/ribas_j/Freewar/src
// 
// Made by jonathan ribas
// Login   <ribas_j@epita.fr>
// 
// Started on  Thu May 13 11:29:56 2004 jonathan ribas
// Last update Tue Jun 29 18:42:44 2004 jonathan huot
//

#include "freewar.h"

int			load_img(SDL_Surface **img, char *name)
{
  *img = IMG_Load(name);
  if (*img == NULL)
    {
      fprintf(fd_log, "Warning: loading %s failed: %s\n",
	      name, SDL_GetError());
      return (-1);
    }
  return (0);
}
