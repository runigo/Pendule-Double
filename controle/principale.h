#ifndef _PRINCIPALE_
#define _PRINCIPALE_

#include "../donnees/constantes.h"

struct Pendule_t {
    double masse;
    double longueur;
    
    double theta_actuel;
    double theta_intermed;
};
typedef struct Pendule_t pendule_t;

struct Points_t {
    SDL_Point coord1;
    SDL_Point coord2;
};
typedef struct Points_t points_t;

#endif
