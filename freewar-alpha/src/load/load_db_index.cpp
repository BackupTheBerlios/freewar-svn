//
// load_db_alias.cpp for freewar in /u/ept2/huot_j/Freewar/src
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Fri May 14 14:48:50 2004 jonathan huot
// Last update Sat Jun 26 19:33:26 2004 jonathan huot
//

#include "freewar.h"

void		db_load_index(t_db_ind *ind)
{
  ind->nb_index = 0;
  ind->index = (t_db_index*)xmalloc(sizeof(*ind->index));
  while (xml_next("index"))
    {
      ind->index[ind->nb_index].type = xml_getstr("type");
      ind->index[ind->nb_index].name = xml_getstr("name");
      ind->nb_index++;
      ind->index = (t_db_index*)xrealloc(ind->index,sizeof(*ind->index)
					 * (ind->nb_index + 1));
      xml_out();
    }
}

void		free_index(t_db_ind *ind)
{
  int		n;

  for (n = 0; n < ind->nb_index; n++)
    {
      free(ind->index[n].type);
      free(ind->index[n].name);
    }
  free(ind->index);
}

int		db_index(t_engine *e, t_db_ind *ind)
{
  int		i;
  int		n;

  for (i = 0; i < MAX_TYPES; i++)
    ind->nb[i] = 0;
  db_load_index(ind);
  for (i = 0; i < ind->nb_index; i++)
    {
      if (!strcmp(ind->index[i].type, "meters"))
	ind->nb[TYPE_METERS]++;
      else if (!strcmp(ind->index[i].type, "layers"))
	ind->nb[TYPE_LAYERS]++;
      else if (!strcmp(ind->index[i].type, "lands"))
	ind->nb[TYPE_LANDS]++;
      else if (!strcmp(ind->index[i].type, "types"))
	ind->nb[TYPE_TYPES]++;
      else if (!strcmp(ind->index[i].type, "weapons"))
	ind->nb[TYPE_WEAPONS]++;
      else if (!strcmp(ind->index[i].type, "armors"))
	ind->nb[TYPE_ARMORS]++;
      else if (!strcmp(ind->index[i].type, "entities"))
	ind->nb[TYPE_ENTITIES]++;
      else if (!strcmp(ind->index[i].type, "instants"))
	ind->nb[TYPE_INSTANTS]++;
      else
	return (put_error("Bad Index in DB file\n"));
    }
  e->db.layers = (t_layer*)xmalloc(sizeof(*e->db.layers) *
					(ind->nb[TYPE_LAYERS] + 1));
  e->db.nb_layers = ind->nb[TYPE_LAYERS];
  e->db.meters = (t_base_meter*)xmalloc(sizeof(*e->db.meters) *
					(ind->nb[TYPE_METERS] + 1));
  e->db.nb_meters = ind->nb[TYPE_METERS];
  e->db.lands = (t_base_land*)xmalloc(sizeof(*e->db.lands) *
				      (ind->nb[TYPE_LANDS] + 1));
  e->db.nb_lands = ind->nb[TYPE_LANDS];
  e->db.types = (t_type*)xmalloc(sizeof(*e->db.types) *
				 (ind->nb[TYPE_TYPES] + 1));
  e->db.nb_types = ind->nb[TYPE_TYPES];
  e->db.weapons = (t_weapon*)xmalloc(sizeof(*e->db.weapons) *
				     (ind->nb[TYPE_WEAPONS] + 1));
  e->db.nb_weapons = ind->nb[TYPE_WEAPONS];
  e->db.armors = (t_armor*)xmalloc(sizeof(*e->db.armors) *
				   (ind->nb[TYPE_ARMORS] + 1));
  e->db.nb_armors = ind->nb[TYPE_ARMORS];
  e->db.entities = (t_base_entity*)xmalloc(sizeof(*e->db.entities)
					   * (ind->nb[TYPE_ENTITIES] + 1));
  n = 0;
  for (i = 0; i < ind->nb_index && n < ind->nb[TYPE_ENTITIES]; i++)
    if (!strcmp(ind->index[i].type, "entities"))
      e->db.entities[n++].name = strdup(ind->index[i].name);
  e->db.nb_entities = ind->nb[TYPE_ENTITIES];
  e->db.instants = (t_base_instant*)xmalloc(sizeof(*e->db.instants)
					    * (ind->nb[TYPE_INSTANTS] + 1));
  n = 0;
  for (i = 0; i < ind->nb_index && n < ind->nb[TYPE_INSTANTS]; i++)
    if (!strcmp(ind->index[i].type, "instants"))
      e->db.instants[n++].name = strdup(ind->index[i].name);
  e->db.nb_instants = ind->nb[TYPE_INSTANTS];
  return(0);
}
