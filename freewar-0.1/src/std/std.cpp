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

int             get_random(int nb)
{
  static int    first = 1;
  unsigned int  ret;

  if (first)
    {
      srand((unsigned int)time(0));
      first = 0;
    }
  ret = ((unsigned int)rand()) % nb;
  return (ret);
}

char	*fill_data(size_t len, char *data)
{
  char	*res;

  res = (char*)xmalloc(len);
  memcpy(res, data, len);
  return (res);
}

char	*add_to_data(size_t len, char *data, size_t plus, char *add)
{
  data = (char*)xrealloc(data, len + plus);
  memcpy(data + len, add, plus);
  return (data);
}

bool	exist_file(char *file)
{
  FILE	*fd;

  fd = fopen(file, "r");
  if (!fd)
    return (false);
  fclose(fd);
  return (true);
}
