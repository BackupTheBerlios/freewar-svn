/*
** init_msg.c for network engine in /u/ept2/huot_j/network_engine
** 
** Made by jonathan huot
** Login   <huot_j@epita.fr>
** 
** Started on  Tue Jun 22 18:06:20 2004 jonathan huot
** Last update Tue Jun 22 18:19:29 2004 jonathan huot
*/

#include "network.h"

void		init_msg(t_trame *msg)
{
  msg->tag = -2;
  msg->len = 0;
  msg->msg = 0;
  msg->pos = 0;
}
