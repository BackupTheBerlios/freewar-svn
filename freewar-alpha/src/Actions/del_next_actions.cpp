#include "freewar.h"

int		del_next_actions(t_engine *e, t_entity *t)
{
  t_wait_action	*next;

  while (t->queued)
    {
      next = t->queued->next;
      free(t->queued);
      t->queued = next;
    }
  return (0);
}
