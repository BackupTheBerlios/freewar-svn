/*
** global.h for freewar in /u/ept2/ribas_j/Freewar/include
** 
** Made by jonathan ribas
** Login   <ribas_j@epita.fr>
** 
** Started on  Thu May 13 11:33:08 2004 jonathan ribas
** Last update Thu May 13 11:41:21 2004 jonathan ribas
*/

#ifndef _GLOBAL_H_
#define _GLOBAL_H_


/* const t_items  gl_items[NB_ITEMS]; */
const t_items  gl_items[NB_ITEMS] =
  {
    {1, IMG_GRASS, true, SDLK_g},
    {843, IMG_RAIN, true, SDLK_q},
    {844, IMG_SNOW, true, SDLK_w},
    {845, IMG_SAND, true, SDLK_e},
    {846, IMG_SWAMP, true, SDLK_r},
    {847, IMG_RIVER, true, SDLK_t},
    {848, IMG_ROCK, true, SDLK_y},
    {849, IMG_MOUNTAIN, true, SDLK_u},
    {850, IMG_SEA, true, SDLK_i},
    {1842, IMG_GOLD, false, SDLK_g}
  };

#endif
