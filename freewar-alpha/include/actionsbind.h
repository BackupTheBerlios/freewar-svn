#ifndef _ACTIONSBIND_H_
#define _ACTIONSBIND_H_

typedef union			s_buttonbind
{
	short				button; // quel clic
	short				key;	// la touche
}						t_buttonbind;

typedef union			s_argbind
{
	short				action; // pour la souris, Press, Over, Release, Click (press & release), ..
	short				mod;	// modifier (alt, shift, ..)
}						t_argbind;

typedef struct			s_bind
{
	bool				mouse;
	t_buttonbind		button;
	t_argbind			arg;
	struct s_bind		*next; // pour les combos de touches
}						t_bind;

typedef struct			s_context
{
	char				*name;
	size_t				*nb_bind;
	t_bind				*bind;
}						t_context;

typedef struct			s_actionbind
{
	t_context			*contexts;
	size_t				nb_context;
}						t_actionbind;

void		manage_events(t_engine *e);

#endif
