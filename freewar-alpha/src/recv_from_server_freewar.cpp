//
// recv_form_server_freewar.cpp for freewar in /root/Freewar/src
// 
// Made by 
// Login   <root@epita.fr>
// 
// Started on  Fri Jul  9 14:30:29 2004 
// Last update Mon Jul 12 15:17:01 2004 
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

//  changement d'actions d'une entitee OK
int			fw_recv_action(t_engine *e, t_trame *trame, int pl)
{
  t_fw_send_action	a;
  t_entity		*t;
  
  if (trame->len != sizeof(a))
    {
      fprintf(stderr, "ERROR: fw_recv_action: failed\n");
      return (1);
    }
  memcpy(&a, trame->msg, sizeof(a));
  for (t = e->entity; t; t = t->next)
    {
      if (t->id == a.id_ent)
	{
	  t->action = a.action;
	  return (0);
	}
    }
  return (1);
}

// changement de position d'une entitee pos OK
int			fw_recv_pos(t_engine *e, t_trame *trame, int pl)
{
  t_fw_send_pos		a;
  t_entity		*t;
  
  if (trame->len != sizeof(a))
    {
      fprintf(stderr, "ERROR: fw_recv_pos: failed\n");
      return (1);
    }
  memcpy(&a, trame->msg, sizeof(a));
  t = find_entity(e, a.id_ent);
  if (!t)
    {
      fprintf(stderr, "ERROR: fw_recv_pos: failed\n");
      return (1);
    }
  place_entity_in_map(e, t, &(a.pos));
  return (0);
}

// changement de position d'une entitee off OK
int			fw_recv_off(t_engine *e, t_trame *trame, int pl)
{
  t_fw_send_off		a;
  t_entity		*t;
  
  if (trame->len != sizeof(a))
    {
      fprintf(stderr, "ERROR: fw_recv_off: failed\n");
      return (1);
    }
  memcpy(&a, trame->msg, sizeof(a));
  t = find_entity(e, a.id_ent);
  if (!t)
    {
      fprintf(stderr, "ERROR: fw_recv_pos: failed\n");
      return (1);
    }
  move_off_in_map(e, t, a.off);
  return (0);
}

// mettre a jour un meter d'une entitee OK
int			fw_recv_ent_meter(t_engine *e, t_trame *trame, int pl)
{
  t_fw_send_ent_meter	a;
  t_entity		*t;
  int			i;	
  
  if (trame->len != sizeof(a))
    {
      fprintf(stderr, "ERROR: fw_recv_ent_meter: failed\n");
      return (1);
    }
  memcpy(&a, trame->msg, sizeof(a));
  t = find_entity(e, a.id_ent);
  if (!t)
    {
      fprintf(stderr, "ERROR: fw_recv_ent_meter: failed\n");
      return (1);
    }
  for (i = 0; t->meter[i].meter->name; i++)
    {
      if (!strcmp(t->meter[i].meter->name, a.name))
	{
	  t->meter[i].value = a.new_val;
	  break;
	}
    }
  return (0);
}


// // mettre a jour un meter du player
// int		fw_recv_ply_meter(t_engine *e, t_trame *trame)
// {
//    send_to_all_fw(e, TAG_FW_SEND_PLY_METER, sizeof(a), &a);
//   return (0);
// }


// // mettre a jour un meter global
// int		fw_recv_gl_meter(t_engine *e, t_trame *trame)
// {
// send_to_all_fw(e, TAG_FW_SEND_GL_METER, sizeof(a), &a);
//   return (0);
// }

// creation d'une entitee
int			fw_recv_create_ent(t_engine *e, t_trame *trame, int pl)
{
  t_fw_send_create_ent	a;
  
  if (trame->len != sizeof(a))
    {
      fprintf(stderr, "ERROR: fw_recv_create_ent: failed\n");
      return (1);
    }
  memcpy(&a, trame->msg, sizeof(a));
  if (put_entity_client(e, a.id_ent, a.name, a.app, a.pos, a.off))
    {
      fprintf(stderr, "ERROR: fw_recv_create_ent: failed\n");
      return (1);
    }
  return (0);
}

// supression d'une entitee
int			fw_recv_del_ent(t_engine *e, t_trame *trame, int pl)
{
  t_fw_send_del_ent	a;
  
  if (trame->len != sizeof(a))
    {
      fprintf(stderr, "ERROR: fw_recv_del_ent: failed\n");
      return (1);
    }
  memcpy(&a, trame->msg, sizeof(a));
  if (del_entity_client(e, a.id_ent))
    {
      fprintf(stderr, "ERROR: fw_recv_del_ent: failed\n");
      return (1); 
    }
  return (0);
}

// supression d'une entitee sur la map
int				fw_recv_del_ent_in_map(t_engine *e, t_trame *trame, int pl)
{
  t_fw_send_del_ent_in_map	a;
  t_entity			*t;
  
  if (trame->len != sizeof(a))
    {
      fprintf(stderr, "ERROR: fw_recv_del_ent_in_map: failed\n");
      return (1);
    }
  memcpy(&a, trame->msg, sizeof(a));
  t = find_entity(e, a.id_ent);
  if (!t)
    {
      fprintf(stderr, "ERROR: fw_recv_del_ent_in_map: failed\n");
      return (1);
    }
  if (del_entity_in_map(e, t))
    {
      fprintf(stderr, "ERROR: fw_recv_del_ent_in_map: failed\n");
      return (1); 
    }
  return (0);
}

int			fw_recv_dir(t_engine *e, t_trame *trame, int pl)
{
  t_fw_send_dir		a;
  t_entity		*t;
  
  if (trame->len != sizeof(a))
    {
      fprintf(stderr, "ERROR: fw_recv_dir: failed\n");
      return (1);
    }
  memcpy(&a, trame->msg, sizeof(a));
  t = find_entity(e, a.id_ent);
  if (!t)
    {
      fprintf(stderr, "ERROR: fw_recv_dir: failed\n");
      return (1);
    }
  t->direction = a.direction;
  return (0);
}

/* coter client */
// int		manage_remote_com_inter_fw(t_engine *e)
// {

//   return (0);
// }
