// Copyright (C) 2004 Freewar Team <doomsday@freewar.net>

// This file is part of Freewar.

// Freewar is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.

// Freewar is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with Freewar; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
#include "freewar.h"

extern t_gfx *gfx;

int		get_choice(int x, int y, int flag)
{
  SDL_Event e;
  SDL_MouseButtonEvent *event;

  gfx->win->img = IMG_Load("AFirstChaos/img/menu/mb_button.png");
  if(gfx->win->img == NULL)
    return(1);
  while (42)
    {
      while (SDL_PollEvent(&e))
	{
	  if (e.type == SDL_MOUSEBUTTONUP)
	    {
	      event = (SDL_MouseButtonEvent*)&(e.button);
	      if (event->y > y + (MB_HEIGHT - gfx->win->img->h) - 6
		  && event->y < y + MB_HEIGHT - 6
		  && event->x > x + ((MB_WIDTH - gfx->win->img->w) / 2) - 112
		  && event->x < x + (MB_WIDTH / 2) - 112 + gfx->win->img->w)
		{
		  if (flag == MB_OKCANCEL)
		    return (MB_OK);
		  else if  (flag == MB_YESNOCANCEL)
		    return (MB_YES);
		  else if  (flag == MB_YESNO)
		    return (MB_YES);
		}
	      else if (event->y > y + (MB_HEIGHT - gfx->win->img->h) - 6
		       && event->y < y + MB_HEIGHT - 6
		       && event->x > x + ((MB_WIDTH - gfx->win->img->w) / 2) + 112
		       && event->x < x + ((MB_WIDTH - gfx->win->img->w) / 2) + 112 + gfx->win->img->w)
		{
		  if (flag == MB_OKCANCEL)
		    return (MB_CANCEL);
		  else if  (flag == MB_YESNOCANCEL)
		    return (MB_CANCEL);
		  else if  (flag == MB_YESNO)
		    return (MB_NO);
		}
	      else if (event->y > y + (MB_HEIGHT - gfx->win->img->h) - 6
		       && event->y < y + MB_HEIGHT - 6
		       && event->x > x + ((MB_WIDTH - gfx->win->img->w) / 2)
		       && event->x < x + ((MB_WIDTH - gfx->win->img->w) / 2) + gfx->win->img->w)
		{
		  if (flag == MB_INFO)
		    return (MB_OK);
		  else if  (flag == MB_YESNOCANCEL)
		    return (MB_NO);
		}
	    }
	}
    }
}

int		show_button(int x, int y, char *msg, int off, char *sprite)
{
  gfx->win->img = IMG_Load(sprite);
  if(gfx->win->img == NULL)
    return(1);
  SDL_SetColorKey(gfx->win->img, SDL_SRCCOLORKEY,0);
  gfx->win->dest.y = y + MB_HEIGHT - gfx->win->img->h - 6;
  if (off == 0)
    gfx->win->dest.x = x + ((MB_WIDTH - gfx->win->img->w) / 2 - 112);
  else if (off == 1)
    gfx->win->dest.x = x + ((MB_WIDTH - gfx->win->img->w) / 2);
  else if (off == 2)
    gfx->win->dest.x = x + ((MB_WIDTH - gfx->win->img->w) / 2 + 112);
  aff_surf(gfx->win->img, 255);
  gfx->win->text = load_string(msg, FONT, 14);
  gfx->win->dest.x = gfx->win->dest.x + ((gfx->win->img->w - gfx->win->text->w) / 2);
  gfx->win->dest.y = gfx->win->dest.y + ((gfx->win->img->h - gfx->win->text->h) / 2);
  aff_surf(gfx->win->text, 255);
  SDL_FreeSurface(gfx->win->img);
  SDL_FreeSurface(gfx->win->text);
  return (0);
}

int		fw_msgbox(char *title, char *msg, int flag)
{
  int x,y;
  
  x = ((gfx->win->sdlMainScreen->w - MB_WIDTH) / 2);
  y = ((gfx->win->sdlMainScreen->h - MB_HEIGHT) / 2);
  gfx->win->text = load_string(title, FONT, 13);
  gfx->win->dest.w = MB_WIDTH + 2;
  gfx->win->dest.h = MB_HEIGHT + 2;
  gfx->win->img = SDL_CreateRGBSurface(SDL_HWSURFACE, gfx->win->dest.w, gfx->win->dest.h,
				  gfx->bpp,
				  gfx->win->sdlMainScreen->format->Rmask,
				  gfx->win->sdlMainScreen->format->Gmask,
				  gfx->win->sdlMainScreen->format->Bmask,
				  gfx->win->sdlMainScreen->format->Amask);
  SDL_SetColorKey(gfx->win->img, SDL_SRCCOLORKEY,0);
  SDL_FillRect(gfx->win->img, NULL, SDL_MapRGB(gfx->win->sdlMainScreen->format,208,208,208));
  gfx->win->dest.x = 1;
  gfx->win->dest.y = 1;
  gfx->win->dest.h = MB_HEIGHT;
  gfx->win->dest.w = MB_WIDTH;
  SDL_FillRect(gfx->win->img, &(gfx->win->dest), SDL_MapRGB(gfx->win->sdlMainScreen->format,0,0,42));
  gfx->win->dest.x = 1;
  gfx->win->dest.y = 21;
  gfx->win->dest.h = 1;
  gfx->win->dest.w = MB_WIDTH;
  SDL_FillRect(gfx->win->img, &(gfx->win->dest), SDL_MapRGB(gfx->win->sdlMainScreen->format,208,208,208));
  gfx->win->dest.x = x;
  gfx->win->dest.y = y;
  aff_surf(gfx->win->img, 255);
  SDL_FreeSurface(gfx->win->img);
  gfx->win->dest.x = x + 3;
  gfx->win->dest.y = y + 2;
  aff_surf(gfx->win->text, 255);
  SDL_FreeSurface(gfx->win->text);
  gfx->win->text = load_string(msg, FONT, 14);
  gfx->win->dest.x = x + 7;
  gfx->win->dest.y = y + 24;
  aff_surf(gfx->win->text, 255);
  SDL_FreeSurface(gfx->win->text);
  if (flag == MB_OKCANCEL)
    {
      show_button(x, y, "OK", 0, "AFirstChaos/img/menu/mb_button.png");
      show_button(x, y, "Cancel", 2, "AFirstChaos/img/menu/mb_button.png");
    }
  else if (flag == MB_YESNO)
    {
      show_button(x, y, "Yes", 0, "AFirstChaos/img/menu/mb_button.png");
      show_button(x, y, "No", 2, "AFirstChaos/img/menu/mb_button.png");
    }
  else if (flag == MB_YESNOCANCEL)
    {
      show_button(x, y, "Yes", 0, "AFirstChaos/img/menu/mb_button.png");
      show_button(x, y, "No", 1, "AFirstChaos/img/menu/mb_button.png");
      show_button(x, y, "Cancel", 2, "AFirstChaos/img/menu/mb_button.png");
    }
  else
    {
      show_button(x, y, "OK", 1, "AFirstChaos/img/menu/mb_button.png");
      flag = MB_INFO;
    }
  return (get_choice(x, y, flag));
}
