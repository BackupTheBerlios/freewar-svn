// Copyright (C) 2004 Freewar Team <doomsday@freewar.net>

// This file is part of Freewar.

// Freewar is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.

// Freewar is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with Freewar; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// load_db_base_entity.cpp for freewar in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Fri May 14 18:21:03 2004 jonathan huot
// Last update Tue Jun 29 17:31:34 2004 jonathan huot
//

#include "freewar.h"

int		db_layers_entity(t_engine *e, t_db_ind *ind,
				 t_base_entity *ent)
{
  int		nb;
  char		*buf;
  int		i;

  if (!xml_next("layers"))
    return (put_error("No type with entity"));
  nb = 0;
  ent->layer = (t_layer**)xmalloc(sizeof(*ent->layer));
  while (xml_next("layer"))
    {
      if (!(buf = xml_getstr("name")))
	return (put_error("Entity has layer, but witch one ?"));
      for (i = 0; i < e->db.nb_layers; i++)
	if (!strcmp(buf, e->db.layers[i].name))
	  break;
      free(buf);
      if (i == e->db.nb_layers)
	return (put_error("Layer doesn't exist"));
      ent->layer[nb++] = &e->db.layers[i];
      ent->layer = (t_layer**)xrealloc(ent->layer, sizeof(*ent->layer) * (nb + 1));
      xml_out();
    }
  ent->layer[nb] = 0;
  xml_out();
  return (0);
}

int		db_types_entity(t_engine *e, t_db_ind *ind,
				t_base_entity *ent)
{
  int		nb;
  char		*buf;
  int		i;

  if (!xml_next("types"))
    return (put_error("No type with entity"));
  nb = 0;
  ent->type = (t_type**)xmalloc(sizeof(*ent->type));
  while (xml_next("type"))
    {
      if (!(buf = xml_getstr("name")))
	return (put_error("Entity has type, but witch one ?"));
      for (i = 0; i < e->db.nb_types; i++)
	if (!strcmp(buf, e->db.types[i].name))
	  break;
      free(buf);
      if (i == e->db.nb_types)
	return (put_error("Type doesn't exist"));
      ent->type[nb++] = &e->db.types[i];
      ent->type = (t_type**)xrealloc(ent->type, sizeof(*ent->type) * (nb + 1));
      xml_out();
    }
  ent->type[nb] = 0;
  xml_out();
  return (0);
}

int		db_weapons_entity(t_engine *e, t_db_ind *ind,
				  t_base_entity *ent)
{
  int		nb;

  if (!xml_next("weapons"))
    {
      ent->weapon = 0;
      return (0);
    }
  nb = 0;
  ent->weapon = (t_weapon**)xmalloc(sizeof(*ent->weapon));
  while (xml_next("weapon"))
    {
      char	*buf;
      int	i;

      if (!(buf = xml_getstr("name")))
	return (put_error("Entity has weapon, but witch one ?"));
      for (i = 0; i < e->db.nb_weapons; i++)
	if (!strcmp(buf, e->db.weapons[i].name))
	  break;
      free(buf);
      if (i == e->db.nb_weapons)
	return (put_error("Weapon doesn't exist"));
      ent->weapon[nb++] = &e->db.weapons[i];
      ent->weapon = (t_weapon**)xrealloc(ent->weapon,
					 sizeof(*ent->weapon) * (nb + 1));
      xml_out();
    }
  ent->weapon[nb] = 0;
  xml_out();
  return (0);
}

int		db_armors_entity(t_engine *e, t_db_ind *ind,
				 t_base_entity *ent)
{
  int		nb;
  char		*buf;
  int		i;

  if (!xml_next("armors"))
    {
      ent->armor = 0;
      return (0);
    }
  nb = 0;
  ent->armor = (t_armor**)xmalloc(sizeof(*ent->armor));
  while (xml_next("armor"))
    {
      if (!(buf = xml_getstr("name")))
	return (put_error("Entity has armor, but witch one ?"));
      for (i = 0; i < e->db.nb_armors; i++)
	if (!strcmp(buf, e->db.armors[i].name))
	  break;
      free(buf);
      if (i == e->db.nb_armors)
	return (put_error("Armor doesn't exist"));
      ent->armor[nb++] = &e->db.armors[i];
      ent->armor = (t_armor**)xrealloc(ent->armor,
				       sizeof(*ent->armor) * (nb + 1));
      xml_out();
    }
  ent->armor[nb] = 0;
  xml_out();
  return (0);
}

int		db_costs_entity(t_engine *e, t_db_ind *ind,
				t_base_entity *ent)
{
  int		nb;

  if (!xml_next("costs"))
    {
      ent->costs = 0;
      return (0);
    }
  nb = 0;
  ent->costs = (t_cost*)xmalloc(sizeof(*ent->costs));
  while (xml_next("costs"))
    {
      if (!(ent->costs[nb].name = xml_getstr("name")))
	return (put_error("Cost without name"));
      ent->costs[nb].type = xml_getstr("type");
      ent->costs[nb].preleave_time = xml_getint("preleave_time");
      ent->costs[nb++].value = xml_getint("value");
      ent->costs = (t_cost*)xrealloc(ent->costs,
				     sizeof(*ent->costs) * (nb + 1));
      xml_out();
    }
  ent->costs[nb].name = 0;
  xml_out();
  return (0);
}

int		db_meters_entity(t_engine *e, t_db_ind *ind,
				 t_base_entity *ent)
{
  int		nb;

  if (!xml_next("meters"))
    return (0);
  nb = 0;
  ent->meters = (t_base_meter*)xmalloc(sizeof(*ent->meters));
  while (xml_next("meter"))
    {
      if (!(ent->meters[nb].name = xml_getstr("name")))
	return (put_error("Meter without entity"));
      ent->meters[nb].value = xml_getint("value");
      ent->meters[nb].rr = xml_getint("rr");
      ent->meters[nb].is = xml_getint("is");
      ent->meters[nb].sr = xml_getint("sr");
      ent->meters[nb].sx = xml_getint("sx");
      ent->meters[nb].kv = xml_getint("kv");
      ent->meters[nb].min = xml_getint("min");
      ent->meters[nb++].max = xml_getint("max");
      ent->meters = (t_base_meter*)xrealloc(ent->meters,
				       sizeof(*ent->meters) * (nb + 1));
      xml_out();
    }
  xml_out();
  return (0);
}

int		db_actions_entity(t_engine *e, t_db_ind *ind,
				  t_base_entity *ent)
{
  if (xml_next("actions"))
    {
      db_action_move(e, &ent->actions);
      db_action_attack(e, &ent->actions);
      db_action_live(e, &ent->actions);
      db_action_died(e, &ent->actions);
      db_action_create(e, &ent->actions);
      xml_out();
    }
  return (0);
}

int		db_base_entity(t_engine *e, t_db_ind *ind)
{
  int		i;
  char		*buf;

  for (i = 0; i < ind->nb[TYPE_ENTITIES]; i++)
    {
      if (!xml_next("entity"))
	return (put_error("Not found enough entity in xml"));
      if (!(buf = xml_getstr("name")))
	return (put_error("Entity without name, refer it in index table"));
      if (strcmp(buf, e->db.entities[i].name))
	return (put_error("Entity isn't in same order that index"));
      e->db.entities[i].idsprite = unpack_sprite(xml_getstr("sprite"));
      e->db.entities[i].idmapedit = xml_getint("idmapedit");
      e->db.entities[i].max_units = xml_getint("max");
      if (db_layers_entity(e, ind, &e->db.entities[i]))
	return (1);
      if (db_types_entity(e, ind, &e->db.entities[i]))
	return (1);
      if (db_weapons_entity(e, ind, &e->db.entities[i]))
	return (1);
      if (db_armors_entity(e, ind, &e->db.entities[i]))
	return (1);
      if (db_costs_entity(e, ind, &e->db.entities[i]))
	return (1);
      if (db_meters_entity(e, ind, &e->db.entities[i]))
	return (1);
      if (db_actions_entity(e, ind, &e->db.entities[i]))
	return (1);
      if (xml_next("visibility"))
	{
	  e->db.entities[i].visibility = xml_getint("warfog");
	  xml_out();
	}
      xml_out();
    }
  return (0);
}
