##
## Makefile for freewar in /u/ept2/huot_j
## 
## Made by jonathan huot
## Login   <huot_j@epita.fr>
## 
## Started on  Tue May 11 15:14:34 2004 jonathan huot
## Last update Thu May 13 09:49:11 2004 jonathan ribas
##

NAME	=	mapeditor

VPATH	=	src:src/STD

STD	=	std.cpp

SRCS	=	main.cpp display.cpp free_menu.cpp freewar.cpp\
		game.cpp game_key.cpp game_mouse.cpp\
		game_verif_pos.cpp\
		init_sdl.cpp load_bmp.cpp load_game.cpp\
		load_map.cpp load_menu.cpp menu.cpp\
		menu_func.cpp menu_key.cpp menu_mouse.cpp\
		open_window.cpp preload_menu.cpp\
		quit.cpp resize_window.cpp show_gamespace.cpp\
		update_gamespace.cpp update_menu.cpp xstd.cpp\
		get_surf.cpp save_map.cpp init_map.cpp\
		$(STD)

OBJS	=	$(SRCS:.cpp=.o)

CXXFLAGS=	-Wall -O3 `sdl-config --cflags`\
		-Iinclude/

LIB	=	`sdl-config --libs` -lSDL -lSDL_image

CXX	=	g++
RM	=	rm -f

$(NAME)	:	$(OBJS)
		$(CXX) -o $(NAME) $(OBJS) $(LIB)
all	:	$(NAME)

clean	:	
		$(RM) $(OBJS) *~
fclean	:	clean
		$(RM) $(NAME)
re	:	fclean all

