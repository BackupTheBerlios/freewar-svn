#include "freewar.h"

int		do_next_action(t_engine *e, t_entity *t)
{
  t_wait_action	*next;

  t->action = ACTION_NONE;
  if (t->queued)
    {
      if (t->queued->tag == ACTION_MOVE)
	create_action(e, t, t->queued->dest);
      else if (t->queued->tag == ACTION_CREATE_UNITS)
	create_action(e, t, t->queued->what, t->queued->arg);
      else if (t->queued->tag == ACTION_ATTACK)
	create_action(e, t, t->queued->against);
      else if (t->queued->tag == ACTION_CREATE_BUILDING)
	create_action(e, t, t->queued->what, &t->queued->dest);
      else
	fprintf(fd_log, "Unknown next action :%d\n", t->queued->tag);
      next = t->queued->next;
      free(t->queued);
      t->queued = next;
    }
  else
    fw_send_action(e, t);
  return (0);
}

int		put_next_action(t_wait_action **a)
{
  t_wait_action	*first;

  first = (t_wait_action*)xmalloc(sizeof(*first));
  first->tag = ACTION_NONE;
  first->against = 0;
  first->dest.x = 0;
  first->dest.y = 0;
  first->off.x = 0;
  first->off.y = 0;
  first->what = 0;
  first->arg = 0;
  first->next = *a;
  *a = first;
  return (0);
}
