/*
** afirstchaos.h for freewar in /u/ept2/huot_j/Freewar/src
** 
** Made by jonathan huot
** Login   <huot_j@epita.fr>
** 
** Started on  Mon May 10 19:39:18 2004 jonathan huot
** Last update Sat Jul  3 19:06:06 2004 stephane petitcolas
*/

#ifndef _AFIRSTCHAOS_H_
#define _AFIRSTCHAOS_H_

/* AFirstChaos */

#include "menu.h"

#define NAME	("AFirstChaos")
#define PLAY_FPS	(SEC_IN_MS / 30)
#define MAX_SAVE_EVENTS (5)

typedef struct		s_game_goodies
{
  t_menu_entry		*menus;
  t_menu_headers	*menu_headers;
  t_db_info		*db_info;
  t_event		*events;
}			t_game_goodies;

/*tag_action.cpp*/
int		get_pos(int xfin, int yfin, t_coord *actual_pos,
			t_coord *actual_off, t_cfg cfg);
char		*is_action(SDLKey key);
/* game.cpp */
int		afirstchaos();

/* run_game.cpp */
int		run_game(t_game_goodies *nfo);

/* draw_game.cpp */
int		draw_game(t_game_goodies *nfo);

/* init.cpp */
int		init_game(t_game_goodies *nfo);

/* send_error_trap */
int		send_error_trap(char *str, int lethal);

/* demo.cpp */
int		demo(t_display *win);

int		get_db_info(t_game_goodies *nfo);
int		wait_engine(char *app);
#endif
