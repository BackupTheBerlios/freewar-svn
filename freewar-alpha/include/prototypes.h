/*
** prototypes.h for freewar in /u/ept2/huot_j/Freewar/src
** 
** Made by jonathan huot
** Login   <huot_j@epita.fr>
** 
** Started on  Mon May 10 19:37:57 2004 jonathan huot
** Last update Mon Jul 12 17:27:49 2004 
*/

#ifndef _PROTOTYPE_H_
#define _PROTOTYPE_H_

/* DECLARATIONS */

/* freewar.cpp */
int	main(int ac, char **av);
int	put_error(char *s);
int	load_db_init(t_db_info *db_info, t_cfg *cfg);
int	get_cfg(t_cfg *cfg);
int	before_starting_game(t_game_param *game_params);
int	update_game_param(t_trame *req, t_game_param *game_params); //
int	engine_server(t_engine *e, t_cfg *cfg,
		      t_game_param *game_param);
int	engine_client(t_engine *e, t_cfg *cfg, t_game_param *game_param);
int	init_log(char *file);
void	close_log();
int	freewar();

// ailleurs..
int	init_minimap(t_engine *e);
void	init_engine(t_engine *e);
int	load_db_data(t_engine *e, t_game_param *gp, t_cfg *cfg);
int	launch_game(t_cfg *cfg);
int	init_players_for_game(t_engine *e, int who);
int	init_player(t_player *player);
int	open_connection_to_the_game();
int	give_info_to_game(t_db_info *db_info);
int	get_launch_params();
int	join_game(t_trame *req);
int	move_clients_to_players(t_engine *e, t_game_param *game_param);
int	transmit_requests();
int	transmit_response();
int	get_and_aff();
int	get_and_play_sound();

int	wait_all_player_is_ready();
int	reset_timer(t_engine *e);
int	timer_count(char *s, bool start);
int	manage_requests(t_engine *e);
int	init_selection(t_engine *e);
int	del_empty_selection(t_engine *e, t_entity *t);
int	manage_player();
int	get_events(t_engine *e);
int	send_event();
int	aff_game(t_engine *e, t_game *g);
int	play_sound();
int	timer_wait(t_engine *e);

int	get_nb_connects();
int	play_is_full();
int	kick_last_player();
int	check_hash5_db_valide();
int	send_db_to_player();

int	req_is_new_game(t_trame *req);
int	send_hash5_to_server();
int	get_game_param_from_server(t_trame *req, t_game_param *game_params);
int	init_game_param(t_game_param *game_params, t_trame *req);
int	copy_game_param(t_trame *req, t_game_param *game_params);
int	send_to_all_player_new_game_status(t_game_param *game_params);

int	add_player(t_game_param *game_param, t_trame *req);
//int	get_pos_of_player(t_pos *pos, int client);
int	get_pos_of_socket(TCPsocket socket);
int	get_pos_of_empty_slot(t_game_param *game_param);
int	get_and_init_sound(t_cfg *cfg);
int	get_and_init_display(t_cfg *cfg);
int	init_globals(t_engine *e);

/* free.cpp */
int		free_engine(t_engine *e);

/* get_direction.cpp */
int		get_direction(int origin, t_coord *src, t_coord *dst);

/* send_to_server_freewar.cpp */
int		send_to_all_fw(t_engine *e, short tag,
			       unsigned int len, void *msg);
int		fw_send_action(t_engine *e, t_entity *t);
int		fw_send_pos(t_engine *e, t_entity *t);
int		fw_send_off(t_engine *e, t_entity *t);
int		fw_send_ent_meter(t_engine *e, t_entity *t, char *name, int new_val);
int		fw_send_create_ent(t_engine *e, t_entity *t);
int		fw_send_del_ent(t_engine *e, t_entity *t);
int		fw_send_del_ent_in_map(t_engine *e, t_entity *t);
int		fw_send_dir(t_engine *e, t_entity *t);

/* recv_from_server_freewar.cpp */
int		fw_recv_action(t_engine *e, t_trame *trame, int pl);
int		fw_recv_pos(t_engine *e, t_trame *trame, int pl);
int		fw_recv_off(t_engine *e, t_trame *trame, int pl);
int		fw_recv_ent_meter(t_engine *e, t_trame *trame, int pl);
int		fw_recv_create_ent(t_engine *e, t_trame *trame, int pl);
int		fw_recv_del_ent(t_engine *e, t_trame *trame, int pl);
int		fw_recv_del_ent_in_map(t_engine *e, t_trame *trame, int pl);
int		fw_recv_dir(t_engine *e, t_trame *trame, int pl);

#endif
