//
// pack.cpp for freewar in /u/ept2/huot_j/freewar/network_engine
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Fri Apr 30 14:26:11 2004 jonathan huot
// Last update Mon May  3 17:21:14 2004 jonathan ribas
//

#include "freewar.h"

t_ctrame	*pack(t_trame *trame)
{
  t_ctrame	*res;

// un jour, cryptera...
  res = (t_ctrame*)xmalloc(sizeof(t_trame));
  memcpy((void*)res, (void*)trame, sizeof(t_trame));
  return (res);
}

t_trame		*unpack(t_ctrame *crypt)
{
  t_trame	*res;

// un jour, decryptera...
  res = (t_trame*)xmalloc(sizeof(t_ctrame));
  memcpy((void*)res, (void*)crypt, sizeof(t_ctrame));
  return (res);
}

