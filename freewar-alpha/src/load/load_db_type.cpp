//
// load_db_type.cpp for freewar in /u/ept2/huot_j/Freewar/src
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Fri May 14 15:32:00 2004 jonathan huot
// Last update Mon May 17 11:34:33 2004 jonathan huot
//

#include "freewar.h"

t_factor	*db_factor_surface(t_engine *e)
{
  t_factor	*got;
  int		nb;
  char		*buf;
  int		i;

  got = (t_factor*)xmalloc(sizeof(*got));
  nb = 0;
  while (xml_next("factor"))
    {
      buf = xml_getstr("name");
      for (i = 0; i < e->db.nb_lands; i++)
	if (!strcmp(e->db.lands[i].name, buf))
	  break;
      if (i == e->db.nb_lands)
	{
	  put_error("Warning: Bad Surface factor, land unknown");
	  return (0);
	}
      got[nb].condition.ptr = (&(e->db.lands[i]));
      got[nb].coef = (float)xml_getfloat("value");
      nb++;
      got = (t_factor*)realloc(got, sizeof(*got) * (nb + 1));
      xml_out();
    }
  got[nb].condition.ptr = 0;
  return (got);
}

int		db_factors(t_engine *e, t_db_ind *ind,
			  t_factors *factors)
{
  int		nb;

  nb = 0;
  if (xml_next("surface"))
    {
      factors[nb].type = FACTOR_SURFACE;
      factors[nb++].factor = db_factor_surface(e);
      xml_out();
    }
//   if (xml_next("time"))
//     {
//       *factor[nb].type = FACTOR_TIME;
//       *factors[nb++].factor = db_factor_time(e);
//     }
//   if (xml_next("layer"))
//     {
//       *factor[nb].type = FACTOR_LAYER;
//       *factors[nb++].factor = db_factor_layer(e);
//     }
  factors[nb].type = FACTOR_NULL;
  factors[nb].factor = NULL;
  xml_out();
  return (0);
}

int		db_type(t_engine *e, t_db_ind *ind)
{
  int		i;

  for (i = 0; i < ind->nb[TYPE_TYPES]; i++)
    {
      if (!xml_next("type"))
	return (put_error("Not found type in xml"));
      e->db.types[i].name = xml_getstr("name");
      if (xml_next("speed"))
	db_factors(e, ind, (t_factors*)e->db.types[i].speed);
      if (xml_next("armor"))
	db_factors(e, ind, (t_factors*)e->db.types[i].armor);
      if (xml_next("visibility"))
	db_factors(e, ind, (t_factors*)e->db.types[i].visibility);
      if (xml_next("attack"))
	db_factors(e, ind, (t_factors*)e->db.types[i].attack);
      xml_out();
    }
  return (0);
}
