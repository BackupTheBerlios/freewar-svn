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
/*
** event.c for freewar in /u/ept2/petitc_s/graphique_engine
** 
** Made by stephane petitcolas
** Login   <petitc_s@epita.fr>
** 
** Started on  Tue May 11 16:14:05 2004 stephane petitcolas
// Last update Mon Jul 12 16:49:13 2004 
*/

#include "freewar.h"

// int		show_event(t_event *all_event)
// {
//   int		i;

//   for (i = 0; i < MAXMOUSEEVENT; i++)
//     {
//       printf("x = %i, y = %i , button %i\n", all_event->mousepose[i].x,
// 	     all_event->mousepose[i].y, (int)all_event->mousepose[i].button);
//     }
//   for (i = 0; i < MAXKEYPRESS; i++)
//     {
//       printf("key = %s\n", SDL_GetKeyName(all_event->key[i]));
//     }
//   printf("x = %i, y = %i\n",  all_event->xfin, all_event->yfin);
// }

int	get_click_pos(t_event *all_event, int c, SDL_MouseButtonEvent* event)
{
  all_event->mousepose[c].x = event->x;
  all_event->mousepose[c].y = event->y;
  all_event->mousepose[c].button = (char)event->button;
  return(0);
}

int	get_last_pos(t_event *all_event, SDL_MouseMotionEvent *event)
{
  all_event->xfin = event->x;
  all_event->yfin = event->y;
  return (0);
}

int	event(t_event *all_event, t_other_events *others)
{
  SDL_Event	event;
  int		mouse;
  int		keycpt;

  keycpt = 0;
  mouse = 0;
  while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_MOUSEBUTTONUP)
	{
	  if (mouse < MAXMOUSEEVENT)
	    {
	      get_click_pos(all_event, mouse,
			    (SDL_MouseButtonEvent*)&event);
	      all_event->mousepose[mouse].type = 1;
	      mouse++;
	    }
	}
      else if (event.type == SDL_MOUSEBUTTONDOWN)
	{
	  if (mouse < MAXMOUSEEVENT)
	    {
	      get_click_pos(all_event, mouse,
			    (SDL_MouseButtonEvent*)&event);
	      all_event->mousepose[mouse].type = 0;
	      mouse++;
	    }
	}
      else if (event.type == SDL_KEYDOWN)
	{
	  if (keycpt < MAXKEYPRESS)
	    {
	   //    printf("SDL_KEYDOWN\n");fflush(stdout);
	       all_event->key[keycpt] = event.key.keysym.sym;
	       keycpt++;
	    }
	}
      else if (event.type == SDL_MOUSEMOTION)
	get_last_pos(all_event, (SDL_MouseMotionEvent*)&event);
      else if (event.type == SDL_QUIT)
	{
// 	  printf("SDL_QUIT\n");fflush(stdout);
	  others->quit = 1;
	}
    }
  all_event->mod = SDL_GetModState();
  if (mouse < MAXMOUSEEVENT)
    {
      all_event->mousepose[mouse].x = -1;
      all_event->mousepose[mouse].y = -1;
      all_event->mousepose[mouse].button = 0;
    }
  all_event->key[keycpt] = (SDLKey)0;
  //get_last_pos(); ^ appeller plus haut
  return (0);
}
