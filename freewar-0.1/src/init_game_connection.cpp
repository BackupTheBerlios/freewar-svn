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
// init_game_connection.cpp for freewar in /u/ept2/ribas_j/freewar
// 
// Made by jonathan ribas
// Login   <ribas_j@epita.fr>
// 
// Started on  Mon May  3 14:20:48 2004 jonathan ribas
// Last update Tue Jun 29 18:38:47 2004 jonathan huot
//

#include "freewar.h" 

int             init_game_connection(t_connections *cnt)
{
 //  cnt->nb_clients = 0;
//   if (SDLNet_Init() == -1)
//     {
//       printf("SDLNet_Init: %s\n", SDLNet_GetError());
//       return (1);
//     }
//   atexit(SDLNet_Quit);
//   printf("Connecting for accept game on port %d\n", NET_GAME_PORT);
//   if (SDLNet_ResolveHost(&cnt->ip, NULL, NET_GAME_PORT) == -1)
//     {
//       printf("SDLNet_ResolveHost: %s\n", SDLNet_GetError());
//       return (1);
//     }
//   cnt->host = (char*)SDLNet_ResolveIP(&cnt->ip);
//   cnt->server.sock = SDLNet_TCP_Open(&cnt->ip);
//   if (!cnt->server.sock)
//     {
//       printf("SDLNet_TCP_Open: %s\n", SDLNet_GetError());
//       return (1);
//     }
//   cnt->sset = SDLNet_AllocSocketSet(FW_MAX_CLIENTS);
//   if (!cnt->sset)
//     {
//       put_error("Not enough memory for alloc socket");
//       return (1);
//     }
//   if (SDLNet_TCP_AddSocket(cnt->sset, cnt->server.sock) < 0)
//     {
//       fprintf(fd_log, "SDLNet_TCP_AddSocket: %s\n", SDLNet_GetError());
//       return (1);
//     }
  return (0);
}
