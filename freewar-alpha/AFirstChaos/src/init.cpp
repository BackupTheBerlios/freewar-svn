//
// init.cpp for freewar in /u/ept2/skondr_m
// 
// Made by mael skondras
// Login   <skondr_m@epita.fr>
// 
// Started on  Tue May 11 18:22:22 2004 mael skondras
// Last update Tue Jun 29 18:49:59 2004 jonathan huot
//

#include "freewar.h"

// int	init_sdl()
// {
//   char	err_msg[BUF_SIZE];

//   if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
//     {
//       strcpy(err_msg, "Error: Couldn't initialize SDL: \n");
//       strcat(err_msg, SDL_GetError());
//       send_error_trap(err_msg, 1);
//       return (1);
//     }
//   atexit(SDL_Quit);
//   return (0);
// }

// int	init_3d_menu(t_display *win)
// {
//   char	err_msg[BUF_SIZE];

//   win->sdlVideoInfo = (SDL_VideoInfo*)SDL_GetVideoInfo();
//   fprintf(fd_log, "%s: Checking mode 800x600@16bpp...", NAME);
//   win->bpp=SDL_VideoModeOK(800, 600, 16, SDL_HWSURFACE);
//   if(!(win->bpp))
//     {
//       fprintf(fd_log, "Mode not available.\n");
//       return (1);
//     }
//   else
//     {
//       win->sdlMainScreen =
// 	SDL_SetVideoMode(800, 600,
// 			 win->sdlVideoInfo->vfmt->BitsPerPixel,
// 			 SDL_HWSURFACE | SDL_DOUBLEBUF
// 			 /*| SDL_FULLSCREEN*/);
//       fprintf(fd_log, "Mode OK\n");
//     }
//   return (0);
// }

int	init_game(t_game_goodies *nfo)
{
  //fprintf(fd_log, "%s: Initializing SDL...", NAME);
  //if (init_sdl())
  //  return (1);
  //fprintf(fd_log, "done.\n");
  fprintf(fd_log, "%s: Initializing network engine...\n", NAME);
  if (init_connection("127.0.0.1", NET_GAME_PORT))
    return (1);
  fprintf(fd_log, "%s: Network engine started.\n", NAME);
  //fprintf(fd_log, "%s: Initializing 3D engine...\n", NAME);
  //if (init_3d_menu(nfo->win))
  //  return (1);
  //fprintf(fd_log, "%s: 3D engine started.\n", NAME);
  fprintf(fd_log, "%s: Waiting for database info from engine...", NAME);
  if (get_db_info(nfo))
    {
      fprintf(fd_log, "timed out!\n");
      return(1);
    }
  else
    fprintf(fd_log, "done.\n");
  return (0);
}
