##
## Makefile for freewar in /u/ept2/ribas_j/freewar/src
## 
## Made by jonathan ribas
## Login   <ribas_j@epita.fr>
## 
## Started on  Sat May  1 13:50:44 2004 jonathan ribas
## Last update Sun Jul 18 17:59:24 2004 
##

VPATH	=	Network:STD:load:Graphics:Pathfinding:../lib/sdlgfx/\
		:Actions:Entities:Graphics/Menu:ActionsBind

SDL_GFX	=	SDL_gfxPrimitives.cpp

DB	=	load_db_init.cpp load_db_data.cpp unpack.cpp load_db_land.cpp\
		load_db_index.cpp load_db_actions.cpp load_db_armor.cpp\
		load_db_base_entity.cpp load_db_instant.cpp load_db_meters.cpp\
		load_db_type.cpp load_db_weapon.cpp load_db_get.cpp\
		load_map.cpp get_id.cpp load_db_layers.cpp

PATHFINDING=	pf_init_open.cpp pf_init_values.cpp calc_case.cpp\
		searchsmall.cpp pathfinding.cpp my_pathlist.cpp\
		get_best_type.cpp

MENU	=	parse_menu.cpp get_headers.cpp\
		get_menu_entry0.cpp get_menu_entry1.cpp\
		uid_play.cpp uid_preplay.cpp uid_general.cpp\
		demo.cpp run_menu.cpp uid_server.cpp\
		aff.cpp aff_func.cpp aff_string.cpp\
		inputbox.cpp msgbox.cpp

GRAPHICS=	event.cpp xstd.cpp load_img.cpp get_events.cpp\
		create_and_open_screen.cpp destroy.cpp\
		create_surface.cpp edit_surface.cpp\
		create_sprite.cpp create_gfx_entity.cpp\
		edit_entity_on_surface.cpp update_surf.cpp\
		aff_screen.cpp update_anim.cpp edit_arena.cpp\
		gfx_debug.cpp

NET_ENGINE=	old.cpp init_msg.cpp init_connection.cpp init_client.cpp\
		check_select.cpp check_sockets.cpp close_connection.cpp\
		new_client.cpp recv.cpp send.cpp list.cpp loss_client.cpp\
		move_last_player.cpp msg_wait.cpp free_net.cpp

NETWORK	=	ping_all_client.cpp wait_all_player_is_ready.cpp\
		play_is_full.cpp send_to_all_player_new_game_status.cpp\
		transmit.cpp give_info_to_game.cpp send_to_server_freewar.cpp\
		recv_from_server_freewar.cpp

ACTION	=	del_action.cpp del_next_actions.cpp\
		pop_action.cpp put_next_action.cpp\
		update_actions.cpp gl_ptr.cpp action_std.cpp\
		attack_is_valid.cpp create_action.cpp\
		get_action_anim.cpp actions.cpp\
		can_construct.cpp

REQUEST =	req_info_scale.cpp req_select_move.cpp\
		req_select_attack.cpp req_select_create.cpp\
		req_event.cpp req_edit_arena_surface.cpp

ENTITY	=	construct_entity.cpp place_entity_in_map.cpp\
		del_entity_in_map.cpp collision.cpp\
		put_entity.cpp create_entity.cpp\
		del_entity_on_all_actions.cpp\
		erase_entity.cpp del_entity.cpp\
		init_entities.cpp manage_entities.cpp\
		get_base.cpp get_place_of_entity.cpp\
		find_entity.cpp get_best_speed.cpp\
		get_best_speed_factor.cpp

CLIENT	=	entity_client_std.cpp

ACTIONSBIND=	manage_events.cpp

SRC	=	freewar.cpp a_faire.cpp get_cfg.cpp std.cpp\
		launch_game.cpp add_player.cpp get_pos.cpp game_param.cpp\
		init_game_connection.cpp init_server_connection.cpp\
		server_connections.cpp engine_client.cpp engine_server.cpp\
		before_starting_game.cpp open_connection_to_the_game.cpp\
		get_and_init_sound.cpp get_and_init_display.cpp\
		xml_std.cpp init_globals.cpp get_direction.cpp\
		$(PATHFINDING) move_clients_to_players.cpp\
		init_engine.cpp aff_game.cpp\
		get_path.cpp free.cpp manage_requests.cpp\
		manage_selection.cpp join_game.cpp init_minimap.cpp\
		init_players_for_game.cpp timer.cpp\
		$(GRAPHICS) $(MENU) $(DB) $(ENTITY) $(NETWORK) $(NET_ENGINE)\
		$(REQUEST) $(SDL_GFX) $(ACTION) $(CLIENT) $(ACTIONSBIND)

OBJ	=	$(SRC:.cpp=.o)

NAME	=	freewar_`uname -s`

EXECUTABLE =	freewar

CXX	=	g++

CXXFLAGS=	-I../include/ -I../include/sdl/ `sdl-config --cflags` -g3\
		-I../lib/sdlgfx/ -I ../lib/sdlGL/

LIB	= 	-L../lib/ -L/usr/lib/ -L/usr/local/lib/ -ltinyxml_`uname -s` \
		`sdl-config --libs` -lSDL -lSDL_net -lSDL_image -lSDL_ttf# -lefence

CP	=	/bin/cp -f
RM	=	/bin/rm -f
LN	=	/bin/ln -sf

$(NAME)	:	$(OBJ)
		$(CXX) -o $(NAME) $(OBJ)  $(LIB) $(CFLAGS)
		cd .. && $(LN) src/$(NAME) $(NAME)
		$(LN) $(NAME) $(EXECUTABLE)

all	:	$(NAME)

clean	:
		$(RM) $(OBJ) *~ \#*\#

fclean	:	clean
		$(RM) $(NAME) ../$(NAME) ../$(EXECUTABLE)

re	:	fclean all
