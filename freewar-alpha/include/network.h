/*
** network.h for zappy in /u/ept2/huot_j/zappy
** 
** Made by jonathan huot
** Login   <huot_j@epita.fr>
** 
** Started on  Mon May 24 16:02:20 2004 jonathan huot
** Last update Sat Jul  3 17:49:07 2004 
*/

#ifndef _NETWORK_H_
#define _NETWORK_H_

#include <signal.h>

#ifndef _FREEWAR_H_
#include "SDL.h"
#include "SDLnetsys.h"
#include "SDL_net.h"
#endif
extern FILE *fd_log;

#include "net_common.h"

/* #ifdef __Cplusplus */
/* #pragma pack */
/* #endif */

#ifdef NETWORK_DEBUG
#define NETDEBUG(x) (put_error(x))
#else
#define NETDEBUG(x)
#endif

#define NET_GAME_PORT		(5119)
#define NET_DROP_TIME_CLT	(123456)
#define NET_DROP_TIME		(123456789)

#ifdef MACOS_OPENTRANSPORT
#include <Events.h>
#include <Threads.h>
#include <OpenTransport.h>
#include <OpenTptInternet.h>
#include <OTDebug.h>

struct _TCPsocket {
	int ready;
	SOCKET channel;

	// These are taken from GUSI interface.
	// I'm not sure if it's really necessary here yet
	// ( masahiro minami<elsur@aaa.letter.co.jp> )
	// ( 01/02/19 )
	OTEventCode curEvent;
	OTEventCode newEvent;
	OTEventCode event;
	OTEventCode curCompletion;
	OTEventCode newCompletion;
	OTEventCode completion;
	OSStatus	error;
	TEndpointInfo info;
	Boolean		readShutdown;
	Boolean		writeShutdown;
	Boolean		connected;
	OTConfigurationRef	config;		// Master configuration. you can clone this.
	TCPsocket	nextListener;
	// ( end of new members --- masahiro minami<elsur@aaa.letter.co.jp>
	
	IPaddress remoteAddress;
	IPaddress localAddress;
	int sflag;
	
	// Maybe we don't need this---- it's from original SDL_net
	// (masahiro minami<elsur@aaa.letter.co.jp>)
	// ( 01/02/20 )
	int rcvdPassConn;
};
#else
struct _TCPsocket {
	int ready;
	SOCKET channel;
	IPaddress remoteAddress;
	IPaddress localAddress;
	int sflag;
};
#endif

#define TAG_RECV(x) (x->recv[x->pos_recv].tag)
#define LEN_RECV(x) (x->recv[x->pos_recv].len)
#define MSG_RECV(x) (x->recv[x->pos_recv].msg)
#define POS_RECV(x) (x->recv[x->pos_recv].pos)
#define CHAR_RECV(x) (x->recv[x->pos_recv].msg[x->recv[x->pos_recv].pos])
#define STAG_RECV(x) (x.recv[x.pos_recv].tag)
#define SLEN_RECV(x) (x.recv[x.pos_recv].len)
#define SMSG_RECV(x) (x.recv[x.pos_recv].msg)
#define SPOS_RECV(x) (x.recv[x.pos_recv].pos)
#define SCHAR_RECV(x) (x.recv[x.pos_recv].msg[x.recv[x.pos_recv].pos])

#define TAG_SEND(x) (x->send[x->pos_send].tag)
#define LEN_SEND(x) (x->send[x->pos_send].len)
#define MSG_SEND(x) (x->send[x->pos_send].msg)
#define POS_SEND(x) (x->send[x->pos_send].pos)
#define CHAR_SEND(x) (x->send[x->pos_send].msg[x->send.pos])
#define STAG_SEND(x) (x.send[x.pos_send].tag)
#define SLEN_SEND(x) (x.send[x.pos_send].len)
#define SMSG_SEND(x) (x.send[x.pos_send].msg + x.send.pos)
#define SPOS_SEND(x) (x.send[x.pos_send].pos)
#define SCHAR_SEND(x) (x.send[x.pos_send].msg[x.send.pos])

#define TAG_EXEC(x) (x->recv[x->pos_exec].tag)
#define LEN_EXEC(x) (x->recv[x->pos_exec].len)
#define MSG_EXEC(x) (x->recv[x->pos_exec].msg)
#define POS_EXEC(x) (x->recv[x->pos_exec].pos)
#define CHAR_EXEC(x) (x->recv[x->pos_exec].msg[0])
#define STAG_EXEC(x) (x.recv[x.pos_exec].tag)
#define SLEN_EXEC(x) (x.recv[x.pos_exec].len)
#define SMSG_EXEC(x) (x.recv[x.pos_exec].msg)
#define SPOS_EXEC(x) (x.recv[x.pos_exec].pos)
#define SCHAR_EXEC(x) (x.recv[x.pos_exec].msg[0])

#define TAG_STOCK(x) (x->send[x->pos_stock].tag)
#define LEN_STOCK(x) (x->send[x->pos_stock].len)
#define MSG_STOCK(x) (x->send[x->pos_stock].msg)
#define POS_STOCK(x) (x->send[x->pos_stock].pos)
#define CHAR_STOCK(x) (x->send[x->pos_stock].msg[0])
#define STAG_STOCK(x) (x.send[x.pos_stock].tag)
#define SLEN_STOCK(x) (x.send[x.pos_stock].len)
#define SMSG_STOCK(x) (x.send[x.pos_stock].msg)
#define SPOS_STOCK(x) (x.send[x.pos_stock].pos)
#define SCHAR_STOCK(x) (x.send[x.pos_stock].msg[0])

typedef struct		s_connections
{
  struct s_tmp		*newclient;
  struct s_tmp		*deadclient;
  struct s_client	*clients;
  struct s_client	server;
  IPaddress		ip;
  char			*host;
  struct s_client	*last_recv; // pour la compabilit�
}			t_connections;

#endif
