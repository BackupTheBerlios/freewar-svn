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
** graphics.h for freewar in /u/ept2/huot_j/Freewar/src
** 
** Made by jonathan huot
** Login   <huot_j@epita.fr>
** 
** Started on  Mon May 10 19:40:09 2004 jonathan huot
** Last update Sun Jul 18 17:49:20 2004 
*/

#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include <stdlib.h>

#include <SDL_image.h>
#include <SDL_ttf.h>

extern FILE		*fd_log;

#define GRAPHICS_TIME
/* #define GRAPHICS_DEBUG */


/* stef */
#define	CASE_SIZE_X	(32)
#define	CASE_SIZE_Y	(32)
#define SCROLL_X	(10)
#define SCROLL_Y	(10)

#define	MAXSUBSCREEN	(32)
#define MAXSAMESURFACE	(32)
#define	MAXSPRITE	(1024)
#define MAXENTITY	(50000)
#define MAXSQUARE	(256)
#define MAXDEBUG	(32)
#define MAXKEYPRESS	(10)
#define	MAXMOUSEEVENT	(3)

#define GFX_MAX_DEPTH	(500000)
#define GFX_MIN_DEPTH	(-500000)

#define GFX_FULL	(SDL_HWSURFACE | SDL_FULLSCREEN | SDL_DOUBLEBUF)
#define GFX_SW		(SDL_SWSURFACE | SDL_DOUBLEBLUF)
#define GFX_FULL_SW	(GFX_SW | SDL_FULLSCREEN)

#define RMASK(s)	(s->format->Rmask)
#define GMASK(s)	(s->format->Gmask)
#define BMASK(s)	(s->format->Bmask)
#define AMASK(s)	(s->format->Amask)

#ifndef STRUCT_S_COORD
#define STRUCT_S_COORD

#define	VERSION ("1.0")

/* Showing Msg Boxes on screen */
#define MB_WIDTH	(420)
#define MB_HEIGHT	(142)
#define MB_OK		(1)
#define MB_CANCEL	(0)
#define MB_YES		(21)
#define MB_NO		(42)

#define MB_INFO			(81)
#define MB_OKCANCEL		(82)
#define MB_YESNO		(83)
#define MB_YESNOCANCEL	(80)

typedef struct	s_coord
{
  int		x;
  int		y;
}		t_coord;
#endif

typedef	struct	s_surface
{
  bool		exist;
  SDL_Surface	*s;
  Uint32	color;
  int		x; // x de depart de l'arena dans l'ecran
  int		y; // y de depart de l'arena dans l'ecran
  int		w; // largeur de l'arena
  int		h; // hauteur de l'arena
  int		depth;
  int		show;
  int		arena;
  int		zoom;
  t_coord	scale; // care haut gauche
  t_coord	off; // off
}		t_surface;

typedef struct	s_gfx_entity // details sur l'entitee
{
  int		id_sprite;
  int		id_surf;
  int		x; // coordonnee sur la map de l'entitee en pixel
  int		y; // 
  int		alpha;
  int		row; // quelle direction
  int		col; // quelle frame de l'animation
}		t_gfx_entity;

typedef struct	s_square
{
  bool		exist;
  int		id_surf;
  Uint32	color;
  int		x1; // coordonnee haut gauche sur la map
  int		y1; //  du carre en pixel
  int		x2; // coord bas droite
  int		y2;
}			t_square;

typedef struct	s_spk // pakage de sprite
{
  int		w; // dimensions d'un sprite
  int		h; // 
  int		row; // nb de sprite
  int		col; // 
  SDL_Surface	*sprite; // l'image regroupant tous les sprites
}		t_spk;

typedef	struct	s_info
{
  int	w;
  int	h;
  int	sprite_w;
  int	sprite_h;
  int	nb_w;
  int	nb_h;
}		t_info;

int	gfx_put_square(int x, int y, int color);
int	show_debug();
int	load_spk(t_spk *spk, char *path);
int	load_img(SDL_Surface **img, char *name);
int	create_and_open_screen(int w, int h, int bpp, int mode);
int	create_surface(int w, int h, int depth, Uint32 color, int arena);
int	create_gfx_entity(int id);
int	create_square_entity();
void	destroy_surface(int i);
void	destroy_sprite(int i);
void	destroy_gfx_entity(int i);
int aff_screen();
int edit_entity_on_surface(int i, int d, int x, int y, int alpha);
int edit_square_on_surface(int id, int s, struct s_coord *c,
						   struct s_coord *c2, Uint32 col);
int create_sprite(char *path);
int edit_surface(int i, int x, int y, int show, int alpha);
int update_surf(int mini, int maxi);
int edit_arena(int id, t_coord *scale, t_coord *offset, int zoom);

int	update_anim(int gfx, int row, int col, int newsprite);

/* void	set_rect_height(struct s_coord coord, int h, int nb, */
/* 			const int off, SDL_Rect *src); */
/* void	set_rect_width(struct s_coord coord, int w, int nb, */
/* 		       const int off, SDL_Rect *src); */
/* int	update_scales(struct s_scale **scales, int x, int y, int w, int h); */

int		xSDL_BlitSurface(SDL_Surface *src, SDL_Rect *srcrect,
				 SDL_Surface *dest, SDL_Rect *destrect);
SDL_Surface	*xSDL_DisplayFormatAlpha(SDL_Surface *s);
int		xSDL_SetAlpha(SDL_Surface *s, Uint32 flag, Uint8 alpha);

/* Msg Boxes*/
int		fw_msgbox(char *title, char *msg, int flag);
char		*fw_inputbox(char *title, char *msg, char *def_val);
int		show_button(int x, int y, char *msg, int off, char *sprite);



// event:
typedef	struct	s_mouse
{
  int	x;
  int	y;
  char	button;
  bool	type;
}		t_mouse;

typedef struct	s_other_events
{
/*   bool		resize; */
/*   bool		expose; */
  bool		quit; // 0 si press 1 si release;
}		t_other_events;

typedef	struct	s_event
{
  int		xfin;
  int		yfin;
  t_mouse	mousepose[MAXMOUSEEVENT];
  SDLKey	key[MAXKEYPRESS];
  SDLMod    mod;
}		t_event;

int	event(t_event *all_event, t_other_events *others);

typedef	struct	s_display
{
  SDL_VideoInfo *sdlVideoInfo;
  int		bpp;
  SDL_Surface	*sdlMainScreen;
  SDL_Surface	*img;
  signed short	alpha;
  signed char	delta_alpha;
  SDL_Rect	sdlSrcSprite;
  SDL_Rect	possprite;
  TTF_Font	*font;
  SDL_Surface	*text;
  SDL_Rect	dest;
  int		focus;
  int		redraw;
}		t_display;

typedef	struct	s_gfx
{
  SDL_VideoInfo *videoinfo;
  int		bpp;
  SDL_Surface	*main;
  SDL_Surface	*buff;
  t_spk		spk[MAXSPRITE];
  t_gfx_entity	entity[MAXENTITY];
  t_surface	surface[MAXSUBSCREEN];
  t_gfx_entity	debug[MAXDEBUG];
  t_square	square[MAXSQUARE];
  t_display	*win;
}		t_gfx;

#endif
