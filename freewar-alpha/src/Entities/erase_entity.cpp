//
// erase_entity.cpp for freewar in /root/Freewar/src/Actions
// 
// Made by 
// Login   <root@epita.fr>
// 
// Started on  Wed Jul 14 11:33:18 2004 
// Last update Wed Jul 14 11:33:19 2004 
//

#include "freewar.h"

int		erase_entity(t_engine *e, t_entity *t)
{
  del_next_actions(e, t);
  del_empty_selection(e, t);
  destroy_gfx_entity(t->idgfx);
  del_entity_on_all_actions(e, t);
  if (del_entity_in_map(e, t))
    {
      fprintf(fd_log, " /!\\ ERROR: del_entity failed\n");
      free(t);
      return (1);
    }
  free(t);
  return (0);
}
