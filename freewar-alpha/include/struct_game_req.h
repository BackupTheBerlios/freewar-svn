/*
** struct_game_req.h for reewar in /goinfre/Freewar/AFirstChaos/src
** 
** Made by stephane petitcolas
** Login   <petitc_s@epita.fr>
** 
** Started on  Fri Jul  2 15:41:23 2004 stephane petitcolas
** Last update Sat Jul  3 21:43:05 2004 stephane petitcolas
*/

typedef	struct	s_id_req
{
  int		select;
  int		info_scale;
  int		attac;
}		t_id_req;

typedef	struct	s_game_info_scale
{
  int		id_req;
  t_coord	pos;
  t_coord	off;
}		t_game_info_scale;

typedef	struct	s_game_select
{
  int		id_req;
  unsigned long	*entitys;
}		t_game_select;

typedef	struct	s_game_select_move
{
  int		id_req;
  t_coord	pos;
  t_coord	off;
}		t_game_select_move;

typedef	struct	s_game_select_attack
{
  int			id_req;
  unsigned long int	id_attacked;
}		t_game_select_attack;

typedef	struct	s_game_select_create_building
{
  int		id_req;
  t_coord	pos;
  char		name[NAME_SIZE];
}		t_game_select_create_building;

typedef	struct	s_game_select_create_units
{
  int		id_req;
  char		nb_units;
  char		name[NAME_SIZE];
}		t_game_select_create_units;
