##
## Makefile for 1 in /u/ept2/petitc_s/freewar/A_First_Chaos
## 
## Made by stephane petitcolas
## Login   <petitc_s@epita.fr>
## 
## Started on  Sun May  2 19:03:21 2004 stephane petitcolas
## Last update Wed Jun  9 10:33:41 2004 stephane petitcolas
##

NAME		= 	create_sprite

CXX		= 	g++

SRC		=	create_sprite.cpp xfunc.cpp
OBJ		= 	$(SRC:.cpp=.o)

LIB		= 	-L./lib\
			`sdl-config --libs` -lSDL -lSDL_net -lSDL_ttf\
			-lSDL_image
CXXFLAGS	= 	-I./include `sdl-config --cflags`
RM		= 	/bin/rm -rf

$(NAME)	: $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LIB)

all	: $(NAME)

clean	:
	$(RM) $(OBJ) \#*\# *~

fclean	: clean
	$(RM) $(NAME)

re	: fclean all
