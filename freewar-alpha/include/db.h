/*
** db.h for freewar in /u/ept2/huot_j/Freewar/src
** 
** Made by jonathan huot
** Login   <huot_j@epita.fr>
** 
** Started on  Fri May 14 13:24:26 2004 jonathan huot
** Last update Mon May 17 14:32:31 2004 jonathan huot
*/

#ifndef _DB_H_
#define _DB_H_

typedef struct	s_db_index
{
  char		*type;
  char		*name;
}		t_db_index;

typedef struct	s_db_ind
{
  int		nb_index;
  t_db_index	*index;
  int		nb[MAX_TYPES];
}		t_db_ind;

void		free_index(t_db_ind *ind);
void		db_load_index(t_db_ind *ind);
int		db_index(t_engine *e, t_db_ind *ind);
int		load_db(t_engine *e);
int		load_db_data(t_engine *e, t_game_param *gp);
int		db_action_move(t_engine *e, t_action *action);
int		db_action_live(t_engine *e, t_action *action);
int		db_action_died(t_engine *e, t_action *action);
int		db_action_attack(t_engine *e, t_action *action);
int		db_action_create(t_engine *e, t_action *action);
int		db_armor(t_engine *e, t_db_ind *ind);
int		db_types_entity(t_engine *e, t_db_ind *ind, t_type ***type);
int		db_weapons_entity(t_engine *e, t_db_ind *ind, t_weapon ***weapon);
int		db_armors_entity(t_engine *e, t_db_ind *ind, t_armor ***armor);
int		db_costs_entity(t_engine *e, t_db_ind *ind, t_cost **costs);
int		db_meters_entity(t_engine *e, t_db_ind *ind, t_base_meter **meters);
int		db_actions_entity(t_engine *e, t_db_ind *ind, t_action *actions);
int		db_base_entity(t_engine *e, t_db_ind *ind);
int		db_base_instant(t_engine *e, t_db_ind *ind);
int		db_base_land(t_engine *e, t_db_ind *ind);
t_factor	*db_factor_surface(t_engine *e);
int		db_factors(t_engine *e, t_db_ind *ind,
			   t_factors **factors);
int		db_type(t_engine *e, t_db_ind *ind);
int		db_weapon(t_engine *e, t_db_ind *ind);
t_type		**db_get_types(t_engine *e);
int		db_meters(t_engine *e);
int		db_layers(t_engine *e);

/*
** MAP
*/
int		load_map_data(t_engine *e, int id);
int		load_map(t_engine *e);
int		free_map(t_engine *e);
int		load_map_data_scale(t_engine *e, FILE *fd);
int		load_map_start_point(t_engine *e, FILE *fd);
int		load_map_header(t_engine *e, FILE *fd);
int		load_img(SDL_Surface **img, char *name);

int		unpack_sprite(char *s);
int		unpack_taunt(char *s);

t_base_land	*get_land(t_engine *e, unsigned int land);
int		get_entity(t_engine *e, unsigned int item, t_coord pos);

#endif
