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
//
// create_pakage_sprite.cpp for create_package_sprite in /u/ept2/petitc_s/sprite_package/create_sprite_package
// 
// Made by stephane petitcolas
// Login   <petitc_s@epita.fr>
// 
// Started on  Mon Jun  7 15:28:47 2004 stephane petitcolas
// Last update Mon Jun  7 17:42:46 2004 stephane petitcolas
//

#include	"create_package.h"

int		parse_argument(char **av, t_arg *arg)
{
  int	i;

  for (i = 1; i < 7; i++)
    if (!av[i][0])
      return(-1);
  arg->path = av[1];
  arg->name = av[2];
  arg->w = atoi(av[3]);
  arg->h = atoi(av[4]);
  arg->nb_w = atoi(av[5]);
  arg->nb_h = atoi(av[6]);
  return(0);  
}

int		compare_value_real(t_arg arg, t_info *info)
{
  SDL_Surface	*img;

  img = IMG_Load(arg.path);
  if(!img)
    {
      printf("IMG_Load: %s\n", IMG_GetError());
      return(-1);
    }
  if (img->w == (arg.w * arg.nb_w) && img->h == (arg.h * arg.nb_h))
    {
      info->w = arg.w * arg.nb_w;
      info->h = arg.h * arg.nb_h;
      info->sprite_w = arg.w;
      info->sprite_h = arg.h;
      info->nb_w = arg.nb_w;
      info->nb_h = arg.nb_h;
      fprintf(stderr,"w = %i h = %i sprite_w = %i sprite_h = %i "
	      "nb_w = %i nb_h = %i\n",
	      info->w, info->h, info->sprite_w,
	      info->sprite_h,  info->nb_w, info->nb_h);
      SDL_FreeSurface(img);
      return(0);
    }
  else
    {
      fprintf(stderr,"bad size you have enter w = %i h = %i\n"
	      "real size of sprite is w = %i h = %i\n", 
	      (arg.w * arg.nb_w), (arg.h * arg.nb_h),
	      img->w, img->h);
      SDL_FreeSurface(img);
      return(-1);
    }
  return(-1);
}

int		create_package(t_arg arg, t_info info)
{
  FILE		*fd_src;
  FILE		*fd_dest;
  char		buff[512];
  int		res;

  fd_src = xfopen(arg.path, "r");
  fd_dest = xfopen(arg.name, "w");
  xfwrite((void*)VERSION, sizeof(char), strlen(VERSION) + 1, fd_dest);
  xfwrite(&info, sizeof(info), 1, fd_dest);
  while ((res = xfread(buff, sizeof(char), 512, fd_src)))
    {
      if (res != -1)
	  xfwrite(buff, sizeof(char), res, fd_dest);
      else
	{	
	  fprintf(stderr, "can't write!\n");
	  return(-1);
	}
    }
  fclose(fd_src);
  fclose(fd_dest);
  return(0);
}

int		main(int ac, char **av)
{
  t_arg		arg;
  t_info	info;

  if (ac == 7)
    {
      printf("nb_arg = %i\n", ac);
      if (parse_argument(av, &arg))
	{
	  fprintf(stderr, "Usage : ./create_package sprite_path "
		  "package_name width height nb_width nb_height!\n");
	  return(-1);
	}
      if (compare_value_real(arg, &info))
	{
	   fprintf(stderr, "erreur dans un des parametre!\n");
	   return(-1);
	}
      if (create_package(arg, info))
	{
	   fprintf(stderr, "erreur lors de la creation du package!\n");
	   return(-1);
	}
    }
  else
  fprintf(stderr, "Usage : ./create_package sprite_path "
		  "package_name width height nb_width nb_height!\n");
  return(0);
}
