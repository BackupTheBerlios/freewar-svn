//
// init_entities.cpp for freewar in /root/Freewar/src/Actions
// 
// Made by 
// Login   <root@epita.fr>
// 
// Started on  Wed Jul 14 18:36:43 2004 
// Last update Wed Jul 14 18:36:45 2004 
//
#include "freewar.h"

int		init_entities(t_engine *e, t_game_param *game_param)
{
  int		p;
  t_coord	*start;
  t_coord	pos;
  t_coord	off;
  t_base_entity *center;
  t_base_entity *peon;
  t_base_entity	*vulture;
  t_base_entity	*phoenix;
  t_base_entity	*dropship;
  t_base_entity	*footman;

  // placer les town-hall et les 4 peons par joueurs sur la map
  // sera remplacer apres kan le map editor sera complet.
  start = (t_coord*)xmalloc(sizeof(*start) * e->nb_players);
  off.x = 0;
  off.y = 0;
  peon = get_base(e, PEON);
  center = get_base(e, CENTER);
  vulture = get_base(e, "vulture");
  phoenix = get_base(e, "phoenix");
  dropship = get_base(e, "dropship");
  footman = get_base(e, "footman");
//   for (p = 0; p < 20; p++)
//   {
// 	pos.x = get_random(e->map_data.w);
// 	pos.y = get_random(e->map_data.h);
// 	put_entity(e, vulture, p, pos, off);
// 	pos.x = get_random(e->map_data.w);
// 	pos.y = get_random(e->map_data.h);
// 	put_entity(e, phoenix, p, pos, off);
// 	pos.x = get_random(e->map_data.w);
// 	pos.y = get_random(e->map_data.h);
// 	put_entity(e, dropship, p, pos, off);
// 	pos.x = get_random(e->map_data.w);
// 	pos.y = get_random(e->map_data.h);
// 	put_entity(e, footman, p, pos, off);
//   }
  for (p = 0; p < e->nb_players; p++)
    {
      start[p].y = get_random(e->map_data.h);
      start[p].x = get_random(e->map_data.w);
      while (start[p].x < START_LENGHT || start[p].x > e->map_data.w - START_LENGHT ||
	     start[p].y < START_LENGHT || start[p].y > e->map_data.h - START_LENGHT)
	{
	  start[p].y = get_random(e->map_data.h);
	  start[p].x = get_random(e->map_data.w);
	}
      // autres fontions pour verifier l'emplacement de debut ptet..
      pos.x = start[p].x;
      pos.y = start[p].y + 1;
      put_entity(e, center, p, pos, off);
      pos.y--;
      put_entity(e, peon, p, pos, off);
      pos.x++;
      put_entity(e, peon, p, pos, off);
      pos.x++;
      put_entity(e, peon, p, pos, off);
      pos.x++;
      put_entity(e, peon, p, pos, off);
      pos.x++;
      put_entity(e, phoenix, p, pos, off);
      pos.x++;
      put_entity(e, footman, p, pos, off);
      pos.x++;
      put_entity(e, vulture, p, pos, off);
    }
  free(start);
  return (0);
}
