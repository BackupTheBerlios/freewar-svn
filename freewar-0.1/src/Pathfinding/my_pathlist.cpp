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

void		my_put_in_path(t_path **b, int x, int y)
{
  t_path        *new_elem;

  new_elem = (t_path*)xmalloc(sizeof(*new_elem));
  new_elem->y = y; 
  new_elem->x = x;
  new_elem->next = *b;
  *b = new_elem;
}

t_path		*my_pathdup(t_path *begin)
{
  t_path	*res;
  
  res = 0;
  res = my_rev_path(begin);
  return (res);
}

t_path           *my_rev_free_path(t_path *begin)
{
  t_path        *res;
  t_path	*tmp;
  
  tmp = begin;
  res = 0;
  while (begin)
    {
      my_put_in_path(&res, begin->x, begin->y);
      begin = begin->next;
    }
  free_path(tmp);
  return (res);
}

t_path           *my_rev_path(t_path *begin)
{
  t_path        *res;
  t_path	*tmp;
  
  tmp = begin;
  res = 0;
  while (begin)
    {
      my_put_in_path(&res, begin->x, begin->y);
      begin = begin->next;
    }
  begin = tmp;
  return (res);
}

void		free_path(t_path *b)
{
  t_path	*tmp;
  
  while (b)
  {
    tmp = b;
    b = b->next;
    free((void*)tmp);
  }
}
