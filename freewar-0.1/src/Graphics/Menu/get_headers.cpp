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
// get_headers.cpp for freewar in /u/ept2/skondr_m
// 
// Made by mael skondras
// Login   <skondr_m@epita.fr>
// 
// Started on  Mon May 24 08:41:57 2004 mael skondras
// Last update Mon May 24 08:52:14 2004 mael skondras
//

#include "freewar.h"

t_menu_headers		*get_headers(TiXmlElement *elm_root)
{
  TiXmlElement		*elm_cur;
  t_menu_headers	*menu_headers = 0;
  t_menu_headers	*tmp_elem;
  
  elm_cur = elm_root->FirstChildElement("menu");
  menu_headers = (t_menu_headers*)malloc(sizeof(*menu_headers));
  menu_headers->menus = get_submenus(elm_cur, elm_root, menu_headers);
  menu_headers->name = xstrdup((char*)elm_cur->Attribute("name"));
  menu_headers->next = 0;
  while (elm_cur = elm_cur->NextSiblingElement("menu"))
    {
      tmp_elem = (t_menu_headers*)malloc(sizeof(*menu_headers));
      tmp_elem->menus = get_submenus(elm_cur, elm_root, menu_headers);
      xstrncpy(tmp_elem->name, (char*)elm_cur->Attribute("name"), BUF_SIZE);
      tmp_elem->next = menu_headers;
      menu_headers = tmp_elem;
    }
  return (menu_headers);
}

t_menu_entry		*find_header(char *name, t_menu_headers *menu_headers)
{
  while(menu_headers)
    {
      if(!strcmp(menu_headers->name, name))
	return(menu_headers->menus);
      else
	menu_headers = menu_headers->next;
    }
  return (0);
}
