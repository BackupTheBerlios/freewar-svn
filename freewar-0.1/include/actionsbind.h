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
