#include "freewar.h"

void		init_engine(t_engine *e)
{
  memset(e->select, 0, sizeof(t_entity*) * FW_MAX_SELECT);
  e->console = false;
  e->scales = 0;
  e->globals = 0;
  e->actions = 0;
  e->id_player = 0;
  e->id = 0;
  e->events = (t_event*)xmalloc(sizeof(*(e->events)));
  memset(e->events->mousepose, 0, sizeof(*e->events->mousepose) *
	 MAXMOUSEEVENT);
  memset(e->events->key, 0, sizeof(*e->events->key) * MAXKEYPRESS);
  e->events->xfin = 0;
  e->events->yfin = 0;
  e->other_events = (t_other_events*)xmalloc(sizeof(*(e->other_events)));
  e->other_events->quit = 0;
}
