#include "freewar.h"

void		set_rect_height(t_info *info, int nb,
				const int off, SDL_Rect *src)
{
  int		var;

  var = -info->game.pos_y;
  src->y = 0;
  if (var + (nb * CASE_SIZE_Y) + CASE_SIZE_Y < CASE_SIZE_Y)
    {
      src->y = CASE_SIZE_Y - off;
      src->h = off;
    }
  else if (var + (nb * CASE_SIZE_Y) - CASE_SIZE_Y >
	   info->mysdl.screen->h - CASE_SIZE_Y)
    src->h = CASE_SIZE_Y - off;
  else
    src->h = CASE_SIZE_Y;
}

void		set_rect_width(t_info *info, int nb,
				const int off, SDL_Rect *src)
{
  int		var;

  var = -info->game.pos_x;
  src->x = 0;
  if (var + (nb * CASE_SIZE_X) + CASE_SIZE_X < CASE_SIZE_X)
    {
      src->x = CASE_SIZE_X - off;
      src->w = off;
    }
  else if (var + (nb * CASE_SIZE_X) - CASE_SIZE_X >
	   info->mysdl.screen->w - CASE_SIZE_X)
    src->w = CASE_SIZE_X - off;
  else
    src->w = CASE_SIZE_X;
}

Err		update_gamespace(t_info *info)
{
  SDL_Rect	tmp, dest, src;
  int		i, n;
  const int	offy = ((info->data.h * CASE_SIZE_Y) -
			info->game.pos_y) % CASE_SIZE_Y;
  const int	offx = ((info->data.w * CASE_SIZE_X) -
			info->game.pos_x) % CASE_SIZE_X;

  dest.y = 0;
  for (i = info->game.pos_y / CASE_SIZE_Y;
       dest.y < info->mysdl.screen->h; i++)
    {
      set_rect_height(info, i, offy, &src);
      dest.h = src.h;
      dest.x = 0;
      for (n = info->game.pos_x / CASE_SIZE_X;
	   dest.x < info->mysdl.screen->w; n++)
	{
	  set_rect_width(info, n, offx, &src);
	  dest.w = src.w;
	  tmp = dest;
	  if (i < info->data.h && n < info->data.w)
	    {
	      if (info->data.data[i][n].land)
		xSDL_BlitSurface(get_surf(info,
					  info->data.data[i][n].land),
				 &src, info->game.gamespace, &tmp);
	      if (info->data.data[i][n].item)
		xSDL_BlitSurface(get_surf(info,
					  info->data.data[i][n].item),
				 &src, info->game.gamespace, &tmp);
	    }
	  else
	    xSDL_BlitSurface(info->img[0], &src,
			     info->game.gamespace, &tmp);
	  dest.x += dest.w;
	}
      dest.y += dest.h;
    }
  return (show_gamespace(info));
}
