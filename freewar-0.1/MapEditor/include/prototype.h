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
#ifndef _PROTOTYPE_H_
#define _PROTOTYPE_H_


/* const t_items  gl_items[NB_ITEMS]; */
const t_items  gl_items[NB_ITEMS] =
  {
    {1, IMG_GRASS, true, SDLK_SPACE},
    {843, IMG_RAIN, true, SDLK_q},
    {844, IMG_SNOW, true, SDLK_w},
    {845, IMG_SAND, true, SDLK_e},
    {846, IMG_SWAMP, true, SDLK_r},
    {847, IMG_RIVER, true, SDLK_t},
    {848, IMG_ROCK, true, SDLK_y},
    {849, IMG_MOUNTAIN, true, SDLK_u},
    {850, IMG_SEA, true, SDLK_i},
    {1842, IMG_GOLD, false, SDLK_g},
    {0, NULL, false, SDLK_d}
  };

Err		freewar(int ac, char **av);
SDL_Surface	*get_surf(t_info *info, unsigned int land);
bool		get_land(unsigned int id);
int		save_map(t_info *info);
Err		init_map(t_info *info, char *file);
int		load_map_data(t_info *info, FILE *fd);
/*
** my_std.cpp
*/
char	*fget_next_line(FILE *fd);
void	my_free_ptr_ptr(char **p);

void    *xmalloc(size_t s);
FILE    *xfopen(char *s, char *mode);
size_t	xfread(void *ptr, size_t size,
	       size_t nmemb, FILE *stream);
size_t	xfwrite(void *ptr, size_t size, size_t nmemb,
		FILE *stream);

int	put_error(char *s);
Err	resize_window(t_info *i, int w, int h);
Err	open_window(t_info *i, t_args *a);
Err	init_sdl(t_info *info);
Err	quit(t_info *info);
Err	menu(t_info *info);
Err	game(t_info *info);
Err	load_menu(t_info *info);
void	free_menu(t_info *info);
void	display_menu(t_info *info, t_menu *menu, int nb);
void	preload_menu(t_info *info);
Err	load_bmp(SDL_Surface **img, char *name);
Err	show_gamespace(t_info *info);
Err	update_gamespace(t_info *info);
Err	update_menu(t_info *info);
Err	load_map(t_info *info, char *file);
Err	load_game(t_info *info);
void	game_verif_pos(t_info *info);
void   	game_verif_move(t_info *info);
void   	game_verif_path(t_info *info, t_path **path);
t_path	*pathfinding(t_info *info, t_game *game);

/*
** menu_func.cpp
*/
Err	menu_exit(t_info *info);
Err	menu_play(t_info *info);
Err	menu_options(t_info *info);
/*
** menu_key.c
*/
Err	menu_key(t_info *info, SDL_Event e);
Err	menu_key_move(t_info *info, SDL_Event e);
/*
** menu_mouse.c
*/
Err	menu_mousebutton(t_info *info, SDL_Event e);
Err	menu_mousemotion(t_info *info, SDL_Event e);

/*
** game_key.c
*/
Err		game_key(t_info *info, SDL_Event e);
Err		game_key_move(t_info *info, SDL_Event e);

/*
** game_mouse.c
*/
Err		game_mousebutton(t_info *info, SDL_Event e);
Err		game_mousemotion(t_info *info, SDL_Event e);

/*
** xstd.cpp
*/
void		xSDL_BlitSurface(SDL_Surface *src,
				 SDL_Rect *srcrect,
				 SDL_Surface *dest,
				 SDL_Rect *destrect);

/*
** my_pathlist.cpp
*/
void		my_put_in_path(t_path **b, int x, int y);
t_path		*my_pathdup(t_path *path);
t_path          *my_rev_free_path(t_path *begin);
t_path          *my_rev_path(t_path *begin);
void		free_path(t_path *b);

#endif
