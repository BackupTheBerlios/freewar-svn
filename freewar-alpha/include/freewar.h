/*
** freewar.h for freewar in /u/ept2/ribas_j/freewar/src
** 
** Made by jonathan ribas
** Login   <ribas_j@epita.fr>
** 
** Started on  Fri Apr 30 11:08:44 2004 jonathan ribas
** Last update Sun Jul 18 17:49:28 2004 
*/

#ifndef _FREEWAR_H_
#define _FREEWAR_H_

#ifdef WIN32

#include "resource.h"
#pragma once
//#define WIN32_LEAN_AND_MEAN // casse tout
#include <windows.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <iostream>
#include <time.h>

#else

#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <errno.h>

#endif

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

#include <SDL.h>

#include "glSDL.h"
#include "SDLnetsys.h"
#include "SDL_net.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_gfxPrimitives.h"
#include "tinyxml.h"
#include "tinystr.h"

/* #define FW_DEBUG */
/* #define PATHFIND_DEBUG */

extern FILE	*fd_log;

#ifdef WIN32
#define stderr (fd_log)
#define stdout (fd_log)

#endif

#include "std.h"
#include "network.h"
#include "graphics.h"
#include "engine.h"
#include "pathfinding.h"
#include "afirstchaos.h"
#include "actionsbind.h"

#endif
