/*
** struct_req.h for freewar in /root/Freewar/include
** 
** Made by 
** Login   <root@epita.fr>
** 
** Started on  Wed Jun 30 15:39:54 2004 
** Last update Sat Jul  3 11:53:43 2004 
*/

typedef struct		s_info_scale
{
  unsigned char		action;
  int			app;
  int			id;
  char			name[NAME_SIZE];
}			t_info_scale;

typedef struct		s_req_info_scale
{
  int			id_req;
  char			nb_ent; // -1 si erreur
  t_info_scale		ent[MAX_ENTITY_ON_SCALE];
}			t_req_info_scale;

/* sachant que ent[MAX_ENTITY_ON_SCALE] ne sera pas  */
/* rempli a fond suivant le nombre d'entitee qu'on va recevoir */

typedef struct		s_req_select_move
{
  int			id_req;
  int			id_action; // -1 si erreur
}			t_req_select_move;

typedef struct		s_req_select_attack
{
  int			id_req;
  int			id_action; // -1 si erreur
}			t_req_select_attack;
//je sais, c'est les memes hehe

typedef struct		s_req_select_create_units
{
  int			id_req;
  int			id_action; // -1 si erreur
}			t_req_select_create_units;

typedef struct		s_req_select_create_building
{
  int			id_req;
  int			id_action; // -1 si erreur
}			t_req_select_create_building;
