//
// add_player.cpp for freewar in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Fri May  7 12:00:45 2004 jonathan huot
// Last update Fri May  7 14:46:44 2004 jonathan huot
//

#include "freewar.h"

//int	add_player(t_game_param *game_param, t_trame *req)
//{
//  int	pos_of_socket;
//  int	pos_of_empty_slot;
//  int	i;
//  //je suce, tu suces, il suce, nous sucons, vous sucez, ils sucent
//  
//  pos_of_socket = get_pos_of_socket(cnt->last_recv->sock);
//  if ((pos_of_empty_slot = get_pos_of_empty_slot(game_param)) < 0)
//    return (put_error("get_pos_of_empty_slot failed"));
//  game_param->players[pos_of_empty_slot].type = TYPE_HUMAN;
//  game_param->players[pos_of_empty_slot].color = 0;
//  game_param->players[pos_of_empty_slot].race = 0;
//  game_param->players[pos_of_empty_slot].team = 1;
//  if (req->len != NAME_SIZE)
//    return (put_error("trame value size missmatch"));
//  memcpy((void*)game_param->players[pos_of_empty_slot].name,
//	 (void*)(req->msg), NAME_SIZE);
//  for (i = 0; i < FW_MAX_CLIENTS && pos[i].player != -1; i++)
//    ;
//  if (i == FW_MAX_CLIENTS)
//    return (put_error("Segmentation fault (freewar parachute deployed)"));
//  pos[i].client = pos_of_socket;
//  pos[i].player = pos_of_empty_slot;
//  return (0);
//}
