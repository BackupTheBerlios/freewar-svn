#include "freewar.h"

int		get_action_anim(t_entity *t)
{
  if (t->action == ACTION_NONE ||
	  t->action == ACTION_WAIT)
    update_anim(t->idgfx, 1, t->direction, t->data->idsprite);
  else
    update_anim(t->idgfx, 1, t->direction,
		t->data->actions.idsprite[t->action]);
  return (0);
}
