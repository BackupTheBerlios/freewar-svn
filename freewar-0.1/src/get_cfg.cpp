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
// get_cfg.cpp for freewar in /u/ept2/ribas_j/freewar/src
// 
// Made by jonathan ribas
// Login   <ribas_j@epita.fr>
// 
// Started on  Mon May  3 13:14:37 2004 jonathan ribas
// Last update Mon May 17 13:55:56 2004 jonathan huot
//

#include "freewar.h"

/* dsl si c'est porc :( */
/* je deporqueriserai plus tar :) */

int		get_cfg(t_cfg *cfg)
{
  TiXmlDocument doc(FREEWAR_CFG);
  const char	*buf;
  int		int_buf;
  char		err_msg[BUF_SIZE];
  
  if (doc.LoadFile() == false)
    {
      char	*err = "Failed to load engine config file: ";
      strcpy(err_msg, err);
      strcat(err_msg, FREEWAR_CFG);
      //send_error_trap(err_msg, 1);
      return (put_error(err_msg));
    }
  puts("\n<get_cfg>");
  TiXmlElement* elm_root = doc.FirstChildElement("root");
  if (elm_root)
    {
      TiXmlElement* elm_game = elm_root->FirstChildElement("game");
      if (elm_game)
	{
	  if ((buf = elm_game->Attribute("Game")) == NULL)
	    return(put_error("FREEWAR_CFG is imcomplete: Game"));
	  strcpy(cfg->Game, (char*)buf);
	  printf("Game: [%s]\n", cfg->Game);

	  if ((buf = elm_game->Attribute("GamePath")) == NULL)
	    return(put_error("FREEWAR_CFG is imcomplete: GamePath"));
	  strcpy(cfg->GamePath, (char*)buf);
	  printf("GamePath: [%s]\n", cfg->GamePath);

	  if ((buf = elm_game->Attribute("DbPath")) == NULL)
	    return(put_error("FREEWAR_CFG is imcomplete: DbPath"));
	  strcpy(cfg->DbPath, (char*)buf);
	  printf("DbPath: [%s]\n", cfg->DbPath);
	}
      else
	return(put_error("FREEWAR_CFG as not members name <game> in <root>"));

      TiXmlElement* elm_video = elm_root->FirstChildElement("video");
      if (elm_video)
	{
	  if ((elm_video->QueryIntAttribute((const char*)"VideoNbBit", &int_buf))
	      != TIXML_SUCCESS)
	    return(put_error("FREEWAR_CFG is imcomplete: video VideoNbBit"));
	  cfg->Mode = int_buf;
	  printf("VideoNbBit: [%i]\n", cfg->Mode);
	  
	  if ((elm_video->QueryIntAttribute((const char*)"screen_width", &int_buf))
	      != TIXML_SUCCESS)
	    return(put_error("FREEWAR_CFG is imcomplete: video screen_width"));
	  cfg->Screen[0] = int_buf;
	  printf("Screen_Width: [%i]\n", cfg->Screen[0]);

	  if ((elm_video->QueryIntAttribute((const char*)"screen_height", &int_buf))
	      != TIXML_SUCCESS)
	    return(put_error("FREEWAR_CFG is imcomplete: video screen_height"));
	  cfg->Screen[1] = int_buf;
	  printf("screen_height: [%i]\n", cfg->Screen[1]);
	}
      else
	return(put_error("FREEWAR_CFG as not members name <video> in <root>"));

      TiXmlElement* elm_sound = elm_root->FirstChildElement("sound");
      if (elm_sound)
	{
	  if ((elm_sound->QueryIntAttribute((const char*)"Left", &int_buf))
	      != TIXML_SUCCESS)
	    return(put_error("FREEWAR_CFG is imcomplete: sound Left"));
	  cfg->Sound[0] = int_buf;
	  printf("Sound_Left: [%i]\n", cfg->Sound[0]);
	  
	  if ((elm_sound->QueryIntAttribute((const char*)"Right", &int_buf))
	      != TIXML_SUCCESS)
	    return(put_error("FREEWAR_CFG is imcomplete: sound Right"));
	  cfg->Sound[1] = int_buf;
	  printf("Sound_Right: [%i]\n", cfg->Sound[1]);
	}
      else
	return(put_error("FREEWAR_CFG as not members name <video> in <root>"));
    }
  else
    return(put_error("FREEWAR_CFG as not members name <root>"));    
#ifndef WIN32
	  cfg->GamePid = 0;
#endif
puts("</get_cfg>");
  return (0);
}
