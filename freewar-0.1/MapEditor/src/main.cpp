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
//
// main.cpp for freewar in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Tue May 11 15:28:16 2004 jonathan huot
// Last update Tue May 11 17:34:02 2004 jonathan huot
//

#include "freewar.h"

#ifdef WIN32
#include "stdafx.h"
int _tmain(int argc, _TCHAR* argv[])
{
	freewar(0, NULL);
	return 0;
}

#else

int	main(int ac, char **av)
{
  if (freewar(ac - 1, av + 1))
    return (-1);
  return (0);
}
#endif
