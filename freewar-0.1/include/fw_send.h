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
** fw_send.h for freewar in /root/Freewar/src
** 
** Made by 
** Login   <root@epita.fr>
** 
** Started on  Fri Jul  9 14:58:50 2004 
** Last update Mon Jul 12 15:14:09 2004 
*/

#ifndef _FW_SEND_H_
#define _FW_SEND_H_

typedef struct	s_fw_send_action
{
  unsigned long	id_ent;
  unsigned char	action;
}		t_fw_send_action;

typedef struct	s_fw_send_pos
{
  unsigned long	id_ent;
  t_coord	pos;
}		t_fw_send_pos;

typedef struct	s_fw_send_off
{
  unsigned long	id_ent;
  t_coord	off;
}		t_fw_send_off;

typedef struct	s_fw_send_ent_meter
{
  unsigned long	id_ent;
  char		name[NAME_SIZE];
  int		new_val;
}		t_fw_send_ent_meter;

/* typedef struct	s_fw_send_ply_meter */
/* { */
/*   char		name[NAME_SIZE]; */
/*   int		new_val; */
/* }		t_fw_send_ply_meter; */

/* typedef struct	s_fw_send_gl_meter */
/* { */
/*   char		name[NAME_SIZE]; */
/*   int		new_val; */
/* }		t_fw_send_gl_meter; */

typedef	struct	s_fw_send_create_ent
{
  unsigned long	id_ent;
  char		name[NAME_SIZE];
  int		app;
  t_coord	pos;
  t_coord	off;
}		t_fw_send_create_ent;

typedef	struct	s_fw_send_del_ent
{
  unsigned long	id_ent;
}		t_fw_send_del_ent;


typedef	struct	s_fw_send_del_ent_in_map
{
  unsigned long	id_ent;
}		t_fw_send_del_ent_in_map;


typedef	struct	s_fw_send_dir
{
  unsigned long	id_ent;
  unsigned char direction;
}		t_fw_send_dir;


#endif
