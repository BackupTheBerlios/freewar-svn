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
// uid_preplay.cpp for freewar in /u/ept2/skondr_m
// 
// Made by mael skondras
// Login   <skondr_m@epita.fr>
// 
// Started on  Wed Jun  2 12:27:23 2004 mael skondras
// Last update Fri Jun  4 14:44:25 2004 mael skondras
//

#include "freewar.h"

void	*uid_create_game(t_menu_entry *menus, void *info)
{
  //setmod "SERVER"
  /*stock_msg(&cnt->clients[0], TAG_CREATE, 0, NULL);
  */return (0);
}

void		*uid_join_game(t_menu_entry *menus, void *info)
{
  //char		msg[42];
  //int		port;
  //size_t	len;

  //port = NET_GAME_PORT;
  //memcpy((void*)msg, &port, sizeof(port));
  //strcpy(msg + sizeof(port), "10.251.3.62");
  //len = sizeof(port) + (sizeof(*msg) * strlen("10.251.3.62"));
  //stock_msg(&cnt->clients[0], TAG_JOIN, (int)(sizeof(port) + len), msg);
  return (0);
}

void	*uid_specify_game(t_menu_entry *menus, void *info)
{
  //requete affichage ==> stef
  // demande une IP et un port
  // envoie des parametres, et setmode "CLIENT"
  return (0);
}

void	*uid_foundservers(t_menu_entry *menus, void *info)
{
  return (0);
}

void	*uid_refresh(t_menu_entry *menus, void *info)
{
  return (0);
}
