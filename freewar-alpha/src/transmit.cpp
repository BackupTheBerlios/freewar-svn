//
// transmit.cpp for freewar in /u/ept2/huot_j/Freewar/src
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Thu May  6 11:10:33 2004 jonathan huot
// Last update Thu May  6 13:59:49 2004 jonathan huot
//

#include "freewar.h"

int		transmit_requests()
{
  t_trame	req;

  recv_trame(&(cnt->clients[0]), &req);
  stock_msg(&cnt->clients[0], req.tag, req.len, req.msg);
  return (0);
}

int		transmit_response()
{
  t_trame	req;

  recv_trame(&cnt->clients[1], &req);
  stock_msg(&cnt->clients[0], req.tag, req.len, req.msg);
  return (0);
}
