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
#include "freewar.h"

t_menu_uid	uidtab[] =
  {
    {"map", uid_map},
    {"map_name", uid_map_name},
    {"ressources", uid_ressources},
    {"server_name", uid_servername},
    {"maxplayers", uid_maxplayers},
    {"players", uid_players},
    {"start", uid_start},
    {"back", uid_back},
    {"play", uid_play},
    {"create_game", uid_create_game},
    {"join_game", uid_join_game},
    {"specify_game", uid_specify_game},
    {"foundservers", uid_foundservers},
    {"refresh", uid_refresh},
    {"server_hostname", uid_server_hostname},
    {"server_port", uid_server_port},
    // {"options", uid_options},
    //    {"display", uid_map},
    //    {"resolution", uid_map},
    //    {"display_mode", uid_map},
    //    {"sound", uid_map},
    //    {"vol_music", uid_map},
    //    {"vol_fx", uid_map},
    //    {"network", uid_map},
    //    {"net_interfaces", uid_map},
    //    {"keyboard", uid_map},
    {"test", uid_test},
    {"credits", uid_credits},
    {"exit", uid_exit},
    {0, 0}
  };

int	call_entity_func(t_menu_entry *menus, void *ptr)
{
  int				tabos;

  for(tabos = 0; uidtab[tabos].uidstr; tabos++)
    if (!strcmp(uidtab[tabos].uidstr, menus->uid))
      {
	uidtab[tabos].uidfunc(menus, ptr);
	break;
      }
  return(0);
}

int		run_menu(t_display *win)
{
  int				menuos;
  t_return_button		*ptr = 0;
  t_menu_entry			*menus;

  fflush(fd_log);
  if(menus = parse_menu())
    fprintf(fd_log, "%s: Menu loaded succesfully.\n", NAME);
  else
    {
      fprintf(fd_log, "%s: Failed Loading menu.\n", NAME);
      return (1);
    }
  fflush(fd_log);
  while (menus)
    {
      for (menuos = 0; menus[menuos].uid; menuos++)
	call_entity_func(&(menus[menuos]), 0);
      ptr = (t_return_button*)launch_menu(win, menus);
      if (ptr > 0)
	{
	  if (ptr->menu < 0)
	    return (1);
	  call_entity_func(&(menus[ptr->menu]), ptr);
	  if (!strcmp(menus[ptr->menu].uid, "start"))
	    return (0);
	  else if (menus[ptr->menu].submenus > 0)
	    menus = menus[ptr->menu].submenus;
	  else if (!strcmp(menus[ptr->menu].uid, "exit"))
	    return (1);
	}
    }
  return (1);
}
