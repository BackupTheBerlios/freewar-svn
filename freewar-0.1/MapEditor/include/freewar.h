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
