#ifndef _STRUCT_H_
#define _STRUCT_H_

/*
** t_args est la struct de communication
** vers le moteur
*/
typedef struct			s_args
{
  int				cmd;
  int				size;
  char				data[BUF_LEN];
}				t_args;

/*
** seront stoqués ici les données en rapport
** avec SDL
*/
struct				s_sdl
{
  SDL_Surface			*screen;
  SDL_Event			event;
  int				video_flags;
  Uint32			rmask;
  Uint32			gmask;
  Uint32			bmask;
  Uint32			amask;
}				;

/*
** menu:
*/
struct				s_menu
{
  int				x;
  int				y;
  int				h;
  int				w;
  char				*img_name[NB_IMG_MENU];
  int				(*select)(struct s_info *info);
  SDL_Surface			*img[NB_IMG_MENU];
}				;

typedef struct		s_coord
{
  unsigned short	x;
  unsigned short	y;  
}			t_coord;

/*
** datamap
*/
typedef struct		s_map_data_scale
{
  unsigned int		land;
  unsigned int		item;
}			t_map_data_scale;

typedef struct		s_map_data
{
  unsigned short	w;
  unsigned short	h;
  unsigned short	nb_players;
  t_coord		*start_point;
  t_map_data_scale	**data;
}			t_map_data;

/*
** les informations de la partie:
*/
struct				s_game
{
  SDL_Surface			*gamespace;
  int				pos_x;
  int				pos_y;
  int				keyup;
  int				keydown;
  int				keyleft;
  int				keyright;
  int				keyshift;
  int				mousehoriz;
  int				mouseverti;
  int				exit;
}				;

/*
** toutes les informations véhiculent ici
*/
struct				s_info
{
  int				exit;
  int				menu_over;
  struct s_menu			menu[NB_MENU];
  struct s_sdl			mysdl;
  struct s_game			game;
  char				*file;
  unsigned short		width;
  unsigned short		height;
  t_map_data			data;
  SDL_Surface			*img[NB_ITEMS];
  unsigned int			selection;
}				;

/*
** items pour la key
*/
typedef struct			s_items
{
  unsigned int			id;
  char				*path;
  bool				land;
  SDLKey			key;
}				t_items;
#endif
