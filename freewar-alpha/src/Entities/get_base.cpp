#include "freewar.h"

t_base_entity	*get_base(t_engine *e, char *name)
{
  int	i;

  for (i = 0; i < e->db.nb_entities; i++)
    if (!strcmp(e->db.entities[i].name, name))
      return (&e->db.entities[i]);
  fprintf(fd_log, "ERROR: get_base failed\n");
  return (0);
}
