//
// load_db_weapon.cpp for freewar in /u/ept2/huot_j/Freewar/src
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Fri May 14 17:15:49 2004 jonathan huot
// Last update Mon May 17 11:16:16 2004 jonathan huot
//

#include "freewar.h"

int		db_weapon(t_engine *e, t_db_ind *ind)
{
  int		i;
  char		*buf;
  int		n;

  if (!xml_next("weapons"))
    return (put_error("Weapons not found in xml"));
  for (i = 0; i < ind->nb[TYPE_WEAPONS]; i++)
    {
      if (!xml_next("weapon"))
	return (put_error("Not enough weapon in xml"));
      if (!(e->db.weapons[i].name = xml_getstr("name")))
	return (put_error("Weapon without name !"));
      e->db.weapons[i].dmg = xml_getint("damage");
      e->db.weapons[i].rof = xml_getint("rof");
      e->db.weapons[i].range = xml_getint("range");
      buf = xml_getstr("projectile");
      for (n = 0; n < e->db.nb_instants; n++)
	if (!strcmp(e->db.instants[n].name, buf))
	  break;
      free(buf);
      if (n && n >= e->db.nb_instants)
	return (put_error("Weapon with Projectile not found"));
      e->db.weapons[i].projectile = &e->db.instants[n];
      if (!xml_next("types"))
	return (put_error("Weapon without type was found"));
      e->db.weapons[i].allowed = db_get_types(e);
      xml_out();
      xml_out();
    }
  xml_out();
  return (0);
}
