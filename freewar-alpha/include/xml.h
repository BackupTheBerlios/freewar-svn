/*
** xml.h for freewar in /u/ept2/huot_j
** 
** Made by jonathan huot
** Login   <huot_j@epita.fr>
** 
** Started on  Sat May 15 20:32:29 2004 jonathan huot
** Last update Sun May 16 18:00:04 2004 jonathan huot
*/

#ifndef _XML_H_
#define _XML_H_

double		xml_getfloat(char *str);
char		*xml_getstr(char *str);
int			xml_next(char *str);
void		xml_out();
int			xml_getint(char *str);
int			xml_init(char *db);

#endif
