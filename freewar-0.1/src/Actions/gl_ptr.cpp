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

// true > 
// false > remote (server)

t_type_tag	gl_type_tag[NB_TAG]=
  {
    {TAG_WELCOME, true, NULL},
    {TAG_GAME_FULL, false, NULL},
    {TAG_GAME_STATUS, false, NULL},
    {TAG_LAUNCH_GAME, false, NULL},
    {TAG_GP_PLAYERS, false, NULL},
    {TAG_CREATE, true, NULL},
    {TAG_JOIN, true, NULL},
    {TAG_LEAVE, true, NULL},
    {TAG_PING, true, NULL},
    {TAG_INFO, true, NULL},
    {TAG_NULL, true, NULL},
    {TAG_PLAYERS_READY, true, NULL},
    {TAG_ECT, true, NULL},
    {TAG_INIT_SOUND_DONE, true, NULL},
    {TAG_INIT_SOUND_NEWS_PARAM, true, NULL},
    {TAG_INIT_SOUND_OPEN_DEVICE, true, NULL},
    {TAG_INIT_DISPLAY_DONE, true, NULL},
    {TAG_INIT_DISPLAY_NEWS_PARAM, true, NULL},
    {TAG_INIT_DISPLAY_CREATE_AND_OPEN_SCREEN, true, NULL},
    {TAG_INIT_DISPLAY_NEW_SURFACE, true, NULL},
    {TAG_INIT_DISPLAY_LOAD_SURFACE, true, NULL},
    {TAG_INIT_DISPLAY_EDIT_SURFACE , true, NULL},
    {TAG_EVENTS, true, NULL},
    {TAG_EXIT, true, NULL},
    {TAG_POS_SCREEN, true, NULL},
    {TAG_EVENT_OK, true, req_event_ok},
    {TAG_EDIT_ARENA_SURFACE, true, req_edit_arena_surface},
    {TAG_EXECUTION, true, NULL},
    {TAG_DEAD, true, NULL},
	{TAG_PLAYER_INFO, false, NULL},
    {TAG_SELECT	, true, manage_selection},
    {TAG_SELECT_MOVE, false, req_select_move},
    {TAG_SELECT_ATTACK, false, req_select_attack},
    {TAG_SELECT_CREATE_BUILDING, false, req_select_create_building},
    {TAG_SELECT_CREATE_UNITS, false, req_select_create_units},
    {TAG_SELECT_KILL, true, NULL},
    {TAG_INFO_SCALE, false, NULL},
    {TAG_SELECT_REPLY, false, NULL},
    {TAG_SELECT_MOVE_REPLY, false, NULL},
    {TAG_SELECT_ATTACK_REPLY, false, NULL},
    {TAG_SELECT_CREATE_BUILDING_REPLY, false, NULL},
    {TAG_SELECT_CREATE_UNITS_REPLY, false, NULL},
    {TAG_SELECT_KILL_REPLY, false, NULL},
    {TAG_INFO_SCALE_REPLY, false, NULL},
    {TAG_FW_SEND_ACTION, true, fw_recv_action},
    {TAG_FW_SEND_POS, true, fw_recv_pos},
    {TAG_FW_SEND_OFF, true, fw_recv_off},
    {TAG_FW_SEND_ENT_METER, true, fw_recv_ent_meter},
    {TAG_FW_SEND_CREATE_ENT, true, fw_recv_create_ent},
    {TAG_FW_SEND_DEL_ENT, true, fw_recv_del_ent},
    {TAG_FW_SEND_DEL_ENT_IN_MAP, true, fw_recv_del_ent_in_map},
    {TAG_FW_SEND_DIR, true, fw_recv_dir}
  };
