#ifndef _ENTITY_PROTOTYPES_H_
#define _ENTITY_PROTOTYPES_H_

int		is_collision(t_engine *e, t_entity *t, t_coord *c);
int		put_entity(t_engine *e, t_base_entity *base, int app,
			   t_coord pos, t_coord offset);
t_entity	*create_entity(t_engine *e, t_base_entity *base, int app,
			       t_coord pos);
int		del_entity_on_all_actions(t_engine *e, t_entity *t);
int		erase_entity(t_engine *e, t_entity *t);
int		del_entity(t_engine *e, unsigned long id);
int		init_entities(t_engine *e, t_game_param *game_param);
int		manage_entities(t_engine *e, t_game_param *game_param);
t_base_entity	*get_base(t_engine *e, char *name);
int		get_place_of_entity(t_engine *e, unsigned long id);
t_entity	*find_entity(t_engine *e, unsigned long id);
int		can_construct(t_engine *e, t_entity *t, t_base_entity *b, int nb);
int		attack_is_valid(t_engine *e, t_entity *origin, t_entity *attacked);

/* del_entity_in_map.cpp */
int		del_entity_in_map(t_engine *e, t_entity *t);

/* place_entity_in_map.cpp */
int		place_entity_in_map(t_engine *e, t_entity *t, t_coord *pos);

/*
** CLIENT
*/

/* entity_client_std.cpp */
t_entity	*create_entity_client(t_engine *e, t_base_entity *base,
				      unsigned long id, int app,
				      t_coord pos, t_coord off);
int		put_entity_client(t_engine *e, unsigned long id, char *name, 
				  int app, t_coord pos, t_coord offset);
int		erase_entity_client(t_engine *e, t_entity *t);
int		del_entity_client(t_engine *e, unsigned long id);

#endif
