#include "freewar.h"

int		del_entity_on_all_actions(t_engine *e, t_entity *t)
{
  t_do_action	*a;
  t_do_action	*next;
  
  a = e->actions;
  while (a)
    {
      next = a->next;
      if (a->entity == t)
	{
	  if (del_action(e, a->id))
	    fprintf(fd_log, "ERROR: del_entity_on_all_actions: del_action failed\n");
	}
      else if (a->tag == ACTION_ATTACK && a->attaked == t)
	{
	  a->entity->action = ACTION_NONE;
	  fw_send_action(e, a->entity);
	  if (del_action(e, a->id))
	    fprintf(fd_log, "ERROR: del_entity_on_all_actions: del_action failed\n");
	}
      a = next;
    }
   return (0);
}
