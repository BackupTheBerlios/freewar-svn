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
// load_db_init.cpp for freewar in /u/ept2/ribas_j/freewar/src
// 
// Made by jonathan ribas
// Login   <ribas_j@epita.fr>
// 
// Started on  Mon May  3 13:15:45 2004 jonathan ribas
// Last update Mon May 17 13:54:13 2004 jonathan huot
//

#include "freewar.h"

 /* dsl si c'est porc :( */
/* je deporqueriserai plus tar :) */

int		load_db_init(t_db_info *db_info, t_cfg *cfg)
{
  TiXmlDocument doc(DB_PATH);
  const char	*buf;
  int		int_buf;
  int		i;
  char		err_msg[BUF_SIZE];
  
  if (doc.LoadFile() == false)
    {
      char	*err = "Failed to load game database file: ";
      strcpy(err_msg, err);
      strcat(err_msg, DB_PATH);
      //send_error_trap(err_msg, 1);
      return (put_error(err_msg));
    }
  puts("\n<load_db_init>");
  TiXmlElement* elm_root = doc.FirstChildElement("root");
  if (elm_root)
    {
      TiXmlElement* elm_head = elm_root->FirstChildElement("head");
      if (elm_head)
	{
	  TiXmlElement* elm_version = elm_head->FirstChildElement("version");
	  if (elm_version)
	    {
	      if ((buf = elm_version->Attribute("db_name")) == NULL)
		return(put_error("DB is imcomplete: db_name"));
	      strcpy(db_info->game, (char*)buf);
	      printf("Game: [%s]\n", db_info->game);
	      
	      if ((buf = elm_version->Attribute("db_verion")) == NULL)
		return(put_error("DB is imcomplete: db_verion"));
	      strcpy(db_info->version, (char*)buf);
	      printf("version: [%s]\n", db_info->version);
	    }
	  else
	    return(put_error("DB as not members name <version> in <head>"));
	}
      else
	return(put_error("DB as not members name <head> in <root>"));

      TiXmlElement* elm_races = elm_root->FirstChildElement("races");
      if (elm_races)
	{
	  TiXmlElement* elm_race = elm_races->FirstChildElement("race");
	  if (elm_race)
	    {
	      if ((buf = elm_race->Attribute("name")) == NULL)
		return(put_error("DB is imcomplete: race name"));
	      strcpy(db_info->races[0], (char*)buf);
	      printf("race[0]: [%s]\n", db_info->races[0]);
	    }
	  else
	    return(put_error("DB as not members name <race> in <races>"));
	  for (i = 1; elm_race = elm_race->NextSiblingElement("race"); i++)
	    {
	      if ((buf = elm_race->Attribute("name")) == NULL)
		return(put_error("DB is imcomplete: race name"));
	      strcpy(db_info->races[i], (char*)buf);
	      printf("race[%i]: [%s]\n", i, db_info->races[i]);
	    }
	  db_info->races[i][0] = 0;
	}	  
      else
	return(put_error("DB as not members name <races> in <head>"));

      TiXmlElement* elm_maps = elm_root->FirstChildElement("maps");
      if (elm_maps)
	{
	   TiXmlElement* elm_map = elm_maps->FirstChildElement("map");
	  if (elm_map)
	    {
	      if ((buf = elm_map->Attribute("name")) == NULL)
		return(put_error("DB is imcomplete: map name"));
	      strcpy(db_info->map_def[0].name, (char*)buf);
	      printf("map[0]: [%s]", db_info->map_def[0].name);

	      if ((elm_map->QueryIntAttribute((const char*)"max_players", &int_buf))
		  != TIXML_SUCCESS)
		return(put_error("DB is imcomplete: map max_players"));
	      db_info->map_def[0].max_players = int_buf;
	      printf(" max_players: [%i]\n", db_info->map_def[0].max_players);
	      
	    }
	  else
	    return(put_error("DB as not members name <map> in <maps>"));
	  for (i = 1; elm_map = elm_map->NextSiblingElement("map"); i++)
	    {
	      if ((buf = elm_map->Attribute("name")) == NULL)
		return(put_error("DB is imcomplete: map name"));
	      strcpy(db_info->map_def[i].name, (char*)buf);
	      printf("map[%i]: [%s]", i, db_info->map_def[i].name);
	   
	      if ((elm_map->QueryIntAttribute((const char*)"max_players", &int_buf))
		  != TIXML_SUCCESS)
		return(put_error("DB is imcomplete: map max_players"));
	      db_info->map_def[i].max_players = int_buf;
	      printf(" max_players: [%i]\n", db_info->map_def[i].max_players);
	    }
	  db_info->map_def[i].name[0] = 0;
	  db_info->map_def[i].max_players = 0;
	}
      else
	return(put_error("DB as not members name <maps> in <root>"));
    }
  else
    return(put_error("DB as not members name <root>"));
  puts("</load_db_init>\n");
  return (0);
}
