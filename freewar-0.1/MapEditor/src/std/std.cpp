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
// std.cpp for freewar in /u/ept2/ribas_j/freewar/src
// 
// Made by jonathan ribas
// Login   <ribas_j@epita.fr>
// 
// Started on  Mon May  3 13:19:28 2004 jonathan ribas
// Last update Wed May 12 18:56:02 2004 jonathan huot
//

#include "freewar.h"

#ifndef LOG_FILE
#define LOG_FILE ("fw.log")
#endif

int		init_log()
{
  FILE		*fd;
  
  if((fd = fopen(LOG_FILE, "w")) == NULL)
    {
      printf("LOG_FILE fopen failed\n");
      return (1);
    }
  else
    {
      fwrite("<FREEWAR>\n", sizeof(char) * 10, 1, fd);
      fclose(fd);
    }
  return (0);
}

int		put_error(char *s)
{
  FILE		*fd;
  
  if((fd = fopen(LOG_FILE, "a")) == NULL)
    printf("LOG_FILE fopen failed\n");
  else
    {
      fwrite("ERROR: ", sizeof(char) * 7, 1, fd);
      fwrite(s , sizeof(char) * strlen(s), 1, fd);
      fwrite("\n", sizeof(char) * 1, 1, fd);
      fclose(fd);
    }
  printf("\n\nERROR: %s\n", s);
  return (1);
}


void		*xmalloc(size_t len)
{
  void		*p;

  p = malloc(len);
  if (!p)
    {
      fprintf(stderr, "Out of memory (%i bytes needed).\n", len);
      exit(-1);
    }
  return (p);
}

char		*xstrdup(char *s)
{
  if (!s)
    return (0);
  else
    return (strdup(s));
}

char		*xstrcpy(char *dst, char *src)
{
  if (dst && src)
    return(strcpy(dst, src));
  else
    return(dst);
}

char		*xstrncpy(char *dst, char *src, int len)
{
  if (dst && src)
    return(strncpy(dst, src, len));
  else
    return(dst);
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
  if (size && nmemb && ret < nmemb)
    return (put_error("Read failed on file descriptor"));
  return (0);
}

size_t		xfwrite(void *ptr, size_t size,
			size_t nmemb, FILE *stream)
{
  size_t        ret;

  ret = fwrite(ptr, size, nmemb, stream);
  if (size && nmemb && ret < nmemb)
    return (put_error("Write failed on file descriptor"));
  return (0);
}

void            my_free_ptr_ptr(char **p)
{
  int           i;

  for (i = 0; p[i]; i++)
    free(p[i]);
  free(p);
}
