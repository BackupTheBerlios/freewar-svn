#ifndef _STD_H_
#define _STD_H_

/*
** STD
*/
void	xfree(void *ptr);
void	*xmalloc(unsigned int size);
char	*xstrdup(char *s);
FILE	*xfopen(char *s, char *mode);
size_t  xfread(void *ptr, size_t size, size_t nmemb, FILE *stream);
char	*xstrncpy(char *dst, char *src, int len);
char	*xstrcpy(char *dst, char *src);
void	*xrealloc(void *ptr, size_t len);
int     get_random(int nb);
char	*fill_data(size_t len, char *data);
char	*add_to_data(size_t len, char *data, size_t plus, char *add);
char	*xstrndup(char *s, int len);
int	xstrlen(char *s);


#endif
