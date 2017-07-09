#ifndef _PRINCIPALE_
#define _PRINCIPALE_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>

#include <math.h>

#include <SDL2/SDL.h>

#define LARGEUR  720
#define HAUTEUR 720

#define G 9.80665f
#define PI 3.14159265359

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
