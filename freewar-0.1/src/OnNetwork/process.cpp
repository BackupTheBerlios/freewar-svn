#include "freewar.h"

void		process_newclient(t_client *client,
				  const t_trame *trame,
				  void *data)
{
  t_engine	*e = (t_engine*)data;

  // TODO: mettre init_players_for_game ici (et l'ameliorer)

  // TODO: remplir le champ client->data, pour que les fonctions
  // ci dessous puissent savoir quel joueur est le client recu.
}

void		process_clients(t_client *client,
				const t_trame *trame,
				void *data)
{
  t_engine	*e;
  int		player = 0;

  // TODO: transformer le client->data en 'player' (numero du player)

  e = (t_engine *)data;
  if (trame->tag != 24 && trame->tag != 23)
    {
      fprintf(fd_log, "process_clients: got trame %d (%d len)\n",
	      trame->tag, trame->len);
      fprintf(stderr, "process_cliens: got trame %d (%d len)\n",
	      trame->tag, trame->len);
    }
  if (is_valid_trame((t_trame*)trame, TAG_EXECUTION))
    ;
  else if (is_valid_trame((t_trame*)trame, TAG_INFO_SCALE))
    req_info_scale(e, (t_trame*)trame, player);
  else if (is_valid_trame((t_trame*)trame, TAG_SELECT_MOVE))
    req_select_move(e, (t_trame*)trame, player);
  else if (is_valid_trame((t_trame*)trame, TAG_SELECT_ATTACK))
    req_select_attack(e, (t_trame*)trame, player);
  else if (is_valid_trame((t_trame*)trame, TAG_SELECT_CREATE_UNITS))
    req_select_create_units(e, (t_trame*)trame, player);
  else if (is_valid_trame((t_trame*)trame, TAG_SELECT_CREATE_BUILDING))
    req_select_create_building(e, (t_trame*)trame, player);
  else
    fprintf(fd_log, "manage_request: got trame unused %d\n", trame->tag);
  if (trame->msg)
    free(trame->msg);
  fflush(fd_log);
  fflush(stderr);
}

void		process_deadclient(t_client *client,
				   const t_trame *trame,
				   void *data)
{

}
