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
** create_package.h for create_package in /u/ept2/petitc_s/sprite_package/create_sprite_package
** 
** Made by stephane petitcolas
** Login   <petitc_s@epita.fr>
** 
** Started on  Mon Jun  7 15:27:14 2004 stephane petitcolas
** Last update Wed Jun  9 11:07:45 2004 stephane petitcolas
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<fcntl.h>
#include	<SDL.h>
#include	<SDL_image.h>
#include	<string.h>
#define		VERSION ("1.0")

typedef	struct	s_info
{
  int	w;
  int	h;
  int	sprite_w;
  int	sprite_h;
  int	nb_w;
  int	nb_h;
}		t_info;
typedef	struct	s_arg
{
  char	*path;
  char	*name;
  int	w;
  int	h;
  int	nb_w;
  int	nb_h;
}		t_arg;

/**
create_package_sprite.cpp
**/

int		main(int ac, char **av);
int		parse_argument(char **av, t_arg *arg);
int		compare_value_real(t_arg arg, t_info *info);
int		create_package(t_arg arg, t_info info);

/**
xfunc.cpp
**/

size_t		xfwrite(void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t		xfread(void *ptr, size_t size, size_t nmemb, FILE *stream);
FILE            *xfopen(char *s, char *mode);
int		put_error(char *s);
