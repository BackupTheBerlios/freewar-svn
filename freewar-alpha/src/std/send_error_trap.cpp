//
// send_error_trap.cpp for freewar in /u/ept2/skondr_m
// 
// Made by mael skondras
// Login   <skondr_m@epita.fr>
// 
// Started on  Mon May  3 17:27:12 2004 mael skondras
// Last update Tue May 11 18:18:45 2004 mael skondras
//

#include "freewar.h"

int	send_trap_motor(int tag, void *info)
{
  t_error	*tmp;

  tmp = (t_error*)info;
  printf("%s\n", tmp->debug);
  if (tmp->lethal)
    exit (-1);
  else
    return (0);
}

int	send_error_trap(char *str, int lethal)
{
  t_error	error;
  xstrncpy(error.debug, str, BUF_SIZE);
  error.lethal = lethal;
  send_trap_motor(ERROR, &error);
  return (0);
}
