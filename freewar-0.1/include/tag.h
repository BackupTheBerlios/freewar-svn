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
** tag.h for freewar in /root/Freewar/include
** 
** Made by 
** Login   <root@epita.fr>
** 
** Started on  Sat Jul  3 17:47:05 2004 
** Last update Mon Jul 12 15:15:32 2004 
*/
#ifndef _TAG_H_
#define _TAG_H_

#define NB_TAG (52)

/*******
* TAGS *
*******/

#ifndef TAG_WELCOME
#define TAG_WELCOME		(0)
#endif

#define TAG_GAME_FULL		(1)
#define TAG_GAME_STATUS		(2)
#define TAG_LAUNCH_GAME		(3)
#define TAG_GP_PLAYERS		(4)
#define TAG_CREATE		(5)
#define TAG_JOIN		(6)
#define TAG_LEAVE		(26)
#define TAG_PING		(7)
#define TAG_INFO		(8)
#define TAG_NULL		(9)
#define TAG_PLAYERS_READY	(10)
#define TAG_ECT			(11)
#define TAG_INIT_SOUND_DONE	(12)
#define TAG_INIT_SOUND_NEWS_PARAM (13)
#define TAG_INIT_SOUND_OPEN_DEVICE (13)
#define TAG_INIT_DISPLAY_DONE	(14)
#define TAG_INIT_DISPLAY_NEWS_PARAM (15)
#define TAG_INIT_DISPLAY_CREATE_AND_OPEN_SCREEN (16)
#define TAG_INIT_DISPLAY_NEW_SURFACE (17)
#define TAG_INIT_DISPLAY_LOAD_SURFACE (18)
#define TAG_INIT_DISPLAY_EDIT_SURFACE (19)
#define TAG_EVENTS		(20)
#define TAG_EXIT		(21)
#define TAG_POS_SCREEN		(22)
#define	TAG_EVENT_OK		(23)
#define	TAG_EDIT_ARENA_SURFACE	(24)
#define	TAG_EXECUTION		(25)

#ifndef TAG_DEAD
#define TAG_DEAD		(42)
#endif

#define TAG_PLAYER_INFO	(30)

// warning: 42 deja pris plus haut

#define TAG_SELECT		(50)
#define TAG_SELECT_MOVE		(51)
#define TAG_SELECT_ATTACK	(52)
#define TAG_SELECT_CREATE_BUILDING (53)
#define TAG_SELECT_CREATE_UNITS (54)
#define TAG_SELECT_KILL		(55)
#define TAG_INFO_SCALE		(56)

#define TAG_SELECT_REPLY	(70)
#define TAG_SELECT_MOVE_REPLY	(71)
#define TAG_SELECT_ATTACK_REPLY	(72)
#define TAG_SELECT_CREATE_BUILDING_REPLY (73)
#define TAG_SELECT_CREATE_UNITS_REPLY (74)
#define TAG_SELECT_KILL_REPLY	(75)
#define TAG_INFO_SCALE_REPLY	(76)

#define TAG_FW_SEND_ACTION	(100)
#define TAG_FW_SEND_POS		(101)
#define TAG_FW_SEND_OFF		(102)
#define TAG_FW_SEND_ENT_METER	(103)
#define TAG_FW_SEND_PLY_METER	(104)
#define TAG_FW_SEND_GL_METER	(105)
#define TAG_FW_SEND_CREATE_ENT	(106)
#define TAG_FW_SEND_DEL_ENT	(107)
#define TAG_FW_SEND_DEL_ENT_IN_MAP	(108)
#define TAG_FW_SEND_DIR		(109)

#endif
