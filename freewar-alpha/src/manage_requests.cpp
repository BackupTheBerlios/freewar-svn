//
// manage_requests.cpp for freewar in /u/ept2/huot_j
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Tue Jun 15 13:04:36 2004 jonathan huot
// Last update Mon Jul 12 16:53:39 2004 
//

#include "freewar.h"

int			manage_requests(t_engine *e)
{
  t_trame		trame;
  int			t;

  for (t = 0; t < e->nb_players; t++)
    while (exec_msg(&(cnt->clients[e->assos_clients[t]]), &trame))
      {
	if (trame.tag != 24 && trame.tag != 23)
	  {
	    fprintf(fd_log, "manage_request: got trame %d (%d len)\n",
		    trame.tag, trame.len);
	    fprintf(stderr, "manage_request: got trame %d (%d len)\n",
		    trame.tag, trame.len);
	  }
	if (is_valid_trame(&trame, TAG_EDIT_ARENA_SURFACE))
	  req_edit_arena_surface(e, &trame, t);
	else if (is_valid_trame(&trame, TAG_EVENT_OK))
	  req_event_ok(e, &trame, t);
	else if (is_valid_trame(&trame, TAG_EXECUTION))
	  ;
	else if (is_valid_trame(&trame, TAG_INFO_SCALE))
	  req_info_scale(e, &trame, t);
	else if (is_valid_trame(&trame, TAG_SELECT_MOVE))
	  req_select_move(e, &trame, t);
	else if (is_valid_trame(&trame, TAG_SELECT_ATTACK))
	  req_select_attack(e, &trame, t);
	else if (is_valid_trame(&trame, TAG_SELECT_CREATE_UNITS))
	  req_select_create_units(e, &trame, t);
	else if (is_valid_trame(&trame, TAG_SELECT_CREATE_BUILDING))
	  req_select_create_building(e, &trame, t);
	else if (is_valid_trame(&trame, TAG_SELECT))
	  {
	    puts("SELECT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	    manage_selection(e, &trame, t);
	  }
	else
	  fprintf(fd_log, "manage_request: got trame unused %d\n", trame.tag);
	if (trame.msg)
	  free(trame.msg);
	fflush(fd_log);
	fflush(stderr);
      }
  return (0);
}
