#include "graphics.h"

extern t_gfx	*gfx;

int     edit_arena(int i, t_coord *scale, t_coord *offset, int zoom)
{
  if (i < 0 || i >= MAXSUBSCREEN || gfx->surface[i].exist == false)
    return (-1);
  if (scale)
    {
      gfx->surface[i].scale.x = scale->x;
      gfx->surface[i].scale.y = scale->y;
    }
  if (offset)
    {
      gfx->surface[i].off.x = offset->x;
      gfx->surface[i].off.y = offset->y;
    }
  if (zoom > 0)
    gfx->surface[i].zoom = zoom;
  return (0);
}
