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
// get_menu_entry1.cpp for freewar in /u/ept2/skondr_m
// 
// Made by mael skondras
// Login   <skondr_m@epita.fr>
// 
// Started on  Mon May 24 08:44:09 2004 mael skondras
// Last update Mon May 24 19:32:46 2004 mael skondras
//

#include "freewar.h"

void		get_menu_cols(TiXmlElement *elm_cur, t_menu_table *info)
{
  // parse all sub entities of type "col"
  // copy the title in the **cols
  // copy the width in the colswdth tab
  ;
}

t_menu_table	*get_menu_table(TiXmlElement *elm_cur)
{
  t_menu_table	*info;
  char		*str;
  int		nb;
  
  info = (t_menu_table*)malloc(sizeof(*info));
  elm_cur->QueryIntAttribute("x", &nb);
  if (nb >= 0)
    info->x = nb;
  elm_cur->QueryIntAttribute("y", &nb);
  if (nb >= 0)
    info->y = nb;
  elm_cur->QueryIntAttribute("width", &nb);
  if (nb >= 0)
    info->width = nb;
  elm_cur->QueryIntAttribute("height", &nb);
  if (nb >= 0)
    info->height = nb;
  if (str = xstrdup((char*)elm_cur->Attribute("title")))
    info->title = str;
  if (str = xstrdup((char*)elm_cur->Attribute("background")))
    info->background = str;
  if (str = xstrdup((char*)elm_cur->Attribute("text_font")))
    info->text_font = str;
  if (str = xstrdup((char*)elm_cur->Attribute("text_color")))
    info->text_color = str;
  elm_cur->QueryIntAttribute("text_size", &nb);
  if (nb)
    info->text_size = nb;
  get_menu_cols(elm_cur, info);
  return (info);
}

t_menu_box	*get_menu_box(TiXmlElement *elm_cur)
{
  t_menu_box	*info;
  char		*str;
  int		nb;
  
  info = (t_menu_box*)malloc(sizeof(*info));
  elm_cur->QueryIntAttribute("x", &nb);
  if (nb >= 0)
    info->x = nb;
  elm_cur->QueryIntAttribute("y", &nb);
  if (nb >= 0)
    info->y = nb;
  info->yes = 0;
  if (str = xstrdup((char*)elm_cur->Attribute("background")))
    info->background = str;
  if (str = xstrdup((char*)elm_cur->Attribute("sprite")))
    info->sprite = str;
  if (str = xstrdup((char*)elm_cur->Attribute("value")))
    info->value = str;
  if (str = xstrdup((char*)elm_cur->Attribute("text_font")))
    info->text_font = str;
  if (str = xstrdup((char*)elm_cur->Attribute("text_color")))
    info->text_color = str;
  elm_cur->QueryIntAttribute("text_size", &nb);
  if (nb)
    info->text_size = nb;
  return (info);
}

t_menu_image	*get_menu_image(TiXmlElement *elm_cur)
{
  t_menu_image	*info;
  char		*str;
  int		nb;

  info = (t_menu_image*)malloc(sizeof(*info));
  elm_cur->QueryIntAttribute("x", &nb);
  if (nb >= 0)
    info->x = nb;
  elm_cur->QueryIntAttribute("y", &nb);
  if (nb >= 0)
    info->y = nb;
  if (str = xstrdup((char*)elm_cur->Attribute("path")))
    info->path = str;
  return (info);
}
