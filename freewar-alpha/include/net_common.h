#ifndef _NET_COMMON_H_
#define _NET_COMMON_H_

#define NET_MAX_MSG		(1024)
#define NET_MSS			(1460)

#define STATE_NEW		(0)
#define STATE_DEAD		(1)
#define STATE_DROP		(2)
#define STATE_FAIL_RECV		(3)
#define STATE_PLAYER	(4)

typedef struct		s_trame
{
  short			tag;
  unsigned int		len;
  char			*msg;
  unsigned int		pos;
}			t_trame;

typedef struct		s_ctrame
{
/* options de cryptage... */
/*   unsigned char		tag; */
/*   unsigned long		sign; */
/*   unsigned long		md5; */
  t_trame		trame;
}			t_ctrame;

typedef struct		s_client
{
  unsigned int		pos_recv;
  unsigned int		pos_exec;
  unsigned int		pos_send;
  unsigned int		pos_stock;
  t_trame		recv[NET_MAX_MSG];
  t_trame		send[NET_MAX_MSG];
  TCPsocket		sock;
  unsigned long		loss;
}			t_client;

typedef struct		s_tmp
{
  int			state;
  t_client		c;
  struct s_tmp		*next;
}			t_tmp;

extern struct s_connections	*cnt;

/*
** recv.c
*/
int		my_recv(TCPsocket sock, void *data, int maxlen);
Uint32		get_msg(struct s_client *client);
int		exec_msg(struct s_client *client, struct s_trame *t);

/*
** send.c
*/
int		my_send(TCPsocket sock, void *datap, int len);
int		put_msg(struct s_client *client);
int		stock_msg(struct s_client *client, short tag,
			  unsigned int len, void *msg);
/*
** extern
*/
void		*xmalloc(size_t len);
void		*xrealloc(void *ptr, size_t len);

/*
** list.c
*/
void		free_list_client(struct s_tmp *newtmp);
void		put_in_tmp_client(struct s_tmp **begin, struct s_client *c);
struct s_tmp	*del_in_list(struct s_tmp *newtmp, struct s_client *c);
void		put_in_client(struct s_tmp **begin, TCPsocket sock, int state);

/*
** check_sockets.c
*/
int		check_tmp(struct s_tmp **newtmp, fd_set *maskr,
			  fd_set *maskw, int *res);
int		manage_client(struct s_client **client, fd_set *maskr,
			      fd_set *maskw, int *res);
int		check_clients(fd_set *maskr, fd_set *maskw, int *res);
int		check_server(fd_set *maskr, fd_set *maskw, int *res);

/*
** old.c
*/
int			is_valid_trame(t_trame *t, short tag);
void			send_trame(t_client *clt, t_trame *tlv);
int			recv_trame(t_client *client, t_trame *trame);
int			receive_one_request(t_trame *req);
int			recv_client_req(t_client *client, t_trame *req);
/*
** solo
*/
int		msg_wait(struct s_client *client);
void		move_last_player(int no);
int		loss_client(struct s_client *c);
void		free_client(struct s_client *c);
int		check_select(Uint32 timeout);
void		init_msg(struct s_trame *msg);
void		init_client(struct s_client *client);
int		init_connection(int port);
int		init_connection(char *ip, int port);
void		close_connection();
void		add_client();
int		new_client(struct s_tmp **newtmp);
void		drop_client(struct s_client *clt);
#endif
