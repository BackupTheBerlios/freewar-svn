//
// aff.cpp for freewar in /u/ept2/skondr_m
// 
// Made by mael skondras
// Login   <skondr_m@epita.fr>
// 
// Started on  Mon May 24 11:51:21 2004 mael skondras
// Last update Mon Jun  7 13:34:07 2004 mael skondras
//

#include "freewar.h"

extern t_gfx *gfx;

t_drawfunc	wesh[] =
  {
    {"button", draw_button},
    {"table", draw_table},
    {"text", draw_txtbox},
    //    {"list", draw_list},
    //    {"image", draw_image},
    //    {"box", draw_box},
    {0, 0}
  };

char		*update_txtbox(char *str, SDL_KeyboardEvent *event)
{
  int		len;
  char		*tmp;

  // enter 13 + numpad 271
  // bksp = 8
  // esc = 27
  len = xstrlen(str);
  if (event->keysym.sym >= ' '
      && event->keysym.sym <= '~')
    {
      tmp = (char*)xmalloc(len + 2);
      xstrncpy(tmp, str, len);
      tmp[len] = event->keysym.sym;
      tmp[len + 1] = 0;
      free(str);
      str = tmp;
    }
  else if (event->keysym.sym == 266)
    {
      tmp = (char*)xmalloc(len + 2);
      xstrncpy(tmp, str, len);
      tmp[len] = '.';
      tmp[len + 1] = 0;
      free(str);
      str = tmp;
    }
  else if (event->keysym.sym >= 256
	   && event->keysym.sym <= 265)
    {
      tmp = (char*)xmalloc(len + 2);
      xstrncpy(tmp, str, len);
      tmp[len] = (event->keysym.sym - 256 + '0');
      tmp[len + 1] = 0;
      free(str);
      str = tmp;
    }
  else if (event->keysym.sym == 27)
    gfx->win->focus = -1;
  else if (event->keysym.sym == 8)
    {
      if (len > 1)
	{
	  tmp = xstrndup(str, len - 1);
	  free(str);
	  str = tmp;
	}
      else if (len == 1)
	{
	  free(str);
	  str = 0;
	}
      else if (!str)
	printf("%c", 7);
    }
  return (str);
}

int		fade(t_display *win, int speed)
{
  int	i;

  for (i = 0; i != speed; i++)
    {
      win->alpha += 0;//win->delta_alpha;
      if(win->alpha >= SDL_ALPHA_OPAQUE)
	{
	  win->alpha = SDL_ALPHA_OPAQUE;
	  win->delta_alpha = -win->delta_alpha;
	}
      else if(win->alpha <= 0)
	{
	  win->alpha = 0;
	  win->delta_alpha = -win->delta_alpha;
	}
      SDL_SetAlpha(win->img, SDL_SRCALPHA, (Uint8)win->alpha);
      SDL_BlitSurface(win->img, NULL/*&(win->sdlSrcSprite)*/, 
		      win->sdlMainScreen, &(win->possprite));
      SDL_Flip(win->sdlMainScreen);
      //SDL_Delay(1);
    }
  return (0);
}

int		aff_surf(SDL_Surface *img, int alpha)
{
  SDL_SetAlpha(img, SDL_SRCALPHA, (Uint8)alpha);
  SDL_BlitSurface(img, NULL/*&(win->sdlSrcSprite)*/, 
		  gfx->win->sdlMainScreen, &(gfx->win->dest));
  SDL_Flip(gfx->win->sdlMainScreen);
  return (0);
}

int		launch_logo(t_display *win, int x, int y, int speed)
{
  if(win->img == NULL)
    return(1);
  SDL_SetColorKey(win->img, SDL_SRCCOLORKEY,0);
  //win->sdlSrcSprite.w = win->res_w;
  //win->sdlSrcSprite.h = win->res_h;
  //win->sdlSrcSprite.y = 0;
  //win->sdlSrcSprite.x = 0;
  win->possprite.x = x;
  win->possprite.y = y;
  fade(win, speed);
  SDL_FreeSurface(win->img);
  return(0);
}

int	InputMouseMotionEvent(SDL_MouseButtonEvent* event,
			      t_display *win, t_menu_entry *menu)
{
  int	i;

  for (i = 0; menu[i].uid; i++)
    {
      if (!strcmp(menu[i].type, "button"))
	{
	  if (event->y > ((t_menu_button*)(menu[i].info))->y
	      && event->y < ((t_menu_button*)(menu[i].info))->y + 50
	      && event->x > ((t_menu_button*)(menu[i].info))->x
	      && event->x < ((t_menu_button*)(menu[i].info))->x + 140)
	    {
	      win->focus = i;
	      return(i);
	    }
	}
      else if (!strcmp(menu[i].type, "text"))
	{
	  win->text = load_string(((t_menu_text*)(menu[i].info))->value, FONT, ((t_menu_text*)(menu[i].info))->text_size);
	  if (event->y > ((t_menu_text*)(menu[i].info))->y
	      && event->y < ((t_menu_text*)(menu[i].info))->y + win->text->h + 4
	      && event->x > ((t_menu_text*)(menu[i].info))->x
	      && event->x < ((t_menu_text*)(menu[i].info))->x + TXTBOX_WIDTH)
	    {
	      xstrcpy(((t_menu_text*)(menu[i].info))->background,"FF0000");
	      //grey out current focus
	      // focus text box
	      win->focus = i;
	      draw_txtbox(win, &(menu[win->focus]));
	      return (i);
	    }
	  xstrcpy(((t_menu_text*)(menu[i].info))->background,"CC0000");
	  draw_txtbox(win, &(menu[i]));
	}
    }
  win->focus = -1;
  return(-1);
}

int		event(t_display *win, t_menu_entry *menu)
{
  int	i;
  SDL_Event event;

  while (42)
    {
      while (SDL_PollEvent(&event) || win->redraw)
	{
	  if (event.type == SDL_MOUSEBUTTONUP)
	    {
	      if ((i = InputMouseMotionEvent((SDL_MouseButtonEvent*)&event,
					     win, menu)) != -1)
		return (i);
	    }
          else if (event.type == SDL_KEYDOWN)
	    {
	      if (win->focus > 0 && !strcmp(menu[win->focus].type, "text"))
		{
		  ((t_menu_text*)(menu[win->focus].info))->value = update_txtbox(((t_menu_text*)(menu[win->focus].info))->value, (SDL_KeyboardEvent*)&(event.key));
		  if (win->focus > 0)
		    {
			  t_return_text		ptr;
  
		      ptr.menu = win->focus;
		      xstrcpy(ptr.value, ((t_menu_text*)(menu[win->focus].info))->value);
			  call_entity_func(&(menu[win->focus]), &ptr);
		      draw_txtbox(win, &(menu[win->focus]));
		      return (win->focus);
		    }
		}
	    }
	}
      if (win->redraw)
	{
	  win->redraw = 0;
	  return (-2);
	}
    }
}

void		*launch_menu(t_display *win, t_menu_entry *menu)
{
  int	i,j;
  t_return_button	*ptr;

  ptr = (t_return_button*)xmalloc(sizeof(*ptr));
  win->alpha = 255;
  win->delta_alpha = 7;
  win->dest.x = 0;
  win->dest.y = 0;
  if (win->img = IMG_Load("AFirstChaos/img/menu/Burloak.png"))
    {
      aff_surf(win->img, 255);
      SDL_FreeSurface(win->img);
    }
  if (win->img = IMG_Load("AFirstChaos/img/menu/freewar_logo.png"))
    {
      win->dest.x = (win->res_w - win->img->w) / 2;
      win->dest.y = 4;
      aff_surf(win->img, 255);
      SDL_FreeSurface(win->img);
    }
  if (menu)
    for (i = 0; menu[i].uid; i++)
      {
	if (!strcmp(menu[i].type, "text") && win->focus != i)
	  xstrcpy(((t_menu_text*)(menu[i].info))->background,"CC0000");
	for(j = 0; wesh[j].type;j++)
	  if(!strcmp(menu[i].type, wesh[j].type))
	    {
	      wesh[j].draw(win, &(menu[i]));
	      break;
	    }
      }
  else
    return ((void*)-1);
  do
    {
      ptr->menu = event(win, menu);
    } while (ptr->menu > 0 && strcmp(menu[ptr->menu].type, "button"));
  return(ptr);
}
