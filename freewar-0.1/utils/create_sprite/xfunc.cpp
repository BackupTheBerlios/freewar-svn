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
// xfunc.cpp for xfunc in /u/ept2/petitc_s/sprite_package/create_sprite_package
// 
// Made by stephane petitcolas
// Login   <petitc_s@epita.fr>
// 
// Started on  Mon Jun  7 16:56:24 2004 stephane petitcolas
// Last update Mon Jun  7 17:09:07 2004 stephane petitcolas
//

#include	"create_package.h"

int		put_error(char *s)
{
  FILE		*fd;
  
  printf("ERROR: %s\n", s);
  return (-1);
}

FILE            *xfopen(char *s, char *mode)
{
  FILE          *fd;

  fd = fopen(s, mode);
  if (!fd)
    {
      put_error("Failed to open file'");
      return (0);
    }
  return (fd);
}

size_t		xfread(void *ptr, size_t size,
		       size_t nmemb, FILE *stream)
{
  size_t           ret;

  ret = fread(ptr, size, nmemb, stream);
  if (ret < 0)
    return (put_error("Read failed on file descriptor"));
  return (ret);
}

size_t		xfwrite(void *ptr, size_t size,
			size_t nmemb, FILE *stream)
{
  size_t        ret;

  ret = fwrite(ptr, size, nmemb, stream);
  if (ret < 0)
    return (put_error("Write failed on file descriptor"));
  return (ret);
}
