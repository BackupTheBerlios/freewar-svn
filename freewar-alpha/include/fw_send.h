/*
** fw_send.h for freewar in /root/Freewar/src
** 
** Made by 
** Login   <root@epita.fr>
** 
** Started on  Fri Jul  9 14:58:50 2004 
** Last update Mon Jul 12 15:14:09 2004 
*/

#ifndef _FW_SEND_H_
#define _FW_SEND_H_

typedef struct	s_fw_send_action
{
  unsigned long	id_ent;
  unsigned char	action;
}		t_fw_send_action;

typedef struct	s_fw_send_pos
{
  unsigned long	id_ent;
  t_coord	pos;
}		t_fw_send_pos;

typedef struct	s_fw_send_off
{
  unsigned long	id_ent;
  t_coord	off;
}		t_fw_send_off;

typedef struct	s_fw_send_ent_meter
{
  unsigned long	id_ent;
  char		name[NAME_SIZE];
  int		new_val;
}		t_fw_send_ent_meter;

/* typedef struct	s_fw_send_ply_meter */
/* { */
/*   char		name[NAME_SIZE]; */
/*   int		new_val; */
/* }		t_fw_send_ply_meter; */

/* typedef struct	s_fw_send_gl_meter */
/* { */
/*   char		name[NAME_SIZE]; */
/*   int		new_val; */
/* }		t_fw_send_gl_meter; */

typedef	struct	s_fw_send_create_ent
{
  unsigned long	id_ent;
  char		name[NAME_SIZE];
  int		app;
  t_coord	pos;
  t_coord	off;
}		t_fw_send_create_ent;

typedef	struct	s_fw_send_del_ent
{
  unsigned long	id_ent;
}		t_fw_send_del_ent;


typedef	struct	s_fw_send_del_ent_in_map
{
  unsigned long	id_ent;
}		t_fw_send_del_ent_in_map;


typedef	struct	s_fw_send_dir
{
  unsigned long	id_ent;
  unsigned char direction;
}		t_fw_send_dir;


#endif
