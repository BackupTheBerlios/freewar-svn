/*
** freewar.h for freewar in /u/ept2/huot_j
** 
** Made by jonathan huot
** Login   <huot_j@epita.fr>
** 
** Started on  Tue May 11 15:27:37 2004 jonathan huot
** Last update Tue May 11 22:36:20 2004 jonathan huot
*/
#ifndef _FREEWAR_H_
#define _FREEWAR_H_

/*
** systeme
*/
#include <stdio.h>
#include <stdlib.h>

#ifdef WIN32
#include <windows.h>
#else
#include <time.h>
#include <string.h>
#include <ctype.h>
#endif
/*
** lib
*/
#include <SDL.h>
#include <SDL_image.h>
/*
** perso
*/
#include "define.h"
#include "struct.h"
#include "typedef.h"
#include "prototype.h"

#endif
