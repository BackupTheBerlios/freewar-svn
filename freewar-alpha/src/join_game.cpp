#include "freewar.h"

int		join_game(t_trame *req)
{
  char		*ip;
  int		len;
  int		port;

  len = req->len - sizeof(port);
  ip = (char*)xmalloc(len);
  memcpy(ip, req->msg, len);
  memcpy(&port, req->msg + len, sizeof(port));
  fprintf(fd_log, "Join la partie ip(%s:%d)\n", ip, port);
  init_connection(ip, port);
  stock_msg(&(cnt->clients[1]), TAG_JOIN, 0, NULL);
  return (0);
}
