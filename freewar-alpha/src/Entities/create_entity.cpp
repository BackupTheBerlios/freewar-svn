//
// create_entity.cpp for freewar in /root/Freewar/src/Actions
// 
// Made by 
// Login   <root@epita.fr>
// 
// Started on  Wed Jul 14 18:24:03 2004 
// Last update Wed Jul 14 18:24:04 2004 
//

#include "freewar.h"


t_entity	*create_entity(t_engine *e, t_base_entity *base, int app,
			    t_coord pos)
{
  t_entity	*n;

  n = (t_entity*)xmalloc(sizeof(*n));
  n->data = base;
  n->action = ACTION_NONE;
  n->queued = 0;
  n->direction = get_random(NB_DIR);
  n->time = 0;
  n->action_fail = 0;
  n->against = 0;
  n->where.x = 0;
  n->where.y = 0;
  n->pos.x = pos.x;
  n->pos.y = pos.y;
  n->off.x = 0;
  n->off.y = 0;
  n->idgfx = create_gfx_entity(base->idsprite);
  n->app = app;
  n->id = e->id++;
  n->buff[0] = BUFF_NULL;
  if (base->meters)
    {
      int		i;
      
      for (i = 0; base->meters[i].name; i++)
	;
      n->meter = (t_meter*)xmalloc(sizeof(*(n->meter)) * (i + 1));
      for (i = 0; base->meters[i].name; i++)
	{
	  n->meter[i].value = base->meters[i].value;
	  n->meter[i].meter = base->meters + i;
	}
      n->meter[i].meter = 0;
      n->update = true;
    }
  else
     {
       n->meter = false;
       n->update = false;
    }
  n->next = e->entity;
  e->entity = n;
  fw_send_create_ent(e, n);
  fw_send_dir(e, n);
  return (n);
}
