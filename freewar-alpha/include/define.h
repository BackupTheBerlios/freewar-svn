/*
** define.h for freewar in /u/ept2/huot_j/Freewar/src
** 
** Made by jonathan huot
** Login   <huot_j@epita.fr>
** 
** Started on  Mon May 10 19:46:33 2004 jonathan huot
** Last update Wed Jul 14 18:37:13 2004 
*/

#ifndef _DEFINE_H_
#define _DEFINE_H_

#define	NONE	(0)
#define HOME	(1)
#define REMOTE  (2)
#ifndef ERROR
#define ERROR	(-1)
#endif

#define JOIN	(1)
#define CREATE  (2)

#ifndef NULL
#define NULL (0)
#endif

#define FREEWAR_CFG ("freewar.xml")

#define LOG_FILE ("debug.log")

/* TIME */
#define SEC_IN_MS (1000)
#define MIN_IN_MS (60 * SEC_IN_MS)
#define HOUR_IN_MS (60 * MIN_IN_MS)

/* FREEWAR CFG */
#define GAME		("AFisrtChaos")
#define GAME_PATH	("AFirstChaos/")
#define DB_PATH		("AFirstChaos/AFirstChaos.xml")
#define VIDEO_MODE	(32)
#define VIDEO_SIZE_WIDTH (800)
#define VIDEO_SIZE_HIGHT (600)
#define SOUND_LEFT	(255)
#define SOUND_RIGHT	(255)

#define PLAYER_NAME_DEFAULT ("Player")
#define NAME_SIZE	(32)
#define	MAX_RACES	(8)
#define	MAX_MAPS	(16)
#define MAX_ENTITY_ON_SCALE (16)
#define MAX_EPHEM	(16)
#define MAX_ACTION_FAIL	(4)
#define FW_MAX_SELECT	(12)
#define FW_MAX_PLAYERS	(32)
#define FW_MAX_CLIENTS	(FW_MAX_PLAYERS)

#define FOG_BLACK	(2)
#define FOG_OFWAR	(1)
#define FOG_NULL	(0)

/* type des slots d'une nouvelle partie*/
#define TYPE_OPEN	(0)
#define TYPE_CLOSE	(1)
#define TYPE_HUMAN	(2)
#define TYPE_CPU	(3)

#define BUF_SIZE (512)
#define BUF_LEN (512)

/* nb de sprite a charger dans la map */
#define NB_ITEMS (10)

#define NB_IMG_GAME (11)

#define SIZE_IMG_X (32)
#define SIZE_IMG_Y (32)

//#define IMG_NULL ("img/black.bmp")
#define IMG_NULL /*0*/ ("img/black.bmp")
#define IMG_GRASS /*1*/("img/grass.bmp")
#define IMG_RAIN /*2*/ ("img/rain.bmp")
#define IMG_SNOW /*3*/ ("img/snow.bmp")
#define IMG_SAND /*4*/ ("img/sand.bmp")
#define IMG_SWAMP /*5*/ ("img/swamp.bmp")
#define IMG_RIVER /*6*/ ("img/river.bmp")
#define IMG_ROCK /*7*/ ("img/rock.bmp")
#define IMG_MOUNTAIN /*8*/ ("img/mountain.bmp")
#define IMG_SEA /*9*/ ("img/sea.bmp")
#define IMG_GOLD ("img/bonhomme.png")


/* entity */
#define NB_DIR (12)
#define NB_TIME (8)
#define BUFF_NULL (0) // pour les sorts
/*
  1  2  3  4
  22       5
  11       6
  10 9  8  7
*/

/*
** sprites dans un tableau de idsprite/idtaunts d'actions
*/
#define NB_ACTION (5)

#define ACTION_MOVE (0)
#define ACTION_ATTACK (1)
#define ACTION_DIED (2)
#define ACTION_LIVE (3)
#define ACTION_CREATE (4)
#define ACTION_NONE (5)

#define ACTION_CREATE_UNITS (6)
#define ACTION_CREATE_BUILDING (7)

#define ACTION_WAIT (8)



#define MAX_TYPES (8)
#define TYPE_LANDS (0)
#define TYPE_TYPES (1)
#define TYPE_WEAPONS (2)
#define TYPE_ARMORS (3)
#define TYPE_ENTITIES (4)
#define TYPE_INSTANTS (5)
#define TYPE_METERS (6)
#define TYPE_LAYERS (7)

/*
** types des facteurs
*/
#define FACTOR_NULL (0)
#define FACTOR_SURFACE (1)

/* temporaire : placement des start points
   distance par rapport aux coter de la map.. */
#define START_LENGHT (15)
#define CENTER ("town-hall")
#define PEON ("peon")

/* pour les cost */
#define COST_GLOBAL ("global")

/* pour trouver le meter a decrementer pdt l'action attaque */
#define METER_LIFE ("life")

#define DIE (2)

#endif
