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
// send_to_server_freewar.cpp for freewar in /root/Freewar/src
// 
// Made by 
// Login   <root@epita.fr>
// 
// Started on  Fri Jul  9 14:30:29 2004 
// Last update Mon Jul 12 15:15:24 2004 
//

#include "freewar.h"

/*
  #client -> server
  information a en informer le server :

  changement d'actions d'une entitee
  changement de position d'une entitee (off et pos)
  mettre a jour un meter d'une entitee
  creataion d'une entitee
  del une entitee
*/

int		send_to_all_fw(t_engine *e, short tag,
			       unsigned int len, void *msg)
{
  int		i;
  int		player;
  
  // TODO: chaipo tro
  // for (i = 0; i < e->nb_players; i++)
  for (i = 1; i < e->nb_players; i++)
    {
      player = e->assos_clients[i];
      if (player >= 1)
	{
	  printf("HUUUUUUUUUUUUUUUUUUUUU\n");fflush(stdout);
	  stock_msg(&(cnt->clients[player]), tag, len, msg);
	}
    }
  return (0);
}

//  changement d'actions d'une entitee OK
int			fw_send_action(t_engine *e, t_entity *t)
{
  t_fw_send_action	a;
  
  a.id_ent = t->id;
  a.action = t->action;
  send_to_all_fw(e, TAG_FW_SEND_ACTION, sizeof(a), &a);
  return (0);
}

// changement de position d'une entitee pos OK
int			fw_send_pos(t_engine *e, t_entity *t)
{
  t_fw_send_pos		a;

  a.id_ent = t->id;
  a.pos = t->pos;
  send_to_all_fw(e, TAG_FW_SEND_POS, sizeof(a), &a);
  return (0);
}

// changement de position d'une entitee off OK
int			fw_send_off(t_engine *e, t_entity *t)
{
  t_fw_send_off		a;

  a.id_ent = t->id;
  a.off = t->off;
  send_to_all_fw(e, TAG_FW_SEND_OFF, sizeof(a), &a);
  return (0);
}

// mettre a jour un meter d'une entitee OK
int			fw_send_ent_meter(t_engine *e, t_entity *t, char *name, int new_val)
{
  t_fw_send_ent_meter a;

  a.id_ent = t->id;
  strncpy(a.name, name, NAME_SIZE);
  a.new_val = new_val;
  send_to_all_fw(e, TAG_FW_SEND_ENT_METER, sizeof(a), &a);
  return (0);
}


// // mettre a jour un meter du player
// int		fw_send_ply_meter(t_engine *e, char *name, int new_val)
// {
//    send_to_all_fw(e, TAG_FW_SEND_PLY_METER, sizeof(a), &a);
//   return (0);
// }


// // mettre a jour un meter global
// int		fw_send_gl_meter(t_engine *e, char *name, int new_val)
// {
// send_to_all_fw(e, TAG_FW_SEND_GL_METER, sizeof(a), &a);
//   return (0);
// }

// creation d'une entitee OK
int			fw_send_create_ent(t_engine *e, t_entity *t)
{
  t_fw_send_create_ent	a;

  a.id_ent = t->id;
  strncpy(a.name, t->data->name, NAME_SIZE);
  a.app = t->app;
  a.pos = t->pos;
  a.off = t->off;
  send_to_all_fw(e, TAG_FW_SEND_CREATE_ENT, sizeof(a), &a);
  return (0);
}

// supression d'une entitee OK
int			fw_send_del_ent(t_engine *e, t_entity *t)
{
  t_fw_send_del_ent	a;

  a.id_ent = t->id;
  send_to_all_fw(e, TAG_FW_SEND_DEL_ENT, sizeof(a), &a);
  return (0);
}

// supression d'une entitee OK
int				fw_send_del_ent_in_map(t_engine *e, t_entity *t)
{
  t_fw_send_del_ent_in_map	a;

  a.id_ent = t->id;
  send_to_all_fw(e, TAG_FW_SEND_DEL_ENT_IN_MAP, sizeof(a), &a);
  return (0);
}


int				fw_send_dir(t_engine *e, t_entity *t)
{
  t_fw_send_dir			a;

  a.id_ent = t->id;
  a.direction = t->direction;
  send_to_all_fw(e, TAG_FW_SEND_DIR, sizeof(a), &a);
  return (0);
}


/* coter client */
// int		manage_remote_com_inter_fw(t_engine *e)
// {

//   return (0);
// }
