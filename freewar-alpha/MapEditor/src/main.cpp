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
