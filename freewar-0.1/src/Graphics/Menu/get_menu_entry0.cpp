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
// get_menu_entry.cpp for freewar in /u/ept2/skondr_m
// 
// Made by mael skondras
// Login   <skondr_m@epita.fr>
// 
// Started on  Fri May  7 17:08:06 2004 mael skondras
// Last update Fri Jun  4 16:45:44 2004 mael skondras
//

#include "freewar.h"

void	get_menu_entry(t_menu_entry *menu,
		       TiXmlElement *elm_cur,
		       TiXmlElement *elm_head)
{
  if (!strcmp(menu->type, "button"))
    menu->info = get_menu_button(elm_cur);
  if (!strcmp(menu->type, "list"))
    menu->info = get_menu_list(elm_cur);
  if (!strcmp(menu->type, "text"))
    menu->info = get_menu_text(elm_cur);
  if (!strcmp(menu->type, "image"))
    menu->info = get_menu_image(elm_cur);
  if (!strcmp(menu->type, "table"))
    menu->info = get_menu_table(elm_cur);
  if (!strcmp(menu->type, "box"))
    menu->info = get_menu_box(elm_cur);
}

t_menu_button	*get_menu_button(TiXmlElement *elm_cur)
{
  t_menu_button	*info;
  char		*str;
  int		nb;

  info = (t_menu_button*)malloc(sizeof(*info));
  elm_cur->QueryIntAttribute("x", &nb);
  if (nb >= 0)
    info->x = nb;
  elm_cur->QueryIntAttribute("y", &nb);
  if (nb >= 0)
    info->y = nb;
  if (str = xstrdup((char*)elm_cur->Attribute("value")))
    info->value = str;
  if (str = xstrdup((char*)elm_cur->Attribute("sprite")))
    info->sprite = str;
  if (str = xstrdup((char*)elm_cur->Attribute("text_font")))
    info->text_font = str;
  if (str = xstrdup((char*)elm_cur->Attribute("text_color")))
    info->text_color = str;
  elm_cur->QueryIntAttribute("text_size", &nb);
  if (nb)
    info->text_size = nb;
  return (info);
}

t_menu_text	*get_menu_text(TiXmlElement *elm_cur)
{
  t_menu_text	*info;
  char		*str;
  int		nb;

  info = (t_menu_text*)malloc(sizeof(*info));
  elm_cur->QueryIntAttribute("x", &nb);
  if (nb >= 0)
    info->x = nb;
  elm_cur->QueryIntAttribute("y", &nb);
  if (nb >= 0)
    info->y = nb;
  if (str = xstrdup((char*)elm_cur->Attribute("value")))
    info->value = str;
  if (str = xstrdup((char*)elm_cur->Attribute("text_color")))
    info->text_color = str;
  elm_cur->QueryIntAttribute("text_size", &nb);
  if (nb)
    info->text_size = nb;
  if (str = xstrdup((char*)elm_cur->Attribute("text_font")))
    info->text_font = TTF_OpenFont(FONT, info->text_size);
  if (str = xstrdup((char*)elm_cur->Attribute("background")))
    info->background = str;
  return (info);
}

t_menu_list	*get_menu_list(TiXmlElement *elm_cur)
{
  t_menu_list	*info;
  char		*str;
  int		nb;

  info = (t_menu_list*)malloc(sizeof(*info));
  elm_cur->QueryIntAttribute("x", &nb);
  if (nb >= 0)
    info->x = nb;
  elm_cur->QueryIntAttribute("y", &nb);
  if (nb >= 0)
    info->y = nb;
  info->def_val = 0;
  if (str = xstrdup((char*)elm_cur->Attribute("background")))
    info->background = str;
  info->background = xstrdup("FF0000"); //grab defaults instead :)
  if (str = xstrdup((char*)elm_cur->Attribute("left_sprite")))
    info->left_sprite = str;
  if (str = xstrdup((char*)elm_cur->Attribute("right_sprite")))
    info->right_sprite = str;
  if (str = xstrdup((char*)elm_cur->Attribute("text_font")))
    info->text_font = str;
  if (str = xstrdup((char*)elm_cur->Attribute("text_color")))
    info->text_color = str;
  elm_cur->QueryIntAttribute("text_size", &nb);
  if (nb)
    info->text_size = nb;
  return (info);
}
