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

#ifndef LOG_FILE
#define LOG_FILE ("fw.log")
#endif

FILE	*fd_log = 0;

int		init_log(char *s)
{
  FILE		*fd;

  if (!s)
    s = LOG_FILE;
  if((fd = fopen(s, "w")) == NULL)
    {
      printf("LOG_FILE fopen failed\n");
      return (1);
    }
  else
    {
      fd_log = fd;
      fprintf(fd_log, "<FREEWAR>\n");
    }
  return (0);
}

void		close_log()
{
  if (fd_log)
    fclose(fd_log);
  fd_log = 0;
}

int		put_error(char *s)
{
  if (fd_log)
    fprintf(fd_log, "ERROR: %s\n", s);
  else
    printf("Warning: log is not initialised\n");
  printf("\nERROR: %s\n", s);
  return (1);
}
