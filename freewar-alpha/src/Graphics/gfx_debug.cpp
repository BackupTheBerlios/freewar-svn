#include "graphics.h"

extern t_gfx	*gfx;

int		gfx_put_square(int x, int y, int color)
{
  int		t;

  for (t = 0; t < MAXDEBUG &&
	 gfx->debug[t].id_sprite != -1; t++)
    ;
  if (t == MAXDEBUG)
    {
      fprintf(fd_log, "Too much gfx debug entity\n");
      return (-1);
    }
  gfx->debug[t].id_sprite = color;
  gfx->debug[t].id_surf = -1;
  gfx->debug[t].x = x;
  gfx->debug[t].y = y;
  gfx->debug[t].alpha = 255;
  return (0);
}

int			show_debug()
{
  static SDL_Surface	*square = 0;
  int			i;
  SDL_Rect		dest;

  if (!square)
    square = SDL_CreateRGBSurface(SDL_SWSURFACE,
				  10, 10,
				  gfx->main->format->BitsPerPixel,
				  gfx->main->format->Rmask,
				  gfx->main->format->Gmask,
				  gfx->main->format->Bmask,
				  gfx->main->format->Amask);
  for (i = 0; i < MAXDEBUG; i++)
    {
      if (gfx->debug[i].id_sprite != -1)
	{
	  dest.w = 10;
	  dest.h = 10;
	  dest.x = gfx->debug[i].x;
	  dest.y = gfx->debug[i].y;
	  SDL_SetAlpha(square, SDL_SRCALPHA, gfx->debug[i].alpha);
	  SDL_FillRect(square, NULL, gfx->debug[i].id_sprite);
	  SDL_BlitSurface(square, NULL, gfx->buff, &dest);
	  if ((gfx->debug[i].alpha -= 10) < 0)
	    gfx->debug[i].id_sprite = -1;
	}
    }
  return (0);
}
