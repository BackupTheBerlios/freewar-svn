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
** struct_req.h for freewar in /root/Freewar/include
** 
** Made by 
** Login   <root@epita.fr>
** 
** Started on  Wed Jun 30 15:39:54 2004 
** Last update Sat Jul  3 11:53:43 2004 
*/

typedef struct		s_info_scale
{
  unsigned char		action;
  int			app;
  int			id;
  char			name[NAME_SIZE];
}			t_info_scale;

typedef struct		s_req_info_scale
{
  int			id_req;
  char			nb_ent; // -1 si erreur
  t_info_scale		ent[MAX_ENTITY_ON_SCALE];
}			t_req_info_scale;

/* sachant que ent[MAX_ENTITY_ON_SCALE] ne sera pas  */
/* rempli a fond suivant le nombre d'entitee qu'on va recevoir */

typedef struct		s_req_select_move
{
  int			id_req;
  int			id_action; // -1 si erreur
}			t_req_select_move;

typedef struct		s_req_select_attack
{
  int			id_req;
  int			id_action; // -1 si erreur
}			t_req_select_attack;
//je sais, c'est les memes hehe

typedef struct		s_req_select_create_units
{
  int			id_req;
  int			id_action; // -1 si erreur
}			t_req_select_create_units;

typedef struct		s_req_select_create_building
{
  int			id_req;
  int			id_action; // -1 si erreur
}			t_req_select_create_building;
