//
// load_db_actions.cpp for freewar in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Sat May 15 11:48:20 2004 jonathan huot
// Last update Mon May 17 12:32:15 2004 jonathan huot
//

#include "freewar.h"

int		db_action_move(t_engine *e, t_action *action)
{
  if (xml_next("move"))
    {
      action->move_speed = xml_getint("speed");
      action->idsprite[ACTION_MOVE] = unpack_sprite(xml_getstr("sprite"));
      action->idtaunt[ACTION_MOVE] = unpack_taunt(xml_getstr("taunt"));
      xml_out();
    }
  else
    action->move_speed = 0;
  return (0);
}

int		db_action_live(t_engine *e, t_action *action)
{
  int		nb;
  int		i;
  char		*buf;

  if (xml_next("live"))
    {
      action->idsprite[ACTION_LIVE] = unpack_sprite(xml_getstr("sprite"));
      action->idtaunt[ACTION_LIVE] = unpack_taunt(xml_getstr("taunt"));
      nb = 0;
      action->live.instant =
	(t_base_instant**)xmalloc(sizeof(*action->live.instant));
      while (xml_next("instant"))
	{
	  buf = xml_getstr("new_instant");
	  for (i = 0; i < e->db.nb_instants; i++)
	    if (!strcmp(buf, e->db.instants[i].name))
	      break;
	  if (i == e->db.nb_instants)
	    return (put_error("Live instant doesn't exist"));
	  action->live.instant[nb] = &e->db.instants[i];
	  action->live.instant =
	    (t_base_instant**)xrealloc(action->live.instant,
				      sizeof(*action->live.instant)
				      * (nb + 1));
	  xml_out();
	}
      action->live.instant[nb] = 0;
      nb = 0;
      action->live.transform =
	(t_base_entity**)xmalloc(sizeof(*action->live.transform));
      while (xml_next("transform"))
	{
	  buf = xml_getstr("new_entity");
	  for (i = 0; i < e->db.nb_entities; i++)
	    if (!strcmp(buf, e->db.entities[i].name))
	      break;
	  if (i == e->db.nb_entities)
	    return (put_error("Live entity doesn't exist"));
	  action->live.transform[nb] = &e->db.entities[i];
	  action->live.transform =
	    (t_base_entity**)xrealloc(action->live.transform,
				      sizeof(*action->live.transform)
				      * (nb + 1));
	  xml_out();
	}
      action->live.transform[nb] = 0;
      xml_out();
    }
  else
    {
      action->live.instant = 0;
      action->live.transform = 0;
    }
  return (0);
}

int		db_action_died(t_engine *e, t_action *action)
{
  int		nb;
  int		i;
  char		*buf;

  if (xml_next("died"))
    {
      action->idsprite[ACTION_DIED] = unpack_sprite(xml_getstr("sprite"));
      action->idtaunt[ACTION_DIED] = unpack_taunt(xml_getstr("taunt"));
      nb = 0;
      action->died.instant =
	(t_base_instant**)xmalloc(sizeof(*action->died.instant));
      while (xml_next("instant"))
	{
	  buf = xml_getstr("new_instant");
	  for (i = 0; i < e->db.nb_instants; i++)
	    if (!strcmp(buf, e->db.instants[i].name))
	      break;
	  if (!e->db.nb_instants)
	    return (put_error("Died instant doesn't exist"));
	  action->died.instant[nb] = &e->db.instants[i];
	  action->died.instant =
	    (t_base_instant**)xrealloc(action->died.instant,
				      sizeof(*action->died.instant)
				      * (nb + 1));
	  xml_out();
	}
      action->died.instant[nb] = 0;
      nb = 0;
      action->died.transform =
	(t_base_entity**)xmalloc(sizeof(*action->died.transform));
      while (xml_next("transform"))
	{
	  buf = xml_getstr("new_entity");
	  for (i = 0; i < e->db.nb_entities; i++)
	    if (!strcmp(buf, e->db.entities[i].name))
	      break;
	  if (i == e->db.nb_entities)
	    return (put_error("Died entity doesn't exist"));
	  action->died.transform[nb] = &e->db.entities[i];
	  action->died.transform =
	    (t_base_entity**)xrealloc(action->died.transform,
				      sizeof(*action->died.transform)
				      * (nb + 1));
	  xml_out();
	}
      action->died.transform[nb] = 0;
      xml_out();
    }
  else
    {
      action->died.instant = 0;
      action->died.transform = 0;
    }
  return (0);
}

int		db_action_attack(t_engine *e, t_action *action)
{
  int		nb;
  int		nbcost;
  char		*buf;
  int		i;

  nb = 0;
  action->attack = (t_attack*)xmalloc(sizeof(*action->attack));
  if (xml_next("attack"))
    {
      action->idsprite[ACTION_ATTACK] = unpack_sprite(xml_getstr("sprite"));
      action->idtaunt[ACTION_ATTACK] = unpack_taunt(xml_getstr("taunt"));
      while (xml_next("entity"))
	{
	  buf = xml_getstr("type");
	  for (i = 0; i < e->db.nb_entities; i++)
	    if (!strcmp(buf, e->db.entities[i].name))
	      break;
	  if (i == e->db.nb_entities)
	    return (put_error("Attack entity doesn't exist"));
	  action->attack[nb].against = &e->db.entities[i];
	  action->attack[nb].speed = xml_getint("speed");
	  action->attack[nb].damage = xml_getint("damage");
	  nbcost = 0;
	  action->attack[nb].cost =
	    (t_cost*)xmalloc(sizeof(*action->attack[nb].cost));
	  if (xml_next("costs"))
	    {
	      while (xml_next("cost"))
		{
		  action->attack[nb].cost[nbcost].name = xml_getstr("name");
		  action->attack[nb].cost[nbcost].type = xml_getstr("type");
		  action->attack[nb].cost[nbcost].preleave_time =
		    xml_getint("preleave_time");
		  action->attack[nb].cost[nbcost++].value =
		    xml_getint("value");
		  action->attack[nb].cost =
		    (t_cost*)xrealloc(action->attack[nb].cost,
				      sizeof(*action->attack[nb].cost)
				      * (nbcost + 1));
		  xml_out(); // cost
		}
	      xml_out(); // costs
	    }
	  action->attack[nb].cost[nbcost].name = 0;
	  action->attack = (t_attack*)xrealloc(action->attack,
					       sizeof(*action->attack)
					       * (nb + 1));
	  xml_out(); // entity
	}
      xml_out(); //attack
    }
  action->attack[nb].against = 0;
  return (0);
}

int		db_action_create(t_engine *e, t_action *action)
{
  int		nb;
  char		*buf;
  int		i;
  int		nbpre;
  int		nbcost;

  nb = 0;
  action->create = (t_create*)xmalloc(sizeof(*action->create));
  if (xml_next("create"))
    {
      while (xml_next("entity"))
	{
	  buf = xml_getstr("name");
	  for (i = 0; i < e->db.nb_entities; i++)
	    if (!strcmp(e->db.entities[i].name, buf))
	      break;
	  if (i == e->db.nb_entities)
	    return (put_error("Create Entity unknown"));
	  action->create[nb].base = &e->db.entities[i];
	  action->create[nb].time = xml_getint("time_to_make");
	  nbpre = 0;
	  action->create[nb].prequesite =
	    (t_base_entity**)xmalloc(sizeof(*action->create[nb].prequesite));
	  if (xml_next("prequesite"))
	    {
	      while (xml_next("entity"))
		{
		  buf = xml_getstr("name");
		  for (i = 0; i < e->db.nb_entities; i++)
		    if (!strcmp(e->db.entities[i].name, buf))
		      break;
		  if (i == e->db.nb_entities)
		    return (put_error("Prequesite unknown"));
		  i = xml_getint("value");
		  while (i-- > 0)
		    {
		      action->create[nb].prequesite[nbpre++] =
			&e->db.entities[i];
		      action->create[nb].prequesite =
			(t_base_entity**)realloc(action->create[nb].prequesite,
						 sizeof(*action->
							create[nb].prequesite)
						 * (nbpre + 1));
		    }
		  xml_out(); // entity
		}
	      xml_out(); // prequesite
	    }
	  action->create[nb].prequesite[nbpre] = 0;
	  nbcost = 0;
	  action->create[nb].cost =
	    (t_cost*)xmalloc(sizeof(*action->create[nb].cost));
	  if (xml_next("costs"))
	    {
	      while (xml_next("cost"))
		{
		  action->create[nb].cost[nbcost].name = xml_getstr("name");
		  action->create[nb].cost[nbcost].type = xml_getstr("type");
		  action->create[nb].cost[nbcost].preleave_time =
		    xml_getint("preleave_time");
		  action->create[nb].cost[nbcost++].value =
		    xml_getint("value");
		  action->create[nb].cost =
		    (t_cost*)xrealloc(action->create[nb].cost,
				      sizeof(*action->create[nb].cost)
				      * (nbcost + 1));
		  xml_out(); // cost
		}
	      action->create[nb].cost[nbcost].name = 0;
	      xml_out(); // costs
	    }
	  xml_out(); // entity
	}
      xml_out(); // create
    }
  action->create[nb].base = 0;
  return (0);
}
