#include "freewar.h"

Err		menu_exit(t_info *info)
{
  info->exit = 1;
  return (0);
}

Err		menu_play(t_info *info)
{
  Err		err;

  err = game(info);
  update_menu(info);
  return (err);
}

Err		menu_options(t_info *info)
{
  return (0);
}
