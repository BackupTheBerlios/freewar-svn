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
// parse-menu.cpp for freewar in /u/ept2/skondr_m
// 
// Made by mael skondras
// Login   <skondr_m@epita.fr>
// 
// Started on  Fri May  7 14:33:17 2004 mael skondras
// Last update Mon Jun 14 15:03:33 2004 mael skondras
//

#include "freewar.h"

void		link_menus(t_menu_entry *menus, t_menu_entry *parent)
{
  int	i;
  
  for (i = 0; menus[i].uid; i++)
    {
      if (!strcmp(menus[i].uid, "back"))
	menus[i].submenus = parent;
      else if (menus[i].submenus > 0)
	link_menus(menus[i].submenus, menus);
    }
}

t_menu_entry		*get_submenus(TiXmlElement *elm_parent,
				      TiXmlElement *elm_head,
				      t_menu_headers *menu_headers)
{
  int			i = 0;
  int			new_element = 1;
  TiXmlElement		*elm_cur;
  t_menu_entry		*menus = 0;
  char			*tag = "menu";

  while (42)
    {
      if (new_element)
	{
	  elm_cur = elm_parent->FirstChildElement(tag);
	  new_element = 0;
	}
      else
	elm_cur = elm_cur->NextSiblingElement(tag);
      if(!elm_cur)
	{
	  if(!strcmp("menu", tag))
	    {
	      tag = "entity";
	      new_element = 1;
	      continue;
	    }
	  else
	    break;
	}
      if (elm_cur->Attribute("name"))
	return (find_header((char*)elm_cur->Attribute("name"), menu_headers));
      if (!menus)
	menus = (t_menu_entry*)malloc(sizeof(*menus));
      else
	menus = (t_menu_entry*)realloc(menus, (sizeof(*menus) * (i + 1)));

      menus[i].uid = xstrdup((char*)elm_cur->Attribute("uid"));
      menus[i].type = xstrdup((char*)elm_cur->Attribute("type"));
      if (!strcmp("menu", tag))
	menus[i].submenus = get_submenus(elm_cur, elm_head, menu_headers);
      else
	menus[i].submenus = 0;
       get_menu_entry(&(menus[i]), elm_cur, elm_head);
      i++;
    }
  menus = (t_menu_entry*)realloc(menus, (sizeof(*menus) * (i + 1)));
  menus[i].uid = 0;
  return (menus);
}

t_menu_entry		*parse_menu()
{
  TiXmlDocument		doc(DB_MENU);
  TiXmlElement		*elm_root;
  TiXmlElement		*elm_head;
  char			err_msg[BUF_SIZE];
  t_menu_entry		*menus = 0;
  t_menu_headers	*menu_headers;

  fprintf(fd_log, "%s: Loading menu description file: %s ...", NAME, DB_MENU);
  if (!(doc.LoadFile()))
    fprintf(fd_log, "failed.\n");
  else
    fprintf(fd_log, "done.\n");
  if ((elm_root = doc.FirstChildElement("root")))
    {
      elm_head = elm_root->FirstChildElement("head");
      menu_headers = get_headers(elm_head);
      menus = get_submenus(elm_root, elm_head, menu_headers);
      link_menus(menus, 0);
    }
  else
    fprintf(fd_log, "%s: Bad menu description file. No <root> tag.\n", NAME);
  return(menus);
}
