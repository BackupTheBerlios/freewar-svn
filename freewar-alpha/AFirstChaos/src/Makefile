##
## Makefile for freewar in /u/ept2/ribas_j/freewar/src
## 
## Made by jonathan ribas
## Login   <ribas_j@epita.fr>
## 
## Started on  Sat May  1 13:50:44 2004 jonathan ribas
## Last update Sun Jul 18 18:03:35 2004 
##

NAME 		=	AFirstChaos_`uname -s`

EXECUTABLE 	=	AFirstChaos

VPATH		=	Network:STD:Menu

STD		=	std.cpp send_error_trap.cpp fget_next_line.cpp

NET_ENGINE	=	old.cpp init_msg.cpp init_connection.cpp init_client.cpp\
			check_select.cpp check_sockets.cpp close_connection.cpp\
			new_client.cpp recv.cpp send.cpp list.cpp loss_client.cpp\
			move_last_player.cpp msg_wait.cpp free_net.cpp wait_engine.cpp

SRC		=	main.cpp game.cpp run_game.cpp init.cpp	get_db_info.cpp\
			draw_game.cpp tag_action.cpp\
			$(STD) $(NET_ENGINE)

OBJ		=	$(SRC:.cpp=.o)

CXX 		=	g++

CXXFLAGS	=	-I../../include -I../../include/sdl/ -I../../lib/sdlgfx/\
			-I../../lib/sdlGL/\
			`sdl-config --cflags` -g3

LIB		= 	-L../../lib/ -L/usr/lib/ -L/usr/local/lib/ -ltinyxml_`uname -s` \
			`sdl-config --libs` -lSDL -lSDL_net -lSDL_image -lSDL_ttf #-lefence

CP		=	/bin/cp -f
RM		=	/bin/rm -rf
LN		=	/bin/ln -sf

$(NAME)	:	links $(OBJ)
		$(CXX) -o $(NAME) $(OBJ)  $(LIB) $(CFLAGS)
		$(CP) $(NAME) ../
		cd .. && $(LN) $(NAME) $(EXECUTABLE)

all	:	$(NAME)

links	:
		ln -sf ../../src/STD
		ln -sf ../../src/Network

clean	:
		$(RM) $(OBJ) *~ *.o

fclean	:	clean
		$(RM) $(NAME) ../$(NAME) ../$(EXECUTABLE)

re	:	fclean links all
