#include "freewar.h"

extern t_gfx	*gfx;

int		launch_demo()
{
  fprintf(fd_log, "Launching demo\n");
//   if (demo(gfx->win)) // TODO: doit etre mis plus haut
//     return (1);
  fprintf(fd_log, "Finished demo\n");  
  return (0);
}
