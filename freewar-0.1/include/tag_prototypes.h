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
#ifndef _TAG_PROTOTYPES_H_
#define _TAG_PROTOTYPES_H_
int	manage_selection(t_engine *e, t_trame *t, int player);

/* req_info_scale.cpp */
int		req_info_scale(t_engine *e, t_trame *trame, int player);

/* req_select_move.cpp */
int		req_select_move(t_engine *e, t_trame *t, int player);

/* req_select_attack.cpp */
int		req_select_attack(t_engine *e, t_trame *t, int src);

/* req_select_create.cpp */
int		req_select_create_units(t_engine *e, t_trame *t, int src);
int		req_select_create_building(t_engine *e, t_trame *t, int src);

#endif
