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

int	show_txtbox(int x, int y, char *value)
{
  char		*old;

  if (value)
    gfx->win->text = load_string(value, FONT, 14);
  else
    gfx->win->text = load_string(" ", FONT, 14);
  gfx->win->dest.h = gfx->win->text->h + 4;
  gfx->win->dest.w = MB_WIDTH - 10;
  gfx->win->img = SDL_CreateRGBSurface(SDL_HWSURFACE, gfx->win->dest.w, gfx->win->dest.h,
						  gfx->bpp,
						  gfx->win->sdlMainScreen->format->Rmask,
						  gfx->win->sdlMainScreen->format->Gmask,
						  gfx->win->sdlMainScreen->format->Bmask,
						  gfx->win->sdlMainScreen->format->Amask);
  SDL_SetColorKey(gfx->win->img, SDL_SRCCOLORKEY,0);
  SDL_FillRect(gfx->win->img, NULL, SDL_MapRGB(gfx->win->sdlMainScreen->format,42,42,42));
  gfx->win->dest.x = 1;
  gfx->win->dest.y = 1;
  gfx->win->dest.h = gfx->win->dest.h - 2;
  gfx->win->dest.w = gfx->win->dest.w - 2;;
  SDL_FillRect(gfx->win->img, &(gfx->win->dest),SDL_MapRGB(gfx->win->sdlMainScreen->format,0,0,142));
  gfx->win->dest.x = x + 9;
  gfx->win->dest.y = y + MB_HEIGHT - 70;
  aff_surf(gfx->win->img, 255);
  SDL_FreeSurface(gfx->win->img);
  while (gfx->win->text->w > (MB_WIDTH - 10))
  {
    old = value;
    value = xstrndup(value, xstrlen(value) - 1);
    free(old);
    SDL_FreeSurface(gfx->win->text);  
    gfx->win->text = load_string(value, FONT, 14);
  }
  aff_surf(gfx->win->text, 255);
  SDL_FreeSurface(gfx->win->text);  
  return(0);
}

char		*get_answer(int x, int y, char *def_val)
{
  SDL_Event e;
  SDL_MouseButtonEvent *m_event;
  SDL_KeyboardEvent *kb_event;
  int		but_h, but_w;

  gfx->win->img = IMG_Load("AFirstChaos/img/menu/mb_button.png");
  if(gfx->win->img == NULL)
    return(0);
  but_h = gfx->win->img->h;
  but_w = gfx->win->img->w;
  while (42)
    {
      while (SDL_PollEvent(&e))
	{
	  if (e.type == SDL_MOUSEBUTTONUP)
	    {
	      m_event = (SDL_MouseButtonEvent*)&(e.button);
	      if (m_event->y > y + (MB_HEIGHT - but_h) - 6
		  && m_event->y < y + MB_HEIGHT - 6
		  && m_event->x > x + ((MB_WIDTH - but_w) / 2) - 112
		  && m_event->x < x + (MB_WIDTH / 2) - 112 + but_w)
		return (def_val);
	      else if (m_event->y > y + (MB_HEIGHT - but_h) - 6
		       && m_event->y < y + MB_HEIGHT - 6
		       && m_event->x > x + ((MB_WIDTH - but_w) / 2) + 112
		       && m_event->x < x + ((MB_WIDTH - but_w) / 2) + 112 + but_w)
		return (0);
	    }
	  else if (e.type == SDL_KEYDOWN)
	    {
	      kb_event = (SDL_KeyboardEvent*)&(e.key);
	      def_val = update_txtbox(def_val, kb_event);
	      show_txtbox(x, y, def_val);
	    }
	}
    }
}

char		*fw_inputbox(char *title, char *msg, char *def_val)
{
  int x,y;
  char	*str;

  str = xstrdup(def_val);
  x = ((gfx->win->res_w - MB_WIDTH) / 2);
  y = ((gfx->win->res_h - MB_HEIGHT) / 2);
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
  show_button(x, y, "OK", 0, "AFirstChaos/img/menu/mb_button.png");
  show_button(x, y, "Cancel", 2, "AFirstChaos/img/menu/mb_button.png");
  show_txtbox(x, y, str);
  return (get_answer(x, y, str));
}
