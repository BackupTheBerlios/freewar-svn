#ifndef _TAG_PROTOTYPES_H_
#define _TAG_PROTOTYPES_H_
int	manage_selection(t_engine *e, t_trame *t, int player);

/* req_info_scale.cpp */
int		req_info_scale(t_engine *e, t_trame *trame, int player);

/* req_select_move.cpp */
int		req_select_move(t_engine *e, t_trame *t, int player);

/* req_select_attack.cpp */
int		req_select_attack(t_engine *e, t_trame *t, int src);

/* req_select_create.cpp */
int		req_select_create_units(t_engine *e, t_trame *t, int src);
int		req_select_create_building(t_engine *e, t_trame *t, int src);

#endif
