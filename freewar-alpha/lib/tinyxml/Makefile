#****************************************************************************
#
# Makefile for TinyXml test.
# Lee Thomason
# www.grinninglizard.com
#
# This is a GNU make (gmake) makefile // modified by freewar team
#****************************************************************************

DEBUG_CFLAG=	-Wall -Wno-unknown-pragmas -Wno-format -g -DDEBUG
RELEASE_CFLAGS=	-Wall -Wno-unknown-pragmas -Wno-format -O3


#****************************************************************************
# Targets of the build
#****************************************************************************

NAME	=	libtinyxml_`uname -s`.a

NAME_TEST=	test_`uname -s`

#****************************************************************************
# Source files
#****************************************************************************

SRC	=	tinyxml.cpp tinyxmlparser.cpp tinyxmlerror.cpp tinystr.cpp

SRC_TEST=	xmltest.cpp

OBJ	=	$(SRC:.cpp=.o)

OBJ_TEST=	$(SRC_TEST:.cpp=.o)

CXXFLAGS=	-g3

CXX	=	g++
RM	=	rm -f
CP	=	cp -f
LN	=	ln -sf

#****************************************************************************
# Output
#****************************************************************************

$(NAME)	:	$(OBJ)
		ar r $(NAME) $(OBJ)
		ranlib $(NAME)
		$(CP) $(NAME) ../
		$(CP) tinystr.h ../../include/
		$(CP) tinyxml.h ../../include/

all	:	$(NAME)

clean	:
		$(RM) $(OBJ) $(OBJ_TEST) *~

test	:	$(OBJ) $(OBJ_TEST)
		$(CC) -o $(NAME_TEST) $(OBJ) $(OBJ_TEST)
		make clean

fclean	:	clean
		$(RM) $(NAME) $(NAME_TEST)

re	:	fclean all
