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
#ifndef _STRUCT_ACTION_H_
#define _STRUCT_ACTION_H_

typedef struct		s_do_action
{
  char			tag;
  unsigned long		id;
  
  t_entity		*entity;
  
  /* attaque */
  t_entity		*attaked; // l'entitee attaquee
  int			damages; // le calcul des damages infliger a
				// chaque attaque, calculer avec la deffense
  int			cpt_time; // compteur incrementer de 1
  int			time_take; // egal au rate
  int			range;

  /* moove */
  t_coord		*path; // le chemin
  t_coord		end_of_path; // l'arrivee
  t_coord		end_off; // l'off d'arrivee
  int			mini_scale_before_next;
  int			mini_increment_size;
  int			move_on_scale_len;
  t_coord		dir;
  bool			first_off;
  unsigned char		h;
  unsigned char		w;
  int			length_of_path; // le nombre de cases sur le chemin
  int			cpt_path;
  int			speed; // le nombre de cycle que mets l'entitees
			       // avant de changer de case
  
  /* construction */ // v les meme plus haut
/*   int			time_take; // egal au temps de construction */
/*   int			cpt_time; // compteur incrementer de 1 */
  int			nb_construct; // nombre d'entitees construites;
  int			nb_must_make;
  t_coord		pos; // si tag == ACTION_CREATE_BUILDING > c'est la place ou
			     // placer l'entitee
  t_base_entity		*entity_c; // l'entitee qui est construite;

  struct s_do_action	*next;
}			t_do_action;

typedef struct		s_wait_action
{
  char			tag;

  t_entity		*against; // sur qui
  t_coord		dest;
  t_coord		off;
  t_base_entity		*what; // sur quoi
  int			arg;

  struct s_wait_action	*next;
}			t_wait_action;

#endif
