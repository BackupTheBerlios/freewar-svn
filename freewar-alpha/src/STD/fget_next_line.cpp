/*
** get_next_line.c for get_next_line in /u/ept1/huot_j/c/rendu/get_next_line
** 
** Made by jonathan huot
** Login   <huot_j@epita.fr>
** 
** Started on  Sat Nov 30 14:27:54 2002 jonathan huot
** Last update Thu Dec 12 18:14:54 2002 jonathan huot
*/

#include "freewar.h"

typedef struct	s_struct
{
  char		*s;
  int		taille;
  int		j;
}		t_struct;

void		*my_realloc(void *ptr, size_t oldsize, size_t newsize)
{
  void		*newz;
  int		i;
 
  newz = malloc(newsize);
  for (i = 0; i < (int)oldsize; i++)
    ((char*)newz)[i] = ((char*)ptr)[i];
  free(ptr);
  return (newz);
}

int		init_struct(t_struct *tbl)
{
  tbl->taille = BUF_SIZE;
  tbl->j = 0;
  if ((tbl->s = (char*)malloc(tbl->taille)) == 0)
    return (0);
  tbl->s[0] = 0;  
  return (1);
}

void		realloc_s(t_struct *tbl)
{
  tbl->s = (char*)my_realloc(tbl->s, tbl->taille, tbl->taille + BUF_SIZE);
  tbl->taille += BUF_SIZE;
}

char		*end_of(char *s, int j)
{
  s[j] = 0;
  return (s);
}

char		*fget_next_line(FILE *fd)
{
  t_struct	tbl;
  static char	buf[BUF_SIZE];
  static int	i = 0;
  static int	lu = 0;

  if (!init_struct(&tbl))
    return (0);
  while (1)
    {
      if (i >= lu)
	{
	  lu = (int)fread(buf, 1, BUF_SIZE, fd);
	  if (lu == 0)
	    return ((tbl.s[0]) ? (end_of(tbl.s, tbl.j)) : (0));
	  i = 0;
	}
      if ((tbl.j + 1) == tbl.taille)
	realloc_s(&tbl);
      if (buf[i] == '\n' || !buf[i])
	{
	  i++;
	  return (end_of(tbl.s, tbl.j));
	}
      tbl.s[tbl.j++] = buf[i++];
    }
}
