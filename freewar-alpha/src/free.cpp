//
// free.cpp for freewar in /u/ept2/ribas_j/Freewar/src/Graphics
// 
// Made by jonathan ribas
// Login   <ribas_j@epita.fr>
// 
// Started on  Mon Jun 14 15:16:56 2004 jonathan ribas
// Last update Mon Jun 14 15:19:43 2004 jonathan ribas
//

#include "freewar.h"

int		free_engine(t_engine *e)
{
  int		i;
  
  for (i = 0; i < e->nb_players; i++)
    {
      if (e->meters[i])
	free (e->meters[i]);
    }
  if (e->meters)
    free(e->meters);
  // rajouter les autres free plus tards .
  return (0);
}
