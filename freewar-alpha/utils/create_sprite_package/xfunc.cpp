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
