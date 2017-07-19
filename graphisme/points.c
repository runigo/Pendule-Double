#include "points.h"

points_t pointsCreation(void)
{
    points_t p;

    p.coord1.x = 0;
    p.coord1.y = 0;
    p.coord2.x = 0;
    p.coord2.y = 0;
    
    return p;
}

void pointsPendules(SDL_Renderer *rendu, points_t p) {    
    int x1 = p.coord1.x;
    int y1 = p.coord1.y;
    
    int x2 = p.coord2.x;
    int y2 = p.coord2.y;
    
    int xoffset = 1;
    
    SDL_SetRenderDrawColor(rendu, 0, 0, 0, SDL_ALPHA_OPAQUE);

    SDL_Point points1[3] = {
        {LARGEUR/2, HAUTEUR/2},
        {x1,    y1},
        {x2,    y2}
    };
    
    SDL_Point points2[3] = {
        {LARGEUR/2 + xoffset, HAUTEUR/2},
        {x1 + xoffset,    y1},
        {x2 + xoffset,    y2}
    };
    
    SDL_RenderDrawLines(rendu, points1, 3);
    SDL_RenderDrawLines(rendu, points2, 3);
}

void pointsChemin(SDL_Renderer *rendu, points_t p) {
    static SDL_Point point[2048] = {{0}};
    static int       i = 0;
    
    point[i].x = p.coord2.x;
    point[i].y = p.coord2.y;
    
    if(++i > 2048)
        i = 0;
    
    SDL_SetRenderDrawColor(rendu, 0, 0, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLines(rendu, point, i);
}

