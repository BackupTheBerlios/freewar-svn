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
#ifndef _ACTION_PROTOTYPES_H_
#define _ACTION_PROTOTYPES_H_


int	replace_entity(t_engine *e, t_do_action *a);
int	get_pos_for_construct(t_engine *e, t_entity *t, t_coord *pos);
int	make_dammage(t_engine *e, t_entity *t, int damages);
int	req_edit_arena_surface(t_engine *e, t_trame *trame, int player);
int    	req_event_ok(t_engine *e, t_trame *req, int player);
int	get_action_anim(t_entity *t);
int	put_next_action(t_wait_action **a);
int	do_next_action(t_engine *e, t_entity *t);
int	del_next_actions(t_engine *e, t_entity *t);
int	pop_action(t_engine *e, t_entity *t, t_do_action *a);

/* create_action.cpp */
int	create_action(t_engine *e, t_entity *t, t_entity *attaked);
int	create_action(t_engine *e, t_entity *t, t_coord goal);
int	create_action(t_engine *e, t_entity *t, t_base_entity *base,
		      int nb_construct);
int	create_action(t_engine *e, t_entity *t, t_base_entity *base,
		      t_coord *pos);
int	create_action(t_engine *e, t_entity *t, int wait);

/* action.cpp */
int	update_actions(t_engine *e);

/* action_std.cpp */
int	get_damages(t_engine *e, t_entity *t, char *w);
int	get_length_of_path(t_coord *p);
int	moove_is_valide(t_engine *e, t_entity *t, t_coord g);
int	get_place_of_action(t_engine *e, unsigned long id);
int	del_action(t_engine *e, int id);
int	get_move_in_scale(t_entity *t, t_coord *pos, t_coord *off);
int	move_off_in_map(t_engine *e, t_entity *t, t_coord off);
int	get_rof(t_engine *e, t_entity *t, char *w);
char	*get_weapon(t_engine *e, t_entity *t, t_entity *attaked);
int	reset_actions(t_engine *e, t_entity *t);
int	get_range(t_engine *e, t_entity *t, char *w_name);
int	range_is_valide(t_engine *e, t_entity *t, t_entity *attaked, int range);
int	get_increment_size(t_do_action *a);

/* get_best_speed_factor.cpp */
float	get_best_speed_factor(t_engine *e, t_entity *t);

/* get_best_speed.cpp */
int	get_best_speed(t_engine *e, t_entity *t);
#endif
