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
** xml.h for freewar in /u/ept2/huot_j
** 
** Made by jonathan huot
** Login   <huot_j@epita.fr>
** 
** Started on  Sat May 15 20:32:29 2004 jonathan huot
** Last update Sun May 16 18:00:04 2004 jonathan huot
*/

#ifndef _XML_H_
#define _XML_H_

double		xml_getfloat(char *str);
char		*xml_getstr(char *str);
int			xml_next(char *str);
void		xml_out();
int			xml_getint(char *str);
int			xml_init(char *db);

#endif
