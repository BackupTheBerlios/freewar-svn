#include "freewar.h"

int		req_event_ok(t_engine *e, t_trame *req, int player)
{
  e->g.event_ok = 1;
  return (0);
}
