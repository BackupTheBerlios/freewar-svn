//
// aff_func.cpp for freewar in /u/ept2/skondr_m
// 
// Made by mael skondras
// Login   <skondr_m@epita.fr>
// 
// Started on  Fri Jun  4 16:30:48 2004 mael skondras
// Last update Mon Jun 14 15:35:54 2004 mael skondras
//

#include "freewar.h"

extern t_gfx *gfx;

Uint32	GetColor(t_display *win, char *color)
{
  //code a fucking converter
  // use the convert base to conv hex to dec
  // extract the r g b portions
  if (!strcmp("FF0000", color))
    return(SDL_MapRGB(win->sdlMainScreen->format,255,0,0));
  else if (!strcmp("CC0000", color))
    return(SDL_MapRGB(win->sdlMainScreen->format,208,0,0));
	return (0);
}

int		draw_button(t_display *win, t_menu_entry *menu)
{
  t_menu_button	*info;
  
  info = (t_menu_button*)menu->info;
  win->img = IMG_Load("AFirstChaos/img/menu/button.png");
  if(win->img == NULL)
    return(1);
  //SDL_SetColorKey(win->img, SDL_SRCCOLORKEY,0);
  if (info->y > win->res_h - win->img->h)
    info->y = win->res_h - win->img->h;
  win->dest.y = info->y;
  if (info->x > win->res_w - win->img->w)
    info->x =  win->res_w - win->img->w;
  win->dest.x = info->x;
  aff_surf(win->img, 255);
  win->text = load_string(info->value, FONT, info->text_size);
  win->dest.x = info->x + ((win->img->w - win->text->w) / 2);
  win->dest.y = info->y + ((win->img->h - win->text->h) / 2);
  aff_surf(win->text, 255);
  SDL_FreeSurface(win->img);
  SDL_FreeSurface(win->text);
  return(0);
}

int		draw_table(t_display *win, t_menu_entry *menu)
{
  t_menu_table	*info;

  info = (t_menu_table*)menu->info;
  win->dest.x = info->x;
  win->dest.y = info->y;
  win->dest.w = info->width;
  win->dest.h = info->height;
  fprintf(fd_log, "drawing a fecking table at x[%i]y[%i]h[%i]w[%i]\n",
	  win->dest.x,win->dest.y,win->dest.h,win->dest.w);
  win->img = SDL_CreateRGBSurface(SDL_HWSURFACE, win->dest.w, win->dest.h,
						  gfx->bpp,
						  win->sdlMainScreen->format->Rmask,
						  win->sdlMainScreen->format->Gmask,
						  win->sdlMainScreen->format->Bmask,
						  win->sdlMainScreen->format->Amask);
  SDL_SetColorKey(win->img, SDL_SRCCOLORKEY,0);
  SDL_FillRect(win->img, NULL, SDL_MapRGB(win->sdlMainScreen->format,42,42,42));
  aff_surf(win->img, 200);
  SDL_FreeSurface(win->img);
  win->text = load_string(info->title, FONT, 14);
  win->dest.x = info->x + ((info->width - win->text->w) / 2);
  win->dest.y = info->y + 12;
  aff_surf(win->text, 255);
  SDL_FreeSurface(win->text);
  return(0);
}

int	draw_txtbox(t_display *win, t_menu_entry *menu)
{
  t_menu_text	*info;
  char		*old;

  // implement txtbox growth according to font size
  // implement coloring according to 
  info = (t_menu_text*)menu->info;
  win->dest.x = info->x;
  win->dest.y = info->y;
  if (info->value)
    win->text = load_string(info->value, FONT, info->text_size);
  else
    win->text = load_string(" ", FONT, info->text_size);
  win->dest.h = win->text->h + 4;
  win->dest.w = TXTBOX_WIDTH + 4;
  win->img = SDL_CreateRGBSurface(SDL_HWSURFACE, win->dest.w, win->dest.h,
						  gfx->bpp,
						  win->sdlMainScreen->format->Rmask,
						  win->sdlMainScreen->format->Gmask,
						  win->sdlMainScreen->format->Bmask,
						  win->sdlMainScreen->format->Amask);
  SDL_SetColorKey(win->img, SDL_SRCCOLORKEY,0);
  SDL_FillRect(win->img, NULL, SDL_MapRGB(win->sdlMainScreen->format,42,42,42));
  win->dest.x = 1;
  win->dest.y = 1;
  win->dest.h = win->text->h + 2;
  win->dest.w = TXTBOX_WIDTH + 2;
  SDL_FillRect(win->img, &(win->dest), GetColor(win, info->background));
  win->dest.x = info->x;
  win->dest.y = info->y;
  aff_surf(win->img, 255);
  SDL_FreeSurface(win->img);
  win->dest.x = info->x + 4;
  win->dest.y = info->y + 2;
  while (win->text->w > TXTBOX_WIDTH - 4)
  {
    old = info->value;
    info->value = xstrndup(info->value, xstrlen(info->value) - 1);
    free(old);
    SDL_FreeSurface(win->text);  
    win->text = load_string(info->value, FONT, info->text_size);    
  }
  aff_surf(win->text, 255);
  SDL_FreeSurface(win->text);  
  return(0);
}
