//
// play_is_full.cpp for freewar in /u/ept2/huot_j/Freewar/src
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Thu May  6 11:11:40 2004 jonathan huot
// Last update Thu May  6 11:11:44 2004 jonathan huot
//

#include "freewar.h"

int		play_is_full()
{
  int		i;

  for (i = 0; cnt->clients[i].sock; i++)
    ;
  if (i >= FW_MAX_CLIENTS)
    return (1);
  return (0);
}
