#ifndef _GL_PTR_H_
#define _GL_PTR_H_

typedef struct	s_type_tag
{
  short		tag;
  bool		local;
  int		(*f)(t_engine *e, t_trame *msg, int player);
}		t_type_tag;

#endif
