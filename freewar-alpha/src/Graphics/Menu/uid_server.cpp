#include "freewar.h"

void	*uid_server_hostname(t_menu_entry *menus, void *info)
{
  if (info)
    cnt->host = strdup(((t_return_text*)info)->value);
  //else
  //  cnt->host = strdup(((t_menu_text*)(menus->info))->value);
  return (0);
}

void	*uid_server_port(t_menu_entry *menus, void *info)
{
  return (0);
}
