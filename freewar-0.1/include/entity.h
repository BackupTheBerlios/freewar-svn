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
/*
** entity.h for freewar in /u/ept2/huot_j/Freewar/src
** 
** Made by jonathan huot
** Login   <huot_j@epita.fr>
** 
** Started on  Thu May 13 18:02:35 2004 jonathan huot
** Last update Sun Jul  4 15:26:01 2004 
*/

#ifndef _ENTITY_H
#define _ENTITY_H

#define GAME_MAX_BUFF (8)
#define GAME_MAX_FACTOR (8)

typedef struct		s_layer
{
  char			*name;
  int			depth;
  int			max_units;
  struct s_layer	*shared;
}			t_layer;

typedef struct		s_base_land
{
  char			*name;
  int			idsprite;
  unsigned int		idmapedit;
}			t_base_land;

typedef struct		s_base_instant
{
  int			idtaunt;
  int			idsprite;
  char			*name;
  int			damage;
  int			splash;
  int			speed;
  int			time; //temps qu'il a a vivre
			      //une fois atteint sa cible
}			t_base_instant;

typedef union		u_int_ptrland
{
  int			nb;
  t_base_land		*ptr;
}			t_int_ptrland;

typedef struct		s_factor
{
  //int			condition; // est en fonction du type, un ptr ou int
  t_int_ptrland	condition;
  float			coef;
}			t_factor;

typedef struct		s_factors
{
  int			type; // surface,layers,time
  t_factor		*factor;
}			t_factors;

typedef struct		s_type
{
  char			*name;
  t_factors		speed[GAME_MAX_FACTOR];
  t_factors		armor[GAME_MAX_FACTOR];
  t_factors		visibility[GAME_MAX_FACTOR];
  t_factors		attack[GAME_MAX_FACTOR];
}			t_type;

typedef struct		s_weapon
{
  char			*name;
  int			dmg;
  int			rof;
  int			range;
  t_base_instant	*projectile;
  t_type		**allowed;
}			t_weapon;

typedef struct		s_armor
{
  char			*name;
  int			defense;
  t_type		**allowed;
}			t_armor;

typedef struct		s_base_meter
{
  char			*name;
  char			*type; // global ou aucun (propre a l'entitée)
  int			value;
  int			rr;
  int			is;
  int			sr;
  int			sx;
  int			kv;
  int			min;
  int			max;
}			t_base_meter;

typedef struct		s_meter
{
  t_base_meter		*meter;
  int			value;
}			t_meter;

typedef struct		s_cost
{
  t_base_meter		*which;
  char			*name;
  char			*type; // global ou aucun (propre a l'entitée)
  int			value;
  short			preleave_time; // entre 0 et 10, 0: les sous sont retires qd la, sera implementer plus tard construction/sort commence, 10 a la fin.
}			t_cost;

typedef struct		s_attack
{
  struct s_base_entity	*against;
  int			speed;
  int			damage; // peux etre negatif (soins)
  t_cost		*cost;
}			t_attack;

typedef struct		s_create
{
  struct s_base_entity	*base;
  int			time; // time_to_make
  struct s_base_entity	**prequesite;
  t_cost		*cost; // ne pas oublier d'ajouter les sous de l'entite
}			t_create;

typedef struct		s_instant
{
  struct s_base_instant	*base;
  struct s_coord	dest;
}			t_instant;

typedef struct		s_ritual
{
  t_base_instant	**instant;
  struct s_base_entity	**transform;
}			t_ritual;

typedef struct		s_action
{
  int			idtaunt[NB_ACTION];// pour chaque action
  int			idsprite[NB_ACTION];// (move/attack/died/live/create)
  int			move_speed;
  t_attack		*attack;
  t_ritual		died;
  t_ritual		live;
  t_create		*create;
}			t_action;

typedef struct		s_base_entity
{
  unsigned int		idmapedit;
  char			*name;
  int			idsprite; // au repos
  t_layer		**layer;
  t_type		**type;
  t_weapon		**weapon;
  t_armor		**armor;
  int			max_units;
  int			visibility;
  t_cost		*costs;
  t_base_meter		*meters;
  t_action		actions;
}			t_base_entity;

typedef struct		s_entity
{
  int			idgfx;
  unsigned char		action; // action actuelle 
  unsigned char		direction; // dans quelle direction il fait son action
  unsigned char		time; // dans quel cycle de l'action il est
  struct s_entity	*against; // sur qui il fait l'action
  t_coord		where; // s'il ne fait pas d'action sur qqn, il le fait ou?
  t_coord		pos; // sa position
  t_coord		off; // sa position
  unsigned char		buff[GAME_MAX_BUFF];
  t_meter		*meter;
  t_base_entity		*data;
  short			action_fail;

  /* dans un premier temps, stoquage en liste chainee */
  /* informations qui ne seront pas presentes apres : */
  int			app; // son appartenance
  bool			update; // pour savoir si cette entitee a des metters
				// a updater..
  unsigned long		id;
  struct s_wait_action	*queued;
  struct s_entity	*next;
}			t_entity;

typedef struct		s_db
{
  int			nb_layers;
  t_layer		*layers;
  int			nb_meters;
  t_base_meter		*meters;
  int			nb_lands;
  t_base_land		*lands;
  int			nb_types;
  t_type		*types;
  int			nb_weapons;
  t_weapon		*weapons;
  int			nb_armors;
  t_armor		*armors;
  int			nb_entities;
  t_base_entity		*entities;
  int			nb_instants;
  t_base_instant	*instants;
}			t_db;

#endif
