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
    
    SDL_Point coord;
};

typedef struct Pendule_t pendule_t;

#endif
