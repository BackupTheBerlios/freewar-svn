
#include "freewar.h"

extern t_gfx	*gfx;

// void	get_pos(t_display *win, int x, int y, int i)
// {
//   //  printf("Got text size w(%i) and h(%i)\n", win->text->w, win->img->h);
//   //printf("win->img->w - win->text->w / 2 = %i with x=%i\n", (win->img->w - win->text->w) / 2, x);
//   if (i == 1 || i == 0)
//     win->dest.x = x + ((win->img->w - win->text->w) / 2);
//   else
//     win->dest.x = x;
//   if (i == 1)  
//     win->dest.y = y + (( + win->img->h - win->text->h) / 2);
//   else
//     win->dest.y = y;
// }

// int	draw_string(t_display *win, int x, int y, char *str, int i)
// {
//   SDL_Color color;

//   color.r=255;
//   color.g=255;
//   color.b=255;
//   if (!win->font)
//     puts("pb de font");
//   win->text = TTF_RenderText_Solid(win->font, str, color);
//   get_pos(win, x, y, i);
//   //printf("dest->x is [%i] and dest->y is [%i]\n", win->dest.x, win->dest.y);
//   if (SDL_BlitSurface(win->text, NULL, win->sdlMainScreen, &win->dest) < 0)
//     fprintf(stderr, "Cannot blit string : %s\n", SDL_GetError());
//   SDL_Flip(win->sdlMainScreen);
//   SDL_FreeSurface(win->text);
//   return(0);
// }

// int	aff_string(t_display *win, int x, int y, char *str)
// {
//   SDL_Color color;
  
//   fprintf(fd_log, "AFF_STRING\n");
//   color.r=255;
//   color.g=255;
//   color.b=255;
//   win->dest.x = x;
//   win->dest.y = y;
//   if (!win->font)
//     puts("pb de font");
//   if (!str || !str[0])
//     return (0);
//   fprintf(fd_log, "pof win->text->[%i]\n", win->text);
//   if (win->text)
//     SDL_FreeSurface(win->text);
//   fprintf(fd_log, "pof2\n");
//   fprintf(fd_log, "DEMO: gonna render text\n");
//   win->text = TTF_RenderText_Solid(win->font, str, color);
//   if (SDL_BlitSurface(win->text, NULL, win->sdlMainScreen, &win->dest) < 0)
//     fprintf(stderr, "Cannot blit string : %s\n", SDL_GetError());
//   SDL_Flip(win->sdlMainScreen);
//   return(0);
// }

SDL_Surface	*load_string(char *str, char *font, int size)
{
  SDL_Color color;
  SDL_Surface *text;
  
  color.r=255;
  color.g=255;
  color.b=255;
  gfx->win->font = TTF_OpenFont(font, size);
  if (!gfx->win->font)
  {
    fprintf(fd_log, "pb de font");
	return (0);
  }
  if (!str || !str[0])
    return (0);
  text = TTF_RenderText_Solid(gfx->win->font, str, color);
  TTF_CloseFont(gfx->win->font);
  return (text);
}
