
#include "freewar.h"

void	*uid_play(t_menu_entry *menus, void *info)
{
  return (0);
}

void	*uid_test(t_menu_entry *menus, void *info)
{
  static char *nick = "Serge";

  if (info)
    {
      nick = fw_inputbox("Freewar", "Please enter your nick", nick);
      //fprintf(fd_log, "Got nick -> %s\n", nick);
    //fw_msgbox("Freewar", "Wesh wesh alors", MB_YESNOCANCEL);
      return (0);
    }
  return (0);
}

void	*uid_options(t_menu_entry *menus, void *info)
{
  return (0);
}

void	*uid_credits(t_menu_entry *menus, void *info)
{
  if (info)
    printf("Credits: Doomsday, drax, hardcore_neo, SpYcAt\n");
  return (0);
}

void	*uid_exit(t_menu_entry *menus, void *info)
{
  return (0);
}

void	*uid_back(t_menu_entry *menus, void *info)
{
  return (0);
}
