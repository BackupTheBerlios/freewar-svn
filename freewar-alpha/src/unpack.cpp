//
// unpack.cpp for freewar in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Sat May 15 19:24:19 2004 jonathan huot
// Last update Sat Jun 26 19:29:06 2004 jonathan huot
//

#include "freewar.h"

int		unpack_sprite(char *s)
{
  int		ret;

  if (!s)
    return (-1);
  if ((ret = create_sprite(s)) < 0)
    put_error("Warning, sprite can't be loaded");
  return (ret);
}

int		unpack_taunt(char *s)
{
  if (s)
    put_error("Warning, taunt is not implemented");
  return (0);
}
