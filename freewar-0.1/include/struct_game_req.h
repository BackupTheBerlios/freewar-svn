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
** struct_game_req.h for reewar in /goinfre/Freewar/AFirstChaos/src
** 
** Made by stephane petitcolas
** Login   <petitc_s@epita.fr>
** 
** Started on  Fri Jul  2 15:41:23 2004 stephane petitcolas
** Last update Sat Jul  3 21:43:05 2004 stephane petitcolas
*/

typedef	struct	s_id_req
{
  int		select;
  int		info_scale;
  int		attac;
}		t_id_req;

typedef	struct	s_game_info_scale
{
  int		id_req;
  t_coord	pos;
  t_coord	off;
}		t_game_info_scale;

typedef	struct	s_game_select
{
  int		id_req;
  unsigned long	*entitys;
}		t_game_select;

typedef	struct	s_game_select_move
{
  int		id_req;
  t_coord	pos;
  t_coord	off;
}		t_game_select_move;

typedef	struct	s_game_select_attack
{
  int			id_req;
  unsigned long int	id_attacked;
}		t_game_select_attack;

typedef	struct	s_game_select_create_building
{
  int		id_req;
  t_coord	pos;
  char		name[NAME_SIZE];
}		t_game_select_create_building;

typedef	struct	s_game_select_create_units
{
  int		id_req;
  char		nb_units;
  char		name[NAME_SIZE];
}		t_game_select_create_units;
