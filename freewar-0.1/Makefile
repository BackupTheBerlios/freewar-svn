##
## Makefile for freewar in /u/ept2/ribas_j/freewar/src
## 
## Made by jonathan ribas
## Login   <ribas_j@epita.fr>
## 
## Started on  Sat May  1 13:50:44 2004 jonathan ribas
## Last update Sun May 16 14:15:29 2004 jonathan huot
##

#DEBUG 	= 	1

##
# PATHS
##

DATE	=	`date "+%G%m%d"`

SRC_PATH=	src

LIB_PATH=	lib

LIB_XML_PATH=	$(LIB_PATH)/tinyxml

LIB_MD5_PATH=	$(LIB_PATH)/md5

LIB_SDL_PATH=	$(LIB_PATH)/sdl

MAP_EDT_PATH=	MapEditor

RM	=	/bin/rm -rf

##
# RULES
##

srcfw	:	libs
		@cd $(SRC_PATH) && make

clean	:
		@cd $(SRC_PATH) && make clean

fclean	:
		@cd $(SRC_PATH) && make fclean

libsdl	:
#		@cd $(LIB_SDL_PATH) && make

libxml	:
		@cd $(LIB_XML_PATH) && make

libmd5	:
#		@cd $(LIB_MD5_PATH) && make

libs	:	libsdl libmd5 libxml

freewar :	srcfw

re	:	fclean freewar

engine	:	freewar


all	:	libs freewar

allclean:
# 		@cd $(LIB_SDL_PATH) && make clean
		@cd $(LIB_XML_PATH) && make clean
# 		@cd $(LIB_MD5_PATH) && make clean
		@cd $(SRC_PATH) && make clean


allfclean:
		@echo "cleaning win32"
		$(RM) win32/Freewar/Debug
		$(RM) win32/$(MAP_EDT_PATH)/Debug
		@echo "cleaning libsdl.."
# 		@cd $(LIB_SDL_PATH) && make fclean
		@echo "cleaning libxml.."
		@cd $(LIB_XML_PATH) && make fclean
		@echo "cleaning libmd5.."
# 		@cd $(LIB_MD5_PATH) && make fclean
		@echo "cleaning engine.."
		@cd $(SRC_PATH) && make fclean
		@echo "cleaning game.."

reall	:	allfclean all

tarball:	allfclean
		@cd .. && tar -cvzf Freewar.`uname -s`.$(DATE).tgz Freewar/

backup	:	allfclean
		tar -cvzf backup_`uname -s`_$(USER)_$(DATE).tar.gz \
		$(LIB_PATH) $(SRC_PATH) \
		$(MAP_EDT_PATH) include/ Makefile doc/ \
		freewar.xml
		runsocks scp backup_`uname -s`_$(USER)_$(DATE).tar.gz \
		freewar@sh.freewar.net:backup/backup_`uname -s`_$(USER)_$(DATE).tar.gz
