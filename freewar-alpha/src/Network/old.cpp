#include "network.h"

int			is_valid_trame(t_trame *t, short tag)
{
  if (tag != t->tag)
    return (0);
  return (1);
}

void			send_trame(t_client *clt, t_trame *tlv)
{
/*   t_ctrame		*crypt; */

/*   crypt = pack(tlv); */
  if (!stock_msg(clt, tlv->tag, tlv->len, tlv->msg))
    {
      printf("send_trame failed (socket closed?)\n");
      return;
    }
}

int			recv_trame(t_client *client, t_trame *trame)
{
  if (check_select(0) && exec_msg(client, trame))
    return (1);
  return (0);
}

int			receive_one_request(t_trame *req)
{
  unsigned short	i;

  while (42)
    {
      if (check_select((Uint32)-1))
	for (i = 0; cnt->clients[i].sock; i++)
	  if (recv_trame(&(cnt->clients[i]), req))
	    return (1);
    }
  // ne devrait pas en arriver jusque la:
  return (0);
}

int			recv_client_req(t_client *client, t_trame *req)
{
  while (42)
    if (check_select((Uint32)-1) && recv_trame(client, req))
      return (1);
  // ne devrait pas en arriver jusque la:
  return (0);
}
