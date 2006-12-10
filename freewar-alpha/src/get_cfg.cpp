//
// get_cfg.cpp for freewar in /u/ept2/ribas_j/freewar/src
// 
// Made by jonathan ribas
// Login   <ribas_j@epita.fr>
// 
// Started on  Mon May  3 13:14:37 2004 jonathan ribas
// Last update Mon May 17 13:55:56 2004 jonathan huot
//

#include "freewar.h"

char *xml_getspy() {return (xml_getstr("value"));};

int		get_gamecfg(t_cfg *cfg)
{
  // balises obligatoires:
  if (!xml_next("game"))
    return (-1);
  if (!xml_next("name"))
    return (-2);
  cfg->Game = xml_getspy();
  xml_out();
  if (!xml_next("events"))
    return (-3);
  cfg->events = xml_getspy();
  xml_out();

  // balises optionelles:
  if (xml_next("path"))
    {
      cfg->GamePath = xml_getspy();
      xml_out();
    }
  else
    cfg->GamePath = strdup("./");
  if (xml_next("db"))
    {
      cfg->DbPath = xml_getspy();
      xml_out();
    }
  else
    cfg->DbPath = strdup("./");
  xml_out();
  return (0);
}

int		get_videocfg(t_cfg *cfg)
{
  if (!xml_next("video"))
    return (-1);

	if (!xml_next("height"))
	  return (-2);
	cfg->Screen[0] = atoi(xml_getspy());
	xml_out();
	if (!xml_next("width"))
	  return (-3);
	cfg->Screen[1] = atoi(xml_getspy());
	xml_out();
	if (!xml_next("bpp"))
	  return (-4);
	cfg->Mode = atoi(xml_getspy());
	xml_out();

  xml_out();
  return (0);
}

int		get_soundcfg(t_cfg *cfg)
{
  if (!xml_next("sound"))
    return (-1);

	if (!xml_next("left"))
	  return (-2);
	cfg->Sound[0] = atoi(xml_getspy());
	xml_out();
	if (!xml_next("right"))
	  return (-3);
	cfg->Sound[1] = atoi(xml_getspy());
	xml_out();

  xml_out();
  return (0);
}

int		get_cfg(t_cfg *cfg)
{
  put_error("Opening ");
  put_error(FREEWAR_CFG);
  if (xml_init(FREEWAR_CFG))
    return (put_error("Failed to load Engine config file"));
  if (get_gamecfg(cfg) < 0)
    return (put_error("Bad Engine config file"));
  if (get_videocfg(cfg) < 0)
    return (put_error("Bad Engine config file (video)"));
  if (get_soundcfg(cfg) < 0)
    return (put_error("Bad Engine config file (sound)"));

#ifndef WIN32
  cfg->GamePid = 0;
#endif

  return (0);
}
