// Copyright (C) 2004 Freewar Team <doomsday@freewar.net>

// This file is part of Freewar.

// Freewar is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.

// Freewar is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with Freewar; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
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

#include "libstdtool.h"
#include "libnettool.h"

/* #define FW_DEBUG */
/* #define PATHFIND_DEBUG */

#include "log.h"
#include "std.h"
/* #include "network.h" */
#include "graphics.h"
#include "engine.h"
#include "pathfinding.h"
#include "actionsbind.h"

#endif
