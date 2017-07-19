#ifndef _POINTS_
#define _POINTS_

#include "interface.h"

struct Points_t {
    SDL_Point coord1;
    SDL_Point coord2;
};
typedef struct Points_t points_t;

points_t pointsCreation(void);
void pointsPendules(SDL_Renderer *rendu, points_t p);
void pointsChemin(SDL_Renderer *rendu, points_t p);

#endif
