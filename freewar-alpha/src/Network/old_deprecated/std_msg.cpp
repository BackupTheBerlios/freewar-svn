//
// std_msg.cpp for freewar in /u/ept2/huot_j/freewar/engine/src/Network
// 
// Made by jonathan huot
// Login   <huot_j@epita.fr>
// 
// Started on  Tue May  4 14:49:49 2004 jonathan huot
// Last update Mon Jun 14 18:05:16 2004 mael skondras
//

#include "freewar.h"

#ifdef FW_DEBUG
int             my_put_unbr_base(int nbr, char *base)
{
  int  n;
  unsigned int  d;
  int           wrote;

  n = nbr;
  d = 1;
  wrote = 0;
  if (nbr < 0)
    {
      printf("-");
      wrote++;
      n = -nbr;
    }
  while (n / d >= strlen(base))
    d *= (unsigned int)strlen(base);
  while (d)
    {
      printf("%c", base[(n / d) % strlen(base)]);
      wrote++;
      d /= (unsigned int)strlen(base);
    }
  return (wrote);
}

int             my_putnchar_fromstr_sign(char *s, int size)
{
  int           i;
  int           wrote;

  i = 0;
  wrote = 0;
  if (s == 0)
    return (0);
  while (s[i] && i < size)
    {
      if (s[i] < 32 || s[i] >= 127)
        {
          printf("\\");
          wrote++;
          wrote += my_put_unbr_base((unsigned int)s[i], "01234567");
        }
      else
        {
          printf("%c", s[i]);
          wrote++;
        }
      i++;
    }
  return (wrote);
}
#endif

int		put_msg(TCPsocket sock, void *buf)
{
  Uint32	result;

  if (!buf)
    return (1);
  result = SDLNet_TCP_Send(sock, buf, sizeof(t_trame));
  if (result < sizeof(t_trame)) {
    if (SDLNet_GetError() && strlen(SDLNet_GetError()))
      printf("SDLNet_TCP_Send: %s\n", SDLNet_GetError());
    return (0);
  }
#ifdef FW_DEBUG
  else
    {
      printf("Debug from putMsg (%d sent from %d total):\n", result,
	     sizeof(t_trame));
      my_putnchar_fromstr_sign((char*)buf, sizeof(t_trame));
      printf("\nend\n");
    }
#endif
  return (result);
}

//Uint32		getMsg(TCPsocket sock, void **buf)
Uint32		get_msg(t_client *client, t_trame *trame)
{
  Uint32	result;
  char		c;

  result = SDLNet_TCP_Recv(client->sock, &c, sizeof(c));
  if (result == (Uint32)-1 || result < sizeof(c))
    {
      if (SDLNet_GetError() && strlen(SDLNet_GetError()))
	printf("SDLNet_TCP_Recv: %s\n", SDLNet_GetError());
      client->loss++;
      printf("loss: %d\n", client->loss);
    }
#ifdef FW_DEBUG
  else
    {
      client->msg[client->pos++] = c;
      if (client->pos == NET_BUF_SIZE)
	{
	  t_trame	*tmp;

	  client->pos = 0;
	  tmp = unpack((t_ctrame*)client->msg);
	  memcpy((void*)trame, (void*)tmp, sizeof(*tmp));
	  free(tmp);
#ifdef FW_DEBUG
	  //printf("trame->tag: %i, len: %i\n", trame->tag, trame->len);
#endif
	  return (result);
	}
      return (0);
    }
#endif
  return (0);
}
