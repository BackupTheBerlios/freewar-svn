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
