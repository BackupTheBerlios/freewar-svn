#include "freewar.h"

int		init_net(t_engine *e)
{
  init_nettool();
  assign_newclient(&process_newclient, e);
  assign_clients(&process_clients, e);
  assign_deadclient(&process_deadclient, e);
  return (0);
}
