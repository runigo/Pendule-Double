#ifndef _PROJECTION_
#define _PROJECTION_

#include "../modele/pendule.h"

struct Points_t {
    SDL_Point coord1;
    SDL_Point coord2;
};
typedef struct Points_t points_t;

points_t pointsCreation(void);
int projectionPremierX(pendule_t p1);
int projectionPremierY(pendule_t p1);
int projectionSecondX(pendule_t p1, pendule_t p2);
int projectionSecondY(pendule_t p1, pendule_t p2);
void projectionPendules(pendule_t *p1, pendule_t *p2, points_t *p);
void dessinPendules(SDL_Renderer *rendu, points_t p);
void dessinChemin(SDL_Renderer *rendu, points_t p);

#endif
