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

