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

void	*uid_server_hostname(t_menu_entry *menus, void *info)
{
  if (info)
    cnt->host = strdup(((t_return_text*)info)->value);
  //else
  //  cnt->host = strdup(((t_menu_text*)(menus->info))->value);
  return (0);
}

void	*uid_server_port(t_menu_entry *menus, void *info)
{
  return (0);
}