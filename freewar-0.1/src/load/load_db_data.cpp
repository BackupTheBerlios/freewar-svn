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
// load_bdd_data.cpp for freewar in /u/ept2/huot_j/Freewar/src
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Sun May  9 18:27:55 2004 jonathan huot
// Last update Sun Jun 27 15:07:37 2004 
//

#include "freewar.h"

int		load_db(t_engine *e, char *file)
{
  t_db_ind	ind;

  if (xml_init(file))
    return (1);
  if (db_index(e, &ind))
    return (1);
  if (e->db.nb_layers && db_layers(e))
    return (1);
  if (e->db.nb_meters && db_meters(e))
    return (1);
  if (e->db.nb_lands && db_base_land(e, &ind))
    return (1);
  if (e->db.nb_types && db_type(e, &ind))
    return (1);
  if (e->db.nb_weapons && db_weapon(e, &ind))
    return (1);
  if (e->db.nb_armors && db_armor(e, &ind))
    return (1);
  if (e->db.nb_entities && db_base_entity(e, &ind))
    return (1);
  if (e->db.nb_instants && db_base_instant(e, &ind))
  return (1);
  free_index(&ind);
  return (0);
}

void		init_db(t_engine *e)
{
  e->db.nb_layers = 0;
  e->db.nb_meters = 0;
  e->db.nb_lands = 0;
  e->db.nb_types = 0;
  e->db.nb_weapons = 0;
  e->db.nb_armors = 0;
  e->db.nb_entities = 0;
  e->db.nb_instants = 0;
  e->db.layers = 0;
  e->db.meters = 0;
  e->db.lands = 0;
  e->db.types = 0;
  e->db.weapons = 0;
  e->db.armors = 0;
  e->db.entities = 0;
  e->db.instants = 0;
}

int		load_db_data(t_engine *e, t_game_param *gp, t_cfg *cfg)
{
  // initialise tout, au cas ou
  init_db(e);
  // charge la bdd
  if (load_db(e, cfg->DbPath))
    return (put_error("Load DB failed.."));
  // initialisation de tous les compteurs de la bdd
  if (init_globals(e))
    return (put_error("Error initialising globals"));
  return (0);
} 
