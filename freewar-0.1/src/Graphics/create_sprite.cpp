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
//
// create_sprite.cpp for graphics in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Fri Jun  4 18:03:52 2004 jonathan huot
// Last update Tue Jun 29 18:55:50 2004 jonathan huot
//

#include "freewar.h"

extern t_gfx	*gfx;

size_t		ret_write(void *ptr, size_t size,
			size_t nmemb, FILE *stream)
{
  size_t        ret;

  ret = fwrite(ptr, size, nmemb, stream);
  if (!ret)
    put_error("Write failed on file descriptor");
  return (ret);
}

size_t		ret_read(void *ptr, size_t size,
		       size_t nmemb, FILE *stream)
{
  size_t           ret;

  ret = fread(ptr, size, nmemb, stream);
  if (!ret)
    put_error("Read failed on file descriptor");
  return (ret);
}

int		load_spk(t_spk *spk, char *path)
{
  FILE		*fd_src;
  FILE		*fd_dest;
  char		mybuff[512];
  char		version[32];
  size_t	res;
  int		i;
  t_info	info;

  fd_src = xfopen(path, "rb");
  fd_dest = xfopen("test.png", "wb");
  if (!fd_src)
    {
      fprintf(fd_log, "create_sprite: couldn't open spk %s!\n", path);
      return(-1);
    }
  if (!fd_dest)
    {
      fprintf(fd_log, "create_sprite: couldn't open temporary file!\n");
      return(-1);
    }
  for (i = 0; (res = ret_read(&version[i], sizeof(char), 1, fd_src)); i++)
    {
      if (!res)
	return (-1);
      if (!version[i])
	break;
    }
  if (strcmp(VERSION, version))
    {
      fprintf(fd_log, "Version of package = %s required version = %s\n",
	      version, VERSION);
    }
  if (!(res = ret_read(&info, sizeof(info), 1, fd_src)) &&
      ferror(fd_src))
    return (-1);
  while (1)
    {
      res = ret_read(mybuff, sizeof(*mybuff), 512, fd_src);
      if (res)
	{
	  if (!ret_write(mybuff, sizeof(*mybuff), res, fd_dest))
	    return (-1);
	}
      if (ferror(fd_src) || ferror(fd_dest))
	{
	  fprintf(fd_log, "can't write/read!\n");
	  return(-1);
	}
      if (feof(fd_src))
	break;
    }
  spk->w = info.w / info.nb_w;
  spk->h = info.h / info.nb_h;
  spk->col = info.nb_w;
  spk->row = info.nb_h;
  fprintf(fd_log, "create spk %s: w = %i h = %i (addr:%d)\n", path,
	  spk->w, spk->h, spk);
  fclose(fd_src);
  fclose(fd_dest);
  spk->sprite = IMG_Load("test.png");
  if (!spk->sprite)
    {
      fprintf(fd_log, "IMG_Load: %s\n", IMG_GetError());
      return (-1);
    }
  return (0);
}

int		create_sprite(char *path)
{
  int		i;

  if (!path)
    return (-1);
  for (i = 0; i < MAXSPRITE && gfx->spk[i].sprite; i++)
    ;
  if (i == MAXSPRITE)
    return (-1);
  if (strlen(path) > 4 && !strcmp(path + strlen(path) - 4, ".spk"))
    {
      if (load_spk(&gfx->spk[i], path) < 0)
	return (-1);
      return (i);
    }
  if (load_img(&gfx->spk[i].sprite, path) < 0)
    return (-1);
  gfx->spk[i].w = gfx->spk[i].sprite->w;
  gfx->spk[i].h = gfx->spk[i].sprite->h;
  gfx->spk[i].row = 1;
  gfx->spk[i].col = 1;
  fprintf(fd_log, "create sprite: %d, %s (%d, %d)\n",
	  i, path,gfx->spk[i].w,gfx->spk[i].h);
  return (i);
}
