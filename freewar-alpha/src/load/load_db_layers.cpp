#include "freewar.h"

int	db_layers(t_engine *e)
{
  int	i;
  int	n;
  char	*shared;

  if (!xml_next("layers"))
    return (put_error("Not found layers in xml"));
  i = 0;
  while (i < e->db.nb_layers)
    {
      if (!xml_next("layer"))
	return (put_error("Not enough layer with the index table"));
      e->db.layers[i].name = xml_getstr("name");
      e->db.layers[i].depth = xml_getint("depth");
      if (xml_next("units"))
	{
	  e->db.layers[i].max_units = xml_getint("max");
	  shared = xml_getstr("share");
	  for (n = 0; n < e->db.nb_layers; n++)
	    if (!strcmp(shared, e->db.layers[i].name))
	      break;
	  free(shared);
	  if (n == e->db.nb_layers)
	    return (put_error("Layer \"shared\" inexistant"));
	  e->db.layers[i].shared = &e->db.layers[i];
	  xml_out();
	}
      else
	{
	  e->db.layers[i].max_units = 0;
	  e->db.layers[i].shared = 0;
	}
      i++;
      xml_out();
    }
  e->db.layers[i].name = 0;
  xml_out();
  return (0);
}
