#ifndef _POINTS_
#define _POINTS_

#include "../donnees/constantes.h"

struct Points_t {
    SDL_Point coord1;
    SDL_Point coord2;
};
typedef struct Points_t points_t;

points_t pointsCreation(void);
void dessinPendules(SDL_Renderer *rendu, points_t p);
void dessinChemin(SDL_Renderer *rendu, points_t p);

#endif
