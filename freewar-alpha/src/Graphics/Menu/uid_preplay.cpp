//
// uid_preplay.cpp for freewar in /u/ept2/skondr_m
// 
// Made by mael skondras
// Login   <skondr_m@epita.fr>
// 
// Started on  Wed Jun  2 12:27:23 2004 mael skondras
// Last update Fri Jun  4 14:44:25 2004 mael skondras
//

#include "freewar.h"

void	*uid_create_game(t_menu_entry *menus, void *info)
{
  //setmod "SERVER"
  /*stock_msg(&cnt->clients[0], TAG_CREATE, 0, NULL);
  */return (0);
}

void		*uid_join_game(t_menu_entry *menus, void *info)
{
  //char		msg[42];
  //int		port;
  //size_t	len;

  //port = NET_GAME_PORT;
  //memcpy((void*)msg, &port, sizeof(port));
  //strcpy(msg + sizeof(port), "10.251.3.62");
  //len = sizeof(port) + (sizeof(*msg) * strlen("10.251.3.62"));
  //stock_msg(&cnt->clients[0], TAG_JOIN, (int)(sizeof(port) + len), msg);
  return (0);
}

void	*uid_specify_game(t_menu_entry *menus, void *info)
{
  //requete affichage ==> stef
  // demande une IP et un port
  // envoie des parametres, et setmode "CLIENT"
  return (0);
}

void	*uid_foundservers(t_menu_entry *menus, void *info)
{
  return (0);
}

void	*uid_refresh(t_menu_entry *menus, void *info)
{
  return (0);
}
