//
// load_db_instant.cpp for freewar in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Sat May 15 14:35:50 2004 jonathan huot
// Last update Sun May 16 10:57:46 2004 jonathan huot
//

#include "freewar.h"

int		db_base_instant(t_engine *e, t_db_ind *ind)
{
  int		i;

  for (i = 0; i < ind->nb[TYPE_INSTANTS]; i++)
    {
      if (!xml_next("instant"))
	return (put_error("Not found instants in xml"));
      e->db.instants[i].name = xml_getstr("name");
      e->db.instants[i].idsprite = unpack_sprite(xml_getstr("sprite"));
      e->db.instants[i].idtaunt = unpack_taunt(xml_getstr("taunt"));
      e->db.instants[i].damage = xml_getint("damage");
      e->db.instants[i].splash = xml_getint("splash");
      e->db.instants[i].speed = xml_getint("speed");
      e->db.instants[i].time = xml_getint("time");
      xml_out();
    }
  return (0);
}
