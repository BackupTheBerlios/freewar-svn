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
** main.c for  in /u/ept2/vallat_a/mtmp/synapse/dos2unix
** 
** Made by arnaud vallat
** Login   <vallat_a@epita.fr>
** 
** Started on  Tue Feb 17 09:01:03 2004 arnaud vallat
** Last update Tue Mar 23 14:29:36 2004 arnaud vallat
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void	dos2unix(char **p_tab)
{
  int	c;
  char	*temp = "__TEMP____TEMP__";
  FILE	*fin;
  FILE	*fout;
  int	count;

  printf("Cleaning file starting ...\n");
  for (count = 0; p_tab[count]; count++)
    {
      printf("\t- checking file [%s] ... ", p_tab[count]);
      fin = fopen(p_tab[count], "rb");
      if (fin == NULL)
	{
	  printf("[FAILED] %s\n", strerror(errno));
	  continue ;
	}
      printf("[  OK  ]\n");
      fout = fopen(temp, "wb");
      if (fout == NULL)
	{
	  printf("/!\\ couldn't create temporary file (%s).\n",
		 strerror(errno));
	  fclose(fin);
	  exit (1);
	}
      printf("\t\t+ starting cleaning ...\n");
      while ((c = getc(fin)) != EOF)
	{
	  if (c != '\015' && c != '\032')
	    {
	      if ((putc(c, fout)) == EOF)
		{
		  fclose(fout);
		  fclose(fin);
		  printf("/!\\ Error while tranfering bytes : End of output"
			 "file reached.\n");
		  exit (1);
		}
	    }
	}
      fclose(fin);
      printf("\t\t+ cleaning done\n");
      printf("\t\t+ removing old file ...\n");
      remove(p_tab[count]);
      printf("\t\t+ renaming new file ...\n");
      rename(temp, p_tab[count]);
      printf("\t\t-> all done\n");
    }
  printf("finished\n");
}

int	main(int ac, char **av)
{
  if (ac > 1)
    dos2unix(av + 1);
  else
    printf("%s : usage : %s file1 file2 ...\n", av[0], av[0]);
  return (0);
}
