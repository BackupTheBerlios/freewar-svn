/*
** menu.h for freewar in /u/ept2/skondr_m
** 
** Made by mael skondras
** Login   <skondr_m@epita.fr>
** 
** Started on  Mon May 17 17:33:46 2004 mael skondras
<<<<<<< menu.h
** Last update Fri Jun  4 16:36:55 2004 mael skondras
=======
** Last update Mon May 24 18:31:17 2004 mael skondras
>>>>>>> 1.11
*/

/* MENU */

#define MAX_TABLE_ROWS	(42)
#define MAX_TABLE_COLS	(6)
#define DB_MENU		("AFirstChaos/menu.xml")
#define TXTBOX_WIDTH	(112)

/* FONT */

#define	FONT		("AFirstChaos/font/menu/mkst.ttf")
#define	SIZE		(22)


typedef struct		s_menu_entry
{
  char			*uid;
  char			*type;
  void			*info;
  int			focus;
  struct s_menu_entry	*submenus;
}			t_menu_entry;

typedef struct		s_menu_headers
{
  char			*name;
  t_menu_entry		*menus;
  struct s_menu_headers	*next;
}			t_menu_headers;

typedef struct		s_menu_button
{
  int			x, y;
  char			*value;
  char			*sprite;
  char			*text_font;
  char			*text_color;
  int			text_size;
}			t_menu_button;

typedef struct		s_menu_text
{
  int			x, y;
  char			*value;
  TTF_Font		*text_font;
  char			*text_color;
  int			text_size;
  char			*background;
}			t_menu_text;

typedef struct		s_menu_list
{
  int			x, y;
  char			**values;
  int			def_val;
  char			*background;
  char			*left_sprite;
  char			*right_sprite;
  char			*text_font;
  char			*text_color;
  int			text_size;
}			t_menu_list;

typedef struct		s_menu_image
{
  int			x, y;
  char			*path;
}			t_menu_image;

typedef struct		s_menu_box
{
  bool			yes;
  int			x, y;
  char			*background;
  char			*sprite;
  char			*value;
  char			*text_font;
  char			*text_color;
  int			text_size;
}			t_menu_box;

typedef struct		s_menu_table
{
  int			x, y, width, height;
  char			*title;
  int			**cols_width;
  char			cols[MAX_TABLE_COLS][BUF_SIZE];
  char			*background;
  char			rows[MAX_TABLE_ROWS][MAX_TABLE_COLS][BUF_SIZE];
  char			*text_font;
  char			*text_color;
  int			text_size;
}			t_menu_table;

typedef struct		s_return_button
{
  int			menu;
  bool			yes;
}			t_return_button;

typedef struct		s_return_text
{
  int			menu;
  char			value[BUF_SIZE];
}			t_return_text;

typedef struct		s_return_list
{
  int			menu;
  int			choice;
}			t_return_list;

typedef struct		s_return_image
{
  int			menu;
  int			x,y;
}			t_return_image;

typedef struct		s_return_box
{
  int			menu;
  bool			yes;
}			t_return_box;

typedef struct		s_return_table
{
  int			menu;
  int			row_nb;
  char			row[MAX_TABLE_COLS][BUF_SIZE];
}			t_return_table;

typedef struct		s_menu_uid
{
  char			*uidstr;
  void			*(*uidfunc)(t_menu_entry *menus, void *info);
}			t_menu_uid;

typedef struct		s_drawfunc
{
  char			*type;
  int			(*draw)(t_display *win, t_menu_entry *menu);
}			t_drawfunc;

/* run_menu.cpp */
int		run_menu(t_display *win);

/* parse_menu.cpp */
t_menu_entry	*parse_menu();
t_menu_entry	*get_submenus(TiXmlElement *elm_parent, TiXmlElement *elm_head, t_menu_headers *menu_headers);
int		call_entity_func(t_menu_entry *menus, void *ptr);

/* get_headers.cpp */
t_menu_headers	*get_headers(TiXmlElement *elm_root);
t_menu_entry	*find_header(char *name, t_menu_headers *menu_headers);

/* get_menu_entry0.cpp */
t_menu_button	*get_menu_button(TiXmlElement *elm_cur);
t_menu_text	*get_menu_text(TiXmlElement *elm_cur);
t_menu_list	*get_menu_list(TiXmlElement *elm_cur);
void		get_menu_entry(t_menu_entry *menu, TiXmlElement *elm_cur, TiXmlElement *elm_head);

/* get_menu_entry1.cpp */
t_menu_table	*get_menu_table(TiXmlElement *elm_cur);
t_menu_box	*get_menu_box(TiXmlElement *elm_cur);
t_menu_image	*get_menu_image(TiXmlElement *elm_cur);

/* uid_play.cpp */
void		*uid_map(t_menu_entry *menus, void *info);
void		*uid_map_name(t_menu_entry *menus, void *info);
void		*uid_ressources(t_menu_entry *menus, void *info);
void		*uid_servername(t_menu_entry *menus, void *info);
void		*uid_maxplayers(t_menu_entry *menus, void *info);
void		*uid_players(t_menu_entry *menus, void *info);
void		*uid_start(t_menu_entry *menus, void *info);

/* uid_general.cpp */
void		*uid_play(t_menu_entry *menus, void *info);
void		*uid_test(t_menu_entry *menus, void *info);
void		*uid_play(t_menu_entry *menus, void *info);
void		*uid_credits(t_menu_entry *menus, void *info);
void		*uid_exit(t_menu_entry *menus, void *info);
void		*uid_back(t_menu_entry *menus, void *info);
void		*uid_server_port(t_menu_entry *menus, void *info);

/* uid_preplay.cpp */
void		*uid_create_game(t_menu_entry *menus, void *info);
void		*uid_join_game(t_menu_entry *menus, void *info);
void		*uid_specify_game(t_menu_entry *menus, void *info);
void		*uid_foundservers(t_menu_entry *menus, void *info);
void		*uid_refresh(t_menu_entry *menus, void *info);

/* uid_server.cpp */
void	*uid_server_port(t_menu_entry *menus, void *info);
void	*uid_server_hostname(t_menu_entry *menus, void *info);

/*aff.cpp*/
int		fade(t_display *win, int speed);
int		launch_logo(t_display *win, int x, int y, int speed);
int		InputMouseMotionEvent(SDL_MouseButtonEvent *event, t_display *win, t_menu_entry *menu);
int		event(t_display *win, t_menu_entry *menu);
void		*launch_menu(t_display *win, t_menu_entry *menu);
int		init_menu(t_display *win);
char		*update_txtbox(char *str, SDL_KeyboardEvent *event);

/* aff_func.cpp */
int		draw_button(t_display *win, t_menu_entry *menu);
int		draw_table(t_display *win, t_menu_entry *menu);
int		draw_txtbox(t_display *win, t_menu_entry *menu);

/* aff_string.cpp */
int		draw_string(t_display *win, int x, int y, char *str, int pu);
int		aff_string(t_display *win, int x, int y, char *str);
SDL_Surface	*load_string(char *str, char *font, int size);
int		aff_surf(SDL_Surface *surf, int alpha);
