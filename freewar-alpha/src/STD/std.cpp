//
// std.cpp for freewar in /u/ept2/ribas_j/freewar/src
// 
// Made by jonathan ribas
// Login   <ribas_j@epita.fr>
// 
// Started on  Mon May  3 13:19:28 2004 jonathan ribas
// Last update Wed Jun 30 16:04:39 2004 
//

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


void		*xmalloc(size_t len)
{
  void		*p;

  p = malloc(len);
#ifdef MALLOCDEBUG
  printf("MALLOC: %d allouer\n", p);
  fflush(stdout);
#endif
  if (!p)
    {
      fprintf(fd_log, "Out of memory (%d bytes needed).\n", len);
      exit(-1);
    }
  return (p);
}

void		*xrealloc(void *ptr, size_t len)
{
  void		*p;

  p = realloc(ptr, len);
#ifdef MALLOCDEBUG
  printf("MALLOC: %d transform en %d\n", ptr, p);
  fflush(stdout);
#endif
  if (!p)
    {
      fprintf(fd_log, "Out of memory (%d bytes needed)\n", len);
      exit(-1);
    }
  return (p);
}

char		*xstrdup(char *s)
{
  char		*ptr;

  if (!s)
    return (0);
  ptr = strdup(s);
#ifdef MALLOCDEBUG
  printf("MALLOC: %d allouer\n", ptr);
  fflush(stdout);
#endif
  if (!ptr)
    {
      fprintf(fd_log, "out of memory\n");
      exit(-1);
    }
  return (ptr);
}

char		*xstrndup(char *s, int len)
{
  char		*ptr;

  if (!s)
    return (0);
  if (len < strlen(s))
    ptr = (char*)xmalloc(len + 1);
  else
    ptr = (char*)xmalloc(strlen(s) + 1);
  strncpy(ptr, s, len);
  ptr[len] = 0;
#ifdef MALLOCDEBUG
  printf("MALLOC: %d allouer\n", ptr);
  fflush(stdout);
#endif
  if (!ptr)
    {
      fprintf(fd_log, "out of memory\n");
      exit(-1);
    }
  return (ptr);
}

int		xstrlen(char *s)
{
  if (s)
    return (strlen(s));
  else
    return (0);
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

void		xfree(void *p)
{
#ifdef MALLOCDEBUG
  printf("MALLOC: %d liberer\n", p);
  fflush(stdout);
#endif
  free(p);
}

void            my_free_ptr_ptr(char **p)
{
  int           i;

  for (i = 0; p[i]; i++)
    xfree(p[i]);
  xfree(p);
}

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
