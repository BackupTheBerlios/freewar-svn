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

#ifndef _STRUCT_H_
#define _STRUCT_H_

#ifndef STRUCT_S_COORD
#define STRUCT_S_COORD
typedef struct		s_coord
{
  unsigned short	x;
  unsigned short	y;
}			t_coord;
#endif

#include "entity.h"
#include "map.h"

typedef struct	s_cfg
{
  /* game */
  char	Game[BUF_SIZE];
  char	GamePath[BUF_SIZE];
  char  DbPath[BUF_SIZE];

  /* video */
  int	Screen[2]; //ex: 800x600
  int	Mode; //nbr of bit
  int	Type; // hardware, fullscreen, opengl..

  /* sound */
  int	Sound[2]; //ex: 255 left 255 rigth
}	t_cfg;

typedef struct		s_map_def
{
  char			name[NAME_SIZE];
  int			max_players;
}			t_map_def;

typedef struct		s_db_info
{
  char			game[NAME_SIZE];
  char			version[NAME_SIZE];
  int			max_player;
  char			races[MAX_RACES][NAME_SIZE];
  t_map_def		map_def[MAX_MAPS];
}			t_db_info;

typedef struct		s_player
{
  short			type; // open/close/human/computer easy/..
  char			name[NAME_SIZE];
  Uint32		color;
  short			race;
  short			team;
  t_client		*client;
}			t_player;

typedef struct		s_game_param
{
  char			nb_players;
  t_player		players[FW_MAX_CLIENTS];
  char			name[NAME_SIZE];
  int			id_map;
  // d'autres infos comme nb d'unites au commencement, ressources, etc...
}			t_game_param;

typedef struct	s_info_player
{
  char			id_player;
}			t_info_player;

/*
** informations recu du jeu
*/
typedef struct		s_game
{
  t_coord		pos_arena;
  t_coord		off_arena;
  int			screen;
  int			hud;
  int			select;
  int			arena_lands; // layer d'affichage
  int			arena_select;//
  int			*arena_units;//
  int			arena_sfx;
  int			w_main;
  int			h_main;
  int			offw_main;
  int			offh_main;
  int			event_ok;
}			t_game;

/*
** the big structure du moteur
*/
typedef struct		s_engine
{
  bool			console;
  bool			server;
  int			id_player;
  unsigned short	nb_players;
  t_player		players[FW_MAX_CLIENTS];
  struct s_map_data	map_data;
  t_scale		**scales;
  t_meter		*globals;
  t_meter		**meters; // * nb_players
  t_db			db;
  t_game		g;
  t_entity		*entity;
  struct s_do_action	*actions;
  unsigned long		id;
  unsigned long		id_action;
  t_event		*events;
  t_other_events	*other_events;
  t_entity		**select[FW_MAX_SELECT];  // select[sel][player][entity*]
  int			select_gfx[FW_MAX_SELECT];
  int			select_sfx[FW_MAX_SELECT];
  int			select_img_44;
  int			select_img;
  int			select_img_neutral;
  int			select_img_ennemy;
  int			gfx_null;
  Uint32		time;
}			t_engine;

/*
** t_error contiendra un message de debug + un booleen ki signale
** si l'erreur est fatale au bon deroulement du jeu
*/

typedef	struct	s_error
{
  char		debug[BUF_SIZE];
  int		lethal;
}		t_error;

typedef struct			s_items
{
  unsigned int			id;
  char				*path;
  bool				land;
  SDLKey			key;
}				t_items;

/*
  LA STRUCTURE DU KWISTEEEE
*/

#endif
