#include "freewar.h"

extern t_type_tag	gl_type_tag[NB_TAG];

int		manage_transmit(t_engine *e)
{
  int		i;
  t_trame	req;

  while (exec_msg(&cnt->clients[0], &req))
    {
      if (req.tag != 23)
	printf("got client trame %d\n", req.tag);
      for (i = 0; i < NB_TAG; i++)
	if (gl_type_tag[i].tag == req.tag)
	  {
	    if (gl_type_tag[i].local == false)
	      stock_msg(&cnt->clients[1], req.tag, req.len, req.msg);
	    else if (gl_type_tag[i].f && gl_type_tag[i].f(e, &req, 0))
	      {
		printf("requete %d failed\n", req.tag);
		return (1);
	      }
	    break;
	  }
    }
  while (exec_msg(&cnt->clients[1], &req))
    {
      printf("got server trame %d\n", req.tag);
      for (i = 0; i < NB_TAG; i++)
	if (gl_type_tag[i].tag == req.tag)
	  {
	    if (gl_type_tag[i].local == false)
	      stock_msg(&cnt->clients[0], req.tag, req.len, req.msg);
	    else if (gl_type_tag[i].f && gl_type_tag[i].f(e, &req, -1))
	      {
		printf("requete for myself failed\n", req.tag);
		return (1);
	      }
	    break;
	  }
    }
  return (0);
}

int	engine_client(t_engine *e, t_cfg *cfg, t_game_param *game_param)
{
	t_trame	pof;
	int		out;
//   get_and_init_display(cfg);
//   get_and_init_sound(cfg);
  stock_msg(&(cnt->clients[1]), TAG_PLAYERS_READY, 0, NULL);
  out = 0;
  while (!out)
    {
      if (!cnt->clients[1].sock ||
	  !cnt->clients[0].sock)
	    return (1);
      if (check_select(100))
	  {
		  while (exec_msg(&cnt->clients[1], &pof))
		  {
			if (is_valid_trame(&pof, TAG_PLAYERS_READY))
			{
				out = 1;
				break;
			}
			fprintf(fd_log, "gfpefe %d\n", pof.tag);
		  }
	  }
	}
  while (12)
    {
      if (!cnt->clients[1].sock ||
	  !cnt->clients[0].sock)
	break;
      reset_timer(e);
      fflush(fd_log);
      fflush(stdout);
      if (check_select(100))
	if (manage_transmit(e))
	  return (1);
      if (timer_wait(e))
	{
	  if (get_events(e))
	    return (1);
#ifdef GRAPHICS_TIME
	  Uint32 ticks=SDL_GetTicks();
#endif
	  aff_game(e, &e->g);
#ifdef GRAPHICS_TIME
	  put_error("aff_game\n---------\n");
#endif
	  play_sound();
	}
    }
  fprintf(fd_log, "Client or server is no more..\n");
  fflush(fd_log);
  return (0);
}
