//
// load_db_get.cpp for freewar in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Sun May 16 19:01:30 2004 jonathan huot
// Last update Sun May 16 19:01:37 2004 jonathan huot
//

#include "freewar.h"

t_type		**db_get_types(t_engine *e)
{
  int		i;
  char		*buf;
  t_type	**res;
  int		nb;

  nb = 0;
  res = (t_type**)xmalloc(sizeof(*res));
  while (xml_next("type"))
    {
      buf = xml_getstr("name");
      for (i = 0; i < e->db.nb_types; i++)
	if (!strcmp(e->db.types[i].name, buf))
	  break;
      if (i && i >= e->db.nb_types)
	{
	  put_error("Bad type");
	  return (0);
	}
      res[nb++] = &e->db.types[i];
      res = (t_type**)xrealloc(res, sizeof(*res) * (nb + 1));
      xml_out();
    }
  res[nb] = 0;
  return (res);
}
